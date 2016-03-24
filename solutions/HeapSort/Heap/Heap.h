#ifndef SOLUTIONS_HEAP_H_
#define SOLUTIONS_HEAP_H_
#include <stdio.h>
class Heap {
 public:
  int size;
  int len;
  int *mas;

  void Add(int a) {
    if (len > size - 1)
      throw "Heap is full";
    len++;
    mas[len] = a;
    int i = len;
    int tmp = 0;
    while (mas[i] < mas[i/2] && i > 1) {
      tmp = mas[i];
      mas[i] = mas[i/2];
      mas[i/2] = tmp;
      i = i/2;
    }
  }

  Heap(int *m, int n, int sz) {
    mas = new int[n + 1];
    len = 0;
    size = sz;
    for (int i = 0; i < n; i++)
      Add(m[i]);
  }

  void print() {
    for (int i = 1; i < len + 1; i++)
      printf("%i ", mas[i]);
  }

  int Delete() {
    mas[0] = mas[1];
    mas[1] = mas[len];
    len--;
    int i = 1;
    while (i*2 < len && (mas[i] > mas[2*i] || mas[i] > mas[2*i+1])) {
      if (mas[2*i] < mas[2*i+1]) {
        int tmp = mas[2*i];
        mas[2*i] = mas[i];
        mas[i] = tmp;
        i = 2*i;
      } else {
        int tmp = mas[2*i + 1];
        mas[2*i + 1] = mas[i];
        mas[i] = tmp;
        i = 2*i + 1;
      }
    }
    return mas[0];
  }
};

//void HeapSort(int *m, int n);

#endif  // SOLUTIONS_HEAP_H_
