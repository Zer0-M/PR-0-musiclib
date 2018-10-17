#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "lib.h"

void add_node(struct song_node * t[27],struct song_node * ll){
    struct song_node *prev=ll;
    while(ll){
        char *first_letter=ll->artist;
        int position=*first_letter-'a';
        t[position]=ordered_insert(t[position],ll->name,ll->artist);
        ll=ll->next;
    }
}
struct song_node * song_search(struct song_node * t[27],char n[100], char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    return search_song(t[position],n,a);
}
struct song_node * artist_search(struct song_node * t[27],char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    return search_artist(t[position],a);
}
struct song_node * list_letter(struct song_node * t[27],char letter){
    int position=letter-'a';
    return t[position];
}
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
}/*
struct song_node * shuffle(struct song_node * t[27]){

}
*/
void delete_song(struct song_node * t[27],char n[100],char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    t[position]=remove_song(t[position],n,a);
}
void clear_lib(struct song_node * t[27]){
    for(int i=0;i<27;i++){
        t[i]=free_list(t[i]);
    }
}