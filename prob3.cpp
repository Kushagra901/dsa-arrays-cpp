/**
 * ============================================================================
 * PROBLEM: Check if an Array is Sorted
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `a` of `n` integers, determine if the array is sorted in 
 *    non-decreasing (ascending) order. Return `true` if sorted, else `false`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(N) - Single linear traversal comparing adjacent elements
 *    - Space Complexity: O(1) - Constant auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How do you check if an array is "Sorted and Rotated"? (LeetCode 1752)
 *    - Count the number of places where `arr[i] > arr[(i + 1) % n]`.
 *    - For a valid sorted and rotated array, there can be AT MOST 1 such drop.
 * 
 * 2. Does non-decreasing mean strictly increasing?
 *    - Non-decreasing allows duplicate adjacent elements (`a[i] >= a[i-1]`).
 *    - Strictly increasing requires `a[i] > a[i-1]`.
 * 
 * 3. What are the base edge cases?
 *    - An array of size 0 or 1 is always trivially sorted.
 * 
 * 4. Can we optimize for early exit?
 *    - Yes, as soon as `a[i] < a[i-1]` is encountered, return `false` immediately
 *      without processing the remaining elements.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1752: Check if Array Is Sorted and Rotated (Easy)
 * 2. GeeksforGeeks: Check if array is sorted (Basic)
 * 3. Coding Ninjas: Check Sorted Array (Easy)
 * 4. LeetCode 896: Monotonic Array (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Linear Adjacent Comparison
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to check if the array is sorted in non-decreasing order
bool isSorted(int n, const vector<int> &a) {
    for (int i = 1; i < n; i++) {
        // If current element is smaller than previous element, array is not sorted
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true; // All adjacent pairs satisfied a[i] >= a[i-1]
}

// Extension: Check if array is sorted and rotated (LeetCode 1752)
bool isSortedAndRotated(const vector<int> &a, int n) {
    int countDrops = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[(i + 1) % n]) {
            countDrops++;
        }
    }
    return countDrops <= 1;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {   
    vector<int> arr = {1, 2, 6, 3, 4, 5};
    int n = arr.size();

    bool sorted = isSorted(n, arr);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Is sorted: " << (sorted ? "Yes (true)" : "No (false)") << endl;
    cout << "Is sorted & rotated: " << (isSortedAndRotated(arr, n) ? "Yes" : "No") << endl;

    return 0;
}