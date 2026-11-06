#include <stdio.h>
#include "golem.h"

/*  TODO: Return the weight of the last surviving golem, or 0 if none.
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
int lastGolem(MaxHeap *H) {
    //If both golems weigh the same, they both shatters
    //If one golem is heavier than the other, the lighter one gets destroyed
    //The Heavier Golem Wins, BUT it loses weight == to the lighter golems weight
    //Ends when one golem OR none is left.
    //Announce the weight of the champion, if none return 0
    int largest, second, winner;

    // NEVER PLACE RETURN STATEMENT INSIDE LOOP 
    while(size(*H) > 1){
        largest = deleteMax(H);
        second = deleteMax(H);
        
        if(largest != second){
            winner = largest - second;
            insert(H, winner);
        }
    }
    
    return (isEmpty(*H)) ? 0: peekMax(*H);

}

// /*Helper Functions:
// void initHeap(MaxHeap *H);

// int isEmpty(MaxHeap H);

// int size(MaxHeap H);

// void swap(int *a, int *b);

// /* Inserts x and bubbles it up. */
// void insert(MaxHeap *H, int x);

// /* Removes and returns the LARGEST value. Returns -1 if empty. */
// int deleteMax(MaxHeap *H);

// /* Returns the largest value without removing it. Returns -1 if empty. */
// int peekMax(MaxHeap H);*/
