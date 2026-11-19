"""
============================================================================
PROBLEM: Find Second Largest and Second Smallest Element in an Array
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `a` of size `n`, find the second largest and 
   second smallest elements. If no such element exists (e.g., all elements 
   are identical or size < 2), return -1.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Single-Pass Traversal):
       • Time Complexity:  O(N) - Single loop over array of size N
       • Space Complexity: O(1) - Constant auxiliary space
   - 2. Better Approach (Two-Pass Traversal):
       • Time Complexity:  O(2N) = O(N) - Pass 1 finds max/min, Pass 2 finds 2nd max/min
       • Space Complexity: O(1)
   - 3. Brute Force Approach (Sorting):
       • Time Complexity:  O(N log N) - Sorting followed by backward/forward linear scans
       • Space Complexity: O(N) for sorted copy or O(1) in-place

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why is the single-pass approach preferred over sorting or two-pass?
   - Single pass visits each memory location once, maximizing cache locality
     and cutting comparisons in half compared to two-pass.

2. How are duplicate values handled?
   - Conditions strictly check `a[i] < largest and a[i] > slargest` ensuring strict
     second maximum and not just duplicate of maximum.

3. What if all elements in the array are equal?
   - Returns -1 because no distinct second largest/smallest exists.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 414: Third Maximum Number (Easy)
2. GeeksforGeeks: Second Largest (Easy)
3. Coding Ninjas: Second Largest Number (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. OPTIMAL APPROACH: Single-Pass Traversal
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def second_largest(a: List[int], n: int) -> int:
    """Finds the second largest element in a single pass."""
    if n < 2:
        return -1

    largest = a[0]
    slargest = -float('inf')

    for i in range(1, n):
        if a[i] > largest:
            slargest = largest  # Previous largest becomes second largest
            largest = a[i]      # Current element is new largest
        elif a[i] < largest and a[i] > slargest:
            slargest = a[i]     # Element between largest and second largest

    return -1 if slargest == -float('inf') else int(slargest)


def second_smallest(a: List[int], n: int) -> int:
    """Finds the second smallest element in a single pass."""
    if n < 2:
        return -1

    smallest = a[0]
    ssmallest = float('inf')

    for i in range(1, n):
        if a[i] < smallest:
            ssmallest = smallest  # Previous smallest becomes second smallest
            smallest = a[i]       # Current element is new smallest
        elif a[i] != smallest and a[i] < ssmallest:
            ssmallest = a[i]      # Element between smallest and second smallest

    return -1 if ssmallest == float('inf') else int(ssmallest)


def get_second_order_elements(n: int, a: List[int]) -> List[int]:
    """Returns both second largest and second smallest in a list [slargest, ssmallest]."""
    slargest = second_largest(a, n)
    ssmallest = second_smallest(a, n)
    return [slargest, ssmallest]


# ============================================================================
# 2. BETTER APPROACH: Two-Pass Traversal
# Time Complexity: O(2N) = O(N) | Space Complexity: O(1)
# ============================================================================

def sec_lar_two_pass(a: List[int], n: int) -> int:
    """Two-pass approach: first find max, then find max ignoring largest."""
    if n < 2:
        return -1

    largest = a[0]
    for i in range(1, n):
        if a[i] > largest:
            largest = a[i]

    slargest = -float('inf')
    for i in range(n):
        if a[i] > slargest and a[i] != largest:
            slargest = a[i]

    return -1 if slargest == -float('inf') else int(slargest)


# ============================================================================
# 3. BRUTE FORCE APPROACH: Sorting
# Time Complexity: O(N log N) | Space Complexity: O(N)
# ============================================================================

def sec_lar_sorting(a: List[int], n: int) -> int:
    """Sorting approach: sorts array copy and scans backward for first distinct element."""
    if n < 2:
        return -1

    sorted_arr = sorted(a)
    largest = sorted_arr[-1]

    for i in range(n - 2, -1, -1):
        if sorted_arr[i] != largest:
            return sorted_arr[i]

    return -1


# C++ Aliases
secondLargest = second_largest
secondSmallest = second_smallest
getSecondOrderElement = get_second_order_elements
secLarTwoPass = sec_lar_two_pass
secLarSorting = sec_lar_sorting


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [1, 2, 4, 7, 7, 5]
    n = len(arr)

    print("Array elements:", *arr)

    sl = second_largest(arr, n)
    ss = second_smallest(arr, n)
    print(f"Second Largest (Optimal Single-Pass):  {sl}")
    print(f"Second Smallest (Optimal Single-Pass): {ss}")

    result = get_second_order_elements(n, arr)
    print(f"Second Order Elements [2nd Largest, 2nd Smallest]: [{result[0]}, {result[1]}]")

    print(f"Second Largest (Better Two-Pass):      {sec_lar_two_pass(arr, n)}")
    print(f"Second Largest (Brute Force Sorting):  {sec_lar_sorting(arr, n)}")
