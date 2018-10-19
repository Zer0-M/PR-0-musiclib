#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "lib.h"

int main(){
    struct song_node *first;
    first=NULL;
    struct song_node *init=first;
    init=NULL;
    printf("Adding songs to song linked list\n\n");
    char a[100]="queen";
    char a1[100]="aerosmith";
    char a2[100]="the rolling stones";
    char a3[100]="eagles";
    char a4[100]="led zeppelin";
    char a5[100]="the clash";
    char a6[100]="pink floyd";
    char a7[100]="21 pilots";

    char n[100]="killer queen";
    char n1[100]="brighton rock";
    char n2[100]="take it easy";
    char n3[100]="immigrant song";
    char n4[100]="dream on";
    char n5[100]="paint it black";
    char n6[100]="this is radio clash";
    char n7[100]="comfortably numb";
    char n8[100]="kashmir";
    char n9[100]="pet cheetah";

    first=insert_front(first,n,a);
    init=insert_front(init,n,a);
    printf("\nAdding %s by %s\n",n,a);
    print_list(first);
    first=ordered_insert(first,n1,a);
    init=insert_front(init,n1,a);
    printf("\nAdding %s by %s\n",n1,a);
    print_list(first);
    first=ordered_insert(first,n2,a3);
    init=insert_front(init,n2,a3);
    printf("\nAdding %s by %s\n",n2,a3);
    print_list(first);
    first=ordered_insert(first,n3,a4);
    init=insert_front(init,n3,a4);
    printf("\nAdding %s by %s\n",n3,a4);
    print_list(first);
    first=ordered_insert(first,n4,a1);
    init=insert_front(init,n4,a1);
    printf("\nAdding %s by %s\n",n4,a1);
    print_list(first);
    first=ordered_insert(first,n5,a2);
    init=insert_front(init,n5,a2);
    printf("\nAdding %s by %s\n",n5,a2);
    print_list(first);
    first=ordered_insert(first,n6,a5);
    init=insert_front(init,n6,a5);
    printf("\nAdding %s by %s\n",n6,a5);
    print_list(first);
    first=ordered_insert(first,n7,a6);
    init=insert_front(init,n7,a6);
    printf("\nAdding %s by %s\n",n7,a6);
    print_list(first);
    first=ordered_insert(first,n8,a4);
    init=insert_front(init,n8,a4);
    printf("\nAdding %s by %s\n",n8,a4);
    print_list(first);
    first=ordered_insert(first,n9,a7);
    init=insert_front(init,n9,a7);
    printf("\nAdding %s by %s\n",n9,a7);
    print_list(first);
    printf("--------------\n\n");
    printf("Search songs in linked list\n\n");
    printf("Search for %s by %s\n",n,a);
    print_list(search_song(first,n,a));
    printf("\nSearch for %s by %s\n",n3,a4);
    print_list(search_song(first,n3,a4));
    printf("\nSearch for %s by %s\n",n5,a2);
    print_list(search_song(first,n5,a2));
    printf("\nSearch for %s by %s\n",n9,a7);
    print_list(search_song(first,n9,a7));
    printf("--------------\n\n");
    printf("Search artist in linked list\n\n");
    printf("Search for songs by %s\n",a);
    print_list(search_artist(first,a));
    printf("\nSearch for songs by %s\n",a4);
    print_list(search_artist(first,a4));
    printf("\nSearch for songs by %s\n",a2);
    print_list(search_artist(first,a2));
    printf("\nSearch for songs by %s\n",a7);
    print_list(search_artist(first,a7));
    printf("--------------\n\n");
    printf("Random song from linked list\n\n");
    print_list(random_song(first));
    printf("--------------\n\n");
    printf("Remove song from linked list\n\n");
    first=remove_song(first,n2,a3);
    printf("\nRemoving %s by %s\n",n2,a3);
    print_list(first);
    first=remove_song(first,n3,a4);
    printf("\nRemoving %s by %s\n",n3,a4);
    print_list(first);
    first=remove_song(first,n4,a1);
    printf("\nRemoving %s by %s\n",n4,a1);
    print_list(first);
    printf("--------------\n\n");
    printf("Adding songs to library\n\n");
    printf("Following list will be added to library: ");
    print_list(init);
    struct song_node *table[27];
    for(int i=0;i<27;i++){
        table[i]=NULL;
    }
    add_node(table,init);
    printf("--------------\n\n");
    printf("Library Tests\n-----------\n");
    printf("List songs in library\n\n");
    print_lib(table);
    printf("--------------\n\n");
    printf("List songs in library by letter\n\n");
    for(int i=0;i<27;i++){  
        if(i==26){
            printf("Songs under other symbols: ");
        }
        else{
            printf("Songs under %c: ",'a'+i);
        }
        print_list(table[i]);
    }
    printf("--------------\n\n");
    printf("List songs in library by artist\n\n");
    printf("Songs by %s\n",a);
    list_artist(table,a);
    printf("Songs by %s\n",a3);
    list_artist(table,a3);
    printf("Songs by %s\n",a5);
    list_artist(table,a5);
    printf("--------------\n\n");
    printf("Search songs in library by a certain artist\n\n");
    printf("Song by %s\n",a);
    print_list(artist_search(table,a));
    printf("Song by %s\n",a3);
    print_list(artist_search(table,a3));
    printf("Song by %s\n",a5);
    print_list(artist_search(table,a5));
    printf("--------------\n\n");
    printf("Search songs library by song\n\n");
    printf("Search for %s by %s\n",n,a);
    print_list(song_search(table,n,a));
    printf("\nSearch for %s by %s\n",n3,a4);
    print_list(song_search(table,n3,a4));
    printf("\nSearch for %s by %s\n",n5,a2);
    print_list(song_search(table,n5,a2));
    printf("\nSearch for %s by %s\n",n9,a7);
    print_list(song_search(table,n9,a7));
    printf("--------------\n\n");
    printf("Remove song from library\n\n");
    delete_song(table,n2,a3);
    printf("\nRemoving %s by %s\n",n2,a3);
    print_lib(table);
    delete_song(table,n3,a4);
    printf("\nRemoving %s by %s\n",n3,a4);
    print_lib(table);
    delete_song(table,n9,a7);
    printf("\nRemoving %s by %s\n",n9,a7);
    print_lib(table);
    printf("--------------\n\n");
    printf("Shuffle\n\n");
    shuffle(table);
    printf("--------------\n\n");
    
    printf("Lists used for previous tests after freed\n\n");
    first=free_list(first);
    init=free_list(init);
    print_list(first);
    print_list(init);
    printf("--------------\n\n");
    printf("Library after freed\n\n");
    clear_lib(table);
    print_lib(table);
    printf("--------------\n\n");
    return 0;
}
