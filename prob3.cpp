/**
 * ============================================================================
 * PROBLEM: Check if an Array is Sorted (and Sorted & Rotated)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `a` of `n` integers, determine if the array is sorted in 
 *    non-decreasing (ascending) order. Return `true` if sorted, else `false`.
 *    Also includes the extension for LeetCode 1752: Check if an array was 
 *    originally sorted and then rotated by some number of positions.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Brute Force Approach (Pairwise Comparison):
 *        • Time Complexity:  O(N^2) - Comparing every element with all subsequent elements
 *        • Space Complexity: O(1) - In-place comparison
 *    - Optimal Approach (Adjacent Comparison):
 *        • Time Complexity:  O(N) - Single linear traversal comparing adjacent elements
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Extension (Sorted and Rotated - LeetCode 1752):
 *        • Time Complexity:  O(N) - Count circular drops `arr[i] > arr[(i + 1) % n]`
 *        • Space Complexity: O(1) - Constant auxiliary space
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
// 1. BRUTE FORCE APPROACH: Pairwise Comparison
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

bool isSortedBruteForce(const vector<int> &arr, int n) {
    // Check every element against all subsequent elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If any subsequent element is smaller, array is not sorted
            if (arr[j] < arr[i]) {
                return false;
            }
        }
    }
    return true;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Linear Adjacent Comparison
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

// ============================================================================
// 3. EXTENSION: Check if Array is Sorted and Rotated (LeetCode 1752)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

bool isSortedAndRotated(const vector<int> &a, int n) {
    if (n <= 1) return true;
    
    int countDrops = 0;
    for (int i = 0; i < n; i++) {
        // Circular comparison: compare last element with first element using modulo
        if (a[i] > a[(i + 1) % n]) {
            countDrops++;
        }
    }
    // A sorted and rotated array can have at most one inversion point / drop
    return countDrops <= 1;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {   
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 1, 2};
    vector<int> arr3 = {2, 1, 3, 4};

    cout << "--- 1. Testing Standard Sorted Check ---" << endl;
    cout << "arr1 is sorted (Optimal): " << (isSorted(arr1.size(), arr1) ? "Yes" : "No") << endl;
    cout << "arr3 is sorted (Optimal): " << (isSorted(arr3.size(), arr3) ? "Yes" : "No") << endl;

    cout << "\n--- 2. Testing Sorted & Rotated (LeetCode 1752) ---" << endl;
    cout << "arr1 is sorted & rotated: " << (isSortedAndRotated(arr1, arr1.size()) ? "Yes" : "No") << endl;
    cout << "arr2 is sorted & rotated: " << (isSortedAndRotated(arr2, arr2.size()) ? "Yes" : "No") << endl;
    cout << "arr3 is sorted & rotated: " << (isSortedAndRotated(arr3, arr3.size()) ? "Yes" : "No") << endl;

    return 0;
}