/**
 * ============================================================================
 * PROBLEM: Maximum Product Subarray
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `arr`, find a contiguous non-empty subarray within 
 *    the array that has the largest product, and return the product.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Prefix and Suffix Product Traversal):
 *        • Time Complexity:  O(N) - Single pass calculating running prefix and suffix products
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Dynamic Programming Approach (Tracking min_prod and max_prod):
 *        • Time Complexity:  O(N)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does Kadane's standard sum algorithm not work directly for product?
 *    - In addition, negative numbers strictly decrease the sum.
 *    - In multiplication, a negative number multiplied by another negative number becomes a large POSITIVE number!
 * 
 * 2. Why does the Prefix and Suffix Product approach work?
 *    - Case 1 (All positive): Product of entire array is maximum.
 *    - Case 2 (Even count of negatives): Product of entire array is positive and maximum.
 *    - Case 3 (Odd count of negatives): Removing ONE negative number leaves an even number of negatives.
 *      The maximum product subarray MUST be either a prefix ending before that odd negative or a suffix starting after it!
 *    - Case 4 (Zeroes present): Zero splits array into smaller subarrays; we reset `prefix = 1` and `suffix = 1` whenever `0` is hit.
 * 
 * 3. What if an array has all negative numbers, e.g. `[-2]`?
 *    - `ans` initialized to `INT_MIN` will correctly return `-2`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 152: Maximum Product Subarray (Medium)
 * 2. LeetCode 53: Maximum Subarray (Medium)
 * 3. GeeksforGeeks: Maximum Product Subarray (Medium)
 * 4. Coding Ninjas: Maximum Product Subarray (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Prefix and Suffix Product Traversal
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int subarrayProduct(const vector<int> &arr) {
    int pre = 1, suff = 1;
    int n = arr.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        // If prefix or suffix product becomes 0, reset to 1
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;

        pre = pre * arr[i];              // Forward product from start
        suff = suff * arr[n - i - 1];    // Backward product from end

        ans = max(ans, max(pre, suff));
    }
    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {2, 3, -4, 5};

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int result = subarrayProduct(arr);
    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}