"""
============================================================================
PROBLEM: Maximum Product Subarray
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `nums`, find a contiguous non-empty subarray within 
   the array that has the largest product, and return the product.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Prefix and Suffix Product Traversal):
       • Time Complexity:  O(N) - Single pass computing forward and backward products
       • Space Complexity: O(1) - Constant auxiliary space
   - Kadane's Extension (Tracking min and max products):
       • Time Complexity:  O(N)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does tracking both prefix and suffix products work?
   - If there is an EVEN number of negative numbers, the product of the whole array is positive.
   - If there is an ODD number of negative numbers, removing either the prefix before the first 
     negative or the suffix after the last negative yields the maximum positive product!
   - Zeroes split the array into independent subarrays: when 0 is reached, reset product to 1.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 152: Maximum Product Subarray (Medium)
2. GeeksforGeeks: Maximum Product Subarray (Medium)
3. Coding Ninjas: Maximum Product Subarray (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Prefix and Suffix Product Traversal
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def subarray_product(arr: List[int]) -> int:
    """Finds maximum product subarray using prefix and suffix running products."""
    n = len(arr)
    if n == 0:
        return 0

    pre = 1
    suff = 1
    ans = -float('inf')

    for i in range(n):
        if pre == 0:
            pre = 1
        if suff == 0:
            suff = 1

        pre = pre * arr[i]
        suff = suff * arr[n - i - 1]

        ans = max(ans, max(pre, suff))

    return int(ans)


# C++ Alias
subarrayProduct = subarray_product


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [2, 3, -2, 4]

    print("Array elements:", *arr)

    result = subarray_product(arr)
    print(f"Maximum Product Subarray: {result}")
