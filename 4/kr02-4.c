#include <aio.h>
#include <ctype.h>
#include <errno.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void please_compute_and_print_some_strange_values_from_some_other_strange_values(
    const char *val1, const char *val2) {

    long a = strtol(val1, NULL, 13);
    long b = strtol(val2, NULL, 13);
    if ((int64_t)a + (int64_t)b != a + b) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    if (b == 0 || a == INT32_MIN && b == -1) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

int main() {
    please_compute_and_print_some_strange_values_from_some_other_strange_values(
        "25b47736b",
        "25b47736c");  // в десятичной системе: 2000000000, 2000000001
}