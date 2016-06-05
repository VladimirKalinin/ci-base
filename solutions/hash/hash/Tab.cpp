#include "Tab.h"

HashTable<int>::HashTable(HashFunction _hash, int _size, int _p) {
  hash = ifunk;
  size = _size;
  count = 0;
  curpos = 0;
  freepos = 0;
  p = _p;
  arr = new TabRecord<int>*[size];
  for (int i = 0; i < size; i++)
    arr[i] = NULL;
  Pmark = new TabRecord<int>(0, 0);
}


HashTable<char*>::HashTable(HashFunction _hash, int _size, int _p) {
  hash = _hash;
  size = _size;
  count = 0;
  curpos = 0;
  p = _p;
  arr = new TabRecord<char*>*[size];
  for (int i = 0; i < size; i++)
    arr[i] = NULL;
  Pmark = new TabRecord<char*>("", 0);
  freepos = -1;
}

int ifunk(int val, int size) {
  return(val%size);
}

int cfunk(char* str, int size) {
  int val = 0;
  for (int i = 0; i < strlen(str); i++)
    val += static_cast<int>(str[i]);
  return(val%size);
}

TabRecord<int>* HashTable<int>::search(int val) {
  curpos = hash(val, size);
  freepos = -1;
  for (int i = 0; i < size; i++) {
    if (arr[curpos] == 0) {
      freepos = curpos;
      return 0;
    }
    if (arr[curpos]->Getkey() == val)
      return arr[curpos];
    if (arr[curpos] == Pmark && freepos == -1)
      freepos = curpos;
    curpos = GetNextPos(curpos);
  }
  return 0;
}

TabRecord<char*>* HashTable<char*>::search(char* val) {
  curpos = hash(val, size);
  freepos = -1;
  for (int i = 0; i < size; i++) {
    if (arr[curpos] == 0) {
      freepos = curpos;
      return 0;
    }
    if (strcmp(arr[curpos]->Getkey(), val) == 0)
      return arr[curpos];
    if (arr[curpos] == Pmark && freepos == -1)
      freepos = curpos;
    curpos = GetNextPos(curpos);
  }
  return 0;
}
