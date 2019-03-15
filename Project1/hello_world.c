/**
* @brief Contains the main body of the program
*
* @author Ayush Dhoot and Shubham Jaiswal
*/



#include "main.h"



#ifdef KL25Z
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"

#endif

//Storing commands and address of corresponding functions in the lookup table.
table lookup[]= {{"help",&help},
				{"allocate",&allocate_mem},
				{"free",&free_mem},
				{"disp",&display_mem},
				{"write",&write_mem},
				{"invert",&invert_mem},
				{"writep",&write_pattern},
				{"verifyp",&verify_pattern},
				{"ex",&ex}};


int main()
{

#ifdef KL25Z
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
#endif

	e = 1;
	int i;
	int ret;
	char *newline;

	PRINTF("\n\rType help to get the list of commands.");
	PRINTF("\n\r");

	while(e)
	{

#ifdef LINUX
		fgets(input,15,stdin);
#endif

#ifdef KL25Z
		SCANF("%14s[^\n]",input);
		PRINTF("\n\r");
#endif

		PRINTF("%s",input);
		PRINTF("\n\r");

		newline = strchr(input, '\n');

		if (newline) //Removing the next line character from the end of input string.
		{
			*newline = '\0';
		}

		for (i = 0; i < 9; i++)  //Running a loop to check the entered input against the lookup table.
		{
			if (strcmp(input, lookup[i].ip) == 0)
			{
				ret = (*lookup[i].my_func)(); //Call the function against the inputed command from the lookup table.
				if(strcmp(input, lookup[0].ip) != 0 && strcmp(input, lookup[8].ip) != 0) // check if the input command is 'help' or 'ex', dont print these.
				{
					if(ret != 0)
					{
						PRINTF("Program directed here due to invalid input.Please start again.\n");
						//printf("Program directed here due to invalid input.Please start again.\n");
					}
					PRINTF("\n\rPlease Input another command or try 'help' to get the list of commands.\n");
					//printf("Please Input another command or try 'help' to get the list of commands.\n");
				}
				break;
			}
			else if(i == 8 && strcmp(input, "") == !0)
			{
				PRINTF("\nEntered command is not a valid command. Try 'help'.\n");
				//printf("\nEntered command is not a valid command. Try 'help'.\n");
			}
		}

	}
	return 0;
}
