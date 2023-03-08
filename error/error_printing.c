//
// Created by henri on 07.03.2023.
//

#include <stdarg.h>
#include "error_printing.h"

void log_error(FILE * out, const char * format, ...) {
    va_list ap;
    va_start(ap, format);
    vfprintf(out, format, ap);
    va_end(ap);
}