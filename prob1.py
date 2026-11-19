"""
============================================================================
PROBLEM: Largest and Smallest Element in an Array
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array/list of integers `arr` of size `n`, find the largest 
   (maximum) and smallest (minimum) elements present in the array.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Single Pass / Linear Scan):
       • Time Complexity:  O(N) - Single traversal of array of size N
       • Space Complexity: O(1) - Constant auxiliary space
   - Brute Force Approach (Sorting):
       • Time Complexity:  O(N log N) - Sorting the array
       • Space Complexity: O(N) or O(1) depending on sorting implementation

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why is linear scan preferred over sorting to find the largest element?
   - Linear scan takes O(N) time and O(1) space, whereas sorting takes O(N log N)
     time. Modifying the array order may also violate requirements.

2. How do you handle an empty array or an array of size 1?
   - For size 1, the single element is both largest and smallest.
   - For size 0 (empty), raise ValueError or return None.

3. What if the array contains negative numbers or extreme values?
   - Initialize the tracking variable with `arr[0]` rather than `0` or `-infinity`
     to correctly handle all negative values.

4. What is the minimum number of comparisons needed to find BOTH min and max?
   - By comparing elements in pairs, we can find both min and max in 3*(N//2) comparisons
     instead of 2*N comparisons.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 414: Third Maximum Number (Easy)
2. LeetCode 215: Kth Largest Element in an Array (Medium)
3. GeeksforGeeks: Largest Element in Array (Basic)
4. GeeksforGeeks: Maximum and Minimum in an Array (Basic)
5. Coding Ninjas: Largest Element in the Array (Easy)
============================================================================
"""

from typing import List, Optional


# ============================================================================
# OPTIMAL APPROACH: Linear Scan
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def largest_element(arr: List[int], n: Optional[int] = None) -> int:
    """Finds the largest element in the array in a single linear pass."""
    if not arr:
        raise ValueError("Array cannot be empty")
    
    length = n if n is not None else len(arr)
    largest = arr[0]  # Initialize with first element
    
    for i in range(length):
        if arr[i] > largest:
            largest = arr[i]
            
    return largest


def smallest_element(arr: List[int], n: Optional[int] = None) -> int:
    """Finds the smallest element in the array in a single linear pass."""
    if not arr:
        raise ValueError("Array cannot be empty")
        
    length = n if n is not None else len(arr)
    smallest = arr[0]  # Initialize with first element
    
    for i in range(length):
        if arr[i] < smallest:
            smallest = arr[i]
            
    return smallest


# Aliases matching C++ signatures
largestElemnt = largest_element
smallestElement = smallest_element


# ============================================================================
# BRUTE FORCE APPROACH: Sorting
# Time Complexity: O(N log N) | Space Complexity: O(N) for sorted copy
# ============================================================================

def largest_element_sort(arr: List[int]) -> int:
    """Finds the largest element by sorting a copy of the array."""
    if not arr:
        raise ValueError("Array cannot be empty")
    sorted_arr = sorted(arr)
    return sorted_arr[-1]


largestElementSort = largest_element_sort


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [2, 5, 6, 2, 8, 9]
    n = len(arr)

    # Optimal Linear Scan
    largest = largest_element(arr, n)
    smallest = smallest_element(arr, n)

    print("Array elements:", *arr)
    print(f"Largest element is: {largest}")
    print(f"Smallest element is: {smallest}")
