#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

struct waster {
    int gg;
    struct waster *next;
};

void *newnode () {

    struct waster *new = malloc(sizeof(struct waster));
    return new; 
}

int llist (uint64_t count, struct waster *wr1) {
    
    wr1->gg = 0; // Assign 0 to first node
    wr1->next = newnode(); // Create new node and make next point to it
    struct waster *save = wr1->next; // Save that address


    for (uint64_t i = 1 ; i < count ; i++) {

        save->gg = i; // Assing data to next node
        save->next = newnode(); // Make new node and assign address of the new node to the current one
        save = save->next; // Make save point to the next node
        
    }
    save->next = NULL; 

    return 0;
}

void freellist(struct waster *wr1) {

    struct waster *save;

    while (wr1->next != NULL) {
        save = wr1;
        wr1 = wr1->next;
        free(save);
    }
}

int main () {

    struct waster wr1;
    llist(5, &wr1);
    struct waster *p = &wr1;
    for ( ; p->next != NULL ; p = p->next) {
        printf("%d\n", p->gg);
    }

    freellist(&wr1);
    return 0;
}