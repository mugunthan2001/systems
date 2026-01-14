#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* arr_p;
    uint size;
    uint type;
} d_arr_t;

d_arr_t* create_arr(int size, int type);

void print_arr(d_arr_t const * d_arr);

#endif