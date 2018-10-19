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
        if(position<0){
            position=26;
        }
        t[position]=ordered_insert(t[position],ll->name,ll->artist);
        ll=ll->next;
    }
}
struct song_node * song_search(struct song_node * t[27],char n[100], char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    if(position<0){
        position=26;
    }
    return search_song(t[position],n,a);
}
struct song_node * artist_search(struct song_node *t[27],char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    if(position<0){
        position=26;
    }
    return search_artist(t[position],a);
}
void list_artist(struct song_node *t[27],char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    if(position<0){
        position=26;
    }
    struct song_node *next=t[position];
    struct song_node *result=NULL;
    result=ordered_insert(result,search_artist(next,a)->name,search_artist(next,a)->artist);
    next=search_artist(next,a)->next;
    while(next){
        if(!strcmp(next->artist,a)){
            result=ordered_insert(result,next->name,next->artist);
        }
        next=next->next;
    }
    print_list(result);

    
}
struct song_node * list_letter(struct song_node * t[27],char letter){
    int position=letter-'a';
    if(position<0){
        position=26;
    }
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
}
int len_lib(struct song_node *t[27]){
    int count=0;
    for(int i=0;i<27;i++){
        struct song_node * init=t[i];
        while(t[i]){
            count++;
            t[i]=t[i]->next;
        }
        t[i]=init;
    }
    return count;
}
void shuffle(struct song_node * t[27]){
    int buckets[27];
    int count=0;
    for(int i=0;i<27;i++){
        if(t[i]){
            buckets[count]=i;
            count++;
        }
    }
    srand(time(NULL));
    int num_results=1+((int)rand())%(len_lib(t)-1);
    int position[num_results];
    for(int i=0;i<num_results;i++){
        position[i]=((int)rand())%num_results;
    }
    for(int i=0;i<num_results;i++){
        struct song_node *song=random_song(t[buckets[position[i]]]);
        printf("%s : %s\n",song->name,song->artist);
    }
}
void delete_song(struct song_node * t[27],char n[100],char a[100]){
    char *first_letter=a;
    int position=*first_letter-'a';
    if(position<0){
        position=26;
    }
    t[position]=remove_song(t[position],n,a);
}
void clear_lib(struct song_node * t[27]){
    for(int i=0;i<27;i++){
        t[i]=free_list(t[i]);
    }
}