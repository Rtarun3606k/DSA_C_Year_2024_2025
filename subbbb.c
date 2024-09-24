#include <stdio.h>

typedef struct Song {
    int duration;
    struct Song* prev;
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* head;
    Song* tail;
} Playlist;

Song* splitPlaylist(Playlist* playlist, int duration) {
    Song* current = playlist->head;
    Song* secondPartHead = NULL;
    Song* secondPartTail = NULL;

    while (current != NULL) {
        Song* next = current->next; // Store the next song before modifying the current song's pointers

        if (current->duration > duration) {
            if (secondPartHead == NULL) {
                secondPartHead = current;
                secondPartTail = current;
            } else {
                secondPartTail->next = current;
                current->prev = secondPartTail;
                secondPartTail = current;
            }

            if (current == playlist->head) {
                playlist->head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current == playlist->tail) {
                playlist->tail = current->prev;
            } else {
                current->next->prev = current->prev;
            }

            current->next = NULL;
            current->prev = NULL;
        }

        current = next; // Move to the next song
    }

    // Append the second part of the playlist to the end of the first part
    if (secondPartHead != NULL) {
        if (playlist->tail == NULL) {
            playlist->head = secondPartHead;
            playlist->tail = secondPartTail;
        } else {
            playlist->tail->next = secondPartHead;
            secondPartHead->prev = playlist->tail;
            playlist->tail = secondPartTail;
        }
    }

    return secondPartHead;
}

int main() {
    // Create a sample playlist
    Playlist playlist;
    Song song1, song2, song3, song4;
    song1.duration = 180;
    song2.duration = 240;
    song3.duration = 300;
    song4.duration = 200;
    song1.prev = NULL;
    song1.next = &song2;
    song2.prev = &song1;
    song2.next = &song3;
    song3.prev = &song2;
    song3.next = &song4;
    song4.prev = &song3;
    song4.next = NULL;
    playlist.head = &song1;
    playlist.tail = &song4;

    // Split the playlist
    int duration = 250;
    Song* secondPartHead = splitPlaylist(&playlist, duration);

    // Print the first part of the playlist
    printf("First part of the playlist:\n");
    Song* current = playlist.head;
    while (current != NULL) {
        printf("Song duration: %d\n", current->duration);
        current = current->next;
    }

    // Print the second part of the playlist
    printf("Second part of the playlist:\n");
    current = secondPartHead;
    while (current != NULL) {
        printf("Song duration: %d\n", current->duration);
        current = current->next;
    }

    return 0;
}
