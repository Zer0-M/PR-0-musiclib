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
    if(!front||strcmp(front->artist,a)>0){
        return insert_front(front,n,a);
        added=1;
    }
    else{
        struct song_node *new = malloc(sizeof(struct song_node));
        strcpy(new->name,n);
        strcpy(new->artist,a);
        while(front){
            if(strcmp(front->artist,a)>0){
                prev->next=new;
                new->next=front;
                break;
            }
            if(strcmp(front->artist,a)==0){
                if(strcmp(front->name,n)>0){
                    new->next=front;
                    if(prev!=front){
                        prev->next=new;
                    }
                    if(init==front){
                        return new;
                    }
                    break;
                }
            }
            prev=front;
            front=front->next;
        }
        prev->next=new;
    }
    return init;
}
struct song_node * search_song(struct song_node * front, char n[100], char a[100]){
    while(front){
        if(!strcmp(front->artist,a)){
            if(!strcmp(front->name,n)){
                struct song_node * result=malloc(sizeof(struct song_node));
                strcpy(result->name,front->name);
                strcpy(result->artist,front->artist);
                return result;
            }
        }
        front=front->next;
    }
    return NULL;
}
int sngcmp(struct song_node * n1,struct song_node *n2){
    if(!strcmp(n1->artist,n2->artist)){
            return strcmp(n1->name,n2->name);
    }
    return strcmp(n1->artist,n2->artist);
}
struct song_node * search_artist(struct song_node * front, char a[100]){
    struct song_node * searchfront=malloc(sizeof(struct song_node));
    searchfront=NULL;
    while(front){
        if(!strcmp(front->artist,a)){
            searchfront=ordered_insert(searchfront,front->name,front->artist);
        }
        front=front->next;
    }
    return searchfront;
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
struct song_node * remove_song(struct song_node * front, char n[100], char a[100]){
    struct song_node * init=front;
    struct song_node * prev=front;
    struct song_node * removed=search_song(front,n,a);
    while(front){
        if(!sngcmp(removed,front)){
            printf("%s : %s\n",prev->artist,prev->name);
            free(front);
            if(prev!=front){
                prev->next=front->next;
            }
            else{
                return front->next;
            }
        }
        else{
            prev=front;
        }
        front=front->next;
    }
    return init;
}