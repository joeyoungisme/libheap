#ifndef HEAPSORT_H
#define HEAPSORT_H

#ifndef DIM
    #define DIM(x)                      (sizeof(x)/sizeof(x[0]))
#endif

#define LCHILD_OFF(num, elesize)    ((num*2-1) * elesize)
#define RCHILD_OFF(num, elesize)    ((num*2) * elesize)
#define NUM_OFF(num, elesize)       ((num-1) * elesize)

int heapify(void *, size_t, size_t,
            int (*cmp_fun)(const void *, const void *),
            void (*swap_fun)(void *, void *, int));



int heapsorting(void *, size_t, size_t,
            int (*cmp_fun)(const void *, const void *),
            void (*swap_fun)(void *, void *, int));

#endif
