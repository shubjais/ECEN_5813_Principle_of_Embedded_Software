/**
* @brief Contains the main body of the program
*
* @author Ayush Dhoot and Shubham Jaiswal
*/



#include "main.h"




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
	int found;
	int ret;
	char *newline;
	printf("\nType help to get the list of commands.\n");

	while(e)
	{
		found = 0;
		fgets(input,15,stdin);
		
		newline = strchr(input, '\n');

		if (newline)
		{			
			*newline = '\0';
		}

		for (int i = 0; i < 9; i++)
		{
			if (strcmp(input, lookup[i].ip) == 0)
			{
				found = 1;
				ret = (*lookup[i].my_func)();
				if(strcmp(input, lookup[0].ip) != 0 && strcmp(input, lookup[8].ip) != 0)
				{
					if(ret != 0)
					{
						printf("Program directed here due to invalid input.Please start again.\n");
					}
					printf("Please Input another command or try 'help' to get the list of commands.\n");
				}
				break;	
			}
			
			
			else if(i == 9)
			{
			printf("\nEntered command is not a valid command. Try 'help'.\n");
			break;
			}
			
		}
		// if (found == 0)
		// {
		// 	printf("%s\n", input);
		// 	printf("Entered command is not a valid command. Try 'help' to see the list of available commands.\n");
		// }
		
	}
	return 0;
}
