/**
* @brief Display the pattern generated at user defined memory location
*
* @author Ayush Dhoot and Shubham Jaiswal
*/


#include "verifypattern.h"

int verify_pattern()
{
	uint32_t *rand_addr;
	uint32_t *i, *j;
	int choice, offset, valid_n = 0, words_available = 0, input_no_words = 0;
	long seed;
	double rand_pattern;
	long rand_pattern_long;

	if(first_ptr == NULL)  // Check if any memory block is allocated or not.
	{
		printf("No memory block is allocated. Please allocate a memory block first.\n");
		return -1;  // Change it with return later on.
	}
	else
	{
		if(pattern_wrote != 1)
		{
			printf("No random pattern was written to be verified.\n");
			return -1;
		}
		printf("Allocated memory addresses on which written random number can be verified:\n"); // print the address of allocated blocks
		for(i = first_ptr; i <= last_ptr; i++)
		{
			printf("\n%p",i);
		}

		printf("\n\nPlease select one of following ways to specify the address:"
				"\n1.Type the address of which you wish to verify the data"
				"\n2.Give an offset from %p"
				"\n3.Exit command.\n", first_ptr);

		while(1)  // Ask user the address of the block at which he/she wishes to write the data.
		{
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
				printf("Enter the address of memory block of which you wish to see the data\n");
				scanf("%p", &rand_addr);
				break;

				case 2:
				printf("Enter the offset from memory address %p:", first_ptr);
				scanf("%d", &offset);
				rand_addr = first_ptr + offset;
				break;

				case 3:
				return 0;

				default:
				printf("Not a valid input.Please try again with a valid input or enter 3 to input another command:\n");
			}

			if(choice == 1 || choice == 2)
			{
				break;
			}
		}

		//Ask user the number of blocks at which he/she wishes to verify the random pseudo data.
		printf("Enter the no of word blocks data you wish to verify random pattern at:\n");
		scanf("%d", &input_no_words);	
		printf("Enter the seed value:\n"); //Ask user to enter the seed value to generate the random number.
		scanf("%ld", &seed);

		//Check if the address provided by the user is among the allocated memory addresses.
		for(i = first_ptr;i <= last_ptr; i++)
		{		
			if(i == rand_addr)		
			{
				for (j = rand_addr; j <= last_ptr; j++)
				{
					words_available++;
				}
				if(input_no_words <= words_available)  // check if the number of blocks demanded by user fall within the number of allocated blocks.
				{
					clock_t start = clock(); //start clock

					for(; input_no_words > 0 ; input_no_words--)   // Verify pseudo random number at requested memory blocks.
					{
						//Algorithm to Generate the Pseudo-random number.
						const long Q = MODULUS / MULTIPLIER;
  						const long R = MODULUS % MULTIPLIER;
				        long t;

						t = MULTIPLIER * (seed % Q) - R * (seed / Q);
						if (t > 0)
						{
							seed = t;
						}
						else
						{ 
							seed = t + MODULUS;
						}

						rand_pattern = ((double) seed / MODULUS);
						//printf("Random number generated is %ld \n", (long)(rand_pattern * 1000000)); 
						rand_pattern = rand_pattern * 1000000;
						rand_pattern_long = (long) rand_pattern;
						
						if(rand_pattern_long == *i)
						{
							printf("Random number verified\n");
						}
						else
						{
							printf("Random number not verified\n");
							printf("Value of random number is %ld and value at memory address %p is %d\n",rand_pattern_long, i, *i);
						}
						
						i++;
					}

					clock_t end = clock(); //end clock
					printf("\nTime taken to verify the random pattern at specified memory address(es):%f seconds",(double)(end - start) / CLOCKS_PER_SEC);
					printf("\n");
				}
				else
				{
					printf("Asked number of blocks not avaible from the desired address.\n");
					return -1;
				}
				break;
			} 
			else
			{
			 	valid_n++;					
			}
		}

		if(valid_n == mem_allocate)					//Condition to check whether entered address is valid or not
   		{
			printf("\nThe address entered is not a valid address");
			printf("\n");
			return -1;
		}
	}
	return 0;
}