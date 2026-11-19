"""
============================================================================
PROBLEM: Find the Repeating and Missing Number (Missing and Repeating)
============================================================================

📌 PROBLEM DESCRIPTION:
   You are given a read-only array of `n` integers from `1` to `n`. 
   Each integer appears exactly once, except `A` which appears twice and `B` 
   which is missing. Find `A` (repeating) and `B` (missing).

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Mathematical Equations S and S^2):
       • Time Complexity:  O(N) - Single pass summing elements and squares
       • Space Complexity: O(1) - Constant auxiliary space
   - 2. Alternative Optimal (Bitwise XOR):
       • Time Complexity:  O(N) - 2 linear passes
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How does the Mathematical Equation approach derive X and Y?
   - Let S_N = N * (N + 1) // 2 and S_2N = N * (N + 1) * (2 * N + 1) // 6.
   - Let S = sum(a) and S_2 = sum(x^2 for x in a).
   - Equation 1: S - S_N = X - Y (val1).
   - Equation 2: S_2 - S_2N = X^2 - Y^2 = (X - Y) * (X + Y) = val1 * (X + Y).
   - Thus: X + Y = (S_2 - S_2N) // val1 (val2).
   - Solving: X = (val1 + val2) // 2 and Y = X - val1.

2. Why is Python advantageous for this calculation?
   - In C++, `sum of squares` for N = 10^5 can exceed 32-bit `INT_MAX`, requiring `long long`.
     In Python, integers have arbitrary precision, preventing overflow inherently!

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. GeeksforGeeks: Missing And Repeating (Medium)
2. LeetCode 268: Missing Number (Easy)
3. LeetCode 287: Find the Duplicate Number (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# 1. OPTIMAL APPROACH: Mathematical Equations (S and S^2)
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def find_missing_and_repeating_math(a: List[int]) -> List[int]:
    """Finds [repeating, missing] using sum and sum of squares equations."""
    n = len(a)

    # Sum of first N natural numbers
    sn = (n * (n + 1)) // 2

    # Sum of squares of first N natural numbers
    s2n = (n * (n + 1) * (2 * n + 1)) // 6

    s = sum(a)
    s2 = sum(x * x for x in a)

    # val1 = X - Y
    val1 = s - sn

    # val2 = X^2 - Y^2 = (X - Y)(X + Y) -> X + Y = (S2 - S2N) // val1
    val2 = (s2 - s2n) // val1

    # X = ((X - Y) + (X + Y)) // 2
    x = (val1 + val2) // 2

    # Y = X - (X - Y)
    y = x - val1

    return [x, y]  # [Repeating X, Missing Y]


# ============================================================================
# 2. ALTERNATIVE OPTIMAL APPROACH: Bitwise XOR
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def find_missing_and_repeating_xor(a: List[int]) -> List[int]:
    """Finds [repeating, missing] using bitwise XOR differentiation."""
    n = len(a)
    xr = 0

    for i in range(n):
        xr ^= a[i]
        xr ^= (i + 1)

    # Get rightmost set bit
    number = xr & ~(xr - 1)

    zero_group = 0
    one_group = 0

    for i in range(n):
        if (a[i] & number) != 0:
            one_group ^= a[i]
        else:
            zero_group ^= a[i]

        if ((i + 1) & number) != 0:
            one_group ^= (i + 1)
        else:
            zero_group ^= (i + 1)

    # Count occurrences to distinguish repeating from missing
    count = a.count(zero_group)

    if count == 2:
        return [zero_group, one_group]
    return [one_group, zero_group]


# C++ Aliases
findMissingAndRepeatingMath = find_missing_and_repeating_math
findMissingAndRepeatingXOR = find_missing_and_repeating_xor


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    a = [3, 1, 2, 5, 4, 6, 7, 5]

    print("Array elements:", *a)

    ans_math = find_missing_and_repeating_math(a)
    print(f"The repeating and missing numbers (Math) are: {{Repeating: {ans_math[0]}, Missing: {ans_math[1]}}}")

    ans_xor = find_missing_and_repeating_xor(a)
    print(f"The repeating and missing numbers (XOR)  are: {{Repeating: {ans_xor[0]}, Missing: {ans_xor[1]}}}")
