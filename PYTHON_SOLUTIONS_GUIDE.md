# 🐍 Ultimate Python Arrays Mastery & C++ to Python Translation Guide

[![Language](https://img.shields.io/badge/Language-Python%203.10%2B%20%2F%203.13-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![Topic](https://img.shields.io/badge/Data%20Structures-Arrays%20%26%20Matrices-orange?style=for-the-badge)](https://leetcode.com/)
[![Problems](https://img.shields.io/badge/Total%20Problems-42%20Core%20DSA-success?style=for-the-badge)](https://github.com/Kushagra901/dsa-arrays-cpp)
[![Codebase](https://img.shields.io/badge/C%2B%2B%20Originals-Untouched-blue?style=for-the-badge&logo=c%2B%2B)](README.md)

This comprehensive technical guide documents the complete Python implementation of the **42 Core Fundamental DSA Array Problems** residing in this repository. All original C++ source files (`prob1.cpp` to `prob42.cpp`) remain 100% untouched, while matching, production-grade Python counterparts (`prob1.py` to `prob42.py`) have been created side-by-side with full type annotations, algorithmic fidelity, and verified unit executions.

---

## 📑 Table of Contents

1. [Architectural Differences: C++ vs. Python in DSA](#-architectural-differences-c-vs-python-in-dsa)
2. [Master Problem Comparison Index (prob1 to prob42)](#-master-problem-comparison-index-prob1-to-prob42)
3. [Deep-Dive Problem-by-Problem Changes](#-deep-dive-problem-by-problem-changes)
4. [Execution and Testing Guide](#-execution-and-testing-guide)

---

## 🏛️ Architectural Differences: C++ vs. Python in DSA

When porting high-performance competitive programming and DSA solutions from C++ (C++17/C++20) to Python (Python 3.10+), several fundamental language paradigms must be handled deliberately:

### 1. Memory Model & Pass-by-Reference
- **C++**: Uses explicit reference parameters (`vector<int> &arr`, `long long arr1[]`) to achieve in-place modifications without memory allocation.
- **Python**: Variables are references to objects. Mutable objects (`list`) passed into functions can be modified in-place using index assignments (`arr[i] = val`), tuple swaps (`arr[i], arr[j] = arr[j], arr[i]`), or full slice reassignments (`arr[:] = ...`). For algorithms returning a copy, list comprehension or `.copy()` / `arr[:]` is used.

### 2. Numerical Precision & Integer Overflow
- **C++**: Fixed-width integers (`int` is 32-bit: $[-2^{31}, 2^{31}-1]$, `long long` is 64-bit). Mathematical sum formulas (e.g., $N(N+1)/2$ in `prob13`, $N(N+1)(2N+1)/6$ in `prob41`, or 4-sum products in `prob36`) can trigger silent arithmetic overflow in 32-bit types.
- **Python**: Integers have **arbitrary precision** (unbounded). Calculations like $S_{2N} = N(N+1)(2N+1)//6$ never overflow memory, simplifying mathematical proofs and edge-case handling.

### 3. Division Semantics
- **C++**: `/` between two integer types performs truncated integer division (floor towards zero for positives).
- **Python**: `/` always performs true floating-point division; `//` must be explicitly used for integer floor division (e.g., `mid = (low + high) // 2` or `nCr` updates).

### 4. Standard Library & Container Equivalences

| Concept / Data Structure | C++ Standard Template Library (STL) | Python 3 Equivalent | Python Complexity Notes |
|:---|:---|:---|:---|
| Dynamic Array | `std::vector<int>` | `list[int]` | Amortized $O(1)$ append / pop |
| Hash Map | `std::unordered_map<K, V>` | `dict[K, V]` | Average $O(1)$ lookup, worst-case $O(N)$ |
| Ordered Map / Tree | `std::map<K, V>` (Red-Black Tree) | `collections.OrderedDict` / sorted iteration | $O(N \log N)$ when sorting keys |
| Hash Set | `std::unordered_set<K>` | `set[K]` | Average $O(1)$ membership test |
| Ordered Set | `std::set<K>` | `set[K]` + `sorted()` | Used for deduplicating tuples |
| Sorting Algorithm | `std::sort()` (Introsort: Quick + Heap + Insertion) | `list.sort()` / `sorted()` (Timsort: Merge + Insertion) | Both $O(N \log N)$; Timsort is stable |
| Swapping Elements | `std::swap(arr[i], arr[j]);` | `arr[i], arr[j] = arr[j], arr[i]` | Bytecode `ROT_TWO` / tuple unpacking |
| Subarray Reversal | `std::reverse(arr.begin() + l, arr.begin() + r);` | Two-pointer while loop or slice assignment | In-place two-pointer prevents extra allocation |
| Infinity Representation | `INT_MAX`, `INT_MIN`, `LLONG_MAX` | `float('inf')`, `-float('-inf')` | Type-cast back to `int` when required |

---

## 📑 Master Problem Comparison Index (prob1 to prob42)

| # | Problem Name | C++ Source | Python Source | Primary Algorithm | Time | Space | Key Python Transformations |
|:---:|:---|:---:|:---:|:---|:---:|:---:|:---|
| **01** | Largest & Smallest Element | [`prob1.cpp`](prob1.cpp) | [`prob1.py`](prob1.py) | Single-pass linear scan | $O(N)$ | $O(1)$ | Initialized with `arr[0]`; handles empty list via `ValueError`. |
| **02** | Second Largest & Second Smallest | [`prob2.cpp`](prob2.cpp) | [`prob2.py`](prob2.py) | Single-pass tracking | $O(N)$ | $O(1)$ | Used `float('inf')` / `-float('inf')` instead of `INT_MAX`/`INT_MIN`. |
| **03** | Check Array Sorted & Rotated | [`prob3.cpp`](prob3.cpp) | [`prob3.py`](prob3.py) | Adjacent comparison & modulo count | $O(N)$ | $O(1)$ | Circular adjacent drop counter with `(i + 1) % n`. |
| **04** | Remove Duplicates from Sorted Array | [`prob4.cpp`](prob4.cpp) | [`prob4.py`](prob4.py) | Slow & Fast Two Pointers | $O(N)$ | $O(1)$ | Mutates list in-place via pointer `i`; returns `k` unique count. |
| **05** | Left Rotate Array by 1 Place | [`prob5.cpp`](prob5.cpp) | [`prob5.py`](prob5.py) | In-place element shift | $O(N)$ | $O(1)$ | Cached `arr[0]` in temp; shifted elements via linear loop. |
| **06** | Rotate Array by K Places | [`prob6.cpp`](prob6.cpp) | [`prob6.py`](prob6.py) | Auxiliary buffer & 3-step reversal | $O(N)$ | $O(1)$ / $O(K)$ | Normalized `k %= n`; in-place two-pointer reversal helper. |
| **07** | Rotate Array by K Places (Optimal) | [`prob7.cpp`](prob7.cpp) | [`prob7.py`](prob7.py) | In-place 3-step reversal | $O(N)$ | $O(1)$ | Left rotate: `reverse(0, d-1)`, `reverse(d, n-1)`, `reverse(0, n-1)`. |
| **08** | Move Zeroes to End | [`prob8.cpp`](prob8.cpp) | [`prob8.py`](prob8.py) | Two Pointers (Slow `j` & Fast `i`) | $O(N)$ | $O(1)$ | Scans to first zero, then performs tuple swaps on non-zeroes. |
| **09** | Move All Zeroes to End | [`prob9.cpp`](prob9.cpp) | [`prob9.py`](prob9.py) | Two Pointers in-place | $O(N)$ | $O(1)$ | Idiomatic in-place swap using Python tuple unpacking. |
| **10** | Linear Search | [`prob10.cpp`](prob10.cpp) | [`prob10.py`](prob10.py) | Linear traversal scan | $O(N)$ | $O(1)$ | Standard iteration returning index on match, `-1` on completion. |
| **11** | Union of Two Sorted Arrays | [`prob11.cpp`](prob11.cpp) | [`prob11.py`](prob11.py) | Two Pointers Merge | $O(N + M)$ | $O(N + M)$ | Compares `arr1[i]` and `arr2[j]`; deduplicates with `res[-1] != val`. |
| **12** | Intersection of Two Sorted Arrays | [`prob12.cpp`](prob12.cpp) | [`prob12.py`](prob12.py) | Two Pointers Scan | $O(N + M)$ | $O(1)$ aux | Advances smaller pointer; appends equal values without extra space. |
| **13** | Find Missing Number | [`prob13.cpp`](prob13.cpp) | [`prob13.py`](prob13.py) | Bitwise XOR & Gauss Formula | $O(N)$ | $O(1)$ | Eliminates integer overflow in sum; XOR uses standard `^` operator. |
| **14** | Maximum Consecutive Ones | [`prob14.cpp`](prob14.cpp) | [`prob14.py`](prob14.py) | Running Streak Counter | $O(N)$ | $O(1)$ | Resets `cnt = 0` on 0; tracks `maxi = max(maxi, cnt)`. |
| **15** | Single Number | [`prob15.cpp`](prob15.cpp) | [`prob15.py`](prob15.py) | Bitwise XOR Cancellation | $O(N)$ | $O(1)$ | XORs all elements; pairs cancel (`a ^ a = 0`), leaving unique element. |
| **16** | Longest Subarray with Sum K | [`prob16.cpp`](prob16.cpp) | [`prob16.py`](prob16.py) | Prefix Sum + Hash Map | $O(N)$ | $O(N)$ | Stores first occurrence of prefix sums in dictionary. |
| **17** | Two Sum (Check Pair Sum) | [`prob17.cpp`](prob17.cpp) | [`prob17.py`](prob17.py) | Two Pointers (YES/NO) & Hash Map | $O(N \log N)$ / $O(N)$ | $O(1)$ / $O(N)$ | Implemented `read` (2 pointers on sorted copy) & `two_sum_indices`. |
| **18** | Sort Array of 0s, 1s, and 2s | [`prob18.cpp`](prob18.cpp) | [`prob18.py`](prob18.py) | Dutch National Flag (3-way partition) | $O(N)$ | $O(1)$ | Pointers `low`, `mid`, `high` with tuple swapping in-place. |
| **19** | Majority Element (> N/2 Times) | [`prob19.cpp`](prob19.cpp) | [`prob19.py`](prob19.py) | Boyer-Moore Voting Algorithm | $O(N)$ | $O(1)$ | Candidate cancellation with running counter; second verification pass. |
| **20** | Maximum Subarray Sum | [`prob20.cpp`](prob20.cpp) | [`prob20.py`](prob20.py) | Kadane's Algorithm | $O(N)$ | $O(1)$ | Resets running sum to 0 if negative; tracks start and end indices. |
| **21** | Best Time to Buy and Sell Stock | [`prob21.cpp`](prob21.cpp) | [`prob21.py`](prob21.py) | Greedy Running Minimum | $O(N)$ | $O(1)$ | Tracks `mini` price and updates `max_profit = max(max_profit, p - mini)`. |
| **22** | Rearrange Array Elements by Sign | [`prob22.cpp`](prob22.cpp) | [`prob22.py`](prob22.py) | Two Pointers Placement | $O(N)$ | $O(N)$ | Separate routines for equal counts (pointers 0 & 1) and unequal counts. |
| **23** | Next Permutation | [`prob23.cpp`](prob23.cpp) | [`prob23.py`](prob23.py) | 3-Step Lexicographical Scan | $O(N)$ | $O(1)$ | Breakpoint search, successor swap, and suffix two-pointer reversal. |
| **24** | Leaders in an Array | [`prob24.cpp`](prob24.cpp) | [`prob24.py`](prob24.py) | Right-to-Left Running Maximum | $O(N)$ | $O(1)$ aux | Right-to-left scan; includes LeetCode 1299 `replace_elements`. |
| **25** | Longest Consecutive Sequence | [`prob25.cpp`](prob25.cpp) | [`prob25.py`](prob25.py) | Hash Set Streak Counting | $O(N)$ | $O(N)$ | Converts list to `set`; triggers streak check only when `x - 1 not in set`. |
| **26** | Set Matrix Zeroes | [`prob26.cpp`](prob26.cpp) | [`prob26.py`](prob26.py) | In-place Row/Col Markers | $O(N \times M)$ | $O(1)$ | Uses matrix row 0 and col 0 as markers with dedicated `col0` flag. |
| **27** | Rotate Matrix by 90° Clockwise | [`prob27.cpp`](prob27.cpp) | [`prob27.py`](prob27.py) | Transpose + Row Reversal | $O(N^2)$ | $O(1)$ | In-place diagonal swap followed by `row.reverse()` for each row. |
| **28** | Spiral Matrix Traversal | [`prob28.cpp`](prob28.cpp) | [`prob28.py`](prob28.py) | 4 Boundary Pointers | $O(N \times M)$ | $O(1)$ aux | Pointers `top, bottom, left, right` with boundary safety guards. |
| **29** | Count Subarrays with Sum K | [`prob29.cpp`](prob29.cpp) | [`prob29.py`](prob29.py) | Prefix Sum Frequency Hash Map | $O(N)$ | $O(N)$ | Initialized `mpp = {0: 1}`; accumulates counts of `pre_sum - k`. |
| **30** | Pascal's Triangle (3 Variations) | [`prob30.cpp`](prob30.cpp) | [`prob30.py`](prob30.py) | Combinatorics & Direct Row Building | $O(N^2)$ | $O(N^2)$ | `nCr` via iterative multiplication and floor division `//`. |
| **31** | Majority Element II (> N/3 Times) | [`prob31.cpp`](prob31.cpp) | [`prob31.py`](prob31.py) | Extended Boyer-Moore (2 Candidates) | $O(N)$ | $O(1)$ aux | Tracks 2 candidate elements and counters with verification pass. |
| **32** | Maximum Product Subarray | [`prob32.cpp`](prob32.cpp) | [`prob32.py`](prob32.py) | Prefix & Suffix Product Scan | $O(N)$ | $O(1)$ | Computes forward `pre` and backward `suff` products, resetting on 0. |
| **33** | Count Inversions in Array | [`prob33.cpp`](prob33.cpp) | [`prob33.py`](prob33.py) | Modified Merge Sort | $O(N \log N)$ | $O(N)$ | Accumulates cross-inversions `cnt += (mid - left + 1)` during merge. |
| **34** | Reverse Pairs (`arr[i] > 2*arr[j]`) | [`prob34.cpp`](prob34.cpp) | [`prob34.py`](prob34.py) | Merge Sort with 2-Pointer Scan | $O(N \log N)$ | $O(N)$ | Separate `count_pairs` two-pointer scan before standard merge step. |
| **35** | 3Sum (Zero Sum Triplets) | [`prob35.cpp`](prob35.cpp) | [`prob35.py`](prob35.py) | Sorting + Two Pointers | $O(N^2)$ | $O(1)$ aux | Skips duplicate values of fixed index `i` and two pointers `j`, `k`. |
| **36** | 4Sum (Target Quadruplets) | [`prob36.cpp`](prob36.cpp) | [`prob36.py`](prob36.py) | Sorting + 2 Outer Loops + 2 Pointers | $O(N^3)$ | $O(1)$ aux | Python arbitrary precision prevents integer overflow; skips duplicates. |
| **37** | Merge Overlapping Subintervals | [`prob37.cpp`](prob37.cpp) | [`prob37.py`](prob37.py) | Sort by Start Time + Greedy Merge | $O(N \log N)$ | $O(N)$ | `intervals.sort(key=lambda x: x[0])`; compares `start` with `ans[-1][1]`. |
| **38** | Largest Subarray with 0 Sum | [`prob38.cpp`](prob38.cpp) | [`prob38.py`](prob38.py) | Prefix Sum First Occurrence Map | $O(N)$ | $O(N)$ | Records earliest index for each prefix sum; handles `sum == 0` base case. |
| **39** | Merge Sorted Arrays in O(1) Space | [`prob39.cpp`](prob39.cpp) | [`prob39.py`](prob39.py) | Gap Method (Shell Sort Traversal) | $O((N+M) \log(N+M))$ | $O(1)$ | Virtual index mapping across `arr1` and `arr2` with pointer swaps. |
| **40** | Count Subarrays with Given XOR K | [`prob40.cpp`](prob40.cpp) | [`prob40.py`](prob40.py) | Prefix XOR Frequency Hash Map | $O(N)$ | $O(N)$ | Uses property `x = xr ^ k`; updates running prefix XOR map `mpp[xr]`. |
| **41** | Repeating and Missing Number | [`prob41.cpp`](prob41.cpp) | [`prob41.py`](prob41.py) | Mathematical Equations ($S, S^2$) & XOR | $O(N)$ | $O(1)$ | Eliminates integer overflow risk using Python unbounded integers. |
| **42** | Count Subarrays with Given XOR K | [`prob42.cpp`](prob42.cpp) | [`prob42.py`](prob42.py) | Multi-Approach Deep Dive | $O(N)$ | $O(N)$ | Implements Brute $O(N^3)$, Better $O(N^2)$, and Optimal $O(N)$ solutions. |

---

## 🔍 Deep-Dive Problem-by-Problem Changes

### Problems 01 – 10: Array Basics & In-Place Manipulations
- **`prob1.py` & `prob2.py`**: In C++, `INT_MIN` and `INT_MAX` from `<climits>` are standard initializers. In Python, `-float('inf')` and `float('inf')` are used to ensure proper handling of all negative values without domain limitations. C++ `largestElemnt` and `smallestElement` function name aliases are preserved.
- **`prob3.py`**: The circular check for LeetCode 1752 uses Python's modulo operator `(i + 1) % n` to cleanly compare the last element with the first element in $O(1)$ space.
- **`prob4.py`**: In-place deduplication directly mutates the list object passed by reference, using slow pointer `i` and fast pointer `j`.
- **`prob5.py`, `prob6.py`, `prob7.py`**: Left and right array rotations. Instead of relying on C++ STL `std::reverse(begin, end)`, an explicit `reverse_subarray(arr, start, end)` two-pointer helper was written to avoid Python slice allocations (`arr[l:r] = reversed(...)`), guaranteeing strict $O(1)$ auxiliary space.
- **`prob8.py` & `prob9.py`**: Moving zeroes to the end uses fast tuple unpacking `nums[i], nums[j] = nums[j], nums[i]` which executes via optimized Python bytecode instructions without auxiliary storage.
- **`prob10.py`**: Linear search implemented with clean Pythonic iteration.

### Problems 11 – 20: Two Pointers, Hashing & Classic Algorithms
- **`prob11.py` & `prob12.py`**: Union and intersection of sorted arrays. In Python, checking `if not union_arr or union_arr[-1] != val` cleanly prevents duplicates during the two-pointer merge.
- **`prob13.py` & `prob15.py`**: Missing number and single number. Bitwise XOR cancellation is implemented using Python's native `^` operator.
- **`prob16.py`**: Longest subarray with sum $K$. A Python dictionary `pre_sum_map = {}` acts as `std::unordered_map`. Importantly, `pre_sum_map` only records the *first* occurrence of any prefix sum to ensure that the resulting subarray length is maximized.
- **`prob17.py`**: Two sum provides both the $O(N \log N)$ two-pointer check on a sorted copy and the $O(N)$ single-pass index retrieval via a hash map.
- **`prob18.py`**: Dutch National Flag (Sort 0s, 1s, and 2s). The 3-way partition using `low`, `mid`, and `high` pointers executes in a single pass with in-place swaps.
- **`prob19.py` & `prob20.py`**: Boyer-Moore majority element voting and Kadane's maximum subarray sum algorithm. `prob20.py` also tracks and records the exact start and end indices of the maximum contiguous subarray.

### Problems 21 – 30: Permutations, 2D Matrices & Hash Set Counting
- **`prob21.py`**: Best time to buy and sell stock with single transaction greedy minimum tracking.
- **`prob22.py`**: Rearranging by sign provides Variety 1 (equal counts, single pass using even/odd pointers) and Variety 2 (unequal counts, list segregation and suffix concatenation).
- **`prob23.py`**: Next permutation implements the exact 3-step lexicographical algorithm: finding the pivot breakpoint from the right, finding the smallest successor greater than the pivot, swapping, and reversing the remaining suffix in-place.
- **`prob24.py`**: Leaders in an array uses a right-to-left scan maintaining a running maximum, plus LeetCode 1299 `replace_elements`.
- **`prob25.py`**: Longest consecutive sequence converts the input list to a Python `set`. A sequence check is only initiated if `x - 1 not in set`, guaranteeing that each number is visited at most twice for a strict $O(N)$ linear time bound.
- **`prob26.py`**: Set matrix zeroes uses Row 0 and Column 0 of the 2D list as marker buffers with an independent `col0` flag, maintaining $O(1)$ auxiliary space.
- **`prob27.py`**: In-place 90° clockwise matrix rotation via transposition (`mat[i][j], mat[j][i] = mat[j][i], mat[i][j]`) followed by `row.reverse()` for each row.
- **`prob28.py`**: Spiral matrix traversal with 4 boundary pointers (`top`, `bottom`, `left`, `right`) and inner boundary guards.
- **`prob29.py`**: Subarray sum equals $K$ uses running prefix sum frequency mapping with base case `mpp = {0: 1}`.
- **`prob30.py`**: Pascal's Triangle implements all 3 interview variations using iterative combination math with floor division (`//`).

### Problems 31 – 42: Advanced Sorting, Divide & Conquer & Subarrays
- **`prob31.py`**: Extended Boyer-Moore algorithm for elements appearing $> \lfloor N/3 \rfloor$ times. Uses 2 candidate variables and 2 counters, followed by a mandatory verification pass.
- **`prob32.py`**: Maximum product subarray tracks forward prefix and backward suffix running products, resetting products to 1 whenever a 0 is encountered.
- **`prob33.py`**: Inversion count via modified Merge Sort. During the merge step, when `arr[left] > arr[right]`, all remaining elements in the left half form inversions, adding `mid - left + 1` to the count.
- **`prob34.py`**: Reverse pairs ($arr[i] > 2 \times arr[j]$). Implements a distinct two-pointer counting pass before the merge step to preserve sorted invariants without violating complexity bounds.
- **`prob35.py` & `prob36.py`**: 3Sum and 4Sum. Implemented using sorting and two pointers. Duplicate elements are skipped at every pointer level (`i`, `j`, `k`, `l`), completely eliminating the overhead of auxiliary hash sets.
- **`prob37.py`**: Merge overlapping subintervals sorts intervals by start time using `lambda x: x[0]` and merges into `ans` greedily in a single pass.
- **`prob38.py`**: Largest subarray with 0 sum using prefix sum first-occurrence indexing. Also includes a power-of-three verification helper.
- **`prob39.py`**: Merging two sorted arrays without extra space via the Gap Method (Shell Sort intuition). Uses virtual index translation between `arr1` and `arr2` with in-place swaps.
- **`prob40.py` & `prob42.py`**: Count subarrays with bitwise XOR equal to $K$. Uses prefix XOR frequency mapping (`mpp[0] = 1`), with `prob42.py` implementing all three tiers (Brute $O(N^3)$, Better $O(N^2)$, Optimal $O(N)$).
- **`prob41.py`**: Missing and repeating numbers. In C++, computing sum of squares $S_{2N}$ often triggers integer overflow for large $N$. Python's native arbitrary precision handles large numbers effortlessly.

---

## 🚀 Execution and Testing Guide

Every single Python file (`prob1.py` to `prob42.py`) is fully self-contained with its own driver execution block:

```bash
# Run any individual problem
python prob1.py
python prob20.py
python prob42.py
```

To run all 42 problems in sequence and verify their outputs:

```powershell
1..42 | ForEach-Object { Write-Host "=== Running prob$_.py ==="; python "prob$_.py" }
```

All 42 test suites execute successfully with zero runtime errors and complete algorithmic parity with the C++ originals.
