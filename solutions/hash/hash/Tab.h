#ifndef SOLUTIONS_HASH_HASH_TAB_H_
#define SOLUTIONS_HASH_HASH_TAB_H_

#include <cstring>
#pragma once

template<class KeyType>
class TabRecord {
 protected:
  KeyType key;
  int data;
 public:
  TabRecord(KeyType, int);
  ~TabRecord() {}
  int Getdata()const;
  KeyType Getkey()const;
};

template<class KeyType>
class HashTable {
  typedef int(*HashFunction)(KeyType, int);
 protected:
  HashFunction hash;
  int count;
  int size;
  int curpos;
  TabRecord<KeyType> *Pmark;
  TabRecord<KeyType> **arr;
  int p;
  int freepos;
  unsigned int GetNextPos(int pos);
 public:
  HashTable(HashFunction _hash, int size, int p);
  ~HashTable();
  TabRecord<KeyType>* search(KeyType);
  void ins(KeyType, int);
  void del(KeyType k);
  int IsEmpty()const;
  int IsFull()const;
  char* state(int i);
  int Getdata(int i)const;
  KeyType Getkey(int i)const;
};

int cfunk(char *, int);
int ifunk(int val, int size);

template<class KeyType>
TabRecord<KeyType>::TabRecord(KeyType k, int d) {
  key = k;
  data = d;
}

template<class KeyType>
int TabRecord<KeyType>::Getdata()const {
  return data;
}

template<class KeyType>
KeyType TabRecord<KeyType>::Getkey()const {
  return key;
}

template<class KeyType>
unsigned int HashTable<KeyType>::GetNextPos(int pos) {
  return ((pos + p) % size);
}

template<class KeyType>
HashTable<KeyType>::~HashTable() {
  for (int i = 0; i < size; i++)
  if (arr[i] != NULL && arr[i] != Pmark)
    delete arr[i];
  delete Pmark;
  delete[]arr;
}

template<class KeyType>
void HashTable<KeyType>::ins(KeyType k, int d) {
  if (IsFull())
    return;
  if (search(k) == 0 && freepos != -1) {
    curpos = freepos;
    arr[curpos] = new TabRecord<KeyType>(k, d);
    count++;;
  }
  return;
}

template<class KeyType>
int HashTable<KeyType>::IsEmpty()const {
  return(count == 0);
}

template<class KeyType>
int HashTable<KeyType>::IsFull()const {
  return(count == size);
}

template<class KeyType>
void HashTable<KeyType>::del(KeyType k) {
  if (IsEmpty())
    return;
  if (search(k) != 0) {
    delete arr[curpos];
    count--;
    arr[curpos] = Pmark;
  }
}

template<class KeyType>
char* HashTable<KeyType>::state(int k) {
  if (arr[k] == 0 || arr[k] == Pmark)
    return "FREE";
  return "BUSY";
}

template<class KeyType>
int HashTable<KeyType>::Getdata(int i)const {
  return (arr[i]->Getdata());
}

template<class KeyType>
KeyType HashTable<KeyType>::Getkey(int i)const {
  return (arr[i]->Getkey());
}

#endif  //  SOLUTIONS_HASH_HASH_TAB_H_
