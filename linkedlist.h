#ifndef LINK_LIST_H
#define LINK_LIST_H
#endif

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};
void print_list(struct song_node * ll);
int sngcmp(struct song_node * n1,struct song_node *n2);
struct song_node * insert_front(struct song_node * front, char n[100], char a[100]);
struct song_node * ordered_insert(struct song_node * front, char n[100], char a[100]);
struct song_node * search_song(struct song_node * front, char n[100], char a[100]);
struct song_node * search_artist(struct song_node * front, char a[100]);
struct song_node * random_song(struct song_node * front);
struct song_node *  remove_song(struct song_node * front, char n[100], char a[100]);
int list_len(struct song_node * front);
struct song_node * free_list(struct song_node * ll);