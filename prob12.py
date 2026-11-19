"""
============================================================================
PROBLEM: Intersection of Two Sorted Arrays
============================================================================

📌 PROBLEM DESCRIPTION:
   Given two sorted arrays `A` and `B` of sizes `m` and `n` respectively, 
   find the intersection of these two arrays.
   The intersection contains elements that are present in both arrays.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Two Pointers):
       • Time Complexity:  O(m + n) - Single linear traversal of both arrays
       • Space Complexity: O(1) auxiliary space (excluding result list)
   - Brute Force Approach (Visited Array):
       • Time Complexity:  O(m * n)
       • Space Complexity: O(n) - Visited array for tracking matched elements

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What if one array is very large (e.g. 1 billion elements) and the other is small (e.g. 100 elements)?
   - Instead of two pointers O(M + N), perform Binary Search for each of the 100 elements 
     in the large sorted array in O(K * log M) time.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 349: Intersection of Two Arrays (Easy)
2. LeetCode 350: Intersection of Two Arrays II (Easy)
3. GeeksforGeeks: Intersection of two sorted arrays (Easy)
4. Coding Ninjas: Intersection Of Two Sorted Arrays (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. OPTIMAL APPROACH: Two Pointers
# Time Complexity: O(m + n) | Space Complexity: O(1) auxiliary
# ============================================================================

def find_array_intersection(a: List[int], b: List[int]) -> List[int]:
    """Finds intersection of two sorted arrays using two pointers."""
    i = 0
    j = 0
    m = len(a)
    n = len(b)
    ans: List[int] = []

    while i < m and j < n:
        if a[i] < b[j]:
            i += 1  # Element in A is smaller
        elif b[j] < a[i]:
            j += 1  # Element in B is smaller
        else:
            ans.append(a[i])  # Common element found
            i += 1
            j += 1

    return ans


# ============================================================================
# 2. BRUTE FORCE APPROACH: Using Visited Array
# Time Complexity: O(m * n) | Space Complexity: O(n)
# ============================================================================

def find_array_intersection_brute(a: List[int], b: List[int]) -> List[int]:
    """Finds intersection using nested loops and a visited tracker."""
    ans: List[int] = []
    m = len(a)
    n = len(b)
    visited = [0] * n

    for i in range(m):
        for j in range(n):
            if b[j] > a[i]:
                break  # Sorted property

            if a[i] == b[j] and not visited[j]:
                ans.append(a[i])
                visited[j] = 1
                break

    return ans


# C++ Aliases
findArrayIntersection = find_array_intersection
findArrayIntersectionBrute = find_array_intersection_brute


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    A = [1, 2, 3, 4, 5, 6]
    B = [3, 4, 5, 6, 7]

    print("Array A:", *A)
    print("Array B:", *B)

    result = find_array_intersection(A, B)

    print("Intersection of A and B:", *result)
