#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include "extern.h"

int enterChoice(void) {
    int menu;
    printf("enter\n"
           "1-print\n"
           "2-insert\n"
           "3-delete\n"
           "4-delete all\n"
           "5- end\n"
    );
    scanf("%d", &menu);
    return menu;
}

int main() {
    void* lib;
    lib = dlopen("libmylist.so",RTLD_LAZY);
    if (!lib) {
	printf("dlopen() error\n");
	exit(1);
    }
	void (*list_initialize)(list *l);
	int (*list_size)(list *l);
	void (*destroy)(list *l);
	void (*list_erase)(list_iterator it, list *l);
	void (*list_insert_after)(list_iterator it, double num, list *l);
	void (*list_print)(list *l);
    list_initialize = dlsym(lib,"list_initialize");
    list_size = dlsym(lib,"list_size");
    destroy = dlsym(lib,"destroy");
    list_erase = dlsym(lib,"list_erase");
    list_insert_after = dlsym(lib,"list_insert_after");
    list_print = dlsym(lib,"list_print");
    	 
    list list;
    int choice;
    list_initialize(&list);
    while ((choice = enterChoice()) != 5) {
        switch (choice) {
            case 1:
                (*list_print)(&list);
                break;
            case 2:
                printf("Enter index new value:\n");
                int index;
                list_iterator it;
                it.ptr = list.start;
                scanf("%d", &index);
                if (index < 0 || index > list.size) {
                    printf("Error, invalid index\n");
                    break;
                } else {
                    for (int j = 0; j < index; ++j) {
                        it.ptr = it.ptr->next;
                    }
                }
                printf("Enter value:\n");
                double newVal;
                scanf("%lf", &newVal);
                (*list_insert_after)(it, newVal, &list);
                break;
            case 3:
                printf("Enter the index to be deleted\n");
                int index2,index22;
                scanf("%d", &index2);
                index22 = index2 + 1;
                list_iterator it2;
                it2.ptr = list.start;
                if (index2 < 0 || index2 >= list.size) {
                    printf("Error, invalid index\n");
                    break;
                }
                for (int i = 0; i < index22; ++i) {
                    it2.ptr = it2.ptr->next;
                }
                (*list_erase)(it2, &list);
                break;
            case 4:
                (*destroy)(&list);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }
    return 0;
}
