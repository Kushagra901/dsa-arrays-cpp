/**
 * ============================================================================
 * PROBLEM: Intersection of Two Sorted Arrays
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given two sorted arrays `A` and `B` of sizes `m` and `n` respectively, 
 *    find the intersection of these two arrays.
 *    The intersection contains elements that are present in both arrays.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Two Pointers):
 *        • Time Complexity:  O(m + n) - Single linear traversal of both arrays
 *        • Space Complexity: O(1) auxiliary space (excluding result vector)
 *    - Brute Force Approach (Visited Array):
 *        • Time Complexity:  O(m * n)
 *        • Space Complexity: O(n) - Visited array for tracking matched elements
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the difference between LeetCode 349 (Intersection - Unique) and LeetCode 350 (Intersection II - Duplicates)?
 *    - LC 349 requires unique elements in the result (use set or skip duplicates).
 *    - LC 350 requires elements to appear as many times as they show up in both arrays (two pointer matching).
 * 
 * 2. What if one array is very large (e.g. 1 billion elements) and the other is small (e.g. 100 elements)?
 *    - Instead of two pointers O(M + N), perform Binary Search for each of the 100 elements 
 *      in the large sorted array in O(K * log M) time.
 * 
 * 3. What if elements cannot be loaded into memory all at once (external sorting/streaming)?
 *    - Chunked stream matching with buffered readers can match sorted chunks incrementally.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 349: Intersection of Two Arrays (Easy)
 * 2. LeetCode 350: Intersection of Two Arrays II (Easy)
 * 3. GeeksforGeeks: Intersection of two sorted arrays (Easy)
 * 4. Coding Ninjas: Intersection Of Two Sorted Arrays (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Two Pointers
// Time Complexity: O(m + n) | Space Complexity: O(1) (excluding output)
// ============================================================================

vector<int> findArrayIntersection(const vector<int> &A, const vector<int> &B) {
    int i = 0;
    int j = 0;
    int m = A.size();
    int n = B.size();
    vector<int> ans;

    while (i < m && j < n) {
        if (A[i] < B[j]) {
            i++; // Element in A is smaller, advance pointer i
        }
        else if (B[j] < A[i]) {
            j++; // Element in B is smaller, advance pointer j
        }
        else {
            ans.push_back(A[i]); // Common element found
            i++;
            j++;
        }
    }
    return ans;
}

// ============================================================================
// 2. BRUTE FORCE APPROACH: Using Visited Array
// Time Complexity: O(m * n) | Space Complexity: O(n)
// ============================================================================

vector<int> findArrayIntersectionBrute(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int m = A.size();
    int n = B.size();
    vector<int> visi(n, 0);  // Mark elements in B as visited

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[j] > A[i]) break; // Since arrays are sorted, no need to check further

            if (A[i] == B[j] && !visi[j]) {
                ans.push_back(A[i]);
                visi[j] = 1;
                break;
            }
        }
    }
    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6};
    vector<int> B = {3, 4, 5, 6, 7};

    cout << "Array A: ";
    for (int x : A) cout << x << " ";
    cout << endl;

    cout << "Array B: ";
    for (int x : B) cout << x << " ";
    cout << endl;

    vector<int> result = findArrayIntersection(A, B);

    cout << "Intersection of A and B: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
