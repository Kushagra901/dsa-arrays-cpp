"""
============================================================================
PROBLEM: Linear Search in an Array
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `arr` of `n` integers and an integer `num` (target), 
   find the index of the first occurrence of `num` in `arr`.
   If `num` is not present, return `-1`.

💡 COMPLEXITY ANALYSIS:
   - Time Complexity:
       • Best Case:    O(1) - Element is at index 0
       • Worst Case:   O(N) - Element is at last index or not present
       • Average Case: O(N)
   - Space Complexity: O(1) - Constant auxiliary memory

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. When should linear search be preferred over binary search?
   - When the array is unsorted and sorting overhead O(N log N) is unjustified,
     or when dealing with small data collections / streaming linked lists.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 704: Binary Search (Easy)
2. GeeksforGeeks: Search an Element in an array (Basic)
3. Coding Ninjas: Linear Search (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Linear Scan
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def linear_search(arr: List[int], n: int, num: int) -> int:
    """Performs linear search for target `num` in `arr`."""
    for i in range(n):
        if arr[i] == num:
            return i
    return -1


# C++ Alias
linearSearch = linear_search


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [6, 7, 8, 4, 1]
    n = len(arr)
    num = 4

    print("Array elements:", *arr)
    print(f"Target to search: {num}")

    index = linear_search(arr, n, num)

    if index != -1:
        print(f"Element {num} found at index: {index}")
    else:
        print(f"Element {num} not found in array.")
