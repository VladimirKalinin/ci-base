#ifndef SOLUTIONS_HEAP_�PP_
#define SOLUTIONS_HEAP_CPP_
#include "Heap.h"

void HeapSort(int *m, int n) {
  Heap a(m, n, n);
  for (int i = 0; i < n; i++)
    m[i] = a.Delete();
}
#endif  // SOLUTIONS_HEAP_CPP_