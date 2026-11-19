"""
============================================================================
PROBLEM: Leaders in an Array (Superior Elements)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `a` of size `n`, find all the superior elements (leaders).
   An element is called a leader/superior element if it is strictly greater than 
   all the elements to its right side.
   The rightmost element is always a leader.
   (Related problem: LeetCode 1299 - Replace Elements with Greatest Element on Right Side).

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Right-to-Left Traversal with Running Max):
       • Time Complexity:  O(N) - Single pass from right to left (+ O(K log K) if sorted)
       • Space Complexity: O(1) auxiliary space (excluding result list)
   - Brute Force Approach:
       • Time Complexity:  O(N^2) - Checking all elements to the right for every index
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why is right-to-left traversal optimal?
   - Any element is a leader if and only if it is strictly greater than the 
     maximum element of its right suffix. By scanning from right to left, 
     we maintain this running maximum in O(1) per element.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. GeeksforGeeks: Leaders in an array (Easy)
2. LeetCode 1299: Replace Elements with Greatest Element on Right Side (Easy)
3. Coding Ninjas: Superior Elements (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Right-to-Left Scan with Running Maximum
# Time Complexity: O(N) | Space Complexity: O(1) auxiliary
# ============================================================================

def superior_element(a: List[int]) -> List[int]:
    """Finds all leaders in an array scanning from right to left."""
    ans: List[int] = []
    maxi = -float('inf')
    n = len(a)

    for i in range(n - 1, -1, -1):
        if a[i] > maxi:
            ans.append(a[i])
        maxi = max(maxi, a[i])

    # Sort in ascending order as typically requested
    ans.sort()
    return ans


def replace_elements(arr: List[int]) -> List[int]:
    """Replaces every element with the greatest element on its right (LeetCode 1299)."""
    n = len(arr)
    result = [0] * n
    max_right = -1

    for i in range(n - 1, -1, -1):
        result[i] = max_right
        max_right = max(max_right, arr[i])

    return result


# C++ Aliases
superiorElement = superior_element
replaceElements = replace_elements


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [1, 2, 2, 1]

    print("Original Array:", *arr)

    leaders = superior_element(arr)
    print("Leaders in array (Sorted):", *leaders)

    arr2 = [17, 18, 5, 4, 6, 1]
    print("\nOriginal Array for LeetCode 1299:", *arr2)
    replaced = replace_elements(arr2)
    print("Replaced with Greatest on Right: ", *replaced)
