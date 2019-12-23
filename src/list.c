#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "extern.h"

void list_initialize(list *l) {
    l->start = malloc(sizeof(list_item));
    l->end = malloc(sizeof(list_item));
    l->start->next = l->end;
    l->start->prev = l->end;
    l->end->next = l->start;
    l->end->prev = l->start;
    l->size = 0;
}

int list_size(list *l) {
    return l->size;
}

void destroy(list *l) {
    if (l->size == 0) {
        printf("List is empty\n");
        return;
    }
    list_item *i = l->start->next;
    int const_size = list_size(l);
    for (int j = 0; j < const_size; ++j) {
        list_item *m = i;
        i->prev->next = i->next;
        i->next->prev = i->prev;
        i = i->next;
        free(m);
        l->size--;
    }
    return;
}

void list_erase(list_iterator it, list *l) {
    --(l->size);
    list_item *temp = it.ptr;
    it.ptr->prev->next = it.ptr->next;
    it.ptr->next->prev = it.ptr->prev;
    free(temp);
}

void list_insert_after(list_iterator it, double num, list *l) {
    ++(l->size);
    list_item *temp = malloc(sizeof(list_item));
    temp->value = num;
    temp->next = it.ptr->next;
    it.ptr->next->prev = temp;
    temp->prev = it.ptr;
    it.ptr->next = temp;
    return;
}

void list_print(list *l) {
    if (l->size == 0) {
        printf("List is empty\n");
        return;
    }
    list_item *temp = l->start->next;
    for (int i = 0; i < l->size; ++i) {
        printf("%lf ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
