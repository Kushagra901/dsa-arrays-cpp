"""
============================================================================
PROBLEM: Next Permutation (Find Next Lexicographically Greater Permutation)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `A`, rearrange it into the lexicographically 
   next greater permutation of numbers.
   If no such permutation exists (the array is sorted in descending order), 
   rearrange it as the lowest possible order (i.e., sorted in ascending order).
   The replacement must be in-place and use only constant extra memory.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (3-Step Lexicographical Algorithm):
       • Time Complexity:  O(N) - Linear scans (breakpoint search, swap, reverse suffix)
       • Space Complexity: O(1) - Pure in-place modification

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What are the 3 steps of the Next Permutation algorithm?
   - Step 1: Find the first decreasing element from right to left (`A[i] < A[i + 1]`).
     Let this index be `ind`.
   - Step 2: If no such index exists, the permutation is the highest possible.
     Reverse the entire array and return.
   - Step 3: Find the element in `A[ind+1 ... n-1]` that is just greater than `A[ind]`.
     Swap `A[ind]` with it.
   - Step 4: Reverse the suffix `A[ind+1 ... n-1]` to make it monotonically increasing (smallest possible).

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 31: Next Permutation (Medium)
2. LeetCode 556: Next Greater Element III (Medium)
3. GeeksforGeeks: Next Permutation (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: 3-Step In-Place Lexicographical Algorithm
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def next_greater_permutation(a: List[int]) -> List[int]:
    """Rearranges list into next lexicographical permutation in-place."""
    n = len(a)
    ind = -1

    # Step 1: Find breakpoint from end
    for i in range(n - 2, -1, -1):
        if a[i] < a[i + 1]:
            ind = i
            break

    # If no breakpoint exists, array is in descending order -> reverse entire array
    if ind == -1:
        a.reverse()
        return a

    # Step 2: Find smallest element in suffix greater than a[ind] and swap
    for i in range(n - 1, ind, -1):
        if a[i] > a[ind]:
            a[i], a[ind] = a[ind], a[i]
            break

    # Step 3: Reverse the suffix from ind + 1 to end
    left = ind + 1
    right = n - 1
    while left < right:
        a[left], a[right] = a[right], a[left]
        left += 1
        right -= 1

    return a


# C++ Alias
nextGreaterPermutation = next_greater_permutation


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    A = [2, 1, 5, 4, 3, 0, 0]

    print("Original Permutation: ", *A)

    next_greater_permutation(A)

    print("Next Permutation:     ", *A)
