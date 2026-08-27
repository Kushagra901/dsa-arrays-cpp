/**
 * ============================================================================
 * PROBLEM: Move All Zeroes to the End of the Array (Brute Force Approach)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of `n` integers, move all the zeroes present in the array 
 *    to the end while maintaining the relative order of the non-zero elements.
 *    In this brute force approach, we use a temporary array/vector to collect 
 *    all non-zero elements first, copy them back, and fill the rest with zeroes.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(N) + O(nz) + O(N - nz) = O(2N) = O(N)
 *        • O(N) to collect non-zeros into temp
 *        • O(nz) to copy back non-zeros
 *        • O(N - nz) to fill remaining slots with 0
 *    - Space Complexity: O(N) in worst case (when all elements are non-zero)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is maintaining the relative order (stability) crucial?
 *    - Many real-world systems (e.g. log processing, event ranking) require 
 *      that valid active records retain their arrival/timestamp sequence.
 * 
 * 2. Why is this approach not optimal?
 *    - It requires O(N) extra space. The problem on LeetCode 283 strictly 
 *      demands in-place modification with O(1) extra memory.
 * 
 * 3. What are the edge cases for this problem?
 *    - All elements are 0: `[0, 0, 0]` -> remains `[0, 0, 0]`.
 *    - No zeroes present: `[1, 2, 3]` -> remains `[1, 2, 3]`.
 *    - Array of length 1: `[0]` or `[5]`.
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

using namespace std;

// ============================================================================
// BRUTE FORCE APPROACH: Using Temporary Array
// Time Complexity: O(2N) = O(N) | Space Complexity: O(N)
// ============================================================================

// Function to move all zeroes to the end using a temporary vector
vector<int> moveZeroes(int n, vector<int> a) {
    // Step 1: Collect all non-zero elements into temporary vector
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp.push_back(a[i]);
        }
    }

    // Step 2: Copy non-zero elements back to original array from index 0
    int nz = temp.size();
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    // Step 3: Fill the remaining indices with zeroes
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }

    return a;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    int n = arr.size();

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> result = moveZeroes(n, arr);

    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
