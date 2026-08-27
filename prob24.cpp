/**
 * ============================================================================
 * PROBLEM: Leaders in an Array (Superior Elements)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `a` of size `n`, an element is called a "Leader" 
 *    (or Superior Element) if it is strictly greater than all elements to its right.
 *    The rightmost element is always a leader. Return all leaders present in the array.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Right-to-Left Traversal with Max Tracking):
 *        • Time Complexity:  O(N) (or O(N log N) if sorting required by specific platform)
 *        • Space Complexity: O(N) to store leaders in output list, O(1) auxiliary
 *    - Brute Force Approach (Check all elements to the right):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is Right-to-Left traversal optimal for Leaders?
 *    - As we traverse backwards from `n - 1` to `0`, we keep track of the maximum 
 *      element seen so far (`maxi`). Any element `a[i] > maxi` is strictly greater 
 *      than ALL elements to its right!
 * 
 * 2. How does LeetCode 1299 ("Replace Elements with Greatest Element on Right Side") relate?
 *    - LC 1299 uses the same right-to-left scan, storing `maxRight` at each position 
 *      before updating `maxRight = max(maxRight, arr[i])`.
 * 
 * 3. Does the order of leaders matter in the output?
 *    - Standard problem: return in original left-to-right order (reverse the collected leaders).
 *    - Coding Ninjas / GFG: some platforms request sorted order (`std::sort`).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Leaders in an array (Easy)
 * 2. Coding Ninjas: Superior Elements (Easy)
 * 3. LeetCode 1299: Replace Elements with Greatest Element on Right Side (Easy)
 * 4. LeetCode 739: Daily Temperatures (Medium - Monotonic Stack extension)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Right-to-Left Scan with Running Maximum
// Time Complexity: O(N) | Space Complexity: O(1) auxiliary
// ============================================================================

// Function to find superior elements (leaders) in an array
vector<int> superiorElement(const vector<int> &a) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxi) {
            ans.push_back(a[i]); // Found a new leader
        }
        maxi = max(maxi, a[i]); // Update running maximum to the right
    }

    // Sort or reverse depending on platform specification
    sort(ans.begin(), ans.end());
    return ans;
}

// Related: LeetCode 1299 - Replace Elements with Greatest Element on Right Side
vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    int maxRight = -1; // Initially, no element to the right of last element

    for (int i = n - 1; i >= 0; i--) {
        result[i] = maxRight;
        maxRight = max(maxRight, arr[i]);
    }
    return result;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> vec = {10, 22, 12, 3, 0, 6};

    cout << "Original Array: ";
    for (int x : vec) cout << x << " ";
    cout << endl;

    vector<int> ans = superiorElement(vec);

    cout << "Leaders in array (sorted): ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}