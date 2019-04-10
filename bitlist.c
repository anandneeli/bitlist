#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1

#define BITMASK_SET(x,y) ((x) |= (y))
#define BITMASK_CLEAR(x,y) ((x) &= (~(y)))
#define BITMASK_FLIP(x,y) ((x) ^= (y))
#define BITMASK_CHECK_ALL(x,y) (((x) & (y)) == (y))   // warning: evaluates y twice
#define BITMASK_CHECK_ANY(x,y) ((x) & (y))

*/

typedef struct {
    int bits;
    int ints;
    u_int32_t *list;
} bitlist_t;


bitlist_t *bitlist_init(bitlist_t *bl, int max)
{
    bl = (bitlist_t *) malloc(sizeof(bitlist_t));
    bl->bits = max;
    bl->ints = max/32;
    if(max % 32)
        bl->ints++;
    bl->list = (u_int32_t *) malloc((bl->ints * sizeof(u_int32_t)));
    memset(bl->list, 0, bl->ints*sizeof(u_int32_t));
    return bl;
}

void bitlist_print(bitlist_t *bl)
{
    printf("max: %d ints:%d\n", bl->bits, bl->ints);
    for(int i=0; i< bl->ints; i++)
    {
        printf(" %d  <--> %d\n", i, bl->list[i]);
    }
}

bitlist_t *bitlist_set(bitlist_t *bl, int bit)
{
    int word = 0;
    int word_bit = 0;
    if (bl->bits < bit) {
        printf("Error max bits");
        return bl;
    }
    word = bit/32;
    word_bit = bit%32;
    bl->list[word] |= (1<<word_bit);


    return bl;

}

int main()
{
    int max_bits = 100;
    bitlist_t *bl = NULL;

    bl = bitlist_init(bl, max_bits);
    bl = bitlist_set(bl, 3);
    bitlist_print(bl);

    return 0;

}


    
