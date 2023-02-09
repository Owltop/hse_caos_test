#include <aio.h>
#include <ctype.h>
#include <errno.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tinyconv(uint8_t bytes[], size_t size) {
    size_t i = 0;
    while (i < size) {
        uint8_t initial = bytes[i];
        uint8_t our = 0;
        int mmog = 128;
        while (initial > 0) {
            our += (initial & 1) * mmog;
            initial = initial >> 1;
            mmog /= 2;
        }
        bytes[i] = our;
        ++i;
    }
}

/*int main() {
    uint8_t b[] = {0xfa, 0x04};
    tinyconv(b, 2);
    printf("ok");
}*/