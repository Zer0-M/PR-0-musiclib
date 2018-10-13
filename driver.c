#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
    struct song_node *first;
    first=NULL;
    printf("the linked list when first initialized:");
    print_list(first);
    char n[100]="Killer Queen";
    char a[100]="Queen";
    first=insert_front(first,n,a);
    print_list(first);
    first=free_list(first);
     printf("Linked list after freed:");
    print_list(first);
    return 0;
}
