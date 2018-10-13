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
    char n2[100]="Bohemian Rhapsody";
    char n3[100]="Take It Easy";
    char a3[100]="Eagles";
    char n4[100]="Under Pressure";
    first=insert_front(first,n,a);
    first=ordered_insert(first,n3,a3);
    first=ordered_insert(first,n2,a);
    first=ordered_insert(first,n4,a);
    print_list(first);
    printf("%s\n",search_artist(first,a)->name);
    first=free_list(first);
     printf("Linked list after freed:");
    print_list(first);
    return 0;
}
