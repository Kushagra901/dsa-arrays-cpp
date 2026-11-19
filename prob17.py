"""
============================================================================
PROBLEM: Two Sum (Check Pair with Given Target Sum)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of integers `book` of size `n` and an integer `target`, 
   determine whether there exists a pair of elements in the array whose sum 
   equals `target`. Return "YES" / True if such a pair exists, otherwise "NO" / False.
   (Variation 2: Return the 0-based indices of the two elements).

💡 COMPLEXITY ANALYSIS:
   - Optimal for Returning Boolean (Hash Map):
       • Time Complexity:  O(N) single pass
       • Space Complexity: O(N) auxiliary space
   - Optimal for Returning YES/NO (Sorting + Two Pointers):
       • Time Complexity:  O(N log N) for sorting + O(N) for two pointers = O(N log N)
       • Space Complexity: O(1) auxiliary space (or O(N) for sorted copy)
   - Optimal for Returning INDICES (Hash Map):
       • Time Complexity:  O(N) single pass
       • Space Complexity: O(N) auxiliary space for hash map

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does Hash Map achieve O(N) time for Two Sum?
   - For each element `x`, checking if `target - x` is already in the map takes O(1) average time.

2. Why is Two-Pointer preferred when only a boolean ("YES"/"NO") is required and space is restricted?
   - Sorting + Two Pointers uses O(1) extra space without hash collision or allocation overhead.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 1: Two Sum (Easy)
2. LeetCode 167: Two Sum II - Input Array Is Sorted (Medium)
3. LeetCode 15: 3Sum (Medium)
============================================================================
"""

from typing import List, Dict


# ============================================================================
# 1. TWO POINTERS APPROACH: (Returns YES/NO using O(1) extra space)
# Time Complexity: O(N log N) | Space Complexity: O(1) auxiliary
# ============================================================================

def read(n: int, book: List[int], target: int) -> str:
    """Returns 'YES' if pair summing to target exists, else 'NO'."""
    sorted_book = sorted(book)  # Sort copy
    left = 0
    right = n - 1

    while left < right:
        curr_sum = sorted_book[left] + sorted_book[right]
        if curr_sum == target:
            return "YES"
        elif curr_sum < target:
            left += 1  # Need larger sum
        else:
            right -= 1  # Need smaller sum

    return "NO"


# ============================================================================
# 2. HASH MAP APPROACH: (Returns Boolean in O(N) time)
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def two_sum(arr: List[int], target: int) -> bool:
    """Returns True if any pair sums to target using hash map."""
    num_map: Dict[int, int] = {}
    for i, num in enumerate(arr):
        complement = target - num
        if complement in num_map:
            return True
        num_map[num] = i
    return False


# ============================================================================
# 3. HASH MAP APPROACH: (Returns Indices in O(N) time)
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def two_sum_indices(nums: List[int], target: int) -> List[int]:
    """Returns 0-based indices of two numbers that add up to target."""
    mpp: Dict[int, int] = {}  # {element -> index}

    for i, num in enumerate(nums):
        complement = target - num
        if complement in mpp:
            return [mpp[complement], i]
        mpp[num] = i

    return [-1, -1]


# C++ Aliases
twoSum = two_sum
twoSumIndices = two_sum_indices


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    book = [4, 1, 2, 3, 1]
    n = len(book)
    target = 5

    print("Array elements:", *book)
    print(f"Target: {target}")

    result = read(n, book, target)
    print(f"Pair with target sum exists (Two Pointers): {result}")

    exists_bool = two_sum(book, target)
    print(f"Pair with target sum exists (Hash Map bool): {exists_bool}")

    indices = two_sum_indices(book, target)
    print(f"Indices of pair: [{indices[0]}, {indices[1]}]")
