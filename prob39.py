"""
============================================================================
PROBLEM: Merge Two Sorted Arrays Without Extra Space (Gap Method / In-Place)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given two sorted arrays `arr1` and `arr2` of sizes `n` and `m` respectively, 
   merge them without using extra space. After merging, both `arr1` and `arr2` remain 
   sorted individually and the combined elements are in sorted order.
   No extra memory (O(1) space) is allowed.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Gap Method - Shell Sort Intuition):
       • Time Complexity:  O((n + m) * log(n + m)) - Gap reductions log(n+m), each pass takes O(n+m)
       • Space Complexity: O(1) - Pure in-place swapping
   - Alternative Optimal (Compare from Back & Swap + Sort):
       • Time Complexity:  O(min(n, m)) + O(n log n) + O(m log m)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does the Gap Method work?
   - Treat both arrays conceptually as one concatenated array of length `len = n + m`.
   - Initialize `gap = (len // 2) + (len % 2)`.
   - Place two pointers with distance `gap` between them and swap if `arr[left] > arr[right]`.
   - Reduce gap: `gap = (gap // 2) + (gap % 2)` after each complete pass until `gap == 1` finishes.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. GeeksforGeeks: Merge Without Extra Space (Hard)
2. LeetCode 88: Merge Sorted Array (Easy)
3. Coding Ninjas: Merge Two Sorted Arrays Without Extra Space (Hard)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Gap Method (Shell Sort In-Place Traversal)
# Time Complexity: O((n + m) * log(n + m)) | Space Complexity: O(1)
# ============================================================================

def swap_if_greater(arr1: List[int], arr2: List[int], ind1: int, ind2: int) -> None:
    """Helper function to swap elements if left element is greater than right element."""
    if arr1[ind1] > arr2[ind2]:
        arr1[ind1], arr2[ind2] = arr2[ind2], arr1[ind1]


def merge(arr1: List[int], arr2: List[int], n: int, m: int) -> None:
    """Merges two sorted lists in-place without extra memory using Gap Method."""
    total_len = n + m
    gap = (total_len // 2) + (total_len % 2)

    while gap > 0:
        left = 0
        right = left + gap

        while right < total_len:
            # Case 1: left pointer in arr1, right pointer in arr2
            if left < n and right >= n:
                swap_if_greater(arr1, arr2, left, right - n)
            # Case 2: both pointers in arr2
            elif left >= n:
                swap_if_greater(arr2, arr2, left - n, right - n)
            # Case 3: both pointers in arr1
            else:
                swap_if_greater(arr1, arr1, left, right)

            left += 1
            right += 1

        if gap == 1:
            break

        gap = (gap // 2) + (gap % 2)


# C++ Aliases
swapIfGreater = swap_if_greater


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr1 = [1, 4, 8, 10]
    arr2 = [2, 3, 9]
    n = len(arr1)
    m = len(arr2)

    print("Original Arrays:")
    print("arr1 =", *arr1)
    print("arr2 =", *arr2)

    merge(arr1, arr2, n, m)

    print("\nMerged Arrays without extra space:")
    print("arr1 =", *arr1)
    print("arr2 =", *arr2)
