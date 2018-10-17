#ifndef LIB_H
#define LIB_H
#endif

void add_node(struct song_node * t[27],struct song_node * ll);
struct song_node * song_search(struct song_node * t[27], char n[100], char a[100]);
struct song_node * artist_search(struct song_node * t[27],char a[100]);
struct song_node * list_letter(struct song_node * t[27],char letter);
void print_lib(struct song_node * t[27]);
struct song_node * shuffle(struct song_node * t[27]);
void delete_song(struct song_node * t[27],char n[100],char a[100]);
void clear_lib(struct song_node * t[27]);
