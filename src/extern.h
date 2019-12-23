#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct List_item list_item;
typedef struct List list;
typedef struct List_iterator list_iterator;

struct List_item {
    double value;
    struct List_item *next;
    struct List_item *prev;
};

struct List {
    struct List_item *start;
    struct List_item *end;
    int size;
};

struct List_iterator {
    struct List_item *ptr;
};

extern void list_initialize(list *l);
extern int list_size(list *l);
extern void destroy(list *l);
extern void list_erase(list_iterator it, list *l);
extern void list_insert_after(list_iterator it, double num, list *l);
extern void list_print(list *l);
