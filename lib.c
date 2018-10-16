#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "lib.h"

struct song_node * add_node(struct song_node * t[27],struct song_node * ll){
    struct song_node *prev=ll;
    while(ll){
        char *first_letter=ll->artist;
        int position=*first_letter-'a';
        t[position]=ordered_insert(t[position],ll->name,ll->artist);
        ll=ll->next;
    }
    return *t;
}
/*
struct song_node * search_song(char n[100], char a[100]){

}
struct song_node * search(char a[100]){

}
struct song_node * list_letter(char letter){

}
struct song_node * list_artist(char a[100]){

}*/
void print_lib(struct song_node * t[27]){
    for(int i=0;i<27;i++){
        if(t[i]){
            if(i==26){
                printf("other symbols:\n");
            }
            else{
                printf("%c:\n",'a'+i);
            }

                print_list(t[i]);
        }
    }
}
/*
struct song_node * shuffle(struct song_node * t[27]){

}
struct song_node * delete_song(struct song_node * t[27]){

}
void clear_lib(struct song_node * t[27]){

}*/