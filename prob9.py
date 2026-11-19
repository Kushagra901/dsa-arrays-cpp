"""
============================================================================
PROBLEM: Move All Zeroes to the End of the Array (Optimal 2-Pointer Approach)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `arr` of size `n`, move all zeroes to the end of 
   the array in-place while maintaining the relative order of the non-zero elements.

💡 COMPLEXITY ANALYSIS:
   - Time Complexity:  O(N) - Single pass (Finding first zero <= N, swapping <= N)
   - Space Complexity: O(1) - Constant auxiliary space, pure in-place pointer swaps

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does the Two-Pointer (Slow & Fast Pointer) logic work here?
   - Pointer `j` tracks the first occurrence of `0`.
   - Pointer `i` scans from `j + 1` to `n - 1`.
   - Whenever `arr[i] != 0`, we swap `arr[i]` with `arr[j]` and increment `j` by 1.

2. Is this algorithm stable?
   - Yes, non-zero elements preserve their original relative order.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 283: Move Zeroes (Easy)
2. LeetCode 27: Remove Element (Easy)
3. GeeksforGeeks: Move all zeroes to end of array (Easy)
4. Coding Ninjas: Move Zero's to End (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Two Pointers (In-Place Swapping)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def move_zero(n: int, a: List[int]) -> List[int]:
    """Moves all zeroes to end of list in-place and returns reference."""
    j = -1

    # Step 1: Find first zero index
    for i in range(n):
        if a[i] == 0:
            j = i
            break

    if j == -1:
        return a

    # Step 2: Iterate through remaining array and swap non-zeroes with index j
    for i in range(j + 1, n):
        if a[i] != 0:
            a[i], a[j] = a[j], a[i]
            j += 1

    return a


# C++ Alias
moveZero = move_zero


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [0, 0, 3, 4, 7, 8, 0, 5, 3, 5, 0, 0]
    n = len(arr)

    print("Original Array:", *arr)

    move_zero(n, arr)

    print("Array after moving zeroes to end:", *arr)
