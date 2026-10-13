/**
 * ============================================================================
 * PROBLEM: 4Sum (Find All Unique Quadruplets with Target Sum)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `nums` of `n` integers and an integer `target`, return an 
 *    array of all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` 
 *    such that:
 *      - 0 <= a, b, c, d < n
 *      - a, b, c, and d are distinct indices.
 *      - nums[a] + nums[b] + nums[c] + nums[d] == target
 *    The solution set must not contain duplicate quadruplets.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Better Approach (3 Nested Loops + Hash Set):
 *        • Time Complexity:  O(N^3 * log(M)) - 3 loops + hash set lookups
 *        • Space Complexity: O(2 * quadruplets) + O(N) auxiliary hash set
 *    - 2. Optimal Approach (Sorting + Two Pointers):
 *        • Time Complexity:  O(N^3) - Two nested loops with a two-pointer scan
 *        • Space Complexity: O(1) auxiliary space (excluding returned result list)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we cast element sums to `long long`?
 *    - In extreme test cases, the sum of four 32-bit integers can exceed 
 *      `INT_MAX` (2 * 10^9) or fall below `INT_MIN`, causing signed integer overflow.
 * 
 * 2. How are duplicate quadruplets avoided without using an expensive std::set?
 *    - By sorting the array first and explicitly skipping adjacent duplicate values:
 *      `if (i > 0 && nums[i] == nums[i - 1]) continue;`
 *      `if (j > i + 1 && nums[j] == nums[j - 1]) continue;`
 *      and skipping duplicates when advancing `k` and `l`.
 * 
 * 3. How does this generalize k-Sum?
 *    - Generalized k-Sum uses recursion to reduce k to 2, where Two Pointers is applied in O(N^(k-1)).
 * 
 * 4. Can we apply early exit pruning?
 *    - Yes, after sorting, if `nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target`, break.
 *    - If `nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target`, continue.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 18: 4Sum (Medium)
 * 2. LeetCode 15: 3Sum (Medium)
 * 3. LeetCode 1: Two Sum (Easy)
 * 4. LeetCode 454: 4Sum II (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// ============================================================================
// 1. BETTER APPROACH: 3 Loops + Hash Set
// Time Complexity: O(N^3) | Space Complexity: O(N) + O(quadruplets)
// ============================================================================

vector<vector<int>> fourSumBetter(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> uniqueQuads;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                long long sum = (long long)nums[i] + nums[j] + nums[k];
                long long fourth = (long long)target - sum;

                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    uniqueQuads.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>>(uniqueQuads.begin(), uniqueQuads.end());
}

// ============================================================================
// 2. OPTIMAL APPROACH: Sorting + 2 Outer Loops + Two Pointers
// Time Complexity: O(N^3) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<vector<int>> fourSum(vector<int> &nums, int target) {
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

    cout << "Unique quadruplets (Optimal Two Pointers):\n";
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