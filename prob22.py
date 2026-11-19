"""
============================================================================
PROBLEM: Rearrange Array Elements by Sign
============================================================================

📌 PROBLEM DESCRIPTION:
   Variety 1: An array of size `n` contains an equal number of positive and negative 
   integers. Rearrange them alternatively such that positive numbers occupy even indices 
   (0, 2, 4...) and negative numbers occupy odd indices (1, 3, 5...), maintaining relative order.

   Variety 2: The count of positive and negative numbers is NOT necessarily equal. 
   Alternate as long as both exist, and append remaining elements at the end preserving relative order.

💡 COMPLEXITY ANALYSIS:
   - Variety 1 (Equal Counts - Direct Placement):
       • Time Complexity:  O(N) - Single pass through array
       • Space Complexity: O(N) - Output list of size N
   - Variety 2 (Unequal Counts - Segregation + Alternation):
       • Time Complexity:  O(2N) = O(N) (Pass 1 segregate into pos/neg, Pass 2 alternate & append)
       • Space Complexity: O(N) - Two separate lists for pos and neg

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Can Variety 1 be solved in-place with O(1) auxiliary space while preserving relative order?
   - Preserving stability (relative order) in-place in O(N) time is an unsolved problem in computer science.
     An O(N) auxiliary list is the standard optimal approach.

2. How do you handle Variety 2 when positive and negative counts differ?
   - Segregate elements into `pos` and `neg` lists.
   - Alternate up to `min(len(pos), len(neg))`.
   - Append the remaining leftovers of the larger list to the end.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 2149: Rearrange Array Elements by Sign (Medium)
2. GeeksforGeeks: Alternate positive and negative numbers (Easy)
3. Coding Ninjas: Rearrange Array Elements by Sign (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# VARIETY 1: Equal Number of Positives and Negatives (Optimal O(N) Single-Pass)
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def rearrange_array(nums: List[int]) -> List[int]:
    """Rearranges equal count of positives and negatives to alternate positions."""
    n = len(nums)
    ans = [0] * n
    positive_index = 0  # Even indices: 0, 2, 4...
    negative_index = 1  # Odd indices: 1, 3, 5...

    for num in nums:
        if num < 0:
            ans[negative_index] = num
            negative_index += 2
        else:
            ans[positive_index] = num
            positive_index += 2

    return ans


# ============================================================================
# VARIETY 2: Unequal Number of Positives and Negatives
# Time Complexity: O(2N) = O(N) | Space Complexity: O(N)
# ============================================================================

def rearrange_by_sign(a: List[int], n: int) -> List[int]:
    """Rearranges unequal count of positives and negatives, appending leftovers."""
    pos = [x for x in a if x > 0]
    neg = [x for x in a if x < 0]
    res = a[:]

    # Case A: Positives are fewer than Negatives
    if len(pos) < len(neg):
        for i in range(len(pos)):
            res[2 * i] = pos[i]
            res[2 * i + 1] = neg[i]

        index = len(pos) * 2
        for i in range(len(pos), len(neg)):
            res[index] = neg[i]
            index += 1
    # Case B: Negatives are fewer than or equal to Positives
    else:
        for i in range(len(neg)):
            res[2 * i] = pos[i]
            res[2 * i + 1] = neg[i]

        index = len(neg) * 2
        for i in range(len(neg), len(pos)):
            res[index] = pos[i]
            index += 1

    return res


# C++ Aliases
rearrangeArray = rearrange_array
RearrangebySign = rearrange_by_sign


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    # Variety 1
    v1_arr = [3, 1, -2, -5, 2, -4]
    print("Variety 1 (Equal Counts) Original:", *v1_arr)
    v1_res = rearrange_array(v1_arr)
    print("Rearranged (Variety 1):           ", *v1_res)

    # Variety 2
    v2_arr = [1, 2, -4, -5, 3, 4]
    print("\nVariety 2 (Unequal Counts) Original:", *v2_arr)
    v2_res = rearrange_by_sign(v2_arr, len(v2_arr))
    print("Rearranged (Variety 2):             ", *v2_res)
