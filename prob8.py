"""
============================================================================
PROBLEM: Move Zeroes to End
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `nums`, move all `0`s to the end of it while 
   maintaining the relative order of the non-zero elements.
   Note that you must do this in-place without making a copy of the array.

💡 COMPLEXITY ANALYSIS:
   - Brute Force Approach (Using Auxiliary Vector):
       • Time Complexity:  O(2N) = O(N) - Two passes over array
       • Space Complexity: O(N) - Temporary vector to collect non-zero elements
   - Optimal Approach (Two Pointers - In-Place Swapping):
       • Time Complexity:  O(N) - Single pass finding first zero and swapping non-zeroes
       • Space Complexity: O(1) - Constant auxiliary space

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does the Two-Pointer approach avoid redundant swaps?
   - Pointer `j` is positioned at the first occurrence of `0`.
   - Pointer `i` searches for subsequent non-zero elements from `j + 1`.
   - When `nums[i] != 0`, `swap(nums[i], nums[j])` is executed, and `j += 1` advances.

2. What happens if the array has no zeroes?
   - The first loop finishes without setting `j != -1`. The function exits early in O(N).

3. Does this maintain the relative ordering of non-zero elements?
   - Yes, non-zero elements are scanned from left to right and swapped sequentially.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 283: Move Zeroes (Easy)
2. GeeksforGeeks: Move all zeroes to end of array (Easy)
3. Coding Ninjas: Move Zero's to End (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. BRUTE FORCE APPROACH: Using Temporary Array
# Time Complexity: O(2N) = O(N) | Space Complexity: O(N)
# ============================================================================

def move_zeroes_brute_force(n: int, a: List[int]) -> List[int]:
    """Collects non-zero elements into temp list and appends zeroes."""
    res = a[:]
    # Step 1: Collect non-zero elements
    temp = [x for x in res if x != 0]

    # Step 2: Copy back non-zero elements
    nz = len(temp)
    for i in range(nz):
        res[i] = temp[i]

    # Step 3: Fill remaining indices with 0
    for i in range(nz, n):
        res[i] = 0

    return res


# ============================================================================
# 2. OPTIMAL APPROACH: In-Place Two Pointers Swapping
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def move_zeroes_optimal(nums: List[int]) -> None:
    """Moves zeroes to end in-place using two-pointer swapping."""
    n = len(nums)
    j = -1  # Pointer to first zero

    # Step 1: Find index of first zero
    for i in range(n):
        if nums[i] == 0:
            j = i
            break

    if j == -1:
        return

    # Step 2: Swap subsequent non-zero elements with zero at j
    for i in range(j + 1, n):
        if nums[i] != 0:
            nums[i], nums[j] = nums[j], nums[i]
            j += 1


# C++ Aliases
moveZeroesBruteForce = move_zeroes_brute_force
moveZeroesOptimal = move_zeroes_optimal


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [0, 1, 0, 3, 12]

    print("Original Array:", *arr)

    move_zeroes_optimal(arr)

    print("Array after moving zeroes to end (Optimal):", *arr)
