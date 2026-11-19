"""
============================================================================
PROBLEM: Count Subarrays with Given XOR K (Multi-Approach Deep Dive)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `arr` and an integer `k`, count the number of 
   subarrays having bitwise XOR equal to `k`.
   Provides Brute Force O(N^3), Better O(N^2), and Optimal O(N) solutions.

💡 COMPLEXITY ANALYSIS:
   - 1. Brute Force Approach (3 Nested Loops):
       • Time Complexity:  O(N^3)
       • Space Complexity: O(1)
   - 2. Better Approach (Running XOR in 2 Nested Loops):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)
   - 3. Optimal Approach (Prefix XOR + Hash Map):
       • Time Complexity:  O(N) - Single linear scan
       • Space Complexity: O(N) auxiliary space for frequency hash map

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What is the mathematical principle behind Prefix XOR?
   - If prefix XOR up to index `i` is `xr`, and we want a subarray with XOR `k`,
     we need an earlier prefix XOR `x` such that `x ^ k = xr`.
   - By XORing both sides by `k`: `x = xr ^ k`.
   - Looking up `xr ^ k` in the frequency map gives all valid subarrays ending at `i`.

2. Why is `mp[0] = 1` initialized before traversing?
   - If a subarray starting from index 0 itself has XOR equal to `k`, then `xr ^ k = 0`.
     Having `mp[0] = 1` counts this entire prefix subarray properly.

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
# 1. BRUTE FORCE APPROACH: 3 Nested Loops
# Time Complexity: O(N^3) | Space Complexity: O(1)
# ============================================================================

def subarray_with_xor_brute(arr: List[int], k: int) -> int:
    """Computes XOR of all subarrays using 3 nested loops."""
    n = len(arr)
    cnt = 0
    for i in range(n):
        for j in range(i, n):
            xr = 0
            for k_idx in range(i, j + 1):
                xr ^= arr[k_idx]
            if xr == k:
                cnt += 1
    return cnt


# ============================================================================
# 2. BETTER APPROACH: Running XOR in 2 Nested Loops
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def subarray_with_xor_better(arr: List[int], k: int) -> int:
    """Computes XOR using 2 nested loops with running XOR."""
    n = len(arr)
    cnt = 0
    for i in range(n):
        xr = 0
        for j in range(i, n):
            xr ^= arr[j]
            if xr == k:
                cnt += 1
    return cnt


# ============================================================================
# 3. OPTIMAL APPROACH: Prefix XOR + Hash Map
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def subarray_with_xor_optimal(arr: List[int], k: int) -> int:
    """Finds count of subarrays with XOR k in O(N) time and O(N) space."""
    xr = 0
    mp: Dict[int, int] = {0: 1}  # Base condition: prefix XOR of 0 has frequency 1
    cnt = 0

    for num in arr:
        xr ^= num
        x = xr ^ k
        if x in mp:
            cnt += mp[x]
        mp[xr] = mp.get(xr, 0) + 1

    return cnt


# C++ Aliases
subarrayWithXorBrute = subarray_with_xor_brute
subarrayWithXorBetter = subarray_with_xor_better
subarrayWithXorOptimal = subarray_with_xor_optimal


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [4, 2, 2, 6, 4]
    k = 6

    print("Array elements:", *arr)
    print(f"Target XOR k: {k}")

    print(f"Subarrays with XOR {k} (Brute Force): {subarray_with_xor_brute(arr, k)}")
    print(f"Subarrays with XOR {k} (Better):      {subarray_with_xor_better(arr, k)}")
    print(f"Subarrays with XOR {k} (Optimal):     {subarray_with_xor_optimal(arr, k)}")
