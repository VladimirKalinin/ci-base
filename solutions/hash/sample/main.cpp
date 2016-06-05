#include <iostream>
#include <fstream>
#include "Tab.h"

void main(int argc, char *argv[]) {
  if (argv[1] != 0) {
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    char spec;
    in >> spec;
    if (spec == 'c') {
      char fun[4], key[20], *ikey;
      int size = 0, data, p, q = 0;
      in >> size >> p;
      char** keys = new char*[100];
      HashTable<char*> ht(cfunk, size, p);
      while (!in.eof()) {
        in >> fun;
        if (fun[0] == 'A') {
          in >> key >> data;
          keys[q] = new char[strlen(key) + 1];
          strcpy_s(keys[q], strlen(key) + 1, key);
          ht.ins(keys[q], data);
          q++;
        }
        if (fun[0] == 'D') {
          in >> key;
          ikey = new char[strlen(key) + 1];
          strcpy_s(ikey, strlen(key) + 1, key);
          ht.del(ikey);
          delete ikey;
        }
      }
      for (int j = 0; j < size; j++) {
        if (ht.state(j) == "BUSY")
          out << ht.state(j) << " " << ht.Getkey(j)
          << " " << ht.Getdata(j) << "\n";
        if (ht.state(j) == "FREE")
          out << ht.state(j) << "\n";
      }
      return;
    } else {
      char fun[4];
      int size = 0, data, p, keyi = 0;
      in >> size >> p;
      HashTable<int> ht(ifunk, size, p);
      while (!in.eof()) {
        in >> fun;
        if (fun[0] == 'A') {
          in >> keyi >> data;
          ht.ins(keyi, data);
        }
        if (fun[0] == 'D') {
          in >> keyi;
          ht.del(keyi);
        }
      }
      for (int j = 0; j < size; j++) {
        if (ht.state(j) == "BUSY")
          out << ht.state(j) << " " << ht.Getkey(j)
          << " " << ht.Getdata(j) << "\n";
        if (ht.state(j) == "FREE")
          out << ht.state(j) << "\n";
      }
      return;
    }
  }
  char f[4] = { 'A', 'A', 'D', 'A' };
  HashTable<int> ht(ifunk, 4, 3);
  for (int i = 0; i < 4; i++) {
    if (f[i] == 'A')
      ht.ins(i + 20, i + 1);
    if (f[i] == 'D')
      ht.del(20);
  }
  for (int j = 0; j < 4; j++) {
    if (ht.state(j) == "BUSY")
      std:: cout << ht.state(j) << " " << ht.Getkey(j)
      << " " << ht.Getdata(j) << "\n";
    if (ht.state(j) == "FREE")
      std::cout << ht.state(j) << "\n";
  }
}
