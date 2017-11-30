#include <stdio.h>
#include <stdlib.h>
#include "movement.c"


int main()
{
    #ifdef ROBOT_CONNECTED
    OutputInit();
    #endif
    int unsolved = 1;
    int input = 0;
    while(unsolved)
    {
        printf("Input: ");
        fflush(stdout);
        scanf(" %d", &input);
        
        // Exit condition
        if(input > 16)
        {
            printf("Terminating.\n");
            fflush(stdout);
            break;
        }
        // extract information from the input here 


        // Using a single ampersand does bitwise and to
        //   determine what the input is.
        if(input & 0x00000008) // Input is: on gold
            printf("Gold! ");
        if(input & 0x00000004) // Input is: near gold
            printf("Glimmer! ");
        if(input & 0x00000002) // Input is: near wumpus
            printf("Wumpus! ");
        if(input & 0x00000001) // Input is: near hole
        {
            printf("Breeze! ");
        }
        printf("\n");
        fflush(stdout);

        #ifdef ROBOT_CONNECTED
        //simple_forward();
        //simple_turn_right();
        //simple_turn_left();
        //print_sensor();
        //sensor_forward();
        //sensor_backward();
        //turn_right();
        //turn_left();
        #endif
    }

    #ifdef ROBOT_CONNECTED
    OutputExit();
    #endif
    return 0;
}
