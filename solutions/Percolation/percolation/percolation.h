class separ {
public:
  int *mas;
  int len;

  separ(int l) {
    len = l;
    mas = new int[len];
    for (int i = 0; i < len; i++)
      mas[i] = -i;
  }

  void merge(int i, int j) {
    mas[getindex(i)] = getindex(j);
  }

  int getindex(int i) {
    while (mas[i] != i)
      i = mas[i];
    return i;
  }

};
