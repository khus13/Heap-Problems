#include <stdio.h>
#include "mana.h"

/*  TODO: Return the total mana harvested after k turns.
    Each turn: take the richest crystal, add its mana, put back half (integer division).
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
int harvestMana(MaxHeap *H, int k) {
    int total = 0;
    int max, division;
    
    if(isEmpty(*H)) return 0;
    
    for(int i = 0; i < k; ++i){
        max = deleteMax(H);
        total += max;
        division = max / 2;
        
        insert(H, division);
    }

    return total;
}

// /*
// typedef struct {
//     int Elem[MAX];
//     int lastNdx;            /* index of last element, -1 if empty */
// } MaxHeap;

// void initHeap(MaxHeap *H);

// int isEmpty(MaxHeap H);

// int size(MaxHeap H);

// void swap(int *a, int *b);

// /* Inserts x and bubbles it up. */
// void insert(MaxHeap *H, int x);

// /* Removes and returns the LARGEST value. Returns -1 if empty. */
// int deleteMax(MaxHeap *H);

// /* Returns the largest value without removing it. Returns -1 if empty. */
// int peekMax(MaxHeap H);

// /* ---------- FUNCTION YOU WILL WRITE ---------- */
// int harvestMana(MaxHeap *H, int k);
// */
