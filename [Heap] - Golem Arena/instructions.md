# [Heap] - Golem Arena

**Author:** Gran Sabandal
**Topic:** Max Heap
**Task:** Write one function: `int lastGolem(MaxHeap *H)`

---

## Story Version

Welcome to the Golem Arena! The crowd only wants to see the two heaviest golems fight.

Every round, the two heaviest golems step into the ring and smash into each other:

- If they weigh the same, both shatter into dust.
- If one is heavier, the lighter golem is destroyed. The heavier golem survives but loses weight equal to the lighter golem's weight, and it limps back into the waiting line.

The tournament ends when one golem or none is left. As the Arena Master, you must announce the weight of the champion. If no golem survives, return `0`.

## Direct Version

Given a max heap of `N` positive integers, repeat until at most one value remains:

1. Remove the largest value `a` and the second largest value `b`.
2. If `a != b`, insert `a - b`.

Return the last remaining value, or `0` if the heap is empty.

---

## Function to Implement

```c
int lastGolem(MaxHeap *H);
```

| Parameter | Description |
|-----------|-------------|
| `H` | Pointer to a max heap holding the golem weights |

**Returns:** the weight of the last remaining golem, or `0` if none survives.

---

## Example Walkthrough

Weights: `2 7 4 1 8 1`

| Round | Fight (a, b) | Result | Heap after |
|-------|--------------|--------|------------|
| 1 | 8 vs 7 | insert 1 | 4 2 1 1 1 |
| 2 | 4 vs 2 | insert 2 | 2 1 1 1 |
| 3 | 2 vs 1 | insert 1 | 1 1 1 |
| 4 | 1 vs 1 | both destroyed | 1 |

Only one golem remains, so the champion weighs `1`.

---

## Sample Output

**Sample 1**

```
N (number of golems): 0
N golem weights:
Arena is empty. No golem survives!
```

**Sample 2**

```
N (number of golems): 1
N golem weights: 9

Champion golem weight: 9
```

**Sample 3**

```
N (number of golems): 2
N golem weights: 5 5

Arena is empty. No golem survives!
```

---

## Complexity

Each round performs up to two deletions and one insertion, each `O(log N)`. The number of golems drops by at least one per round, so there are at most `N - 1` rounds.

- **Time:** `O(N log N)`
- **Space:** `O(1)` extra (the heap is modified in place)
