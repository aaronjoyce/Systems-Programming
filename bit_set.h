struct bit_set
{	
	unsigned int * array;
	int max;
};


struct bit_set * bit_set_new( int size );
int bit_set_lookup( struct bit_set * this, int item );
int bit_set_add( struct bit_set * this, int item );
int bit_set_remove( struct bit_set * this, int item );
void bit_set_union( struct bit_set * dest, struct bit_set * src1, 
	struct bit_set * src2 );
void bit_set_intersect( struct bit_set * dest, struct bit_set * src1, 
	struct bit_set * src2 );
