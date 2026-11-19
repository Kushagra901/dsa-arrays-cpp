"""
============================================================================
PROBLEM: Check if an Array is Sorted (and Sorted & Rotated)
============================================================================

📌 PROBLEM DESCRIPTION:
   1. Given an array `a` of size `n`, check if the array is sorted in 
      non-decreasing (ascending) order.
   2. Extension: Check if an array was originally sorted in non-decreasing order,
      then rotated some number of positions (LeetCode 1752).

💡 COMPLEXITY ANALYSIS:
   - Check Sorted (Optimal Linear Scan):
       • Time Complexity:  O(N) - Single pass comparing adjacent elements
       • Space Complexity: O(1) - Constant auxiliary space
   - Check Sorted & Rotated (Optimal Circular Drop Counter):
       • Time Complexity:  O(N) - Single pass checking circular adjacent pairs
       • Space Complexity: O(1) - Constant auxiliary space
   - Check Sorted (Brute Force):
       • Time Complexity:  O(N^2) - Pairwise comparisons
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What defines an array as 'sorted and rotated' (LeetCode 1752)?
   - In a circularly sorted array, there is AT MOST ONE index `i` such that `a[i] > a[(i + 1) % n]`.
   - If `countDrops == 0`, it is fully sorted (rotated by 0).
   - If `countDrops == 1`, it was sorted and rotated.
   - If `countDrops > 1`, it cannot be obtained by rotating a sorted array.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 1752: Check if Array Is Sorted and Rotated (Easy)
2. GeeksforGeeks: Check if an Array is Sorted (Basic)
3. Coding Ninjas: Check Sorted Array (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. BRUTE FORCE APPROACH: Pairwise Comparison
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def is_sorted_brute_force(arr: List[int], n: int) -> bool:
    """Checks every pair (i, j) where j > i to verify arr[j] >= arr[i]."""
    for i in range(n):
        for j in range(i + 1, n):
            if arr[j] < arr[i]:
                return False
    return True


# ============================================================================
# 2. OPTIMAL APPROACH: Linear Adjacent Comparison
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def is_sorted(n: int, a: List[int]) -> bool:
    """Checks if array is sorted in non-decreasing order in O(N) time."""
    for i in range(1, n):
        if a[i] < a[i - 1]:
            return False
    return True


# ============================================================================
# 3. EXTENSION: Check if Array is Sorted and Rotated (LeetCode 1752)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def is_sorted_and_rotated(a: List[int], n: int) -> bool:
    """Checks if array can be obtained by rotating a sorted array (at most 1 drop)."""
    if n <= 1:
        return True

    count_drops = 0
    for i in range(n):
        # Circular comparison using modulo
        if a[i] > a[(i + 1) % n]:
            count_drops += 1

    return count_drops <= 1


# C++ Aliases
isSortedBruteForce = is_sorted_brute_force
isSorted = is_sorted
isSortedAndRotated = is_sorted_and_rotated


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [3, 4, 5, 1, 2]
    arr3 = [2, 1, 3, 4]

    print("Array 1:", *arr1)
    print(f"Is arr1 sorted? {is_sorted(len(arr1), arr1)}")

    print("\nArray 2 (Rotated):", *arr2)
    print(f"Is arr2 sorted? {is_sorted(len(arr2), arr2)}")
    print(f"Is arr2 sorted and rotated? {is_sorted_and_rotated(arr2, len(arr2))}")

    print("\nArray 3 (Unsorted):", *arr3)
    print(f"Is arr3 sorted and rotated? {is_sorted_and_rotated(arr3, len(arr3))}")
