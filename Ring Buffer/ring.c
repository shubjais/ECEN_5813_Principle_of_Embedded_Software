/*========================================================================
** Circular buffer
** ECEN5813
**========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "ring.h"


void ring_reset(ring_t *ring)
{
	printf("Ring has been reset\n\r");;
	ring->Ini = 0;
	ring->Outi =0;
	ring->Buffer_full =  false;
} 

void ring_free(ring_t *ring)
{
	free(ring);
}

ring_t * init (int length)
{
	
	ring_t * my_ring_buff = (ring_t *) malloc(sizeof(ring_t));

	if (my_ring_buff == NULL)
	{
		return NULL;
	}

	my_ring_buff->Buffer = (char *)malloc (length);
	
	if (my_ring_buff->Buffer == NULL)
	{
		return NULL;
	}
	else
	{
	my_ring_buff->Length = length;
	ring_reset(my_ring_buff);
	}

	return (my_ring_buff);
}


bool ring_status(ring_t *ring)
{
	if(num == 0)
	{
		ring->Buffer_full = false;
	}
	else if(num == (ring->Length))
	{
		ring->Buffer_full = true;
	}
	
	return ring->Buffer_full;
}

int insert( ring_t *ring, char data )
{
	if(ring_status(ring))
	{
		printf("Buffer full\n\r");
		return -1;
	}
	else
	{
		printf("Buffer element can be inserted\n\r");
	}

	if (num != MAX)
	{
	ring->Buffer[ring->Ini] = data;
	printf("Inserting value %x at position %d\n\r", data, ring->Ini);
	ring->Ini = (ring->Ini + 1) % ring->Length;
	num++;
	return 0;
	}
}

int remove_data( ring_t *ring, char *data )
//char removed ( ring_t *ring )
{
	if(!ring_status(ring))
	{
		printf("Buffer empty\n\r");
		return -1;
	}
	else
	{
		printf("Buffer element can be removed\n\r");
	}
	
	if(num != 0)
	{		
		*data = ring->Buffer[ring->Outi];
		printf("Removing element %x from address %d\n\r", ring->Buffer[ring->Outi], ring->Outi);
		ring->Outi = (ring->Outi + 1) % ring->Length;
		num--;
		return 0;
	}
}

int entries( ring_t *ring )
{
	printf("Number of entries are %d\n\r", num);
	return num;
}

/*int main (void)
{
	char data1;
	printf("Ring Buffer\n\r");

	num = 0;
	
	ring_t *startaddr = init(MAX);

	
	printf("Size of Structure : %ld\r\n", sizeof(ring_t));
    printf("Starting Memory Address : %s\r\n", startaddr);
    printf("Starting Buffer Memory Address : %s\r\n", startaddr->Buffer);
    printf("Length : %d\r\n", startaddr->Length);
    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);

    insert(startaddr, 12);
    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);


    insert(startaddr, 2);
    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);

    entries(startaddr);

    remove_data(startaddr, &data1);
    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);

    entries(startaddr);

	insert(startaddr, 4);
    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);

	entries(startaddr);
	insert(startaddr, 24);
	printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);

	remove_data(startaddr, &data1);
    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);

    ring_reset(startaddr);

    printf("Head : %d\r\n", startaddr->Ini);
    printf("Tail : %d\r\n", startaddr->Outi);
    printf("Status : %d\r\n", startaddr->Buffer_full);


}*/