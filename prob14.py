"""
============================================================================
PROBLEM: Maximum Consecutive Ones
============================================================================

📌 PROBLEM DESCRIPTION:
   Given a binary array `nums` containing only `0`s and `1`s, return the 
   maximum number of consecutive `1`s in the array.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Running Counter Scan):
       • Time Complexity:  O(N) - Single linear traversal through array
       • Space Complexity: O(1) - Constant auxiliary space

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. What is the state machine transition?
   - On `1`: increment streak counter `cnt += 1`, update global max `maxi = max(maxi, cnt)`.
   - On `0`: reset streak counter `cnt = 0`.

2. What is the extension "Max Consecutive Ones III" (LeetCode 1004)?
   - You can flip at most K zeroes. Solved using sliding window: maintain a window
     containing at most `k` zeroes in O(N) time and O(1) space.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 485: Max Consecutive Ones (Easy)
2. LeetCode 487: Max Consecutive Ones II (Medium)
3. LeetCode 1004: Max Consecutive Ones III (Medium)
4. GeeksforGeeks: Maximum Consecutive Ones (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Linear Counter Scan
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def find_max_consecutive_ones(nums: List[int]) -> int:
    """Finds maximum streak of consecutive 1s in binary list."""
    maxi = 0  # Global max streak
    cnt = 0   # Current running streak

    for num in nums:
        if num == 1:
            cnt += 1
            maxi = max(maxi, cnt)
        else:
            cnt = 0  # Reset on 0

    return maxi


# C++ Alias
findMaxConsecutiveOnes = find_max_consecutive_ones


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    nums = [1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1]

    print("Binary Array:", *nums)

    result = find_max_consecutive_ones(nums)

    print(f"Max Consecutive Ones: {result}")
