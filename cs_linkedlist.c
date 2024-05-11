#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// circular singly linked list demo

struct waster {
    int gg;
    struct waster *next;
};

struct waster *newnode (void) {

    struct waster *new = malloc(sizeof(struct waster));
    return new; 
}

struct waster *llist (uint64_t count) {
    
    struct waster *wr1 = malloc(sizeof(struct waster));
    struct waster *head = wr1;
    for (uint64_t i = 0 ; i < count ; i++) {

        wr1->gg = i; 
        if (i == count-1) {
	    wr1->next = head;
	} else {
	    wr1->next = newnode(); // Make new node and assign address of the new node to the current one
        }
	wr1 = wr1->next; // Make save point to the next node
        
    }


    return head;
}

void freellist(struct waster *wr1) {
    //printf("freelist \n");
    struct waster *head = wr1;
    struct waster *save;
    while (wr1->next != head) {
        save = wr1;
        wr1 = wr1->next;
        free(save);
    }
}

int main (void) {
    
    uint64_t passes = 4; // 1 pass = the whole linked list. So 4 passes would be to print the linked list 4 times.
    uint64_t passstep = 1; // counter to compare to passes
    uint64_t steps = 20; // amount of nodes to create
    struct waster *wr1 = llist(steps); // Create the nodes
    
    while(passstep < passes+1) {
        
	
	uint64_t steps_count = 0;  
	struct waster *p;
	for (p = wr1 ; steps_count < steps ; p = p->next, steps_count++) {
            printf("\n------%p----------", (void*)p);
	    printf("\ndata: %d\nnext: %p\n", p->gg, (void*)p->next);
	    printf("-----------------------------\n");
        }
	printf("\npass %lld done\n", passstep);
        passstep = passstep+1;
    }
    printf("\nHEAD: %p\n", (void*)wr1);
    freellist(wr1);
    return 0;
}
