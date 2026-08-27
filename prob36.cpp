/**
 * ============================================================================
 * PROBLEM: 4Sum (Find Unique Quadruplets with Target Sum)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `nums` of `n` integers and an integer `target`, return an 
 *    array of all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` 
 *    such that:
 *    - `0 <= a, b, c, d < n`
 *    - `a, b, c, and d` are all distinct
 *    - `nums[a] + nums[b] + nums[c] + nums[d] == target`
 *    The solution set must not contain duplicate quadruplets.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Sorting + 2 Fixed Loops + Two Pointers):
 *        • Time Complexity:  O(N^3) - Two outer loops O(N^2) and inner two-pointer scan O(N)
 *        • Space Complexity: O(1) auxiliary space (excluding output quadruplets)
 *    - Better Approach (Hash Set for 4th element):
 *        • Time Complexity:  O(N^3 * log(set_size))
 *        • Space Complexity: O(N) + O(unique_quadruplets)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is `long long` sum computation essential in 4Sum?
 *    - If 4 numbers are close to 10^9 (e.g. 10^9 + 10^9 + 10^9 + 10^9), their sum 
 *      is 4 * 10^9, which overflows standard 32-bit signed `int` (INT_MAX ≈ 2.14 * 10^9).
 *      Accumulating into `long long` prevents undefined overflow behavior.
 * 
 * 2. How do we skip duplicate quadruplets cleanly in O(1) extra space?
 *    - Skip duplicate `i`: if (i > 0 && nums[i] == nums[i - 1]) continue;
 *    - Skip duplicate `j`: if (j > i + 1 && nums[j] == nums[j - 1]) continue;
 *    - Skip duplicate `k` and `l`: after finding a quadruplet, advance pointers past identical values:
 *      while (k < l && nums[k] == nums[k - 1]) k++; and while (k < l && nums[l] == nums[l + 1]) l--;.
 * 
 * 3. How does this generalize to K-Sum (LeetCode generalized problem)?
 *    - Recursively reduce K-Sum to (K - 1)-Sum by fixing elements, down to base case 2-Sum (Two Pointers) in O(N^(K - 1)) time.
 * 
 * 4. What is 4Sum II (LeetCode 454)?
 *    - Given 4 separate lists: compute sums of pairs (A[i] + B[j]) in a hash map, 
 *      then find -(C[k] + D[l]) in O(N^2) time and O(N^2) space.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 18: 4Sum (Medium)
 * 2. LeetCode 454: 4Sum II (Medium)
 * 3. LeetCode 15: 3Sum (Medium)
 * 4. GeeksforGeeks: Find all four sum numbers (Medium)
 * 5. Coding Ninjas: 4Sum (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Sorting + 2 Outer Loops + Two Pointers
// Time Complexity: O(N^3) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); 
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end()); // Step 1: Sort the array

    for (int i = 0; i < n; i++) {
        // Skip duplicate first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            // Skip duplicate second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int l = n - 1;

            // Two pointers for 3rd and 4th elements
            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; 
                    l--;

                    // Skip duplicate elements for k and l
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }

    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;

    cout << "Original Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nTarget: " << target << endl;

    vector<vector<int>> ans = fourSum(nums, target);

    cout << "Unique quadruplets:\n";
    for (const auto &it : ans) {
        cout << "[ ";
        for (int ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}