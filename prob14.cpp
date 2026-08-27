/**
 * ============================================================================
 * PROBLEM: Maximum Consecutive Ones
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a binary array `nums` consisting only of 0s and 1s, find the maximum 
 *    number of consecutive 1s in the array.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(N) - Single linear scan across array of size N
 *    - Space Complexity: O(1) - Constant auxiliary variables (`maxi`, `cnt`)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How do you handle the follow-up: "Max Consecutive Ones II" (LeetCode 487)?
 *    - You can flip at most ONE 0 to 1.
 *    - Use a sliding window `[left, right]` keeping count of zeroes in window `<= 1`.
 * 
 * 2. How do you handle "Max Consecutive Ones III" (LeetCode 1004)?
 *    - You can flip at most `K` zeroes to 1.
 *    - Maintain sliding window where `zeroCount <= K`. Window size is `right - left + 1`.
 * 
 * 3. What are the edge cases?
 *    - All zeroes: `[0, 0, 0]` -> 0.
 *    - All ones: `[1, 1, 1]` -> 3.
 *    - Single element: `[1]` -> 1, `[0]` -> 0.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 485: Max Consecutive Ones (Easy)
 * 2. LeetCode 487: Max Consecutive Ones II (Medium)
 * 3. LeetCode 1004: Max Consecutive Ones III (Medium)
 * 4. GeeksforGeeks: Maximum Consecutive Ones (Easy)
 * 5. Coding Ninjas: Maximum Consecutive Ones (Easy)
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

class Solution {
public:
    // Function to find maximum consecutive 1s in binary array
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
};

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1};

    cout << "Binary Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    Solution sol;
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Max Consecutive Ones: " << result << endl;

    return 0;
}