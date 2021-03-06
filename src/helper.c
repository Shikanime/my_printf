/*
   helper.c for my_printf in /home/asuramaru/Project/print/phetsi_w/src

   Made by PHETSINORATH William
   Login   <phetsi_w@etna-alternance.net>

   Started on  Fri Mar 24 14:37:11 2017 PHETSINORATH William
   Last update Fri Mar 24 14:37:17 2017 PHETSINORATH William
*/

#include "headers/helper.h"

/* Usable functions */

void  charPrintHelper(char c) {
  write(1, &c, 1);
}

long int        stringLengthHelper(const char * s) {
  const char *  bfs;

  bfs = s;
  while (*bfs != '\0') {
    ++bfs;
  }

  return bfs - s;
}

void            stringPrintHelper(const char * s) {
  const char *  bfs;

  bfs = s;
  while (*bfs != '\0') {
    charPrintHelper(*bfs);
    ++bfs;
  }
}

void            unsignedIntegerPrintHelper(unsigned int n) {
  unsigned int	b;

  if (n < 10) {
    charPrintHelper((char) (n + 48));
    return;
  }
  b = 1;
  while (b <= (n / 10))
    b *= 10;
  while (b >= 1) {
    charPrintHelper((char) (n / b + '0'));
    n %= b;
    b /= 10;
  }
}

void  integerPrintHelper(int n) {
  if (n == -2147483647)
    stringPrintHelper((char *) ("-2147483647"));
  if (n < 0) {
    charPrintHelper('-');
    n *= -1;
  }
  unsignedIntegerPrintHelper((unsigned int) n);
}

void            hexadecimalPrintHelper(unsigned int n) {
  unsigned int  bfn;

  if (n >= 16) {
    bfn = n % 16;
    n /= 16;
    hexadecimalPrintHelper(n);
  } else if (n > 0) {
      bfn = n % 16;
      n /= 16;
  }
  if (bfn > 9)
    charPrintHelper((char) (bfn + 87));
  else
    charPrintHelper((char) (bfn + 48));
}

void            hexadecimalCapitalPrintHelper(unsigned int n) {
  unsigned int  bfn;

  if (n >= 16) {
      bfn = n % 16;
      n /= 16;
      hexadecimalPrintHelper(n);
  } else if (n > 0){
      bfn = n % 16;
      n /= 16;
  }
  if (bfn > 9)
    charPrintHelper((char) (bfn + 55));
  else
    charPrintHelper((char) (bfn + 48));
}

/* 楽園追放のアンジェラバルザック */

void		addressHexadecimalPrintHelper(unsigned int n, int i) {
  unsigned int  bfn;

  if (n >= 16 || i > 0) {
    bfn = n % 16;
    n /= 16;
    addressHexadecimalPrintHelper(n, i - 1);
  } else if (n > 0) {
      bfn = n % 16;
      n /= 16;
  }
  if (bfn > 9)
    charPrintHelper((char) (bfn + 87));
  else
    charPrintHelper((char) (bfn + 48));
}

void	addressPrintHelper(unsigned int n) {
  int	i;

  i = 8;
  addressHexadecimalPrintHelper(n, i);
}

void	          octalPrintHelper(unsigned int n) {
  unsigned int  m;
  unsigned int  i;

  m = 0;
  i = 1;
  while (n != 0) {
    m += (n % 8) * i;
    n /= 8;
    i *= 10;
  }
  integerPrintHelper((int) m);
}
