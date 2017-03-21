#include "../main.h"
#define PROCESS_NUMBER 7

/* Usable functions */

void        my_printf(const string query, ...) {
    int     i,
            j
            opt[5];
    size_t  querySize;
    va_list ap;

    querySize = stringLengthHelper(query);

    va_start(ap, query);

    i = 0;
    while (i < querySize) {
        if (query[i] == '%') {
          ++i;

          // Options
          // TODO

          // Process
          j = 0;
          while (j < PROCESS_NUMBER) {
             if ((*check[j])(query, j))
                (*print[j])(ap, opt);
             ++j;
          }
        } else {
            chr_print(query[i]);
        }
        ++i;
    }

    var_end(ap);
}
