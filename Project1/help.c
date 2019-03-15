/**
* @brief
*Definition of help function which display's all the available commands.
*
* @author Shubham Jaiswal and Ayush Dhoot
*/


#include <stdio.h>
#include "help.h"

int help()
{


	PRINTF("\n\rEntered help function" );
	PRINTF("\n\rYou can execute the following commands:");
	PRINTF("\n\rallocate - Allocates memory.");
	PRINTF("\n\rfree - frees up the allocated memory.");
	PRINTF("\n\rdisp - displays the contents of memory");
	PRINTF("\n\rwrite - Writes the value provided by user at specified memory location.");
	PRINTF("\n\rinvert - inverts all bits in the specified memory. And returns the amount of time taken to perform operation.");
	PRINTF("\n\rwritep - writes a pseudo-random number at the specified memory location. And returns the amount of time taken for operation");
	PRINTF("\n\rverifyp - verifies the pseudo-random number at a specified memory location. And returns the amount of time taken for operation");
	PRINTF("\n\rex - to exit the command line.");
	PRINTF("\n\r");

//	printf("\nEntered help function" );
//	printf("\nYou can execute the following commands:");
//	printf("\nallocate - Allocates memory.");
//	printf("\nfree - frees up the allocated memory.");
//	printf("\ndisp - displays the contents of memory");
//	printf("\nwrite - Writes the value provided by user at specified memory location.");
//	printf("\ninvert - inverts all bits in the specified memory. And returns the amount of time taken to perform operation.");
//	printf("\nwritep - writes a pseudo-random number at the specified memory location. And returns the amount of time taken for operation");
//	printf("\nverifyp - verifies the pseudo-random number at a specified memory location. And returns the amount of time taken for operation");
//	printf("\nex - to exit the command line.");
//	printf("\n");
//

	return 0;
}
