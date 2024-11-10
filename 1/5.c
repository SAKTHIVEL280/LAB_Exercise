#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Song {
    char title[100];
    struct Song *next;
} Song;
typedef struct {
    Song *head;
} Playlist;
void addSong(Playlist *list, char *title) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    newSong->next = NULL;
    if (list->head == NULL) {
        list->head = newSong;
    } else {
        Song *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
    }
}
void removeSong(Playlist *list, char *title) {
    Song *current = list->head;
    Song *previous = NULL;
    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous != NULL) {
            previous->next = current->next;
        } else {
            list->head = current->next;
        }
        free(current);
    } else {
        printf("Song not found.\n");
    }
}
void displayPlaylist(Playlist *list) {
    Song *current = list->head;
    while (current != NULL) {
        printf("Song: %s\n", current->title);
        current = current->next;
    }
}
int main() {
    Playlist myPlaylist;
    myPlaylist.head = NULL;
    addSong(&myPlaylist, "Song 1");
    addSong(&myPlaylist, "Song 2");
    printf("Playlist:\n");
    displayPlaylist(&myPlaylist);
    removeSong(&myPlaylist, "Song 1");
    printf("Playlist after removal:\n");
    displayPlaylist(&myPlaylist);
    return 0;
}
