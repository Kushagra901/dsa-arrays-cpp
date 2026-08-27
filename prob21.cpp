/**
 * ============================================================================
 * PROBLEM: Best Time to Buy and Sell Stock (Single Transaction)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    You are given an array `prices` where `prices[i]` is the price of a given 
 *    stock on the `i-th` day. You want to maximize your profit by choosing a 
 *    single day to buy one stock and choosing a different day in the future 
 *    to sell that stock. Return the maximum profit you can achieve.
 *    If you cannot achieve any profit, return 0.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Greedy / Min Price Tracking):
 *        • Time Complexity:  O(N) - Single pass through the prices vector
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Brute Force Approach (Check all pairs):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does tracking the minimum price seen so far guarantee the optimal solution?
 *    - To maximize `prices[sell_day] - prices[buy_day]` for any chosen `sell_day`,
 *      `buy_day` must be the lowest price among all days prior to `sell_day`.
 * 
 * 2. How do other stock trading variations differ?
 *    - Buy and Sell Stock II (LeetCode 122): Unlimited transactions -> Add all positive price differences `max(0, prices[i] - prices[i-1])`.
 *    - Buy and Sell Stock III (LeetCode 123): At most 2 transactions -> Dynamic Programming with 4 states.
 *    - Buy and Sell Stock IV (LeetCode 188): At most K transactions -> DP with 2*k states.
 *    - Stock with Cooldown (LeetCode 309) & Transaction Fee (LeetCode 714).
 * 
 * 3. What if prices are monotonically decreasing (e.g. `[7, 6, 4, 3, 1]`)?
 *    - `maxProfit` remains 0 because no profitable transaction can be made.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 121: Best Time to Buy and Sell Stock (Easy)
 * 2. LeetCode 122: Best Time to Buy and Sell Stock II (Medium)
 * 3. LeetCode 123: Best Time to Buy and Sell Stock III (Hard)
 * 4. GeeksforGeeks: Stock Buy and Sell (Easy)
 * 5. Coding Ninjas: Best Time to Buy and Sell Stock (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Greedy Minimum Price Tracking
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int maximumProfit(const vector<int> &prices) {
    if (prices.empty()) return 0;

    int mini = prices[0]; // Tracks minimum buying price seen so far
    int maxProfit = 0;   // Tracks maximum profit achievable
    int n = prices.size();

    for (int i = 0; i < n; i++) {
        int cost = prices[i] - mini;       // Profit if sold on day i
        maxProfit = max(maxProfit, cost);  // Update max profit
        mini = min(mini, prices[i]);       // Update minimum buying price
    }

    return maxProfit;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Stock Prices: ";
    for (int p : prices) cout << p << " ";
    cout << endl;

    int result = maximumProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}