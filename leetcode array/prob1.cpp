/**
 * ============================================================================
 * PROBLEM: Find Minimum and Maximum Element in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `arr` of size `n`, find the minimum and maximum 
 *    elements in the array with the minimum number of comparisons.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (Sorting):
 *        • Time Complexity:  O(N log N) - Sorting the array
 *        • Space Complexity: O(1) or O(N) depending on sort
 *        • Total Comparisons: O(N log N)
 *    - 2. Standard Linear Scan:
 *        • Time Complexity:  O(N) - Comparing every element with both min and max
 *        • Space Complexity: O(1) - Constant auxiliary space
 *        • Total Comparisons: 2 * (N - 1) in worst case
 *    - 3. Optimal Approach (Pairwise Comparison / Tournament Method):
 *        • Time Complexity:  O(N) - Comparing elements in pairs
 *        • Space Complexity: O(1) - Constant auxiliary space
 *        • Total Comparisons: 3 * (N / 2) = 1.5 * N comparisons (optimal!)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the theoretical lower bound on comparisons to find both min and max?
 *    - The theoretical minimum number of comparisons is `ceil(3N / 2) - 2`.
 *    - By comparing adjacent elements `arr[i]` and `arr[i + 1]` first (1 comparison),
 *      we then compare the larger with `maxVal` and the smaller with `minVal` (2 comparisons).
 *      This gives 3 comparisons per 2 elements.
 * 
 * 2. How does the Divide and Conquer (Tournament) approach work?
 *    - Recursively divide the array into halves, find (min1, max1) and (min2, max2),
 *      then combine: `min = min(min1, min2)` and `max = max(max1, max2)`.
 *    - Total comparisons also equals `3N/2 - 2`.
 * 
 * 3. How do we initialize variables safely against extreme inputs?
 *    - Rather than using `INT_MAX` and `INT_MIN`, initializing with `arr[0]`
 *      ensures safety even if array contains `INT_MAX` or `INT_MIN`.
 * 
 * 4. What if the array has only 1 element?
 *    - If `n == 1`, both minimum and maximum are `arr[0]`, requiring 0 comparisons.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Find minimum and maximum element in an array (Basic)
 * 2. LeetCode 414: Third Maximum Number (Easy)
 * 3. LeetCode 215: Kth Largest Element in an Array (Medium)
 * 4. Coding Ninjas: Min and Max Element (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================================================
// 1. STANDARD LINEAR SCAN APPROACH
// Time Complexity: O(N) | Comparisons: 2 * (N - 1) | Space Complexity: O(1)
// ============================================================================

pair<int, int> minMaxLinear(const vector<int> &arr, int n) {
    if (n == 0) return {0, 0};

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        } else if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return {minVal, maxVal};
}

// ============================================================================
// 2. OPTIMAL APPROACH: Pairwise Comparison (Minimizes Total Comparisons)
// Time Complexity: O(N) | Comparisons: ~1.5 * N | Space Complexity: O(1)
// ============================================================================

pair<int, int> minMaxPairwise(const vector<int> &arr, int n) {
    if (n == 0) return {0, 0};
    if (n == 1) return {arr[0], arr[0]};

    int minVal, maxVal;
    int i = 0;

    // If n is odd, initialize min and max with arr[0] and start pairing from index 1
    if (n % 2 != 0) {
        minVal = arr[0];
        maxVal = arr[0];
        i = 1;
    } 
    // If n is even, compare first two elements to initialize min and max
    else {
        if (arr[0] < arr[1]) {
            minVal = arr[0];
            maxVal = arr[1];
        } else {
            minVal = arr[1];
            maxVal = arr[0];
        }
        i = 2;
    }

    // Process remaining elements in pairs
    while (i < n - 1) {
        // Step 1: 1 comparison between pair elements
        if (arr[i] < arr[i + 1]) {
            // Step 2: 2 comparisons against running min and max
            minVal = min(minVal, arr[i]);
            maxVal = max(maxVal, arr[i + 1]);
        } else {
            minVal = min(minVal, arr[i + 1]);
            maxVal = max(maxVal, arr[i]);
        }
        i += 2;
    }

    return {minVal, maxVal};
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {2, 5, 6, 2, 8, 9, 1, 14, -3};
    int n = arr.size();

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Linear Scan
    pair<int, int> res1 = minMaxLinear(arr, n);
    cout << "Linear Scan      -> Min: " << res1.first << ", Max: " << res1.second << endl;

    // Optimal Pairwise Scan
    pair<int, int> res2 = minMaxPairwise(arr, n);
    cout << "Optimal Pairwise -> Min: " << res2.first << ", Max: " << res2.second << endl;

    return 0;
}