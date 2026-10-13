/**
 * ============================================================================
 * PROBLEM: XOR Queries of a Subarray (LeetCode 1310)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    You are given an array `arr` of positive integers and an array `queries` 
 *    where `queries[i] = [left_i, right_i]`.
 *    For each query `i`, compute the XOR of elements from `left_i` to `right_i` 
 *    (that is, `arr[left_i] ^ arr[left_i + 1] ^ ... ^ arr[right_i]`).
 *    Return an array containing the answers to the given queries.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(Q * N) - For each of Q queries, loop through range (r - l + 1)
 *        • Space Complexity: O(1) auxiliary space (excluding result vector)
 *    - 2. Better Approach (Prefix XOR Array):
 *        • Time Complexity:  O(N + Q) - O(N) to build prefix XOR array, O(1) per query
 *        • Space Complexity: O(N) - Extra vector for prefix XOR values
 *    - 3. Optimal Approach (In-Place Prefix XOR):
 *        • Time Complexity:  O(N + Q) - In-place transformation of arr + O(1) per query
 *        • Space Complexity: O(1) auxiliary space (modifies input array in-place)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does Prefix XOR answer range queries in O(1) time?
 *    - Just like Prefix Sum uses subtraction: `sum(l, r) = prefix[r] - prefix[l - 1]`.
 *    - Since XOR is its own inverse (`x ^ x = 0`), subtracting an interval is done by XOR:
 *      `xor(l, r) = prefixXor[r] ^ prefixXor[l - 1]`.
 * 
 * 2. Why does `prefixXor[r] ^ prefixXor[l - 1]` isolate `arr[l ... r]`?
 *    - `prefixXor[r] = arr[0] ^ ... ^ arr[l - 1] ^ arr[l] ^ ... ^ arr[r]`
 *    - `prefixXor[l - 1] = arr[0] ^ ... ^ arr[l - 1]`
 *    - XORing both cancels out elements `arr[0 ... l - 1]`, leaving `arr[l ... r]`.
 * 
 * 3. What if `left == 0`?
 *    - If `l == 0`, simply return `prefixXor[r]` directly.
 * 
 * 4. Is this algorithm applicable to updates (Point Updates & Range Queries)?
 *    - For mutable arrays with updates, a Binary Indexed Tree (Fenwick Tree) or
 *      Segment Tree allows both Point Update and Range XOR Query in O(log N) time.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1310: XOR Queries of a Subarray (Medium)
 * 2. LeetCode 303: Range Sum Query - Immutable (Easy)
 * 3. LeetCode 304: Range Sum Query 2D - Immutable (Medium)
 * 4. LeetCode 2433: Find The Original Array of Prefix Xor (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(Q * N) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<int> xorQueriesBrute(const vector<int> &arr, const vector<vector<int>> &queries) {
    vector<int> ans;
    for (const auto &q : queries) {
        int l = q[0];
        int r = q[1];
        int currXor = 0;
        for (int j = l; j <= r; j++) {
            currXor ^= arr[j];
        }
        ans.push_back(currXor);
    }
    return ans;
}

// ============================================================================
// 2. BETTER APPROACH: Prefix XOR Array
// Time Complexity: O(N + Q) | Space Complexity: O(N)
// ============================================================================

vector<int> xorQueriesPrefix(const vector<int> &arr, const vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> prefixXor(n);
    prefixXor[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }

    vector<int> ans;
    for (const auto &q : queries) {
        int l = q[0];
        int r = q[1];
        if (l == 0) {
            ans.push_back(prefixXor[r]);
        } else {
            ans.push_back(prefixXor[r] ^ prefixXor[l - 1]);
        }
    }
    return ans;
}

// ============================================================================
// 3. OPTIMAL APPROACH: In-Place Prefix XOR Modification
// Time Complexity: O(N + Q) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<int> xorQueriesOptimal(vector<int> arr, const vector<vector<int>> &queries) {
    int n = arr.size();
    // Step 1: Transform arr in-place into prefix XOR array
    for (int i = 1; i < n; i++) {
        arr[i] ^= arr[i - 1];
    }

    // Step 2: Answer queries in O(1) per query
    vector<int> ans;
    for (const auto &q : queries) {
        int l = q[0];
        int r = q[1];
        if (l == 0) {
            ans.push_back(arr[r]);
        } else {
            ans.push_back(arr[r] ^ arr[l - 1]);
        }
    }
    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> result = xorQueriesOptimal(arr, queries);

    cout << "XOR Query Results (Optimal): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}