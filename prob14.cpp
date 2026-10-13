/**
 * ============================================================================
 * PROBLEM: Maximum Consecutive Ones
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a binary array `nums` containing only `0`s and `1`s, return the 
 *    maximum number of consecutive `1`s in the array.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Brute Force / Running Counter Scan:
 *        • Time Complexity:  O(N) - Single linear traversal through array
 *        • Space Complexity: O(1) - Constant auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the state machine transition?
 *    - On `1`: increment streak counter `cnt++`, update global max `maxi = max(maxi, cnt)`.
 *    - On `0`: reset streak counter `cnt = 0`.
 * 
 * 2. What is the extension "Max Consecutive Ones II" (LeetCode 487)?
 *    - You can flip at most ONE 0 to 1. Solved using sliding window tracking at most 1 zero.
 * 
 * 3. What is the extension "Max Consecutive Ones III" (LeetCode 1004)?
 *    - You can flip at most K zeroes. Solved using sliding window: maintain a window
 *      containing at most `k` zeroes in O(N) time and O(1) space.
 * 
 * 4. What if the array has only 0s or only 1s?
 *    - Only 0s: returns 0.
 *    - Only 1s: returns `n`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 485: Max Consecutive Ones (Easy)
 * 2. LeetCode 487: Max Consecutive Ones II (Medium)
 * 3. LeetCode 1004: Max Consecutive Ones III (Medium)
 * 4. GeeksforGeeks: Maximum Consecutive Ones (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Linear Counter Scan
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int findMaxConsecutiveOnes(const vector<int> &nums) {
    int maxi = 0; // Tracks maximum streak of 1s seen so far
    int cnt = 0;  // Tracks current running streak of consecutive 1s

    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt); // Update global max streak
        } else {
            cnt = 0; // Reset counter when 0 is encountered
        }
    }
    return maxi;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1};

    cout << "Binary Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    int result = findMaxConsecutiveOnes(nums);

    cout << "Max Consecutive Ones: " << result << endl;

    return 0;
}