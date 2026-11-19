"""
============================================================================
PROBLEM: Majority Element (> N/2 Times) - Moore's Voting Algorithm
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `nums` of size `n`, return the majority element.
   The majority element is the element that appears strictly more than 
   `⌊n / 2⌋` times. You may assume that the majority element always exists.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Boyer-Moore Voting Algorithm):
       • Time Complexity:  O(N) - Single pass through the array
       • Space Complexity: O(1) - Constant auxiliary space

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does Boyer-Moore Voting Algorithm work?
   - The majority element occurs > N/2 times. Even if every other distinct 
     element teams up to cancel out occurrences of the majority element, 
     the majority element will still have at least 1 count remaining!

2. What if the majority element is NOT guaranteed to exist?
   - Perform a second linear pass counting occurrences of `el`.
     If `count > n // 2`, return `el`; otherwise return -1.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 169: Majority Element (Easy)
2. LeetCode 229: Majority Element II (Medium)
3. GeeksforGeeks: Majority Element (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Boyer-Moore Voting Algorithm
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def majority_element(v: List[int]) -> int:
    """Finds majority element appearing > n // 2 times in O(N) time and O(1) space."""
    cnt = 0
    el = -1  # Candidate element

    # Step 1: Find candidate
    for x in v:
        if cnt == 0:
            cnt = 1
            el = x
        elif x == el:
            cnt += 1
        else:
            cnt -= 1

    # Step 2: Verification pass (optional if guaranteed, but good practice)
    cnt1 = 0
    for x in v:
        if x == el:
            cnt1 += 1

    if cnt1 > len(v) // 2:
        return el
    return -1


# C++ Alias
majorityElement = majority_element


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [2, 2, 1, 1, 1, 2, 2]

    print("Array elements:", *arr)

    ans = majority_element(arr)

    print(f"The majority element is: {ans}")
