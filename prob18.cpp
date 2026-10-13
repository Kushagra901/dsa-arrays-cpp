/**
 * ============================================================================
 * PROBLEM: Sort an Array of 0s, 1s, and 2s (Dutch National Flag Problem)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `arr` consisting of only 0s, 1s, and 2s, sort the array 
 *    in-place in non-decreasing order without using the library sort function.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (Sorting):
 *        • Time Complexity:  O(N log N) - Standard comparison sort
 *        • Space Complexity: O(1)
 *    - 2. Better Approach (Counting Sort):
 *        • Time Complexity:  O(2N) - 1st pass counts frequencies, 2nd pass overwrites array
 *        • Space Complexity: O(1) - Constant variables (c0, c1, c2)
 *    - 3. Optimal Approach (Dutch National Flag - 3-Way Partitioning):
 *        • Time Complexity:  O(N) - Strictly single pass
 *        • Space Complexity: O(1) - Modifies array completely in-place
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What are the invariants maintained in the Dutch National Flag algorithm?
 *    - `[0 ... low - 1]`:       All 0s
 *    - `[low ... mid - 1]`:     All 1s
 *    - `[mid ... high]`:        Unsorted elements (yet to be classified)
 *    - `[high + 1 ... n - 1]`:  All 2s
 * 
 * 2. Why is `mid` NOT incremented when `arr[mid] == 2`?
 *    - When swapping `arr[mid]` with `arr[high]`, the element brought from `high`
 *      has not yet been examined (it could be 0, 1, or 2). Hence, `mid` must examine
 *      it on the next iteration while `high--` shrinks the 2s boundary.
 * 
 * 3. Why IS `mid` incremented when `arr[mid] == 0`?
 *    - The element at `low` before the swap was guaranteed to be a 1 (or `low == mid`),
 *      so after swapping, `arr[mid]` is guaranteed to be 1, which is valid for the middle region.
 * 
 * 4. Can this algorithm be extended to 4 colors or general pivot partitioning?
 *    - Yes, Dutch National Flag is the foundation of 3-way Quicksort (Bentley-McIlroy),
 *      which handles arrays with heavy duplicates in O(N) time.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 75: Sort Colors (Medium)
 * 2. GeeksforGeeks: Sort an array of 0s, 1s and 2s (Easy)
 * 3. Coding Ninjas: Sort 0 1 2 (Easy)
 * 4. LeetCode 283: Move Zeroes (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BETTER APPROACH: Counting Frequencies
// Time Complexity: O(2N) | Space Complexity: O(1)
// ============================================================================

void sortColorsCounting(vector<int> &arr, int n) {
    int c0 = 0, c1 = 0, c2 = 0;

    // Step 1: Count occurrences of 0, 1, and 2
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) c0++;
        else if (arr[i] == 1) c1++;
        else c2++;
    }

    // Step 2: Overwrite the original array
    int idx = 0;
    while (c0--) arr[idx++] = 0;
    while (c1--) arr[idx++] = 1;
    while (c2--) arr[idx++] = 2;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Dutch National Flag Algorithm (3-Way Partitioning)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

void sortArray(vector<int> &arr, int n) {
    int low = 0;       // Boundary for 0s
    int mid = 0;       // Scanner pointer for 1s
    int high = n - 1;  // Boundary for 2s

    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap 0 to the low region
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            // 1 is in the correct middle region
            mid++;
        }
        else { // arr[mid] == 2
            // Swap 2 to the high region (do NOT increment mid yet)
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    sortArray(arr, n);

    cout << "Sorted array (Optimal DNF): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
