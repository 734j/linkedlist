#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

struct waster {
    int gg;
    struct waster *next;
};

void *newnode () {

    struct waster *new = malloc(sizeof(struct waster));
    return new; 
}

struct waster *llist (uint64_t count) {
    
    struct waster *wr1 = malloc(sizeof(struct waster));
    struct waster *head = wr1;
    for (uint64_t i = 0 ; i < count ; i++) {

        wr1->gg = i; 
        wr1->next = newnode(); // Make new node and assign address of the new node to the current one
        wr1 = wr1->next; // Make save point to the next node
        
    }

    wr1->next = NULL;
    return head;
}

void freellist(struct waster *wr1) {
    //printf("freelist \n");
    struct waster *save;
    while (wr1 != NULL) {
        save = wr1;
        wr1 = wr1->next;
        free(save);
    }
}

int main () {

    struct waster *wr1 = llist(10);
    struct waster *p;
    for (p = wr1 ; p->next != NULL ; p = p->next) {
        printf("%d\n", p->gg);
    }

    freellist(wr1);
    return 0;
}