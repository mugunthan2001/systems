#include "array.h"

d_arr_t *curr_arr = NULL;

// --- Helpers ---

static int getsize(int type) {
    if(type == 1) return sizeof(int);
    else if(type == 2) return sizeof(float);
    else return sizeof(char);
}

static void printInt(void* elem) {
    printf("%d, ", *(int*)elem);
}

static void printFloat(void* elem) {
    printf("%.2f, ", *(float*)elem);
}

static void printChar(void* elem) {
    printf("%c, ", *(char*)elem);
}

static void (*print_cb[])(void*) = {NULL, printInt, printFloat, printChar};

// ------

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
    int elem_size = getsize(d_arr->type);
 
    if(arr_p == NULL) {
        printf("Invalid array \n");
        return;
    }

    for(int i = 0; i < d_arr->size; i++) {
        print_cb[d_arr->type](arr_p += elem_size);
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