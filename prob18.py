"""
============================================================================
PROBLEM: Sort an Array of 0s, 1s, and 2s (Dutch National Flag Problem)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `arr` containing only `0`s, `1`s, and `2`s, sort the array 
   in-place in non-decreasing order without using any library sort function.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Dutch National Flag Algorithm - 3-Way Partitioning):
       • Time Complexity:  O(N) - Exactly single pass
       • Space Complexity: O(1) - Pure in-place modification
   - 2. Better Approach (Counting Frequencies):
       • Time Complexity:  O(2N) = O(N) - Pass 1 counts frequencies, Pass 2 overwrites
       • Space Complexity: O(1) - Three counter variables

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does the 3-Way Partitioning (Dutch National Flag) guarantee correctness?
   - Invariant:
       • `arr[0 ... low - 1]` contains only 0s
       • `arr[low ... mid - 1]` contains only 1s
       • `arr[mid ... high]` is unexamined
       • `arr[high + 1 ... n - 1]` contains only 2s
   - When `arr[mid] == 0`: swap with `arr[low]`, increment `low` and `mid`.
   - When `arr[mid] == 1`: increment `mid`.
   - When `arr[mid] == 2`: swap with `arr[high]`, decrement `high` (do NOT increment `mid`).

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 75: Sort Colors (Medium)
2. GeeksforGeeks: Sort an array of 0s, 1s and 2s (Easy)
3. Coding Ninjas: Sort 0 1 2 (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. BETTER APPROACH: Counting Frequencies
# Time Complexity: O(2N) | Space Complexity: O(1)
# ============================================================================

def sort_colors_counting(arr: List[int], n: int) -> None:
    """Sorts array by counting occurrences of 0, 1, and 2."""
    c0 = c1 = c2 = 0

    for i in range(n):
        if arr[i] == 0:
            c0 += 1
        elif arr[i] == 1:
            c1 += 1
        else:
            c2 += 1

    idx = 0
    for _ in range(c0):
        arr[idx] = 0
        idx += 1
    for _ in range(c1):
        arr[idx] = 1
        idx += 1
    for _ in range(c2):
        arr[idx] = 2
        idx += 1


# ============================================================================
# 2. OPTIMAL APPROACH: Dutch National Flag Algorithm (3-Way Partitioning)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def sort_array(arr: List[int], n: int) -> None:
    """Sorts array in-place in a single pass using Dutch National Flag algorithm."""
    low = 0
    mid = 0
    high = n - 1

    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1


# C++ Aliases
sortColorsCounting = sort_colors_counting
sortArray = sort_array


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [2, 0, 2, 1, 1, 0]
    n = len(arr)

    print("Original Array:", *arr)

    sort_array(arr, n)

    print("Array after sorting (DNF Optimal):", *arr)
