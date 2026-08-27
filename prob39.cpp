/**
 * ============================================================================
 * PROBLEM: Merge Two Sorted Arrays Without Extra Space (Gap Method / In-Place)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given two sorted arrays `arr1[]` of size `n` and `arr2[]` of size `m`, 
 *    merge them in-place such that after merging, both `arr1` and `arr2` remain 
 *    sorted individually and the combined elements are in sorted order.
 *    No extra memory (O(1) space) is allowed.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Gap Method - Shell Sort Intuition):
 *        • Time Complexity:  O((n + m) * log(n + m)) - Number of gap reductions is log(n+m), each pass takes O(n+m)
 *        • Space Complexity: O(1) - Pure in-place swapping
 *    - Alternative Optimal (Compare from Back & Swap + Sort):
 *        • Time Complexity:  O(min(n, m)) + O(n log n) + O(m log m)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the Gap Method work?
 *    - Treat both arrays conceptually as one concatenated array of length len = n + m.
 *    - Initialize gap = ceil(len / 2.0) = (len / 2) + (len % 2).
 *    - Place two pointers with a distance of gap between them and swap if arr[left] > arr[right].
 *    - Divide gap by 2 after each complete pass until gap = 1 is processed.
 * 
 * 2. Why is the Gap Method guaranteed to produce a fully sorted sequence?
 *    - The Gap method is derived directly from Shell Sort, which reduces inversions rapidly 
 *      across distant elements and finishes with a guaranteed insertion sort pass at gap = 1.
 * 
 * 3. How do we translate virtual index idx across two arrays?
 *    - If idx < n, element belongs to arr1[idx].
 *    - If idx >= n, element belongs to arr2[idx - n].
 * 
 * 4. What is LeetCode 88 (Merge Sorted Array)?
 *    - In LC 88, `nums1` has enough extra capacity (m + n). 
 *      We fill `nums1` backwards from m + n - 1 using 3 pointers in strictly O(m + n) time!
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Merge Without Extra Space (Hard)
 * 2. LeetCode 88: Merge Sorted Array (Easy)
 * 3. Coding Ninjas: Merge Two Sorted Arrays Without Extra Space (Hard)
 * 4. GeeksforGeeks: Shell Sort (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Gap Method (Shell Sort In-Place Traversal)
// Time Complexity: O((n + m) * log(n + m)) | Space Complexity: O(1)
// ============================================================================

// Helper function to swap elements if left element is greater than right element
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

// Function to merge two sorted arrays without extra space
void merge(long long arr1[], long long arr2[], int n, int m) {
    int len = n + m; // Total virtual array length

    // Initial gap
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {
            // Case 1: left pointer in arr1[], right pointer in arr2[]
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // Case 2: both pointers in arr2[]
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // Case 3: both pointers in arr1[]
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }

        // Break once iteration with gap = 1 completes
        if (gap == 1) break;

        // Reduce gap for next iteration
        gap = (gap / 2) + (gap % 2);
    }
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;

    cout << "Original Arrays:\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) cout << arr2[i] << " ";
    cout << "\n\n";

    merge(arr1, arr2, n, m);

    cout << "Merged Arrays without extra space:\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}