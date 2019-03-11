/**
* @brief Contains the main body of the program
*
* @author Ayush Dhoot and Shubham Jaiswal
*/



#include "main.h"



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
	e = 1;
	int found, i;
	int ret;
	char *newline;
	printf("\nType help to get the list of commands.\n");

	while(e)
	{
		found = 0;
		fgets(input,15,stdin);
		
		newline = strchr(input, '\n');

		if (newline) //Removing the next ine character from the end of input string.
		{			
			*newline = '\0';
		}

		for (i = 0; i < 9; i++)  //Running a loop to check the entered input against the lookup table.
		{
			if (strcmp(input, lookup[i].ip) == 0)
			{
				found = 1;
				ret = (*lookup[i].my_func)(); //Call the function against the inputed command from the lookup table.
				if(strcmp(input, lookup[0].ip) != 0 && strcmp(input, lookup[8].ip) != 0) // check if the input command is 'help' or 'ex', dont print these.
				{
					if(ret != 0)
					{
						printf("Program directed here due to invalid input.Please start again.\n");
					}
					printf("Please Input another command or try 'help' to get the list of commands.\n");
				}
				break;	
			}
			else if(i == 8 && strcmp(input, "") == !0)
			{
				printf("\nEntered command is not a valid command. Try 'help'.\n");
			}			
		}
		
	}
	return 0;
}
