/**
 * ============================================================================
 * PROBLEM: Left Rotate an Array by K Places (Brute Force Approach)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `arr` of size `n` and an integer `d` (or `k`), left rotate 
 *    the array to the left by `d` positions.
 *    In this brute force approach, we use a temporary array of size `d` to 
 *    store the first `d` elements, shift the remaining `(n - d)` elements to the 
 *    front, and copy back the `d` elements to the end.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(d) + O(n - d) + O(d) = O(n + d) = O(n)
 *    - Space Complexity: O(d) auxiliary space for the temporary buffer
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we perform `d = d % n` at the beginning?
 *    - Rotating by `n` positions brings the array back to its original state.
 *      Hence, rotating by `d` is identical to rotating by `d % n`.
 *      This also prevents out-of-bounds indexing when `d >= n`.
 * 
 * 2. What is the space limitation of this brute force method?
 *    - It requires O(d) auxiliary memory. In the worst case (when d ≈ n), 
 *      it requires O(n) extra space. The optimal Reversal Algorithm takes O(1) space.
 * 
 * 3. How would you handle negative values of `d`?
 *    - If `d < 0`, a left rotation by `d` is equivalent to a left rotation by `(d % n + n) % n`.
 * 
 * 4. How does this compare with the Juggling Algorithm (GCD-based)?
 *    - Juggling algorithm achieves O(N) time and O(1) space by moving elements in cycles of size gcd(n, d).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 189: Rotate Array (Medium)
 * 2. GeeksforGeeks: Rotate Array (Medium)
 * 3. Coding Ninjas: Rotate array (Easy)
 * 4. LeetCode 61: Rotate List (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// BRUTE FORCE APPROACH: Using Auxiliary Array of Size `d`
// Time Complexity: O(N) | Space Complexity: O(d)
// ============================================================================

// Function to left rotate array by d places
void leftRotate(int arr[], int n, int d) {
    if (n == 0) return;
    d = d % n; // Handle cases where d >= n
    if (d == 0) return;

    // Step 1: Copy the first d elements into a temporary array
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift the remaining (n - d) elements to the left by d places
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Step 3: Copy the elements from temp back to the end of arr
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    leftRotate(arr, n, d);

    cout << "Array after Left Rotating by " << d << " places: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}