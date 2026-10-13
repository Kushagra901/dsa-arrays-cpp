/**
 * ============================================================================
 * PROBLEM: Move Zeroes to End
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `nums`, move all `0`s to the end of it while 
 *    maintaining the relative order of the non-zero elements.
 *    Note that you must do this in-place without making a copy of the array.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Brute Force Approach (Using Auxiliary Vector):
 *        • Time Complexity:  O(2N) = O(N) - Two passes over array
 *        • Space Complexity: O(N) - Temporary vector to collect non-zero elements
 *    - Optimal Approach (Two Pointers - In-Place Swapping):
 *        • Time Complexity:  O(N) - Single pass finding first zero and swapping non-zeroes
 *        • Space Complexity: O(1) - Constant auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the Two-Pointer approach avoid redundant swaps?
 *    - Pointer `j` is positioned at the first occurrence of `0`.
 *    - Pointer `i` searches for subsequent non-zero elements from `j + 1`.
 *    - When `nums[i] != 0`, `swap(nums[i], nums[j])` is executed, and `j++` advances.
 * 
 * 2. What happens if the array has no zeroes?
 *    - The first loop finishes without setting `j != -1`. The function exits early in O(N).
 * 
 * 3. Does this maintain the relative ordering of non-zero elements?
 *    - Yes, non-zero elements are scanned from left to right and swapped sequentially.
 * 
 * 4. Can we overwrite non-zero elements and fill the tail with zeroes?
 *    - Yes, an alternative 2-pass O(1) approach copies non-zero elements forward and
 *      then zeroes out the remaining tail. Swapping is preferred as it minimizes writes.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 283: Move Zeroes (Easy)
 * 2. GeeksforGeeks: Move all zeroes to end of array (Easy)
 * 3. Coding Ninjas: Move Zero's to End (Easy)
 * 4. LeetCode 27: Remove Element (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Using Temporary Array
// Time Complexity: O(2N) = O(N) | Space Complexity: O(N)
// ============================================================================

vector<int> moveZeroesBruteForce(int n, vector<int> a) {
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
// 2. OPTIMAL APPROACH: In-Place Two Pointers Swapping
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

void moveZeroesOptimal(vector<int> &nums) {
    int n = nums.size();
    int j = -1; // Pointer to the first zero element

    // Step 1: Find the index of the first zero
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    // If no zero was found, array is already in desired state
    if (j == -1) return;

    // Step 2: Start scanning from (j + 1) to find non-zero elements and swap with zero at j
    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++; // Next index that is now 0
        }
    }
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    moveZeroesOptimal(arr);

    cout << "Array after moving zeroes to end (Optimal): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
