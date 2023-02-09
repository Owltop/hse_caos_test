#include <aio.h>
#include <ctype.h>
#include <errno.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"


Node *push(Node *place, int value) {
    Node *ans = calloc(1, sizeof(*ans));
    if (ans == NULL) {
        return NULL;
    }
    ans->value = value;
    if (place == NULL) {
        return ans;
    }
    if (place->prev) {
        ans->prev = place->prev;
    }
    ans->next = place;
    place->prev = ans;
    if (ans->prev) {
        ans->prev->next = ans;
    }
    return ans;
}

int pop(Node *node) {
    int ans = node->value;
    Node* prev = node->prev;
    if (prev) {
        prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = prev;
    }
    node->next = NULL;
    node->prev = NULL;
    free(node);
    return ans;
}

/*int main() {
    Node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    if (pop(head->next) == 1) {
        printf("1");
    }
    if (pop(head) == 2) {
        printf("1");
    }
}*/