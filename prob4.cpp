/**
 * ============================================================================
 * PROBLEM: Remove Duplicates from Sorted Array (In-Place)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `arr` sorted in non-decreasing order, remove the 
 *    duplicates in-place such that each unique element appears only once.
 *    The relative order of elements should be kept the same.
 *    Return the number of unique elements `k`, where the first `k` elements 
 *    of `arr` hold the result.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Two Pointers - In-Place):
 *        • Time Complexity:  O(N) - Single pass through the array of size N
 *        • Space Complexity: O(1) - In-place modification without extra memory
 *    - Brute Force Approach (Using Hash Set):
 *        • Time Complexity:  O(N log N) or O(N)
 *        • Space Complexity: O(N) - Extra space for set
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does the Two-Pointer approach require the array to be sorted?
 *    - Because in a sorted array, all duplicate elements appear contiguously. 
 *      If the array were unsorted, a Hash Set or sorting first would be required.
 * 
 * 2. What is the follow-up: "Remove Duplicates from Sorted Array II" (LeetCode 80)?
 *    - Allow at most two duplicates: start pointer from index 2, and check
 *      `if (arr[j] != arr[i - 2]) { arr[i++] = arr[j]; }`.
 * 
 * 3. Does this approach preserve stability and relative order?
 *    - Yes, since we traverse left-to-right, the first occurrence of each unique
 *      element is placed sequentially.
 * 
 * 4. What if the array is empty?
 *    - If `n == 0`, return 0 immediately.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 26: Remove Duplicates from Sorted Array (Easy)
 * 2. LeetCode 80: Remove Duplicates from Sorted Array II (Medium)
 * 3. LeetCode 27: Remove Element (Easy)
 * 4. GeeksforGeeks: Remove duplicate elements from sorted Array (Easy)
 * 5. Coding Ninjas: Remove Duplicates from Sorted Array (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Two Pointers (Slow & Fast Pointer)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to remove duplicates in-place from a sorted array
int removeDuplicates(vector<int> &arr, int n) {
    if (n == 0) return 0;

    int i = 0; // Slow pointer: points to the last unique element placed

    // Fast pointer `j` scans through the array
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            arr[i + 1] = arr[j]; // Place the new unique element next to `i`
            i++;                 // Advance slow pointer
        }
    }
    return i + 1; // Number of unique elements is (index + 1)
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int k = removeDuplicates(arr, n);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates (first " << k << " elements): ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}