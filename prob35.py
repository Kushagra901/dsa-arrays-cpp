"""
============================================================================
PROBLEM: 3Sum (Find Unique Triplets with Zero Sum)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]`
   such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.
   Notice that the solution set must not contain duplicate triplets.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Sorting + Two Pointers):
       • Time Complexity:  O(N log N) + O(N^2) = O(N^2)
       • Space Complexity: O(1) auxiliary space (excluding returned result list)
   - 2. Brute Force Approach (3 Nested Loops + Set):
       • Time Complexity:  O(N^3 * log(triplets))
       • Space Complexity: O(unique_triplets)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How do we eliminate duplicate triplets without using a Set?
   - Step 1: Sort the array.
   - Step 2: Skip duplicate fixed elements: `if i > 0 and arr[i] == arr[i - 1]: continue`.
   - Step 3: When a valid triplet is found, advance pointers past duplicate values:
     `while j < k and arr[j] == arr[j - 1]: j += 1` and `while j < k and arr[k] == arr[k + 1]: k -= 1`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 15: 3Sum (Medium)
2. LeetCode 16: 3Sum Closest (Medium)
3. LeetCode 18: 4Sum (Medium)
============================================================================
"""

from typing import List, Set, Tuple


# ============================================================================
# 1. OPTIMAL APPROACH: Sorting + Two Pointers (O(1) Auxiliary Space)
# Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
# ============================================================================

def triplet(n: int, arr: List[int]) -> List[List[int]]:
    """Finds all unique triplets with zero sum in O(N^2) time and O(1) extra space."""
    ans: List[List[int]] = []
    nums = sorted(arr)

    for i in range(n):
        # Skip duplicate fixed elements
        if i != 0 and nums[i] == nums[i - 1]:
            continue

        j = i + 1
        k = n - 1

        while j < k:
            total = nums[i] + nums[j] + nums[k]

            if total < 0:
                j += 1
            elif total > 0:
                k -= 1
            else:
                ans.append([nums[i], nums[j], nums[k]])
                j += 1
                k -= 1

                # Skip duplicate elements for j and k
                while j < k and nums[j] == nums[j - 1]:
                    j += 1
                while j < k and nums[k] == nums[k + 1]:
                    k -= 1

    return ans


# ============================================================================
# 2. BRUTE FORCE APPROACH: 3 Nested Loops + Set
# Time Complexity: O(N^3 * log(triplets)) | Space Complexity: O(triplets)
# ============================================================================

def triplet_brute_force(n: int, num: List[int]) -> List[List[int]]:
    """Brute force approach checking all triplets."""
    st: Set[Tuple[int, int, int]] = set()

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                if num[i] + num[j] + num[k] == 0:
                    trip = tuple(sorted([num[i], num[j], num[k]]))
                    st.add(trip)

    return [list(t) for t in sorted(st)]


# C++ Alias
tripletBruteForce = triplet_brute_force


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [-1, 0, 1, 2, -1, -4]
    n = len(arr)

    print("Original Array:", *arr)

    ans = triplet(n, arr)

    print("Unique zero-sum triplets:")
    for trip in ans:
        print(trip, end=" ")
    print()
