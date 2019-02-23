/**
* @brief Contains the main body of the program
*
* @author Ayush Dhoot and Shubham Jaiswal
*/



#include "main.h"




table lookup[]= {{"help\n",&help},
				{"allocate\n",&allocate_mem},\
				{"free\n",&free_mem},\
				//{"disp",&disp},\
				//{"write",&write},\
				//{"invert",&invert},\
				//{"write_p",&write_pattern},\
				//{"verify_p",&verify_pattern},
				 {"ex\n",&ex}};


int main()
{
	e = 1;
	uint8_t found;
	printf("\nType help to get the list of commands.\n");

	while(e)
	{
		fgets(input,10,stdin);
		for (int i=0; i<4; i++)
		{
			found = 0;
			if (strcmp(input,lookup[i].ip) == 0)
			{
				found = 1;
				(*lookup[i].my_func)();
				//break;	
			}
			
			
			else if(i == 3)
			{
			printf("\nEntered command is not a valid command. Try 'help'.\n");
			break;
			}
			
		}
		
	}
	return 0;
}
