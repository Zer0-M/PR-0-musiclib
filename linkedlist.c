#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

void print_list(struct song_node *ll){
    printf("[");
    while (ll){
        if(!ll->next){
            printf("%s:%s",ll->name,ll->artist);
        }
        else{
            printf("%s:%s|",ll->name,ll->artist);
        }
        ll=ll->next;
    }
    printf("]\n");
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

struct song_node * ordered_insert(struct song_node * front, char n[100], char a[100]){
    struct song_node * init=front;
    struct song_node * prev=front;
    int added=0;
    if(strcmp(front->artist,a)>0){
        return insert_front(front,n,a);
    }
    else{
        while(front){
            if(strcmp(front->artist,a)>0){
                struct song_node *new = malloc(sizeof(struct song_node));
                strcpy(new->name,n);
                strcpy(new->artist,a);
                prev->next=new;
                new->next=front;
                added=1;
            }
            if(strcmp(front->artist,a)==0){
                if(strcmp(front->name,n)>0){
                    struct song_node *new = malloc(sizeof(struct song_node));
                    strcpy(new->name,n);
                    strcpy(new->artist,a);
                    prev->next=new;
                    new->next=front;
                    added=1;
                }
            }
            prev=front;
            front=front->next;
        }
        if(!added){
            struct song_node *new = malloc(sizeof(struct song_node));
            strcpy(new->name,n);
            strcpy(new->artist,a);
            prev->next=new;
        }
    }
    return init;
}
struct song_node * search_song(struct song_node * front, char n[100], char a[100]){
    while(front){
        if(strcmp(front->artist,a)==0){
            if(strcmp(front->name,n)==0){
                return front;
            }
        }
        front=front->next;
    }
    return NULL;
}
struct song_node * search_artist(struct song_node * front, char a[100]){
    while(front){
        if(strcmp(front->artist,a)==0){
            return front;
        }
        front=front->next;
    }
    return NULL;
}
struct song_node * random_song(struct song_node * front){
    srand( time(NULL) );
    int i=rand()%list_len(front);
    int count=0;
    while(count!=i){
        front=front->next;
        count++;
    }
    return front;
}
int list_len(struct song_node * front){
    int count = 0;
    while(front){
        front=front->next;
        count++;
    }
    return count;
}
void remove_song(struct song_node * front, char n[100], char a[100]){
    struct song_node * init=front;
    struct song_node * prev=front;
    while(front){
        if(front==search_song(front,n,a)){
            prev->next=front->next;
            free(front);
            return;
        }
        else{
            prev=front;
        }
        front=front->next;
    }
}