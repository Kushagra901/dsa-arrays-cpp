"""
============================================================================
PROBLEM: Single Number (Find the Element that Appears Once)
============================================================================

📌 PROBLEM DESCRIPTION:
   Given a non-empty array of integers `nums`, every element appears twice 
   except for one. Find that single one.
   You must implement a solution with a linear runtime complexity and use 
   only constant extra space.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Bitwise XOR):
       • Time Complexity:  O(N) - Single pass through array of size N
       • Space Complexity: O(1) - Constant auxiliary space
   - 2. Better 1 (Sorting):
       • Time Complexity:  O(N log N) - Sorting the array + linear check
       • Space Complexity: O(N) or O(1)
   - 3. Better 2 (Hashing):
       • Time Complexity:  O(N) - Hash map frequency counting
       • Space Complexity: O(N) - Auxiliary space for hash table
   - 4. Brute Force (Linear Scan for Pairs):
       • Time Complexity:  O(N^2) - For each element, count its occurrences
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does Bitwise XOR solve this problem in O(1) space?
   - `a ^ a = 0` (any number XORed with itself is 0)
   - `a ^ 0 = a` (any number XORed with 0 is itself)
   - Order does not matter (commutative & associative).
   - Duplicate pairs cancel: `(a ^ a) ^ (b ^ b) ^ c = 0 ^ 0 ^ c = c`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 136: Single Number (Easy)
2. LeetCode 137: Single Number II (Medium)
3. LeetCode 260: Single Number III (Medium)
============================================================================
"""

from typing import List, Dict


# ============================================================================
# 1. BRUTE FORCE APPROACH: Nested Counting
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def get_single_element_brute(arr: List[int]) -> int:
    """Counts occurrences of each element using nested loops."""
    n = len(arr)
    for i in range(n):
        count = 0
        for j in range(n):
            if arr[j] == arr[i]:
                count += 1
        if count == 1:
            return arr[i]
    return -1


# ============================================================================
# 2. BETTER APPROACH 1: Sorting
# Time Complexity: O(N log N) | Space Complexity: O(N)
# ============================================================================

def get_single_element_sort(arr: List[int]) -> int:
    """Sorts copy of array and checks adjacent pairs."""
    n = len(arr)
    if n == 1:
        return arr[0]

    sorted_arr = sorted(arr)
    for i in range(0, n, 2):
        if i == n - 1 or sorted_arr[i] != sorted_arr[i + 1]:
            return sorted_arr[i]

    return -1


# ============================================================================
# 3. BETTER APPROACH 2: Hashing
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def get_single_element_hash(arr: List[int]) -> int:
    """Counts frequency using a dictionary."""
    freq: Dict[int, int] = {}
    for x in arr:
        freq[x] = freq.get(x, 0) + 1

    for val, count in freq.items():
        if count == 1:
            return val
    return -1


# ============================================================================
# 4. OPTIMAL APPROACH: Bitwise XOR
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def get_single_element(arr: List[int]) -> int:
    """Finds unique element using bitwise XOR cancellation."""
    xorr = 0
    for num in arr:
        xorr ^= num
    return xorr


# C++ Aliases
getSingleElementBrute = get_single_element_brute
getSingleElementSort = get_single_element_sort
getSingleElementHash = get_single_element_hash
getSingleElement = get_single_element


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [4, 1, 2, 1, 2]

    print("Array elements:", *arr)

    print(f"Single Element (Brute Force): {get_single_element_brute(arr)}")
    print(f"Single Element (Sorting):     {get_single_element_sort(arr)}")
    print(f"Single Element (Hashing):     {get_single_element_hash(arr)}")
    print(f"Single Element (Bitwise XOR): {get_single_element(arr)}")
