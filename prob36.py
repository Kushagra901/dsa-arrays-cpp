"""
============================================================================
PROBLEM: 4Sum (Find All Unique Quadruplets with Target Sum)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `nums` of `n` integers and an integer `target`, return an 
   array of all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` 
   such that:
     - 0 <= a, b, c, d < n
     - a, b, c, and d are distinct indices.
     - nums[a] + nums[b] + nums[c] + nums[d] == target
   The solution set must not contain duplicate quadruplets.

💡 COMPLEXITY ANALYSIS:
   - 1. Better Approach (3 Nested Loops + Hash Set):
       • Time Complexity:  O(N^3)
       • Space Complexity: O(quadruplets) + O(N) auxiliary hash set
   - 2. Optimal Approach (Sorting + Two Pointers):
       • Time Complexity:  O(N^3) - Two nested loops with a two-pointer scan
       • Space Complexity: O(1) auxiliary space (excluding returned result list)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does Python handle integer sums safely without overflow?
   - Unlike C++ where sum of four 32-bit integers can exceed `INT_MAX` (2 * 10^9),
     Python integers have arbitrary precision and never overflow!

2. How are duplicate quadruplets avoided without using an expensive set?
   - By sorting the array first and explicitly skipping adjacent duplicate values:
     `if i > 0 and nums[i] == nums[i - 1]: continue`
     `if j > i + 1 and nums[j] == nums[j - 1]: continue`
     and skipping duplicates when advancing `k` and `l`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 18: 4Sum (Medium)
2. LeetCode 15: 3Sum (Medium)
3. LeetCode 454: 4Sum II (Medium)
============================================================================
"""

from typing import List, Set, Tuple


# ============================================================================
# 1. BETTER APPROACH: 3 Loops + Hash Set
# Time Complexity: O(N^3) | Space Complexity: O(N) + O(quadruplets)
# ============================================================================

def four_sum_better(nums: List[int], target: int) -> List[List[int]]:
    """Finds unique quadruplets using 3 loops and a hash set."""
    n = len(nums)
    unique_quads: Set[Tuple[int, int, int, int]] = set()

    for i in range(n):
        for j in range(i + 1, n):
            hashset: Set[int] = set()
            for k in range(j + 1, n):
                curr_sum = nums[i] + nums[j] + nums[k]
                fourth = target - curr_sum

                if fourth in hashset:
                    temp = sorted([nums[i], nums[j], nums[k], fourth])
                    unique_quads.add((temp[0], temp[1], temp[2], temp[3]))

                hashset.add(nums[k])

    return [list(q) for q in unique_quads]


# ============================================================================
# 2. OPTIMAL APPROACH: Sorting + 2 Outer Loops + Two Pointers
# Time Complexity: O(N^3) | Space Complexity: O(1) auxiliary
# ============================================================================

def four_sum(nums: List[int], target: int) -> List[List[int]]:
    """Finds all unique quadruplets summing to target in O(N^3) time and O(1) space."""
    n = len(nums)
    ans: List[List[int]] = []
    arr = sorted(nums)

    for i in range(n):
        if i > 0 and arr[i] == arr[i - 1]:
            continue

        for j in range(i + 1, n):
            if j > i + 1 and arr[j] == arr[j - 1]:
                continue

            k = j + 1
            l = n - 1

            while k < l:
                total = arr[i] + arr[j] + arr[k] + arr[l]

                if total == target:
                    ans.append([arr[i], arr[j], arr[k], arr[l]])
                    k += 1
                    l -= 1

                    while k < l and arr[k] == arr[k - 1]:
                        k += 1
                    while k < l and arr[l] == arr[l + 1]:
                        l -= 1
                elif total < target:
                    k += 1
                else:
                    l -= 1

    return ans


# C++ Aliases
fourSumBetter = four_sum_better
fourSum = four_sum


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    nums = [1, 0, -1, 0, -2, 2]
    target = 0

    print("Original Array:", *nums)
    print(f"Target sum: {target}")

    ans = four_sum(nums, target)

    print(f"The unique quadruplets are (Total {len(ans)}):")
    for quad in ans:
        print(quad, end=" ")
    print()
