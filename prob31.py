"""
============================================================================
PROBLEM: Majority Element II (> N/3 Times) - Extended Boyer-Moore Voting
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `v` of size `n`, find all elements that appear 
   strictly more than `⌊n / 3⌋` times.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Extended Boyer-Moore Voting Algorithm):
       • Time Complexity:  O(N) + O(N) = O(2N) = O(N) (Pass 1 find up to 2 candidates, Pass 2 verify)
       • Space Complexity: O(1) auxiliary space (returns at most 2 elements)
   - Hash Map Approach:
       • Time Complexity:  O(N)
       • Space Complexity: O(N) auxiliary space

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why can there be AT MOST 2 majority elements appearing strictly > N/3 times?
   - If there were 3 elements each appearing > N/3 times, their combined count 
     would be > 3 * (N / 3) = N, which exceeds the total array size N!
     In general, for > N / k, there can be at most (k - 1) candidates.

2. Why is the second verification pass strictly mandatory here?
   - The voting algorithm provides candidate elements, but cannot guarantee whether they 
     actually appear > floor(N / 3) times without an explicit recount.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 229: Majority Element II (Medium)
2. LeetCode 169: Majority Element (Easy)
3. GeeksforGeeks: Majority Vote (> n/3) (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Extended Boyer-Moore Voting Algorithm
# Time Complexity: O(N) | Space Complexity: O(1) auxiliary
# ============================================================================

def majority_element_2(v: List[int]) -> List[int]:
    """Finds all elements appearing strictly more than n // 3 times."""
    n = len(v)
    cnt1 = 0
    cnt2 = 0
    el1 = -float('inf')
    el2 = -float('inf')

    # Step 1: Extended Boyer-Moore Voting to find up to 2 candidates
    for x in v:
        if cnt1 == 0 and el2 != x:
            cnt1 = 1
            el1 = x
        elif cnt2 == 0 and el1 != x:
            cnt2 = 1
            el2 = x
        elif x == el1:
            cnt1 += 1
        elif x == el2:
            cnt2 += 1
        else:
            cnt1 -= 1
            cnt2 -= 1

    # Step 2: Verification pass to confirm counts > n // 3
    ls: List[int] = []
    cnt1 = 0
    cnt2 = 0
    for x in v:
        if x == el1:
            cnt1 += 1
        if x == el2:
            cnt2 += 1

    threshold = n // 3
    if cnt1 > threshold:
        ls.append(int(el1))
    if cnt2 > threshold:
        ls.append(int(el2))

    ls.sort()
    return ls


# C++ Alias
majorityElement = majority_element_2


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [11, 33, 33, 11, 33, 11]

    print("Array elements:", *arr)

    ans = majority_element_2(arr)

    print("Majority elements (> n/3):", *ans)
