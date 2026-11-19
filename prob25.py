"""
============================================================================
PROBLEM: Longest Consecutive Sequence in an Array
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an unsorted array of integers `nums`, return the length of the 
   longest consecutive elements sequence.
   You must write an algorithm that runs in O(N) time.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Hash Set Streak Counting):
       • Time Complexity:  O(N) - Each number is inserted into set and visited at most twice
       • Space Complexity: O(N) - Hash set storing unique elements
   - 2. Better Approach (Sorting):
       • Time Complexity:  O(N log N) - Sorting the array + single pass
       • Space Complexity: O(N) for copy
   - 3. Brute Force Approach (Linear Search):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does the Hash Set approach achieve O(N) linear time?
   - A streak is ONLY initiated if `num - 1` is NOT present in the set.
     This ensures that the `while num + 1 in s` loop is triggered only from the
     TRUE START of each consecutive sequence, preventing repeated inner traversals.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 128: Longest Consecutive Sequence (Medium)
2. GeeksforGeeks: Longest consecutive subsequence (Medium)
3. Coding Ninjas: Longest Successive Elements (Medium)
============================================================================
"""

from typing import List, Set


# ============================================================================
# 1. BRUTE FORCE APPROACH: Linear Search for Successors
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def linear_search(arr: List[int], num: int) -> bool:
    """Checks if num exists in arr."""
    return num in arr


def longest_consecutive_brute(arr: List[int]) -> int:
    """Checks for presence of x + 1 for every element x."""
    n = len(arr)
    if n == 0:
        return 0

    longest = 1
    for x in arr:
        cnt = 1
        curr = x
        while linear_search(arr, curr + 1):
            curr += 1
            cnt += 1
        longest = max(longest, cnt)

    return longest


# ============================================================================
# 2. BETTER APPROACH: Sorting
# Time Complexity: O(N log N) | Space Complexity: O(N)
# ============================================================================

def longest_consecutive_sort(arr: List[int]) -> int:
    """Sorts copy of array and counts contiguous streaks."""
    n = len(arr)
    if n == 0:
        return 0

    sorted_arr = sorted(arr)
    last_smaller = -float('inf')
    cnt = 0
    longest = 1

    for num in sorted_arr:
        if num - 1 == last_smaller:
            cnt += 1
            last_smaller = num
        elif num != last_smaller:
            cnt = 1
            last_smaller = num
        longest = max(longest, cnt)

    return longest


# ============================================================================
# 3. OPTIMAL APPROACH: Hash Set Streak Counting
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def longest_successive_elements(a: List[int]) -> int:
    """Finds longest consecutive streak in O(N) time using a set."""
    n = len(a)
    if n == 0:
        return 0

    st: Set[int] = set(a)
    longest = 1

    for x in st:
        # If x is the start of a streak (i.e. x - 1 does not exist in set)
        if (x - 1) not in st:
            cnt = 1
            curr = x
            while (curr + 1) in st:
                curr += 1
                cnt += 1
            longest = max(longest, cnt)

    return longest


# C++ Aliases
linearSearch = linear_search
longestConsecutiveBrute = longest_consecutive_brute
longestConsecutiveSort = longest_consecutive_sort
longestSuccessiveElements = longest_successive_elements


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [100, 200, 1, 3, 2, 4]

    print("Array elements:", *arr)

    print(f"Longest Consecutive (Brute Force): {longest_consecutive_brute(arr)}")
    print(f"Longest Consecutive (Sorting):     {longest_consecutive_sort(arr)}")
    print(f"Longest Consecutive (Optimal Set): {longest_successive_elements(arr)}")
