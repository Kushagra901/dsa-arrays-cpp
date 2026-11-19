"""
============================================================================
PROBLEM: Count Subarrays with Given Sum K (Subarray Sum Equals K)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `arr` and an integer `k`, find the total number 
   of contiguous subarrays whose sum equals `k`.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Prefix Sum + Hash Map Frequency Table):
       • Time Complexity:  O(N) - Single pass through array
       • Space Complexity: O(N) to store prefix sum frequencies in map
   - Brute Force Approach (All Subarrays):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why do we initialize `mpp[0] = 1` before starting the loop?
   - If a subarray starting at index 0 has prefix sum equal to `k`, then 
     `preSum - k = 0`. `mpp[0] = 1` ensures this entire prefix subarray is counted!

2. Why does the Two-Pointer / Sliding Window method FAIL for this problem?
   - Sliding window requires monotonicity. If the array contains negative numbers
     or zeroes, expanding/shrinking does not guarantee monotonic sum changes.
     Prefix sum + hash map is the universal O(N) solution.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 560: Subarray Sum Equals K (Medium)
2. LeetCode 930: Binary Subarrays With Sum (Medium)
3. LeetCode 1248: Count Number of Nice Subarrays (Medium)
============================================================================
"""

from typing import List, Dict


# ============================================================================
# OPTIMAL APPROACH: Prefix Sum + Hash Map Frequency Counting
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def find_all_subarrays_with_given_sum(arr: List[int], k: int) -> int:
    """Finds count of subarrays with sum equal to k."""
    mpp: Dict[int, int] = {0: 1}  # Base case: prefix sum of 0 occurs once
    pre_sum = 0
    cnt = 0

    for num in arr:
        pre_sum += num
        remove = pre_sum - k

        if remove in mpp:
            cnt += mpp[remove]

        mpp[pre_sum] = mpp.get(pre_sum, 0) + 1

    return cnt


# C++ Alias
findAllSubarraysWithGivenSum = find_all_subarrays_with_given_sum


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [3, 1, 2, 4]
    k = 6

    print("Array elements:", *arr)
    print(f"Target sum k: {k}")

    cnt = find_all_subarrays_with_given_sum(arr, k)
    print(f"The number of subarrays with sum {k} is: {cnt}")
