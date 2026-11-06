# [Heap] - Mana Crystal Harvest

**Author:** Gran Sabandal
**Topic:** Max Heap
**Task:** Write one function: `int harvestMana(MaxHeap *H, int k)`

---

## Story Version

You are a wizard in the Crystal Caves. Each crystal stores some mana. You have exactly `k` turns before the cave collapses.

On each turn you pick one crystal, absorb all of its mana, and the crystal slowly regrows to half its previous mana (rounded down).

A greedy wizard always picks the richest crystal on every turn. Return the total mana absorbed after `k` turns.

## Direct Version

Given a max heap of `N` non-negative integers and an integer `k`, repeat `k` times:

1. Remove the largest value `m`.
2. Add `m` to a running total.
3. Insert `m / 2` (integer division).

Return the total. If the heap is empty, stop early.

---

## Function to Implement

```c
int harvestMana(MaxHeap *H, int k);
```

| Parameter | Description |
|-----------|-------------|
| `H` | Pointer to a max heap holding the crystal mana values |
| `k` | Number of turns available |

**Returns:** the total mana absorbed after `k` turns (or fewer, if the heap runs empty).

---

## Example Walkthrough

Crystals: `10 4 7`, `k = 4`

| Turn | Pick | Total | Insert | Heap after |
|------|------|-------|--------|------------|
| 1 | 10 | 10 | 5 | 7 5 4 |
| 2 | 7 | 17 | 3 | 5 4 3 |
| 3 | 5 | 22 | 2 | 4 3 2 |
| 4 | 4 | 26 | 2 | 3 2 2 |

Total mana harvested: `26`.

---

## Sample Output

**Sample 1**

```
Number of crystals and number of turns: 1 5
N crystal mana values: 100
Total mana harvested: 193
```

(100 + 50 + 25 + 12 + 6 = 193)

**Sample 2**

```
Number of crystals and number of turns: 3 4
N crystal mana values: 0 0 0
Total mana harvested: 0
```

**Sample 3**

```
Number of crystals and number of turns: 4 6
N crystal mana values: 1 1 1 1
Total mana harvested: 4
```

(Each `1` is absorbed once and regrows to `0`, so the last two turns add nothing.)

---

## Complexity

Each turn performs one deletion and one insertion, each `O(log N)`.

- **Time:** `O(k log N)`
- **Space:** `O(1)` extra (the heap is modified in place)
