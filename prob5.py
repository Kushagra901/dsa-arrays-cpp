"""
============================================================================
PROBLEM: Left Rotate an Array by One Place
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `arr` of size `n`, rotate the array to the left 
   by one position in-place. The first element moves to the end of the array,
   and all other elements shift one position to the left.

💡 COMPLEXITY ANALYSIS:
   - Brute Force Approach (Auxiliary Temporary Array):
       • Time Complexity:  O(N) - Two passes over array
       • Space Complexity: O(N) - Extra array of size N
   - Optimal Approach (In-Place Shift):
       • Time Complexity:  O(N) - Single pass shifting elements left
       • Space Complexity: O(1) - Constant auxiliary space (only 1 temp variable)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why do we store `arr[0]` in a temporary variable before shifting?
   - Shifting `arr[i] = arr[i+1]` immediately overwrites `arr[0]`.
     Saving it first allows us to safely place it at `arr[n - 1]`.

2. How does rotating by 1 place generalize to rotating by K places?
   - Shifting K times takes O(K * N). The optimal reversal algorithm runs in O(N) time and O(1) space.

3. What if the array is empty or has only one element?
   - If `n <= 1`, no rotation is needed; return array as is.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 189: Rotate Array (Medium)
2. GeeksforGeeks: Quick Left Rotation (Easy)
3. Coding Ninjas: Left Rotate an Array by One (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. BRUTE FORCE APPROACH: Auxiliary Array
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def rotate_array_brute_force(arr: List[int], n: int) -> List[int]:
    """Left rotates array by 1 using an auxiliary temporary array."""
    if n <= 1:
        return arr[:]

    temp = [0] * n
    for i in range(1, n):
        temp[i - 1] = arr[i]
    temp[n - 1] = arr[0]

    return temp


# ============================================================================
# 2. OPTIMAL APPROACH: Shift Elements Left by 1 In-Place
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def rotate_array(arr: List[int], n: int) -> List[int]:
    """Left rotates array by 1 place in-place."""
    if n <= 1:
        return arr

    temp = arr[0]
    for i in range(1, n):
        arr[i - 1] = arr[i]
    arr[n - 1] = temp

    return arr


# C++ Aliases
rotateArrayBruteForce = rotate_array_brute_force
rotateArray = rotate_array


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    n = len(arr)

    print("Original Array:", *arr)

    rotate_array(arr, n)

    print("Array after Left Rotation by 1:", *arr)
