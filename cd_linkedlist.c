#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// circular doubly linked list demo

struct waster {
    int gg;
    struct waster *prev;
    struct waster *next;
};

struct waster *newnode () {

    struct waster *new = malloc(sizeof(struct waster));
    return new; 
}

struct waster *llist (uint64_t count) {
    
    struct waster *wr1 = malloc(sizeof(struct waster));
    struct waster *head = wr1;
    
    wr1->gg = 0; // Data for first node
    wr1->prev = NULL; // There is no previous node *yet*
    wr1->next = newnode(); // Make new node, next points to it
    struct waster *prv = wr1; // Make prv point to current node
    wr1 = wr1->next; // Make wr1 point to next node

    
    for (uint64_t i = 1 ; i < count ; i++) { // Actual loop starts
        
        wr1->gg = i; // Data for 2nd node
	wr1->prev = prv; // make prev point to prv = wr1 = last node
        if (i == count-1) {
	    wr1->next = head;
	    head->prev = wr1;
	} else {
	    wr1->next = newnode(); // Make next node, next points to it
        }
	prv = wr1; // prv points to current node
        wr1 = wr1->next; // Make wr1 point to the next node
        
    }

    
    return head;
}

void freellist(struct waster *wr1) {
    
    struct waster *head = wr1;
    struct waster *save;
    while (wr1->next != head) {
        save = wr1;
        wr1 = wr1->next;
        free(save);
    }
}

int main () {

    struct waster *wr1 = llist(20);
    struct waster *p;
    for (p = wr1 ; p != NULL ; p = p->next) {
        void *prev = (void*)p->prev;
	void *next = (void*)p->next;
	printf("\n------%p----------",(void *)p);
	printf("\ndata: %d\nprev: %p\nnext: %p\n", p->gg, prev, next);
	printf("-----------------------------\n");
    }
    
    freellist(wr1);
    return 0;
}
