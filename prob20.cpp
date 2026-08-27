/**
 * ============================================================================
 * PROBLEM: Maximum Subarray Sum (Kadane's Algorithm)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `arr` of size `n`, find the contiguous subarray 
 *    (containing at least one number) which has the largest sum and return its sum.
 *    (Extended: Print the starting and ending indices of the maximum subarray).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Kadane's Algorithm):
 *        • Time Complexity:  O(N) - Single pass through the array
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Divide and Conquer Approach:
 *        • Time Complexity:  O(N log N)
 *        • Space Complexity: O(log N) recursion stack
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the core intuition behind Kadane's Algorithm?
 *    - A negative running sum will only decrease the sum of any future subarray.
 *      Therefore, whenever `sum < 0`, we discard the running subarray and reset `sum = 0`.
 * 
 * 2. How do you handle an array containing ONLY negative numbers (e.g. `[-5, -2, -8]`)?
 *    - Initialize `maxi = LONG_MIN` or `arr[0]`.
 *    - Update `maxi = max(maxi, sum)` BEFORE resetting `sum = 0`, OR only add to running sum if positive.
 *      This ensures the least negative number (e.g. -2) is correctly returned.
 * 
 * 3. How do you print the actual subarray yielding the maximum sum?
 *    - Maintain `start`, `ansStart`, and `ansEnd` pointers.
 *    - When `sum == 0`, set `start = i`.
 *    - When `sum > maxi`, set `ansStart = start` and `ansEnd = i`.
 * 
 * 4. What is the Maximum Product Subarray (LeetCode 152)?
 *    - Unlike sum, multiplying two negative numbers yields a positive number.
 *      Hence, we must maintain both running `max_product` and running `min_product`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 53: Maximum Subarray (Medium)
 * 2. LeetCode 918: Maximum Sum Circular Subarray (Medium)
 * 3. LeetCode 152: Maximum Product Subarray (Medium)
 * 4. GeeksforGeeks: Kadane's Algorithm (Medium)
 * 5. Coding Ninjas: Maximum Subarray Sum (Medium)
 * ============================================================================
 */

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Kadane's Algorithm
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

long long maxSubarraySum(int arr[], int n) {
    long long sum = 0;
    long long maxi = LONG_MIN; // Handles all-negative arrays

    int start = 0;
    int ansStart = -1, ansEnd = -1; // To track subarray indices

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // Potential new starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If running sum becomes negative, reset it to 0
        if (sum < 0) {
            sum = 0;
        }
    }

    return maxi;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}