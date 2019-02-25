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
				//{"write_p",&write_pattern},\
				//{"verify_p",&verify_pattern},
				 {"ex",&ex}};


int main()
{
	e = 1;
	int found;
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

		for (int i = 0; i < 7; i++)
		{
			if (strcmp(input, lookup[i].ip) == 0)
			{
				found = 1;
				(*lookup[i].my_func)();
				if(strcmp(input, lookup[0].ip) != 0 && strcmp(input, lookup[6].ip) != 0)
				{
					printf("Please Input another command or try 'help' to get the list of commands.\n");
				}
				break;	
			}
			
			
			else if(i == 7)
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
