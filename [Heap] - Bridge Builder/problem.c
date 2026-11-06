#include <stdio.h>
#include "bridge.h"

/*  TODO: Return the minimum total gold needed to join all planks into one.
    Joining planks of length a and b costs a + b gold and makes one plank of length a + b.
    Available: size(*H), isEmpty(*H), deleteMin(H), insert(H, x), peekMin(*H) */
int minBridgeCost(MinHeap *H) {
    int total = 0, sum = 0;
    
    if (isEmpty(*H)) return 0;
    
    while(size(*H) >= 2){
        int smallest = deleteMin(H);
        int smaller = deleteMin(H);
        
        sum = smallest + smaller;//to avoid overwritting the value of total
        total += sum;
        insert(H, sum);
    }


    return total;
}

// #define MAX 100

// typedef struct {
//     int Elem[MAX];
//     int lastNdx;            /* index of last element, -1 if empty */
// } MinHeap;

// void initHeap(MinHeap *H);

// int isEmpty(MinHeap H);

// int size(MinHeap H);

// void swap(int *a, int *b);

// /* Inserts x and bubbles it up. */
// void insert(MinHeap *H, int x);

// /* Removes and returns the SMALLEST value. Returns -1 if empty. */
// int deleteMin(MinHeap *H);

// /* Returns the smallest value without removing it. Returns -1 if empty. */
// int peekMin(MinHeap H);

// /* ---------- FUNCTION YOU WILL WRITE ---------- */
// int minBridgeCost(MinHeap *H);
