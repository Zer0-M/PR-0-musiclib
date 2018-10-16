#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "lib.h"

int main(){
    struct song_node *first;
    first=NULL;
    printf("the linked list when first initialized:");
    print_list(first);
    char a[100]="queen";
    char a1[100]="aerosmith";
    char a2[100]="the rolling stones";
    char a3[100]="eagles";
    char a4[100]="led zeppelin";
    char a5[100]="foo fighters";
    char a6[100]="pink floyd";

    char n[100]="killer queen";
    char n1[100]="brighton rock";
    char n2[100]="take it easy";
    char n3[100]="immigrant song";
    char n4[100]="dream on";
    char n5[100]="paint it black";
    char n6[100]="walk";
    char n7[100]="comfortably numb";
    printf("%d\n",strcmp(n,n2));
    first=insert_front(first,n,a);
    first=ordered_insert(first,n1,a);
    first=ordered_insert(first,n2,a3);
    first=ordered_insert(first,n3,a4);
    first=ordered_insert(first,n4,a1);
    first=ordered_insert(first,n5,a2);
    first=ordered_insert(first,n6,a5);
    first=ordered_insert(first,n7,a6);
    printf("%s\n",random_song(first)->name);
    //remove_song(first,n,a);
    print_list(first);
    printf("%p\n",search_artist(first,a)->name);
    struct song_node *table[27];
    for(int i=0;i<27;i++){
        table[i]=NULL;
    }
    *table=add_node(table,first);
    print_lib(table);
    //char *b=a3;
    //printf("%d\n",*a);
    return 0;
}
