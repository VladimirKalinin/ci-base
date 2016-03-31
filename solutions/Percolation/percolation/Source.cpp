#include <stdio.h>
#include "percolation.h"
#include "stdlib.h"
#include <time.h>

int main() {
  int h, tmp, stime, s = 0, j, n;
  long ltime;

  ltime = time(NULL);
  stime = (unsigned) ltime/2;
  srand(stime);

  printf("h = ");
  scanf("%i", &h);
  double sum = 50;
  separ a(h * (h + 2));

  for (j = 0, n = 1; ; j++, n++) {  
    
    for (int i = 0; i < h; i++)
      a.mas[i] = 0;
    for (int i = h * (h + 1); i < h * (h + 2); i++)
      a.mas[i] = h * (h + 2) - 1;
    for (int i = h; i < h * (h + 1); i++)
      a.mas[i] = -i;


  /*  for (int i = 0; i < h + 2; i++) {
      for (int j = 0; j < h; j++)
        printf("%i ", a.mas[i * h + j]);
      printf("\n");
    }*/

    while (a.getindex(0) != a.getindex(2*h + h * h - 1)) {
      tmp = h + rand() % (h * h);
  //    printf("tmp = %i\n", tmp);
      while (a.mas[tmp] > 0) {
        tmp = h + rand() % (h * h);
  //      printf("tmp2 = %i\n", tmp);
      }
      a.mas[tmp] = -a.mas[tmp];
      if (a.mas[tmp - h] >= 0)
        a.merge(tmp, tmp - h);
      if (a.mas[tmp + h] >= 0)
        a.merge(tmp, tmp + h);
      if ((a.mas[tmp - 1] >= 0) && (tmp % h != 0))
        a.merge(tmp, tmp - 1);
      if ((a.mas[tmp + 1] >= 0) && ((tmp + 1) % h != 0))
        a.merge(tmp, tmp + 1);
      s++;
    }
    sum = sum*(1 - double(1)/double(n + 1)) + double(s)/double(n + 1);
    if (j == 100) {
      j = 0;
      printf("open/all = %f n = %i\n", sum/h/h, n);
    }
    s = 0;
  }  

/*   for (int i = 1; i < h + 1; i++) {
    for (int j = 0; j < h; j++)
      if (a.mas[i * h + j] >= 0)
        if (a.getindex(i * h + j) == a.getindex(0))
          printf("\033[31mX\033[0m");
        else
          printf("\033[32mX\033[0m");
      else
        printf("\033[34mX\033[0m");
    printf("\n");
  }
  printf("open/all = %f\n", float(s) / h / h);
/*  printf("index[3] = %i\n", a.getindex(3));
  printf("index[115] = %i\n", a.getindex(115));
  printf("index[54] = %i\n", a.getindex(54));*/
}
