"""
============================================================================
PROBLEM: Rotate Array by K Places (Left and Right Rotations)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `arr` and an integer `k` (or `d`), rotate the array:
   - Left by `d` places
   - Right by `k` places
   Provide both the auxiliary buffer approach and the optimal in-place reversal algorithm.

💡 COMPLEXITY ANALYSIS:
   - Auxiliary Buffer Approach:
       • Time Complexity:  O(N) - Elements copied to temp and shifted
       • Space Complexity: O(K) - Temporary list of size K
   - Optimal Reversal Approach:
       • Time Complexity:  O(N) - 3 reversals over subarrays
       • Space Complexity: O(1) - Pure in-place modification

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What if k >= n?
   - Always normalize `k = k % n` because rotating by `n` leaves array identical.

2. Reversal Steps:
   - Right Rotate by k:
     1. Reverse entire array: `[0 ... n-1]`
     2. Reverse first k: `[0 ... k-1]`
     3. Reverse remaining: `[k ... n-1]`
   - Left Rotate by k:
     1. Reverse first k: `[0 ... k-1]`
     2. Reverse remaining: `[k ... n-1]`
     3. Reverse entire array: `[0 ... n-1]`

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 189: Rotate Array (Medium)
2. GeeksforGeeks: Rotate Array (Medium)
3. Coding Ninjas: Rotate array (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. AUXILIARY BUFFER APPROACH: Using Temp Array of Size K
# Time Complexity: O(N) | Space Complexity: O(K)
# ============================================================================

def left_rotate_aux(arr: List[int], n: int, d: int) -> None:
    """Left rotate array by d places using temporary buffer."""
    if n == 0:
        return
    d = d % n
    if d == 0:
        return

    # Step 1: Copy first d elements into temp
    temp = arr[:d]

    # Step 2: Shift remaining (n - d) elements to the left by d places
    for i in range(d, n):
        arr[i - d] = arr[i]

    # Step 3: Copy elements from temp back to the end
    for i in range(n - d, n):
        arr[i] = temp[i - (n - d)]


def right_rotate_aux(arr: List[int], n: int, k: int) -> None:
    """Right rotate array by k places using temporary buffer."""
    if n == 0:
        return
    k = k % n
    if k == 0:
        return

    # Step 1: Store last k elements in temp
    temp = arr[n - k:]

    # Step 2: Shift first n - k elements to the right by k places
    for i in range(n - k - 1, -1, -1):
        arr[i + k] = arr[i]

    # Step 3: Copy elements from temp into the beginning
    for i in range(k):
        arr[i] = temp[i]


# ============================================================================
# 2. OPTIMAL APPROACH: 3-Step Reversal Algorithm (In-Place)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def reverse_subarray(arr: List[int], start: int, end: int) -> None:
    """Reverses elements in arr from start to end inclusive in-place."""
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1


def rotate_right_optimal(nums: List[int], k: int) -> None:
    """Right rotates array by k places in-place using 3-step reversal."""
    n = len(nums)
    if n == 0:
        return
    k = k % n
    if k == 0:
        return

    # 1. Reverse entire array
    reverse_subarray(nums, 0, n - 1)
    # 2. Reverse first k elements
    reverse_subarray(nums, 0, k - 1)
    # 3. Reverse remaining n - k elements
    reverse_subarray(nums, k, n - 1)


def rotate_left_optimal(nums: List[int], k: int) -> None:
    """Left rotates array by k places in-place using 3-step reversal."""
    n = len(nums)
    if n == 0:
        return
    k = k % n
    if k == 0:
        return

    # 1. Reverse first k elements
    reverse_subarray(nums, 0, k - 1)
    # 2. Reverse remaining n - k elements
    reverse_subarray(nums, k, n - 1)
    # 3. Reverse the entire array
    reverse_subarray(nums, 0, n - 1)


# C++ Aliases
leftRotateAux = left_rotate_aux
rightRotateAux = right_rotate_aux
reverseSubarray = reverse_subarray
rotateRightOptimal = rotate_right_optimal
rotateLeftOptimal = rotate_left_optimal


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7]
    k = 2

    print("Original Array:", *arr)

    # Test Right Rotation
    right_arr = arr[:]
    rotate_right_optimal(right_arr, k)
    print(f"Array after Right Rotation by {k} (Optimal):", *right_arr)

    # Test Left Rotation
    left_arr = arr[:]
    rotate_left_optimal(left_arr, k)
    print(f"Array after Left Rotation by {k} (Optimal):", *left_arr)
