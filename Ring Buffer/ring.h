/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
**========================================================================*/

#ifndef RING_H
#define RING_H
#include <stdbool.h>

#define MAX 3   //size of ring buffer

typedef struct
{
	char *Buffer;
	int Length;
	int Ini;
	int Outi;
	volatile bool Buffer_full
} ring_t;


ring_t *init( int length );
int insert( ring_t *ring, char data );
//char removed( ring_t *ring );
int remove_data( ring_t *ring, char *data );
int entries( ring_t *ring );
void ring_reset(ring_t *ring);
bool ring_status(ring_t *ring);
void ring_free(ring_t *ring);

int num;



#endif