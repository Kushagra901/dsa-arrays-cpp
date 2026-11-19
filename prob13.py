"""
============================================================================
PROBLEM: Find Missing Number in an Array
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array `arr` containing `N - 1` distinct numbers in the range `[1, N]`,
   find the one missing number in the array.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Bitwise XOR):
       • Time Complexity:  O(N) - Single pass
       • Space Complexity: O(1) - Constant auxiliary space, overflow-safe
   - 2. Optimal Approach (Mathematical Sum):
       • Time Complexity:  O(N) - Single pass
       • Space Complexity: O(1)
   - 3. Better Approach (Hashing / Frequency Array):
       • Time Complexity:  O(N)
       • Space Complexity: O(N)
   - 4. Brute Force Approach (Exhaustive Search):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why is Bitwise XOR preferred over Mathematical Sum?
   - In languages like C++, `N * (N + 1) // 2` can overflow a 32-bit signed integer when N >= 10^5.
     XOR operates bitwise and never suffers from overflow.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 268: Missing Number (Easy)
2. GeeksforGeeks: Missing number in array (Easy)
3. Coding Ninjas: Missing Number (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# 1. BRUTE FORCE APPROACH: Exhaustive Search
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def missing_number_brute_force(arr: List[int]) -> int:
    """Linearly searches for every number from 1 to N."""
    n = len(arr) + 1
    for i in range(1, n + 1):
        if i not in arr:
            return i
    return -1


# ============================================================================
# 2. BETTER APPROACH: Hashing with Frequency Array
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def missing_number_hashing(arr: List[int]) -> int:
    """Uses a frequency tracker list."""
    n = len(arr) + 1
    freq = [0] * (n + 1)

    for num in arr:
        freq[num] += 1

    for i in range(1, n + 1):
        if freq[i] == 0:
            return i
    return -1


# ============================================================================
# 3. MATHEMATICAL SUMMATION APPROACH
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def missing_number_sum(arr: List[int]) -> int:
    """Calculates difference between expected Gauss sum and actual sum."""
    n = len(arr) + 1
    expected_sum = (n * (n + 1)) // 2
    actual_sum = sum(arr)
    return expected_sum - actual_sum


# ============================================================================
# 4. OPTIMAL APPROACH: Bitwise XOR (Overflow-Safe)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def missing_number_xor(arr: List[int]) -> int:
    """Uses bitwise XOR cancellation."""
    n = len(arr) + 1
    xor1 = 0  # XOR of 1..N
    xor2 = 0  # XOR of array elements

    for i in range(len(arr)):
        xor2 ^= arr[i]
        xor1 ^= (i + 1)
    xor1 ^= n

    return xor1 ^ xor2


# C++ Aliases
missingNumberBruteForce = missing_number_brute_force
missingNumberHashing = missing_number_hashing
missingNumberSum = missing_number_sum
missingNumberXOR = missing_number_xor


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [8, 2, 4, 5, 3, 7, 1]  # Missing is 6 from range 1..8

    print("Array elements:", *arr)
    print(f"Range: 1 to {len(arr) + 1}")

    print(f"Missing Number (Brute Force): {missing_number_brute_force(arr)}")
    print(f"Missing Number (Hashing):     {missing_number_hashing(arr)}")
    print(f"Missing Number (Sum Formula): {missing_number_sum(arr)}")
    print(f"Missing Number (Bitwise XOR): {missing_number_xor(arr)}")
