/**
 * ============================================================================
 * PROBLEM: Sort an Array of 0s, 1s, and 2s (Dutch National Flag Algorithm)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `arr` containing only 0s, 1s, and 2s, sort the array in-place 
 *    in ascending order without using the library's sort function.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Dutch National Flag - DNF 3-Way Partition):
 *        • Time Complexity:  O(N) - Single pass (each element processed at most once)
 *        • Space Complexity: O(1) - Constant auxiliary space, in-place swaps
 *    - Better Approach (Counting Sort - 2 Pass):
 *        • Time Complexity:  O(2N) = O(N) (Pass 1 count 0s,1s,2s; Pass 2 overwrite)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What are the 3 pointer invariants in the Dutch National Flag Algorithm?
 *    - Region [0 ... low - 1]: Contains only 0s.
 *    - Region [low ... mid - 1]: Contains only 1s.
 *    - Region [mid ... high]: Unsorted / unprocessed elements.
 *    - Region [high + 1 ... n - 1]: Contains only 2s.
 * 
 * 2. Why don't we increment `mid` when `arr[mid] == 2`?
 *    - Because the element swapped from `arr[high]` is unknown (it could be 0, 1, or 2).
 *      `mid` must stay at its position to evaluate the newly swapped element in the next iteration!
 * 
 * 3. Why DO we increment `mid` when `arr[mid] == 0`?
 *    - Because `arr[low]` was previously evaluated (it could only be a 1), so after swapping,
 *      `arr[mid]` is guaranteed to be 1. Both `low` and `mid` can safely advance.
 * 
 * 4. Can DNF be used for 3-way partitioning in QuickSort?
 *    - Yes! QuickSort with 3-way DNF partitioning avoids O(N^2) worst-case performance 
 *      on arrays with large numbers of duplicate keys (Fat Pivot).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 75: Sort Colors (Medium)
 * 2. GeeksforGeeks: Sort an array of 0s, 1s and 2s (Easy)
 * 3. Coding Ninjas: Sort 0 1 2 (Easy)
 * 4. LeetCode 324: Wiggle Sort II (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Dutch National Flag Algorithm (3-Way Partitioning)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

void sortArray(vector<int>& arr, int n) {
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

    cout << "Sorted array:   ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}