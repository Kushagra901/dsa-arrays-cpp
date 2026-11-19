"""
============================================================================
PROBLEM: Maximum Subarray Sum (Kadane's Algorithm)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `arr` of size `n`, find the contiguous subarray 
   (containing at least one number) which has the largest sum, and return its sum.
   Additionally, identify the start and end indices of the maximum subarray.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Kadane's Algorithm):
       • Time Complexity:  O(N) - Single pass through the array
       • Space Complexity: O(1) - Constant auxiliary space
   - Brute Force Approach:
       • Time Complexity:  O(N^2) - Checking all subarray sums
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does Kadane's Algorithm reset running sum to 0 when it drops below 0?
   - A negative prefix sum can only REDUCE the sum of any subsequent subarray.
     Discarding it and starting fresh from index 0 is always optimal.

2. How do you handle an array where ALL numbers are negative?
   - Initialize `maxi = -infinity` (or `arr[0]`). If all numbers are negative,
     `maxi` will hold the maximum single element (the least negative value).

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 53: Maximum Subarray (Medium)
2. LeetCode 918: Maximum Sum Circular Subarray (Medium)
3. GeeksforGeeks: Kadane's Algorithm (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Kadane's Algorithm
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def max_subarray_sum(arr: List[int], n: int) -> int:
    """Finds maximum contiguous subarray sum and tracks subarray boundary indices."""
    maxi = -float('inf')
    curr_sum = 0
    start = 0
    ans_start = -1
    ans_end = -1

    for i in range(n):
        if curr_sum == 0:
            start = i  # Potential new starting index

        curr_sum += arr[i]

        if curr_sum > maxi:
            maxi = curr_sum
            ans_start = start
            ans_end = i

        # If running sum becomes negative, reset it to 0
        if curr_sum < 0:
            curr_sum = 0

    return int(maxi)


# C++ Alias
maxSubarraySum = max_subarray_sum


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    n = len(arr)

    print("Array elements:", *arr)

    max_sum = max_subarray_sum(arr, n)
    print(f"The maximum subarray sum is: {max_sum}")
