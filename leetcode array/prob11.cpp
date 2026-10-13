/**
 * ============================================================================
 * PROBLEM: Maximum Length of Subarray With Positive Product (LeetCode 1567)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `nums`, find the maximum length of a subarray 
 *    where the product of all its elements is strictly positive.
 *    A subarray is a contiguous sequence of elements within an array.
 *    Return the maximum length of such a subarray.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(N^2) - Count negative numbers across all subarrays until 0
 *        • Space Complexity: O(1)
 *    - 2. Better Approach (Zero-Segment Partitioning):
 *        • Time Complexity:  O(N) - Process zero-free segments tracking first & last negative
 *        • Space Complexity: O(1)
 *    - 3. Optimal Approach (Dynamic Programming State Transition):
 *        • Time Complexity:  O(N) - Single pass through the array
 *        • Space Complexity: O(1) - Two tracking counters (posCount, negCount)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How do positive and negative numbers transition DP states?
 *    - At `nums[i] > 0`:
 *        • Extending a positive product remains positive: `posCount++`.
 *        • Extending a negative product remains negative: `negCount = (negCount == 0 ? 0 : negCount + 1)`.
 *    - At `nums[i] < 0`:
 *        • Multiplying a negative product by negative becomes positive: `pos = (negCount == 0 ? 0 : negCount + 1)`.
 *        • Multiplying a positive product by negative becomes negative: `neg = oldPos + 1`.
 *    - At `nums[i] == 0`:
 *        • Any product with 0 is 0 (neither positive nor negative): reset both `posCount = 0, negCount = 0`.
 * 
 * 2. Why can't we just compute the product directly?
 *    - Subarray products can quickly overflow `long long` or even 128-bit integers.
 *      Tracking signs and counts eliminates all integer overflow.
 * 
 * 3. What if all elements are negative?
 *    - Even number of negatives produces a positive product.
 *    - Odd number of negatives: maximum length is `n - 1` (dropping either first or last negative).
 * 
 * 4. What is the relation to LeetCode 152: Maximum Product Subarray?
 *    - LeetCode 152 maximizes the product VALUE.
 *    - LeetCode 1567 maximizes the subarray LENGTH with positive product.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1567: Maximum Length of Subarray With Positive Product (Medium)
 * 2. LeetCode 152: Maximum Product Subarray (Medium)
 * 3. LeetCode 53: Maximum Subarray (Easy)
 * 4. LeetCode 713: Subarray Product Less Than K (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int getMaxLenBrute(const vector<int> &nums) {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int negCount = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == 0) {
                break; // Product becomes 0
            }
            if (nums[j] < 0) {
                negCount++;
            }
            if (negCount % 2 == 0) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// ============================================================================
// 2. BETTER APPROACH: Segment Splitting by Zeroes
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int getMaxLenSegment(const vector<int> &nums) {
    int n = nums.size();
    int maxLength = 0;
    int start = 0;

    while (start < n) {
        // Skip leading zeroes
        while (start < n && nums[start] == 0) {
            start++;
        }
        if (start >= n) break;

        int end = start;
        int negCount = 0;
        int firstNeg = -1;
        int lastNeg = -1;

        // Traverse segment until next zero or end
        while (end < n && nums[end] != 0) {
            if (nums[end] < 0) {
                negCount++;
                if (firstNeg == -1) firstNeg = end;
                lastNeg = end;
            }
            end++;
        }

        // If even number of negative numbers, whole segment has positive product
        if (negCount % 2 == 0) {
            maxLength = max(maxLength, end - start);
        } else {
            // Drop either prefix ending at first negative, or suffix starting at last negative
            maxLength = max(maxLength, end - firstNeg - 1);
            maxLength = max(maxLength, lastNeg - start);
        }
        start = end + 1;
    }

    return maxLength;
}

// ============================================================================
// 3. OPTIMAL APPROACH: Dynamic Programming State Tracking
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int getMaxLen(const vector<int> &nums) {
    int n = nums.size();
    int maxLength = 0;
    int posCount = 0; // Length of longest positive product subarray ending at current index
    int negCount = 0; // Length of longest negative product subarray ending at current index

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            posCount++;
            negCount = (negCount == 0) ? 0 : negCount + 1;
        } 
        else if (nums[i] < 0) {
            int tempPos = posCount;
            posCount = (negCount == 0) ? 0 : negCount + 1;
            negCount = tempPos + 1;
        } 
        else { // nums[i] == 0
            posCount = 0;
            negCount = 0;
        }

        maxLength = max(maxLength, posCount);
    }

    return maxLength;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {1, -2, -3, 4};
    vector<int> nums2 = {0, 1, -2, -3, -4};
    vector<int> nums3 = {-1, -2, -3, 0, 1};

    cout << "Test 1: {1, -2, -3, 4} -> " << getMaxLen(nums1) << " (Expected: 4)" << endl;
    cout << "Test 2: {0, 1, -2, -3, -4} -> " << getMaxLen(nums2) << " (Expected: 3, [1, -2, -3])" << endl;
    cout << "Test 3: {-1, -2, -3, 0, 1} -> " << getMaxLen(nums3) << " (Expected: 2, [-1, -2])" << endl;

    return 0;
}