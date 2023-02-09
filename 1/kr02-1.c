#include <aio.h>
#include <ctype.h>
#include <errno.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strip_spaces(char *buf) {
    char *cur = buf;
    char *cur_for_write = buf;
    int flag = 1;
    while (1) {
        if (*cur == '\0') {
            if (cur_for_write != buf && *(cur_for_write - 1) == ' ') {
                *(cur_for_write - 1) = '\0';
            } else {
                *cur_for_write = '\0';
            }
            return;
        }
        if (isspace(*cur) && flag == 0) {
            flag = 1;
            ++cur;
            ++cur_for_write;
            *(cur_for_write - 1) = ' ';
        } else if (isspace(*cur) && flag == 1) {
            ++cur;
        } else {
            flag = 0;
            ++cur;
            ++cur_for_write;
            *(cur_for_write - 1) = *(cur - 1);
        }
    }
}

/*int main() {
    char str[] = "   филе \t клавиатуры   под\tплесенью\n";
    strip_spaces(str);
    printf("%s", str);
}*/