/**
 * ============================================================================
 * PROBLEM: Next Permutation (Find Next Lexicographically Greater Permutation)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    A permutation of an array of integers is an arrangement of its members 
 *    into a sequence or linear order. Find the next lexicographically greater 
 *    permutation of the given array `A`. If no such permutation exists (i.e. 
 *    the array is sorted in descending order), rearrange it to the lowest 
 *    possible order (i.e., sorted in ascending order).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Standard 3-Step In-Place Scan):
 *        • Time Complexity:  O(N) - 3 linear steps: find breakpoint O(N), find swap element O(N), reverse suffix O(N)
 *        • Space Complexity: O(1) - Pure in-place modification
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the 3-step algorithm for Next Permutation?
 *    - Step 1 (Find Breakpoint): Scan backwards from right to find the first index `i` 
 *      such that `A[i] < A[i + 1]`. Let `ind = i`.
 *    - Step 2 (Find Next Greater Element): If breakpoint exists, scan backwards from the 
 *      end to find the first element `A[j] > A[ind]`, and swap `A[ind]` with `A[j]`.
 *    - Step 3 (Reverse Suffix): Reverse the subarray from `ind + 1` to `n - 1` to make it 
 *      the smallest possible lexicographical order.
 * 
 * 2. What if no breakpoint exists (`ind == -1`)?
 *    - The array is in completely descending order (e.g. `[5, 4, 3, 2, 1]`).
 *      Simply reverse the whole array to wrap around to the first permutation `[1, 2, 3, 4, 5]`.
 * 
 * 3. How does this compare with `std::next_permutation` in C++ STL?
 *    - `std::next_permutation(A.begin(), A.end())` implements this exact same 3-step O(N) algorithm!
 * 
 * 4. How would you solve "Previous Permutation" (LeetCode 1053)?
 *    - Invert the conditions: find first `A[i] > A[i+1]` from right, swap with largest element smaller than `A[i]`, then reverse.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 31: Next Permutation (Medium)
 * 2. LeetCode 556: Next Greater Element III (Medium)
 * 3. GeeksforGeeks: Next Permutation (Medium)
 * 4. Coding Ninjas: Next Permutation (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: 3-Step In-Place Lexicographical Algorithm
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

vector<int>& nextGreaterPermutation(vector<int> &A) {
    int ind = -1;
    int n = A.size();

    // Step 1: Find the first decreasing element from the end (breakpoint)
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    // If no breakpoint exists, array is in descending order -> reverse entire array
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the smallest element in the suffix that is greater than A[ind] and swap
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: Reverse the suffix starting from index ind + 1 to n - 1
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};

    cout << "Original permutation: [";
    for (int x : A) cout << x << " ";
    cout << "]" << endl;

    nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (int x : A) cout << x << " ";
    cout << "]" << endl;

    return 0;
}