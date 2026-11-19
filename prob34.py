"""
============================================================================
PROBLEM: Reverse Pairs (LeetCode 493)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an integer array `nums`, return the number of reverse pairs in the array.
   A reverse pair is a pair `(i, j)` where:
     - `0 <= i < j < nums.length`
     - `nums[i] > 2 * nums[j]`

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Modified Merge Sort with Separate Two-Pointer Counting):
       • Time Complexity:  O(2N log N) = O(N log N) - Count step takes O(N), merge takes O(N)
       • Space Complexity: O(N) auxiliary space during merge
   - Brute Force Approach (Nested Loops):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why CANNOT we count reverse pairs directly during the merge step like standard inversions?
   - In standard inversions, the condition is `arr[i] > arr[j]`.
   - Here, the condition is `arr[i] > 2 * arr[j]`. An element `arr[j]` that satisfies `arr[i] > 2 * arr[j]`
     does not necessarily mean elements can be merged simultaneously without altering relative sorted order.
     A separate linear two-pointer scan before merging guarantees correctness in O(N).

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 493: Reverse Pairs (Hard)
2. LeetCode 315: Count of Smaller Numbers After Self (Hard)
3. GeeksforGeeks: Inversion Count (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Modified Merge Sort with Separate Two-Pointer Counting
# Time Complexity: O(N log N) | Space Complexity: O(N)
# ============================================================================

def merge(arr: List[int], low: int, mid: int, high: int) -> None:
    """Standard merge step for two sorted subarrays."""
    temp: List[int] = []
    left = low
    right = mid + 1

    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1

    while left <= mid:
        temp.append(arr[left])
        left += 1

    while right <= high:
        temp.append(arr[right])
        right += 1

    for i in range(low, high + 1):
        arr[i] = temp[i - low]


def count_pairs(arr: List[int], low: int, mid: int, high: int) -> int:
    """Counts reverse pairs (arr[i] > 2 * arr[j]) across two sorted halves in O(N)."""
    right = mid + 1
    cnt = 0

    for i in range(low, mid + 1):
        while right <= high and arr[i] > 2 * arr[right]:
            right += 1
        cnt += (right - (mid + 1))

    return cnt


def merge_sort(arr: List[int], low: int, high: int) -> int:
    """Recursive merge sort accumulating reverse pair counts."""
    cnt = 0
    if low >= high:
        return cnt

    mid = (low + high) // 2
    cnt += merge_sort(arr, low, mid)
    cnt += merge_sort(arr, mid + 1, high)
    cnt += count_pairs(arr, low, mid, high)
    merge(arr, low, mid, high)

    return cnt


def team(skill: List[int], n: int) -> int:
    """Wrapper function returning total reverse pairs."""
    arr_copy = skill[:]
    return merge_sort(arr_copy, 0, n - 1)


# C++ Aliases
countPairs = count_pairs
mergeSort = merge_sort


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [4, 1, 2, 3, 1]
    n = len(arr)

    print("Skill array:", *arr)

    result = team(arr, n)
    print(f"Total Reverse Pairs (arr[i] > 2 * arr[j]): {result}")
