# [Heap] - Bridge Builder

**Author:** Gran Sabandal
**Topic:** Min Heap
**Task:** Write one function: `int minBridgeCost(MinHeap *H)`

---

## Story Version

A river splits the kingdom, and the villagers have collected `N` wooden planks of different lengths. To cross, all of the planks must be joined into one long bridge.

The village carpenter can join two planks at a time. Joining planks of length `a` and `b` costs `a + b` gold and produces one plank of length `a + b`.

The village treasury is small. Find the minimum total gold needed to join all of the planks into one.

## Direct Version

Given a min heap of `N` positive integers, repeat while there are at least two values:

1. Remove the two smallest values `a` and `b`.
2. Add `a + b` to the total cost.
3. Insert `a + b`.

Return the total cost. If `N` is 0 or 1, the cost is 0.

---

## Function to Implement

```c
int minBridgeCost(MinHeap *H);
```

| Parameter | Description |
|-----------|-------------|
| `H` | Pointer to a min heap holding the plank lengths |

**Returns:** the minimum total gold needed to join all planks into one (`0` if there are fewer than two planks).

---

## Example Walkthrough

Planks: `1 2 3 4 5`

| Step | Join (a, b) | Cost | Total | Heap after |
|------|-------------|------|-------|------------|
| 1 | 1 + 2 | 3 | 3 | 3 3 4 5 |
| 2 | 3 + 3 | 6 | 9 | 4 5 6 |
| 3 | 4 + 5 | 9 | 18 | 6 9 |
| 4 | 6 + 9 | 15 | 33 | 15 |

Minimum gold spent: `33`.

---

## Sample Output

**Sample 1**

```
N (number of planks): 4
N plank lengths: 4 3 2 6

Minimum gold spent: 29
```

(2 + 3 = 5, then 4 + 5 = 9, then 6 + 9 = 15; total 5 + 9 + 15 = 29)

**Sample 2**

```
N (number of planks): 0
N plank lengths:
Minimum gold spent: 0
```

**Sample 3**

```
N (number of planks): 1
N plank lengths: 15

Minimum gold spent: 0
```

---

## Complexity

Each join performs two deletions and one insertion, each `O(log N)`. Every join reduces the plank count by one, so there are `N - 1` joins.

- **Time:** `O(N log N)`
- **Space:** `O(1)` extra (the heap is modified in place)
