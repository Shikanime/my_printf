#ifndef MY_PRINTF_RULLES_CHECK_H
#define MY_PRINTF_RULLES_CHECK_H

#define CHECK_NUMBER 7

int (*check[CHECK_NUMBER])  (const char * query, unsigned int n);
int integerCheck            (const char * query, unsigned int n);
int longCheck               (const char * query, unsigned int n);
int charCheck               (const char * query, unsigned int n);
int stringCheck             (const char * query, unsigned int n);
int pointerCheck            (const char * query, unsigned int n);
int shortCheck              (const char * query, unsigned int n);
int hexadecimalCheck        (const char * query, unsigned int n);

#endif //MY_PRINTF_RULLES_CHECK
