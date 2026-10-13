/**
 * ============================================================================
 * PROBLEM: Rotate Array by K Places (Left and Right Rotations)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `arr` of size `n`, rotate the array by `k` 
 *    positions to the left or right.
 *    If `k >= n`, effective rotation is `k % n`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Auxiliary Buffer Approach:
 *        • Time Complexity:  O(N) - Linear copy and shift operations
 *        • Space Complexity: O(K) - Temporary storage for K rotated elements
 *    - Optimal In-Place Approach (3-Step Reversal):
 *        • Time Complexity:  O(N) - Reversing array segments takes O(N) total steps
 *        • Space Complexity: O(1) - Modifies array in-place without auxiliary memory
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the 3-step reversal algorithm work for Right Rotation by K?
 *    - Step 1: Reverse entire array: `reverse(0, n - 1)`
 *    - Step 2: Reverse first k elements: `reverse(0, k - 1)`
 *    - Step 3: Reverse remaining n - k elements: `reverse(k, n - 1)`
 * 
 * 2. How does the 3-step reversal algorithm work for Left Rotation by K?
 *    - Step 1: Reverse first k elements: `reverse(0, k - 1)`
 *    - Step 2: Reverse remaining elements: `reverse(k, n - 1)`
 *    - Step 3: Reverse entire array: `reverse(0, n - 1)`
 * 
 * 3. Why is `k = k % n` necessary?
 *    - Rotating an array of size `n` by `n` places returns it to original state.
 *      Taking modulo prevents out-of-bounds errors and eliminates redundant loops.
 * 
 * 4. What if k is negative?
 *    - A negative rotation by `k` to the left is equivalent to rotating by `(k + n) % n`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 189: Rotate Array (Medium)
 * 2. GeeksforGeeks: Rotate Array (Medium)
 * 3. Coding Ninjas: Rotate array by K steps (Easy)
 * 4. LeetCode 61: Rotate List (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. AUXILIARY BUFFER APPROACH: Using Temp Array of Size K
// Time Complexity: O(N) | Space Complexity: O(K)
// ============================================================================

// Left rotate array by d places using temporary buffer
void leftRotateAux(vector<int> &arr, int n, int d) {
    if (n == 0) return;
    d = d % n;
    if (d == 0) return;

    // Step 1: Copy first d elements into temp
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift remaining (n - d) elements to the left by d places
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Step 3: Copy elements from temp back to the end
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

// Right rotate array by k places using temporary buffer
void rightRotateAux(vector<int> &arr, int n, int k) {
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;

    // Step 1: Store last k elements in temp
    vector<int> temp(k);
    for (int i = n - k; i < n; i++) {
        temp[i - (n - k)] = arr[i];
    }

    // Step 2: Shift first n - k elements to the right by k places
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }

    // Step 3: Copy back the k elements to the start
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

// ============================================================================
// 2. OPTIMAL APPROACH: 3-Step In-Place Reversal Algorithm
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

void reverseSubarray(vector<int> &nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// Function to right rotate array by k places in-place (LeetCode 189)
void rotateRightOptimal(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;

    // 1. Reverse the entire array
    reverseSubarray(nums, 0, n - 1);
    // 2. Reverse first k elements
    reverseSubarray(nums, 0, k - 1);
    // 3. Reverse remaining n - k elements
    reverseSubarray(nums, k, n - 1);
}

// Function to left rotate array by k places in-place
void rotateLeftOptimal(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;

    // 1. Reverse first k elements
    reverseSubarray(nums, 0, k - 1);
    // 2. Reverse remaining n - k elements
    reverseSubarray(nums, k, n - 1);
    // 3. Reverse the entire array
    reverseSubarray(nums, 0, n - 1);
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Test Right Rotation
    vector<int> rightArr = arr;
    rotateRightOptimal(rightArr, k);
    cout << "Array after Right Rotation by " << k << " (Optimal): ";
    for (int x : rightArr) cout << x << " ";
    cout << endl;

    // Test Left Rotation
    vector<int> leftArr = arr;
    rotateLeftOptimal(leftArr, k);
    cout << "Array after Left Rotation by " << k << " (Optimal): ";
    for (int x : leftArr) cout << x << " ";
    cout << endl;

    return 0;
}