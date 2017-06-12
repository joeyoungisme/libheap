#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "heapsort.h"

#define LCHILD_OFF(num, elesize)                ((num * 2 - 1) * elesize)
#define RCHILD_OFF(num, elesize)                ((num * 2) * elesize)
#define NUM_OFF(num, elesize)                   ((num - 1) * elesize)

int heapify(void *base, size_t num, size_t ele_size,
            int (*cmp_fun)(const void *, const void*),
            void (*swap_fun)(void *, void *, int))
{
    if(!base)
        return -1;

    for(int index = num/2; index > 0; index -= 1)
    {
        int bigchild;
        for(int sub_index = index; sub_index * 2 <= num; sub_index = bigchild) {

            //if (node only have left child) or (left child > rigth child)
            //bigchild = left
            if((sub_index * 2 + 1 > num) || cmp_fun(base+LCHILD_OFF(sub_index, ele_size), base+RCHILD_OFF(sub_index, ele_size)) > 0)
                bigchild = sub_index * 2;
            //else bigchild = right
            else
                bigchild = sub_index * 2 + 1;

            //Compare node and big child, swap or do nothing
            if(cmp_fun(base+NUM_OFF(bigchild, ele_size), base+NUM_OFF(sub_index, ele_size)) > 0)
                swap_fun(base+NUM_OFF(bigchild, ele_size), base+NUM_OFF(sub_index, ele_size), ele_size);
            else break;
        }
    }

    return 0;
}

int heapsorting(void *base, size_t num, size_t ele_size,
                int (*cmp_fun)(const void *, const void *),
                void (*swap_fun)(void *, void *, int))
{
    if(!base)
        return -1;

    heapify(base, num, ele_size, cmp_fun, swap_fun);


    for(int index = num; index > 0; --index) {
        swap_fun(base+NUM_OFF(1, ele_size), base+NUM_OFF(index, ele_size), ele_size);
        heapify(base, index - 1, ele_size, cmp_fun, swap_fun);
    }

    return 0;
}

