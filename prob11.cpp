/**
 * ============================================================================
 * PROBLEM: Union of Two Sorted Arrays
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given two sorted arrays `a[]` and `b[]` of size `n` and `m` respectively, 
 *    return the union of both arrays. The union of two arrays is an array 
 *    containing all unique elements present in either array in sorted order.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Brute Force Approach (Using std::set or std::map):
 *        • Time Complexity:  O((N + M) log(N + M)) - Inserting all elements into set
 *        • Space Complexity: O(N + M) - Auxiliary space for set to store unique elements
 *    - Optimal Approach (Two Pointers Linear Merge):
 *        • Time Complexity:  O(N + M) - Single synchronized scan through both arrays
 *        • Space Complexity: O(N + M) - Result array (O(1) auxiliary space beyond result)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does the Two-Pointer approach avoid sorting?
 *    - Both input arrays are already sorted. Merging works similarly to the merge
 *      step in Merge Sort, skipping duplicate adjacent values as they are inserted.
 * 
 * 2. How do we ensure no duplicate values enter the union array?
 *    - Before pushing an element `x`, check if `unionArr.empty() || unionArr.back() != x`.
 * 
 * 3. What if arrays contain duplicate elements internally?
 *    - The condition `unionArr.back() != element` automatically filters internal duplicates.
 * 
 * 4. What is the difference between Union and Intersection?
 *    - Union collects distinct elements present in AT LEAST ONE array.
 *    - Intersection collects distinct elements present in BOTH arrays.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Union of Two Sorted Arrays (Easy)
 * 2. Coding Ninjas: Merge 2 Sorted Array (Easy)
 * 3. LeetCode 349: Intersection of Two Arrays (Easy)
 * 4. LeetCode 88: Merge Sorted Array (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Using std::set / std::map
// Time Complexity: O((N + M) log(N + M)) | Space Complexity: O(N + M)
// ============================================================================

vector<int> unionUsingSet(const vector<int> &a, const vector<int> &b) {
    set<int> st;
    for (int x : a) st.insert(x);
    for (int x : b) st.insert(x);

    vector<int> temp(st.begin(), st.end());
    return temp;
}

// Frequency map approach for union
vector<int> unionUsingMap(const vector<int> &a, const vector<int> &b) {
    map<int, int> freq;
    for (int x : a) freq[x]++;
    for (int x : b) freq[x]++;

    vector<int> result;
    for (const auto &it : freq) {
        result.push_back(it.first);
    }
    return result;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Two Pointers (Linear Merge with Deduplication)
// Time Complexity: O(N + M) | Space Complexity: O(N + M)
// ============================================================================

vector<int> sortedArrayUnion(const vector<int> &a, const vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    // Traverse both arrays simultaneously
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } 
        else if (b[j] < a[i]) {
            if (unionArr.empty() || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        } 
        else { // a[i] == b[j]
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    // Process remaining elements from array a
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    // Process remaining elements from array b
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b = {2, 3, 4, 4, 5, 11, 12};

    cout << "Array A: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << "Array B: ";
    for (int x : b) cout << x << " ";
    cout << endl;

    vector<int> result = sortedArrayUnion(a, b);

    cout << "Union of A and B (Optimal Two Pointers): ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}