#include <stdio.h>
#include "BitSet.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


const float INTEGER_SIZE = 32;
const int MAX_RANGE = 256;
struct bit_set * bit_set_new( int size ) 
{
	int number_of_array_elements;
	number_of_array_elements = ceil( size / INTEGER_SIZE );
	
	struct bit_set * set = malloc( sizeof( struct bit_set ) );
	(*set).array = malloc( sizeof( unsigned int ) * number_of_array_elements );
	(*set).max = size - 1;
	return ( set );
}

int bit_set_lookup( struct bit_set * this, int item )
{
	return 0;
}


int bit_set_add( struct bit_set * this, int item )
{
	if ( item <= (*this).max )
	{
		int index = ( int ) ceil( item / INTEGER_SIZE ) - 1;
		unsigned int operand = 1;
		operand = operand << (item - ( index * ( int ) INTEGER_SIZE ));
		(*this).array[index] = (*this).array[index] | operand;
		return 1;
	}
	return 0;
}

int bit_set_remove( struct bit_set * this, int item )
{
	if ( item <= (*this).max )
	{
		int index = ( int ) ceil( item / INTEGER_SIZE ) - 1;
		unsigned int operand = 1;
		operand = operand << (item - ( index * ( int ) INTEGER_SIZE ));
		operand = ~operand;
		(*this).array[index] = (*this).array[index] & operand;
		return 1; 



	}
	return 0;
}


void bit_set_union( struct bit_set * dest, struct bit_set * src1, 
	struct bit_set * src2 )
{

}

void bit_set_intersect( struct bit_set * dest, struct bit_set * src1, 
	struct bit_set * src2 )
{

}

int main()
{
	// Just some test code
	struct bit_set * bit_set_1 = bit_set_new( 256 );
	bit_set_add( bit_set_1, 45 );
	bit_set_add( bit_set_1, 37 );
	bit_set_remove( bit_set_1, 37 );
	bit_set_remove( bit_set_1, 45 );
	
	printf( "%d", bit_set_1->array[1] );

}
