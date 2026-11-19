"""
============================================================================
PROBLEM: Rotate an Array by K Places (Optimal Reversal Algorithm)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of `n` integers and a number `d` (or `k`), left rotate 
   the array by `d` positions in-place using O(1) extra space.

💡 COMPLEXITY ANALYSIS:
   - Time Complexity:  O(d) + O(n - d) + O(n) = O(2n) = O(n)
   - Space Complexity: O(1) - Pure in-place modification

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does the 3-step Reversal Algorithm work for LEFT Rotation by d?
   - Step 1: Reverse the first `d` elements (`0` to `d - 1`).
   - Step 2: Reverse the remaining `n - d` elements (`d` to `n - 1`).
   - Step 3: Reverse the entire array (`0` to `n - 1`).

2. How does the Reversal Algorithm work for RIGHT Rotation by k (LeetCode 189)?
   - Step 1: Reverse the entire array (`0` to `n - 1`).
   - Step 2: Reverse the first `k` elements (`0` to `k - 1`).
   - Step 3: Reverse the remaining `n - k` elements (`k` to `n - 1`).

3. Why is this algorithm optimal?
   - It achieves O(N) linear time while using O(1) auxiliary memory.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 189: Rotate Array (Medium)
2. GeeksforGeeks: Rotate Array (Medium)
3. Coding Ninjas: Rotate array (Easy)
============================================================================
"""

from typing import List


def _reverse(arr: List[int], start: int, end: int) -> None:
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1


# ============================================================================
# OPTIMAL APPROACH: Reversal Algorithm (In-Place)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def left_rotate(arr: List[int], n: int, d: int) -> None:
    """Left rotates array by d places in-place using 3-step reversal."""
    if n == 0:
        return
    d = d % n
    if d == 0:
        return

    # Step 1: Reverse first d elements: [0 ... d-1]
    _reverse(arr, 0, d - 1)

    # Step 2: Reverse remaining (n-d) elements: [d ... n-1]
    _reverse(arr, d, n - 1)

    # Step 3: Reverse the entire array: [0 ... n-1]
    _reverse(arr, 0, n - 1)


def right_rotate(nums: List[int], k: int) -> None:
    """Right rotates array by k places in-place (LeetCode 189 style)."""
    n = len(nums)
    if n == 0:
        return
    k = k % n
    if k == 0:
        return

    _reverse(nums, 0, n - 1)
    _reverse(nums, 0, k - 1)
    _reverse(nums, k, n - 1)


# C++ Aliases
leftRotate = left_rotate
rightRotate = right_rotate


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7]
    n = len(arr)
    d = 3

    print("Original Array:", *arr)

    left_rotate(arr, n, d)

    print(f"Array after Left Rotate by {d} places:", *arr)
