"""
============================================================================
PROBLEM: Count Subarrays with Given XOR K
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `A` and an integer `B` (or `k`), find the total 
   number of contiguous subarrays having bitwise XOR of their elements equal to `B`.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Prefix XOR + Hash Map):
       • Time Complexity:  O(N) - Single pass through array
       • Space Complexity: O(N) auxiliary space for frequency hash map
   - Better Approach (Running XOR with 2 Loops):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)
   - Brute Force Approach:
       • Time Complexity:  O(N^3)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What is the mathematical principle behind Prefix XOR?
   - If prefix XOR up to index `i` is `xr`, and we want a subarray with XOR `k`,
     we need an earlier prefix XOR `x` such that `x ^ k = xr`.
   - By XORing both sides by `k`: `x = xr ^ k`.
   - Thus, looking up `xr ^ k` in the frequency map gives all valid subarrays ending at `i`.

2. Why is `mpp[0] = 1` initialized before traversing?
   - If a subarray starting from index 0 itself has XOR equal to `k`, then `xr ^ k = 0`.
     Having `mpp[0] = 1` counts this entire prefix subarray properly.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. InterviewBit: Subarray with given XOR (Medium)
2. LeetCode 560: Subarray Sum Equals K (Medium)
3. LeetCode 1310: XOR Queries of a Subarray (Medium)
============================================================================
"""

from typing import List, Dict


# ============================================================================
# OPTIMAL APPROACH: Prefix XOR + Hash Map Frequency
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def subarray_with_sum_k(a: List[int], k: int) -> int:
    """Counts subarrays with given bitwise XOR k using prefix XOR and hash map."""
    xr = 0
    mpp: Dict[int, int] = {0: 1}  # Base case: prefix XOR of 0 occurs once
    cnt = 0

    for num in a:
        # Step 1: Accumulate current element into running prefix XOR
        xr = xr ^ num

        # Step 2: Compute prefix XOR needed (x = xr ^ k)
        x = xr ^ k

        # Step 3: Add frequency of x from map
        if x in mpp:
            cnt += mpp[x]

        # Step 4: Record current prefix XOR in map
        mpp[xr] = mpp.get(xr, 0) + 1

    return cnt


# C++ Alias
subarrayWithSumK = subarray_with_sum_k


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [4, 2, 2, 6, 4]
    k = 6

    print("Array elements:", *arr)
    print(f"Target XOR k: {k}")

    total_subarrays = subarray_with_sum_k(arr, k)
    print(f"Total Subarrays with XOR {k}: {total_subarrays}")
