#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void print_list(struct song_node *ll){
    printf("{");
    while (ll){
        if(ll->name==NULL){
            printf("[%s,%s]",ll->name,ll->artist);
        }
        else{
            printf("[%s,%s]",ll->name,ll->artist);
        }
        ll=ll->next;
    }
    printf("}\n");
}
struct song_node * insert_front(struct song_node * front, char n[100], char a[100]){
    struct song_node *new = malloc(sizeof(struct song_node));
    strcpy(new->name,n);
    strcpy(new->artist,a);
    new->next=front;
    return new;
}
struct song_node * free_list(struct song_node * ll){
    struct song_node *first=ll;
    while(ll!=NULL){
        free(ll);
        ll=ll->next; 
    }
    first=NULL;
    return first;
}