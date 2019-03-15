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
	long int seed;
	double rand_pattern;
	long rand_pattern_long;

	if(first_ptr == NULL)  // Check if any memory block is allocated or not.
	{
		PRINTF("\n\rNo memory block is allocated. Please allocate a memory block first.\n");
		return -1;  // Change it with return later on.
	}
	else
	{
		if(pattern_wrote != 1)
		{
			PRINTF("\n\rNo random pattern was written to be verified.\n");
			return -1;
		}
		PRINTF("\n\rAllocated memory addresses on which written random number can be verified:\n"); // print the address of allocated blocks
		for(i = first_ptr; i <= last_ptr; i++)
		{
			PRINTF("\n\r\n%p",i);
		}

		PRINTF("\n\r\n\nPlease select one of following ways to specify the address:"
				"\n\r1.Type the address of which you wish to verify the data"
				"\n\r2.Give an offset from %p"
				"\n\r3.Exit command", first_ptr);

		while(1)  // Ask user the address of the block at which he/she wishes to write the data.
		{
			SCANF("%d",&choice);
			PRINTF("\t%d", choice);
			switch(choice)
			{
				case 1:
				PRINTF("\n\rEnter the address of memory block of which you wish to see the data\n");
				SCANF("%p", &rand_addr);
				break;

				case 2:
				PRINTF("\n\rEnter the offset from memory address %p:", first_ptr);
				SCANF("%d", &offset);
				PRINTF("\t%d", offset);
				rand_addr = first_ptr + offset;
				break;

				case 3:
				return 0;

				default:
				PRINTF("\n\rNot a valid input.Please try again with a valid input or enter 3 to input another command:\n");
			}

			if(choice == 1 || choice == 2)
			{
				break;
			}
		}

		//Ask user the number of blocks at which he/she wishes to verify the random pseudo data.
		PRINTF("\n\rEnter the no of word blocks data you wish to verify random pattern at:\n");
		SCANF("%d", &input_no_words);
		PRINTF("\t%d", input_no_words);
		PRINTF("\n\rEnter the seed value:\n"); //Ask user to enter the seed value to generate the random number.
#ifdef KL25Z
		SCANF("%d", &seed);
		PRINTF("\t%d", seed);
#endif
#ifdef LINUX
		SCANF("%ld", &seed);
#endif
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
#ifdef LINUX
					clock_t start = clock();  //start timer
#endif

#ifdef KL25Z
					SysTick_Config(16000000);
#endif

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
						//PRINTF("\n\rRandom number generated is %d \n", (long int)(rand_pattern * 1000000));
						rand_pattern = rand_pattern * 1000000;
						rand_pattern_long = (long int) rand_pattern;
						
						if(rand_pattern_long == *i)
						{
							PRINTF("\n\rRandom number verified\n");
						}
						else
						{
							PRINTF("\n\rRandom number not verified\n");

#ifdef KL25Z
						PRINTF("\n\rValue of random number is %d and value at memory address %p is %d\n",rand_pattern_long, i, *i);
#endif
#ifdef LINUX
						PRINTF("\n\rValue of random number is %ld and value at memory address %p is %d\n",rand_pattern_long, i, *i);
#endif

						}
						
						i++;
					}


#ifdef KL25Z
					uint32_t count = 16000000 - SysTick->VAL;
					SysTick->CTRL = 0;
					float timetaken = ((0.047619)*count);
					PRINTF("\n\r\nTime taken to verify random pattern at specified memory address(es): %f micro-seconds",timetaken);
#endif

#ifdef LINUX
					clock_t end = clock();  //end timer
					PRINTF("\n\r\nTime taken to verify random pattern at specified memory address(es):%f seconds",(double)(end - start) / CLOCKS_PER_SEC);
					PRINTF("\n\r\n");
#endif

				}
				else
				{
					PRINTF("\n\rAsked number of blocks not avaible from the desired address.\n");
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
			PRINTF("\n\r\nThe address entered is not a valid address");
			PRINTF("\n\r\n");
			return -1;
		}
	}
	return 0;
}
