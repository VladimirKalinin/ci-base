#include "stdio.h"
#include "Heap.h"

int main() {
  int a[10] = {2, 6, 4, 8, 4, 0, 10, 33, 5, 7};

  printf("source massive: ");
  for (int i = 0; i < 10; i++)
    printf("%i ", a[i]);
  printf("\n");
  printf("heap:           ");
  Heap h(a, 10);
  h.print();
  printf("\n");
  printf("sorted massive: ");
  HeapSort(a, 10);
  for (int i = 0; i < 10; i++)
    printf("%i ", a[i]);
}
