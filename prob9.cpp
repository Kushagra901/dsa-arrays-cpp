/**
 * ============================================================================
 * PROBLEM: Move All Zeroes to the End of the Array (Optimal 2-Pointer Approach)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `arr` of size `n`, move all zeroes to the end of 
 *    the array in-place while maintaining the relative order of the non-zero elements.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(N) - Single pass (Finding first zero takes <= N, second loop takes <= N)
 *    - Space Complexity: O(1) - Constant auxiliary space, pure in-place pointer swaps
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the Two-Pointer (Slow & Fast Pointer) logic work here?
 *    - Pointer `j` tracks the first occurrence of `0`.
 *    - Pointer `i` scans from `j + 1` to `n - 1`.
 *    - Whenever `arr[i] != 0`, we swap `arr[i]` with `arr[j]` and increment `j` by 1.
 * 
 * 2. Can we minimize the number of write/swap operations?
 *    - If `i == j` (e.g. no zeroes seen yet), avoid self-swaps.
 *    - Alternatively, overwrite non-zeroes forward and fill trailing positions with 0.
 * 
 * 3. What if all elements are zeroes or all elements are non-zeroes?
 *    - If no zeroes exist (`j == -1`), return immediately without any swaps.
 *    - If all are zeroes, loop finishes without triggering non-zero swap.
 * 
 * 4. Is this algorithm stable?
 *    - Yes, non-zero elements preserve their original relative order.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 283: Move Zeroes (Easy)
 * 2. LeetCode 27: Remove Element (Easy)
 * 3. GeeksforGeeks: Move all zeroes to end of array (Easy)
 * 4. Coding Ninjas: Move Zero's to End (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Two Pointers (In-Place Swapping)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to move zeroes to the end in-place
vector<int>& moveZero(int n, vector<int> &a) {
    int j = -1;

    // Step 1: Find the first 0 element index
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    // If there are no zeroes in the array, no modifications are needed
    if (j == -1) return a;

    // Step 2: Iterate through the remaining array and swap non-zeroes with index j
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++; // Move pointer j to next zero index
        }
    }

    return a;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {0, 0, 3, 4, 7, 8, 0, 5, 3, 5, 0, 0};
    int n = arr.size();

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    moveZero(n, arr);

    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
