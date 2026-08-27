/**
 * ============================================================================
 * PROBLEM: Rotate an Array by K Places (Optimal Reversal Algorithm)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of `n` integers and a number `d` (or `k`), left rotate 
 *    the array by `d` positions in-place using O(1) extra space.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(d) + O(n - d) + O(n) = O(2n) = O(n)
 *    - Space Complexity: O(1) - Pure in-place modification
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the 3-step Reversal Algorithm work for LEFT Rotation by d?
 *    - Step 1: Reverse the first `d` elements (`0` to `d - 1`).
 *    - Step 2: Reverse the remaining `n - d` elements (`d` to `n - 1`).
 *    - Step 3: Reverse the entire array (`0` to `n - 1`).
 * 
 * 2. How does the Reversal Algorithm work for RIGHT Rotation by k (LeetCode 189)?
 *    - Step 1: Reverse the entire array (`0` to `n - 1`).
 *    - Step 2: Reverse the first `k` elements (`0` to `k - 1`).
 *    - Step 3: Reverse the remaining `n - k` elements (`k` to `n - 1`).
 * 
 * 3. Why is this algorithm optimal?
 *    - It achieves O(N) linear time while using O(1) auxiliary memory.
 *    - It is cache-friendly and extremely simple to implement without extra buffers.
 * 
 * 4. What if `d > n`?
 *    - Always normalize `d = d % n` before reversing to avoid unnecessary revolutions.
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
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Reversal Algorithm (In-Place)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to left rotate an array by d places using 3-step reversal
void leftRotate(int arr[], int n, int d) {
    if (n == 0) return;
    d = d % n;
    if (d == 0) return;

    // Step 1: Reverse first d elements: [0 ... d-1]
    reverse(arr, arr + d);

    // Step 2: Reverse remaining (n-d) elements: [d ... n-1]
    reverse(arr + d, arr + n);

    // Step 3: Reverse the entire array: [0 ... n-1]
    reverse(arr, arr + n);
}

// Function to right rotate an array by k places (LeetCode 189 style)
void rightRotate(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
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

    cout << "Array after Left Rotate by " << d << " places: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}