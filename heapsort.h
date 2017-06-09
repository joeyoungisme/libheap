#ifndef HEAPSORT_H
#define HEAPSORT_H

int heapify(void *, size_t, size_t,
            int (*cmp_fun)(const void *, const void *),
            void (*swap_fun)(void *, void *, int));



int heapsorting(void *, size_t, size_t,
            int (*cmp_fun)(const void *, const void *),
            void (*swap_fun)(void *, void *, int));

#endif
