/**
 * ============================================================================
 * PROBLEM: Left Rotate an Array by One Place
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of `n` integers, left rotate the array by one position.
 *    In a left rotation by 1, every element moves to the left by one index,
 *    and the first element (`arr[0]`) wraps around to become the last element (`arr[n-1]`).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:  O(N) - Single pass shifting (N-1) elements to the left
 *    - Space Complexity: O(1) - In-place rotation using a single temporary variable
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does Left Rotate by 1 generalize to Left Rotate by K places?
 *    - Rotating by 1 K times takes O(K * N). For large K, this is inefficient.
 *      Optimal general approach uses Reversal Algorithm in O(N) time and O(1) space.
 * 
 * 2. What is the difference between Left Rotate and Right Rotate?
 *    - Left Rotate by 1 moves `arr[0]` to `arr[n-1]`.
 *    - Right Rotate by 1 moves `arr[n-1]` to `arr[0]`.
 *    - Left rotate by K is equivalent to Right rotate by (N - K % N).
 * 
 * 3. What are the edge cases?
 *    - Array size `n <= 1`: No change is needed.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 189: Rotate Array (Medium)
 * 2. GeeksforGeeks: Cyclically rotate an array by one (Basic)
 * 3. Coding Ninjas: Left Rotate an Array by One (Easy)
 * 4. GeeksforGeeks: Quick Left Rotation (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Shift Elements Left by 1
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to left rotate an array by 1 place
vector<int>& rotateArray(vector<int> &arr, int n) {
    if (n <= 1) return arr;

    int temp = arr[0]; // Store the first element in a temporary variable

    // Shift all remaining elements one position to the left
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    // Place the first element at the end of the array
    arr[n - 1] = temp;

    return arr;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() { 
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotateArray(arr, n);

    cout << "Array after Left Rotation by 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}