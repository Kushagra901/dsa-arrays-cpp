/**
 * ============================================================================
 * PROBLEM: Union of Two Sorted Arrays
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given two sorted arrays `a` and `b` of sizes `n1` and `n2` respectively, 
 *    find the union of these two arrays. The union contains all unique elements 
 *    present in either array, sorted in ascending order.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Two Pointers Merge):
 *        • Time Complexity:  O(n1 + n2) - Linear traversal of both arrays
 *        • Space Complexity: O(n1 + n2) - To return the resulting union array
 *    - Brute Force Approach (Using Ordered Set):
 *        • Time Complexity:  O(n1*log(set_size) + n2*log(set_size))
 *        • Space Complexity: O(n1 + n2) - Extra space for set and output array
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is the Two-Pointer approach superior to using `std::set`?
 *    - Two pointers take advantage of the fact that inputs are already sorted,
 *      running in strictly linear O(n1 + n2) time with zero tree-allocation overhead.
 * 
 * 2. How do we prevent duplicate elements from being inserted into the union array?
 *    - Before inserting element `x`, check if `unionArr.empty() || unionArr.back() != x`.
 * 
 * 3. What if the input arrays are unsorted?
 *    - If unsorted, sort them first in O(N log N) or use an `unordered_set` followed by sorting.
 * 
 * 4. How would you handle union of K sorted arrays or huge disk streams?
 *    - Use a Min-Heap (K-way merge) to stream the smallest unique elements in O(N log K) time.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Union of Two Sorted Arrays (Medium)
 * 2. Coding Ninjas: Merge 2 Sorted Array (Easy)
 * 3. LeetCode 88: Merge Sorted Array (Easy)
 * 4. LeetCode 349: Intersection of Two Arrays (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Two Pointers (Linear Merge)
// Time Complexity: O(n1 + n2) | Space Complexity: O(n1 + n2)
// ============================================================================

vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    // Traverse both arrays simultaneously
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } else {
            if (unionArr.empty() || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    // Process remaining elements from array b
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    // Process remaining elements from array a
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}

// ============================================================================
// 2. BRUTE FORCE APPROACH: Using std::set
// Time Complexity: O((n1+n2) * log(n1+n2)) | Space Complexity: O(n1 + n2)
// ============================================================================

vector<int> unionUsingSet(const vector<int> &a, const vector<int> &b) {
    set<int> st;
    for (int x : a) st.insert(x);
    for (int x : b) st.insert(x);

    vector<int> temp;
    for (int x : st) {
        temp.push_back(x);
    }
    return temp;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {2, 3, 4, 5, 6, 7, 8};

    cout << "Array A: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << "Array B: ";
    for (int x : b) cout << x << " ";
    cout << endl;

    vector<int> result = sortedArray(a, b);

    cout << "Union of A and B: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
