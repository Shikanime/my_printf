#include "loader.h"

/* Usable functions */

void                my_printf(const char * query, ...) {
    unint    positionQuery;
    unint    j;
    long int        sizeQuery;
    int             opt[5];
    va_list         ap;

    sizeQuery = stringLengthHelper(query);

    va_start(ap, query);

    positionQuery = 0;
    while (positionQuery < sizeQuery) {
        if (query[positionQuery] == '%' && query[positionQuery + 1] != '\0') {
          ++positionQuery;

          // Options
          j = 0;
          while (j < OPTION_NUMBER) {
             if ((*option[j])(query, positionQuery, opt)){
                 ++positionQuery;
             }
             ++j;
          }

          // Process
          j = 0;
          while (j < PROCESS_NUMBER) {
             if ((*process[j])(query, positionQuery, ap, opt)){
                 j = PROCESS_NUMBER;
             }
             ++j;
          }
        } else {
            charPrintHelper(query[positionQuery]);
        }
        ++positionQuery;
    }

    va_end(ap);
}
