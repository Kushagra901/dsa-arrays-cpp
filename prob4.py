"""
============================================================================
PROBLEM: Remove Duplicates from Sorted Array (In-Place)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `nums` sorted in non-decreasing order, remove the 
   duplicates in-place such that each unique element appears only once.
   The relative order of the elements should be kept the same.
   Return `k`, the number of unique elements.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Two Pointers - Slow & Fast Pointer):
       • Time Complexity:  O(N) - Single pass traversal through array
       • Space Complexity: O(1) - Pure in-place modification
   - Brute Force Approach (Hash Set):
       • Time Complexity:  O(N) - Hashing insertion and retrieval
       • Space Complexity: O(N) - Extra memory for set

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does the Two-Pointer approach work only on SORTED arrays?
   - In a sorted array, all duplicate occurrences of any element are clustered
     contiguously. A fast pointer can easily skip contiguous duplicates.

2. How do you extend this to allow at most K duplicates? (LeetCode 80: Remove Duplicates II)
   - For at most 2 occurrences: compare `nums[fast]` against `nums[slow - 2]`.
     If different, write `nums[slow] = nums[fast]` and advance `slow`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 26: Remove Duplicates from Sorted Array (Easy)
2. LeetCode 80: Remove Duplicates from Sorted Array II (Medium)
3. LeetCode 27: Remove Element (Easy)
4. GeeksforGeeks: Remove duplicate elements from sorted Array (Easy)
============================================================================
"""

from typing import List, Set


# ============================================================================
# 1. BRUTE FORCE APPROACH: Using Set
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def remove_duplicates_brute_force(nums: List[int]) -> int:
    """Preserves order while collecting unique elements using a set."""
    if not nums:
        return 0

    seen: Set[int] = set()
    index = 0

    for num in nums:
        if num not in seen:
            seen.add(num)
            nums[index] = num
            index += 1

    return index


# ============================================================================
# 2. OPTIMAL APPROACH: Two Pointers (Slow & Fast Pointer)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def remove_duplicates(arr: List[int], n: int) -> int:
    """Removes duplicates in-place from sorted array using slow and fast pointers."""
    if n == 0:
        return 0

    i = 0  # Slow pointer: points to last unique element placed

    # Fast pointer `j` scans through the array
    for j in range(1, n):
        if arr[i] != arr[j]:
            arr[i + 1] = arr[j]  # Place new unique element next to slow pointer
            i += 1               # Advance slow pointer

    return i + 1  # Number of unique elements


# C++ Aliases
removeDuplicatesBruteForce = remove_duplicates_brute_force
removeDuplicates = remove_duplicates


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [1, 1, 2, 2, 3, 3, 4]
    n = len(arr)

    print("Original array:", *arr)

    k = remove_duplicates(arr, n)

    print(f"Number of unique elements: {k}")
    print(f"Array after removing duplicates (first {k} elements):", *arr[:k])
