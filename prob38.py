"""
============================================================================
PROBLEM: Largest Subarray with 0 Sum
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `A` of `n` integers (containing both positive and negative values), 
   find the length of the longest contiguous subarray whose elements sum up to 0.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Prefix Sum + Hash Map):
       • Time Complexity:  O(N) - Single pass through array
       • Space Complexity: O(N) auxiliary space to store prefix sums
   - Brute Force Approach (All Subarrays):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why do we store only the FIRST occurrence of each prefix sum in the hash map?
   - To maximize subarray length `i - mpp[sum]`, we need the earliest possible index `mpp[sum]`.
     Overwriting `mpp[sum]` would shorten the calculated subarray length.

2. Why is `sum == 0` handled specially?
   - If `sum == 0` at index `i`, the subarray from index 0 to `i` (length `i + 1`) 
     sums to 0. This is the entire prefix, which is always longer than any internal subarray ending at `i`.

3. What is the relation to Contiguous Array (LeetCode 525 - Equal 0s and 1s)?
   - Convert all 0s in the binary array to -1s. The problem of finding the longest subarray 
     with equal 0s and 1s transforms directly into "Largest Subarray with 0 Sum"!

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. GeeksforGeeks: Largest subarray with 0 sum (Medium)
2. LeetCode 525: Contiguous Array (Medium)
3. LeetCode 560: Subarray Sum Equals K (Medium)
============================================================================
"""

from typing import List, Dict


# ============================================================================
# OPTIMAL APPROACH: Prefix Sum + First Occurrence Hash Map
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def max_len(a: List[int], n: int) -> int:
    """Finds length of longest contiguous subarray summing to 0."""
    mpp: Dict[int, int] = {}  # {prefixSum -> first occurrence index}
    maxi = 0
    curr_sum = 0

    for i in range(n):
        curr_sum += a[i]

        # Case 1: Entire prefix from index 0 to i sums to 0
        if curr_sum == 0:
            maxi = i + 1
        # Case 2: Prefix sum has been seen before
        else:
            if curr_sum in mpp:
                maxi = max(maxi, i - mpp[curr_sum])
            else:
                mpp[curr_sum] = i

    return maxi


# ============================================================================
# COMPLEMENTARY HELPER: Power of Three Check (LeetCode 326)
# ============================================================================

def is_power_of_three(n: int) -> bool:
    """Returns True if n is a power of 3."""
    if n <= 0:
        return False
    while n % 3 == 0:
        n //= 3
    return n == 1


# C++ Aliases
maxLen = max_len
isPowerOfThree = is_power_of_three


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    A = [15, -2, 2, -8, 1, 7, 10, 23]
    n = len(A)

    print("Array elements:", *A)

    result = max_len(A, n)
    print(f"Length of the largest subarray with zero sum: {result}")
