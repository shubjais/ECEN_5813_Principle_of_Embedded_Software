/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
** Submitted By: Shubham Jaiswal, Ayush Dhoot
**========================================================================*/

#ifndef RING_H
#define RING_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct ring_buffer
{
	int8_t *Buffer;
	int Length;
	int Ini;
	int Outi;
	volatile bool Buffer_full;
}ring_t;


ring_t *init( int length );
int insert( ring_t *ring, int8_t data );
int8_t remove_element( ring_t *ring);
int entries( ring_t *ring );
ring_t *buffer_resize(ring_t *ring, int new_length, int old_length);
extern int num;

#endif
