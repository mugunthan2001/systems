#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* arr_p;
    uint size;
    uint type;
} d_arr_t;

d_arr_t *curr_arr = NULL;

int getsize(int type) {
    if(type == 1) return sizeof(int);
    else if(type == 2) return sizeof(float);
    else return sizeof(char);
}

char gettype(int type) {
    if(type == 1) return 'd';
    else if(type == 2) return 'f';
    else return 'c';
}

d_arr_t* create_arr(int size, int type) {
    d_arr_t* new_d_arr = (d_arr_t*) malloc(sizeof(d_arr_t));
    new_d_arr->size = size;
    new_d_arr->type = type;

    void* new_arr = malloc(size * getsize(type));
    memset(new_arr, 0, size * getsize(type));
    
    new_d_arr->arr_p = new_arr;

    return new_d_arr;
}

void print_arr(d_arr_t const * d_arr) {
    void* arr_p = d_arr->arr_p;
    if(arr_p == NULL) {
        printf("Invalid array \n");
        return;
    }
    char fmts[4];
    fmts[0] = '%'; 
    fmts[1] = gettype(d_arr->type);
    fmts[2] = ',';
    fmts[3] = '\0'; 

    for(int i = 0; i < d_arr->size; i++){
        printf(fmts, *(char*)(arr_p += getsize(d_arr->type)));
    }

    printf("\n");
}

int main(void) {
    int ui = 1;
    int size = 0, type = 0;

    while(ui) {
        printf("Enter an option:\n\
                1: create an array\n\
                2: print current array\n\
                0: exit\n");
        scanf("%d", &ui);

        switch(ui) {
            case 1: {
                printf("Input: <size> <type [1:int, 2:float, 3:char]> : \n");
                scanf("%d %d", &size, &type);
                curr_arr = create_arr(size, type);
                break;   
            }
            case 2:
                print_arr(curr_arr);
                break;
            default: printf("Byee!!\n");
        }
    }
}