/**
 * ============================================================================
 * PROBLEM: 3Sum (Find Unique Triplets with Zero Sum)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `arr` of size `n`, find all unique triplets 
 *    `[arr[i], arr[j], arr[k]]` such that `i != j`, `i != k`, and `j != k`, 
 *    and `arr[i] + arr[j] + arr[k] == 0`.
 *    The solution set must not contain duplicate triplets.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Sorting + Two Pointers):
 *        • Time Complexity:  O(N log N) + O(N^2) = O(N^2)
 *        • Space Complexity: O(1) auxiliary space (excluding the output list)
 *    - Better Approach (Hash Set for 3rd Element):
 *        • Time Complexity:  O(N^2 * log(set_size))
 *        • Space Complexity: O(N) + O(unique_triplets)
 *    - Brute Force Approach (3 Nested Loops + Set):
 *        • Time Complexity:  O(N^3 * log(triplets))
 *        • Space Complexity: O(unique_triplets)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How do we eliminate duplicate triplets without using `std::set`?
 *    - Step 1: Sort the array.
 *    - Step 2: Skip duplicate fixed elements: `if (i > 0 && arr[i] == arr[i - 1]) continue;`.
 *    - Step 3: When a valid triplet is found, advance pointers past duplicate values:
 *      `while (j < k && arr[j] == arr[j - 1]) j++;` and `while (j < k && arr[k] == arr[k + 1]) k--;`.
 * 
 * 2. Why is Sorting + Two Pointers superior to Hash Set?
 *    - Sorting guarantees O(1) auxiliary space and completely eliminates the high overhead 
 *      and hashing collisions of `std::set<vector<int>>`.
 * 
 * 3. What if the target sum is `K` instead of `0`?
 *    - The exact same logic applies: replace `0` with `target - arr[i]`.
 * 
 * 4. What is the 3Sum Closest problem (LeetCode 16)?
 *    - Same Two Pointers pattern, but track `minDiff = min(minDiff, abs(sum - target))` and update `closestSum`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 15: 3Sum (Medium)
 * 2. LeetCode 16: 3Sum Closest (Medium)
 * 3. LeetCode 259: 3Sum Smaller (Medium)
 * 4. LeetCode 18: 4Sum (Medium)
 * 5. GeeksforGeeks: 3 Sum / Triplet Sum in Array (Medium)
 * 6. Coding Ninjas: Three Sum (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Sorting + Two Pointers (O(1) Auxiliary Space)
// Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // Step 1: Sort the array

    for (int i = 0; i < n; i++) {
        // Skip duplicate fixed elements
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        // Two pointers for the remaining two elements
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0) {
                j++; // Sum too small, move left pointer right
            }
            else if (sum > 0) {
                k--; // Sum too large, move right pointer left
            }
            else {
                // Found a valid zero-sum triplet
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                // Skip duplicate elements for j and k
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

// ============================================================================
// 2. BRUTE FORCE APPROACH: 3 Nested Loops + std::set
// Time Complexity: O(N^3 * log(triplets)) | Space Complexity: O(triplets)
// ============================================================================

vector<vector<int>> tripletBruteForce(int n, const vector<int> &num) {
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (num[i] + num[j] + num[k] == 0) {
                    vector<int> temp = {num[i], num[j], num[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<vector<int>> ans = triplet(n, arr);

    cout << "Unique zero-sum triplets:\n";
    for (const auto &it : ans) {
        cout << "[ ";
        for (int i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
