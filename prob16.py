"""
============================================================================
PROBLEM: Longest Subarray with Sum K
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `arr` of integers (can contain positive, negative, and zero)
   and an integer `k`, find the length of the longest contiguous subarray whose 
   elements sum up to `k`.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Positives + Negatives + Zeroes):
       • Method: Prefix Sum + Hash Map
       • Time Complexity:  O(N) - Single pass through array
       • Space Complexity: O(N) - Hash map storing prefix sums
   - 2. Optimal Approach (Strictly Positive Integers):
       • Method: Two Pointers / Dynamic Sliding Window
       • Time Complexity:  O(2N) = O(N)
       • Space Complexity: O(1) - Constant auxiliary space
   - 3. Brute Force Approach:
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does the Two-Pointer approach fail when array contains negative numbers?
   - Two pointers relies on monotonicity: expanding increases sum, shrinking decreases it.
     Negative values break this monotonic guarantee. Prefix sum with hash map works for all integers.

2. Why do we NOT update `pre_sum_map[sum]` if `sum` is already present in the map?
   - We want the LONGEST subarray. Storing only the FIRST occurrence of a prefix sum
     maximizes `i - pre_sum_map[rem]`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 560: Subarray Sum Equals K (Medium)
2. GeeksforGeeks: Longest Sub-Array with Sum K (Medium)
3. Coding Ninjas: Longest Subarray With Sum K (Medium)
============================================================================
"""

from typing import List, Dict


# ============================================================================
# 1. BRUTE FORCE APPROACH: Nested Iteration
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def longest_subarray_brute_force(arr: List[int], k: int) -> int:
    """Computes sums of all subarrays using nested loops."""
    n = len(arr)
    max_len = 0

    for i in range(n):
        curr_sum = 0
        for j in range(i, n):
            curr_sum += arr[j]
            if curr_sum == k:
                max_len = max(max_len, j - i + 1)

    return max_len


# ============================================================================
# 2. OPTIMAL APPROACH (ALL INTEGERS): Prefix Sum + Hash Map
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def longest_subarray_with_sum_k(a: List[int], k: int) -> int:
    """Finds longest subarray with sum k for positive, negative, and zero elements."""
    pre_sum_map: Dict[int, int] = {}  # {prefix_sum -> first seen index}
    curr_sum = 0
    max_len = 0

    for i in range(len(a)):
        curr_sum += a[i]

        # Case 1: Entire prefix from index 0 to i sums to k
        if curr_sum == k:
            max_len = max(max_len, i + 1)

        # Case 2: Subarray starting after index pre_sum_map[rem] sums to k
        rem = curr_sum - k
        if rem in pre_sum_map:
            length = i - pre_sum_map[rem]
            max_len = max(max_len, length)

        # Only store first occurrence of prefix sum to maximize length
        if curr_sum not in pre_sum_map:
            pre_sum_map[curr_sum] = i

    return max_len


# ============================================================================
# 3. OPTIMAL APPROACH (POSITIVES ONLY): Two Pointers / Sliding Window
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def longest_subarray_positives_only(a: List[int], k: int) -> int:
    """Sliding window approach valid ONLY for arrays with non-negative numbers."""
    n = len(a)
    left = 0
    right = 0
    curr_sum = a[0] if n > 0 else 0
    max_len = 0

    while right < n:
        # Shrink window from left while sum exceeds k
        while left <= right and curr_sum > k:
            curr_sum -= a[left]
            left += 1

        if curr_sum == k:
            max_len = max(max_len, right - left + 1)

        right += 1
        if right < n:
            curr_sum += a[right]

    return max_len


# C++ Aliases
longestSubarrayBruteForce = longest_subarray_brute_force
longestSubarrayWithSumK = longest_subarray_with_sum_k
longestSubarrayPositivesOnly = longest_subarray_positives_only


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr_pos = [10, 5, 2, 7, 1, 9]
    k_pos = 15

    print("Array (Positives):", *arr_pos)
    print(f"Target sum K: {k_pos}")
    print(f"Longest Subarray (Two Pointers - Positives): {longest_subarray_positives_only(arr_pos, k_pos)}")
    print(f"Longest Subarray (Prefix Sum HashMap):      {longest_subarray_with_sum_k(arr_pos, k_pos)}")

    arr_all = [-1, 2, 3]
    k_all = 2
    print(f"\nArray with negatives: {arr_all}, K = {k_all}")
    print(f"Longest Subarray (Prefix Sum HashMap):      {longest_subarray_with_sum_k(arr_all, k_all)}")
