"""
============================================================================
PROBLEM: Union of Two Sorted Arrays
============================================================================

📌 PROBLEM DESCRIPTION:
   Given two sorted arrays `arr1` and `arr2` of sizes `n` and `m` respectively, 
   find the union of these two arrays.
   The union should contain distinct common and distinct individual elements 
   from both arrays in sorted order.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Two Pointers Merge):
       • Time Complexity:  O(n + m) - Single linear scan through both arrays
       • Space Complexity: O(n + m) to return the union list, O(1) auxiliary space
   - Brute Force Approach (Set / Tree Set):
       • Time Complexity:  O((n + m) log(n + m)) - Inserting elements into set
       • Space Complexity: O(n + m) - Set storage

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How do Two Pointers avoid duplicates during merge?
   - Before appending `arr1[i]` or `arr2[j]`, verify `union_arr[-1] != element`.

2. What if one array is exhausted earlier than the other?
   - Append remaining elements from the unfinished array, still checking for duplicates.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. GeeksforGeeks: Union of Two Sorted Arrays (Medium)
2. LeetCode 349: Intersection of Two Arrays (Easy)
3. Coding Ninjas: Merge 2 Sorted Array (Easy)
============================================================================
"""

from typing import List, Set


# ============================================================================
# 1. OPTIMAL APPROACH: Two Pointers Merge
# Time Complexity: O(n + m) | Space Complexity: O(n + m)
# ============================================================================

def find_union_optimal(arr1: List[int], arr2: List[int], n: int, m: int) -> List[int]:
    """Finds union of two sorted arrays using two pointers merge technique."""
    i = 0
    j = 0
    union_arr: List[int] = []

    while i < n and j < m:
        if arr1[i] <= arr2[j]:
            if not union_arr or union_arr[-1] != arr1[i]:
                union_arr.append(arr1[i])
            i += 1
        else:
            if not union_arr or union_arr[-1] != arr2[j]:
                union_arr.append(arr2[j])
            j += 1

    # Add remaining elements from arr1
    while i < n:
        if not union_arr or union_arr[-1] != arr1[i]:
            union_arr.append(arr1[i])
        i += 1

    # Add remaining elements from arr2
    while j < m:
        if not union_arr or union_arr[-1] != arr2[j]:
            union_arr.append(arr2[j])
        j += 1

    return union_arr


# ============================================================================
# 2. BRUTE FORCE APPROACH: Using Set
# Time Complexity: O((n + m) log(n + m)) | Space Complexity: O(n + m)
# ============================================================================

def find_union_set(arr1: List[int], arr2: List[int], n: int, m: int) -> List[int]:
    """Finds union using set and sorting."""
    s: Set[int] = set(arr1[:n]) | set(arr2[:m])
    return sorted(s)


# C++ Aliases
findUnion = find_union_optimal
findUnionSet = find_union_set


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    arr2 = [2, 3, 4, 4, 5, 11, 12]
    n = len(arr1)
    m = len(arr2)

    print("Array 1:", *arr1)
    print("Array 2:", *arr2)

    result = find_union_optimal(arr1, arr2, n, m)

    print("Union of arr1 and arr2:", *result)
