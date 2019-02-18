/**
* @brief 
* Main function: gets the input from user and invokes the appropriate 
* function, depending upon the user input.
* @author Shubham Jaiswal and Ayush Dhoot.
*/



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "help.h"

char input[10];
//char cmd[10] = "ex";
int e = 1;

void ex(void)
{
	e=0;
	printf("\n");
}

int main()
{
	printf("\nType help to get the list of commands.\n");
	
	while(e)
	{
		fgets(input,10,stdin);

		if (strcmp(input,"help\n") == 0)
		{
			help();	
		}

		else if (strcmp(input,"ex\n") == 0)
		{
			printf("exiting...");
			ex();
		}

		else 
		{
			printf("\nEntered command is not yet supported or not a valid command. Try 'help or ex'.\n");
		}
	}

	return 0;
}