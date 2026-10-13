/**
 * ============================================================================
 * PROBLEM: Left Rotate an Array by One Place
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `arr` of size `n`, rotate the array to the left 
 *    by one position in-place. The first element moves to the end of the array,
 *    and all other elements shift one position to the left.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Brute Force Approach (Auxiliary Temporary Array):
 *        • Time Complexity:  O(N) - Two passes over array
 *        • Space Complexity: O(N) - Extra array of size N
 *    - Optimal Approach (In-Place Shift):
 *        • Time Complexity:  O(N) - Single pass shifting elements left
 *        • Space Complexity: O(1) - Constant auxiliary space (only 1 temp variable)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we store `arr[0]` in a temporary variable before shifting?
 *    - Because shifting `arr[i] = arr[i+1]` immediately overwrites `arr[0]`.
 *      Saving it first allows us to safely place it at `arr[n - 1]`.
 * 
 * 2. How does rotating by 1 place generalize to rotating by K places?
 *    - Shifting K times yields O(K * N) time. The optimal generalization uses
 *      the 3-step reversal algorithm running in O(N) time and O(1) space.
 * 
 * 3. What if the array is empty or has only one element?
 *    - If `n <= 1`, no rotation is needed; return the array as is.
 * 
 * 4. Is the array modified in-place?
 *    - Yes, the optimal approach does not allocate extra memory.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 189: Rotate Array (Medium)
 * 2. GeeksforGeeks: Quick Left Rotation (Easy)
 * 3. Coding Ninjas: Left Rotate an Array by One (Easy)
 * 4. GeeksforGeeks: Cyclically rotate an array by one (Basic)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Auxiliary Array
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

vector<int> rotateArrayBruteForce(const vector<int> &arr, int n) {
    if (n <= 1) return arr;

    vector<int> temp(n);
    // Shift elements from index 1..n-1 to 0..n-2
    for (int i = 1; i < n; i++) {
        temp[i - 1] = arr[i];
    }
    // Place original first element at the end
    temp[n - 1] = arr[0];

    return temp;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Shift Elements Left by 1 In-Place
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to left rotate an array by 1 place in-place
vector<int>& rotateArray(vector<int> &arr, int n) {
    if (n <= 1) return arr;

    // Step 1: Store the first element in a temporary variable
    int temp = arr[0];

    // Step 2: Shift all remaining elements one position to the left
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    // Step 3: Place the first element at the end of the array
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
    for (int x : arr) cout << x << " ";
    cout << endl;

    rotateArray(arr, n);

    cout << "Array after Left Rotation by 1: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}