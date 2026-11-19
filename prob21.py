"""
============================================================================
PROBLEM: Best Time to Buy and Sell Stock (Single Transaction)
============================================================================

📌 PROBLEM DESCRIPTION:
   You are given an array `prices` where `prices[i]` is the price of a given 
   stock on the `i-th` day. You want to maximize your profit by choosing a 
   single day to buy one stock and choosing a different day in the future 
   to sell that stock. Return the maximum profit you can achieve.
   If you cannot achieve any profit, return 0.

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Greedy / Min Price Tracking):
       • Time Complexity:  O(N) - Single pass through the prices list
       • Space Complexity: O(1) - Constant auxiliary space
   - Brute Force Approach (Check all pairs):
       • Time Complexity:  O(N^2)
       • Space Complexity: O(1)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does tracking the minimum price seen so far guarantee the optimal solution?
   - To maximize `prices[sell_day] - prices[buy_day]` for any chosen `sell_day`,
     `buy_day` must be the lowest price among all days prior to `sell_day`.

2. What if prices are monotonically decreasing (e.g. `[7, 6, 4, 3, 1]`)?
   - `max_profit` remains 0 because no profitable transaction can be made.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 121: Best Time to Buy and Sell Stock (Easy)
2. LeetCode 122: Best Time to Buy and Sell Stock II (Medium)
3. LeetCode 123: Best Time to Buy and Sell Stock III (Hard)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Greedy Minimum Price Tracking
# Time Complexity: O(N) | Space Complexity: O(1)
# ============================================================================

def maximum_profit(prices: List[int]) -> int:
    """Finds maximum profit with a single buy and sell transaction."""
    if not prices:
        return 0

    mini = prices[0]  # Minimum buying price seen so far
    max_profit = 0    # Maximum profit achievable

    for p in prices:
        cost = p - mini
        max_profit = max(max_profit, cost)
        mini = min(mini, p)

    return max_profit


# C++ Alias
maximumProfit = maximum_profit


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    prices = [7, 1, 5, 3, 6, 4]

    print("Stock Prices:", *prices)

    result = maximum_profit(prices)
    print(f"Maximum Profit: {result}")
