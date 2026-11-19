"""
============================================================================
PROBLEM: Count Inversions in an Array (Modified Merge Sort)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `a`, count the number of inversions.
   An inversion is defined as a pair of indices `(i, j)` such that 
   `i < j` and `a[i] > a[j]`.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Modified Merge Sort):
       • Time Complexity:  O(N log N) - Dividing into halves and merging in linear time
       • Space Complexity: O(N) auxiliary space for temporary array during merge
   - Brute Force Approach (Check all pairs):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does Merge Sort count inversions in O(N log N)?
   - When merging two sorted halves `arr[low..mid]` and `arr[mid+1..high]`, 
     if `arr[left] > arr[right]`, then because the left half is SORTED, all elements 
     from `left` to `mid` are strictly greater than `arr[right]`.
     Thus, we add `(mid - left + 1)` to the inversion count in one step!

2. What is the maximum possible number of inversions for an array of size N?
   - For a reverse sorted array `[N, N-1, ... 1]`, max inversions = `N * (N - 1) // 2`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. GeeksforGeeks: Inversion of array (Medium)
2. Coding Ninjas: Count Inversions (Medium)
3. LeetCode 493: Reverse Pairs (Hard)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Modified Merge Sort
# Time Complexity: O(N log N) | Space Complexity: O(N)
# ============================================================================

def merge(arr: List[int], low: int, mid: int, high: int) -> int:
    """Merges two sorted halves [low..mid] and [mid+1..high] and counts cross-inversions."""
    temp: List[int] = []
    left = low
    right = mid + 1
    cnt = 0

    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            # arr[left] > arr[right] -> all elements from left to mid form inversions with arr[right]
            temp.append(arr[right])
            cnt += (mid - left + 1)
            right += 1

    while left <= mid:
        temp.append(arr[left])
        left += 1

    while right <= high:
        temp.append(arr[right])
        right += 1

    for i in range(low, high + 1):
        arr[i] = temp[i - low]

    return cnt


def merge_sort(arr: List[int], low: int, high: int) -> int:
    """Recursively sorts halves and accumulates total inversion count."""
    cnt = 0
    if low >= high:
        return cnt

    mid = (low + high) // 2
    cnt += merge_sort(arr, low, mid)
    cnt += merge_sort(arr, mid + 1, high)
    cnt += merge(arr, low, mid, high)

    return cnt


def number_of_inversions(a: List[int], n: int) -> int:
    """Wrapper function to calculate total number of inversions."""
    arr_copy = a[:]
    return merge_sort(arr_copy, 0, n - 1)


# C++ Aliases
mergeSort = merge_sort
numberOfInversions = number_of_inversions


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    a = [5, 4, 3, 2, 1]
    n = len(a)

    print("Array elements:", *a)

    inv_count = number_of_inversions(a, n)
    print(f"The number of inversions is: {inv_count}")
