#include "Heap/Heap.h"
#include "Heap/Heap.cpp"
#include "gtest/gtest.h"

TEST(Heap, can_create_heap) {
  int a[10] = {2, 6, 4, 8, 4, 0, 10, 33, 5, 7};
  ASSERT_NO_THROW(Heap h(a, 10, 20));
}

TEST(Heap, cant_create_heap_with_negative_size) {
  int a[10] = {2, 6, 4, 8, 4, 0, 10, 33, 5, 7};
  ASSERT_ANY_THROW(Heap h(a, -10, 20));
}

TEST(Heap, can_add_element_to_heap) {
  int a[10] = {2, 6, 4, 8, 4, 0, 10, 33, 5, 7};
  Heap h(a, 10, 20);
  h.Add(-100);
  ASSERT_EQ(h.mas[1], -100);
}


TEST(Heap, can_sort_massive) {
  int a[10] = {2, 6, 4, 8, 4, 0, 10, 33, 5, 7};
  HeapSort(a, 10);
  for (int i = 1; i < 10; i++)
    ASSERT_LE(a[i-1], a[i]);
}
