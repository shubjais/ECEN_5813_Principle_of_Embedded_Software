/*========================================================================
** Circular buffer
** ECEN5813
** Submitted By: Shubham Jaiswal
**========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ring.h"

int num = 0;

ring_t *init(int length)
{
	
	ring_t *ring_buff = (ring_t *) malloc(sizeof(ring_t));

	if (ring_buff == NULL)
	{
		return NULL;
	}

	ring_buff->Buffer = (char *)malloc (length);
	
	if (ring_buff->Buffer == NULL)
	{
		return NULL;
	}
	else
	{
	ring_buff->Length = length;
	ring_buff->Ini = 0;
	ring_buff->Outi = 0;
	ring_buff->Buffer_full =  false;
	num = 0;
	}

	return (ring_buff);
}

ring_t *buffer_resize(ring_t *ring, int new_length)
{
	ring->Buffer = (char *)realloc (ring->Buffer, new_length);
	if (ring->Buffer == NULL)
		{
			return NULL;
		}
	ring->Length = new_length;
	return (ring);
}

int insert( ring_t *ring, char data )
{
	if(!ring->Buffer_full && (num != ring->Length))
	{
		printf("Element can be inserted into buffer\n\r");
		ring->Buffer[ring->Ini] = data;
		printf("Inserting value %x at position %d\n\r", data, ring->Ini);
		ring->Ini = (ring->Ini + 1); //% ring->Length;
		num++;
		if (num == ring->Length)
		{
			ring->Buffer_full = true;
		}
		return 0;
	}
	else
	{
		printf("Buffer is full\n");
		return -1;
	}
}

int remove_element( ring_t *ring, char *data )
{
	if(num == 0)
	{
		printf("Buffer is Empty\n");
		return -1;
	}
	else
	{
		printf("Buffer element can be removed\n");
		*data = ring->Buffer[ring->Outi];
		printf("Removing element %x from address %d\n\r", ring->Buffer[ring->Outi], ring->Outi);
		ring->Outi = (ring->Outi + 1); //% ring->Length;
		num--;
		if(ring->Buffer_full)
		{
			ring->Buffer_full = false;
		}
		return 0;
	}
}

int entries( ring_t *ring )
{
	printf("Number of entries:%d\n\r", num);
	return num;
}
