/**
 * ============================================================================
 * PROBLEM: Linear Search in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `arr` of `n` integers and an integer `num` (target), 
 *    find the index of the first occurrence of `num` in `arr`.
 *    If `num` is not present, return `-1`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Time Complexity:
 *        • Best Case:    O(1) - Element is at the very first index
 *        • Worst Case:   O(N) - Element is at the last index or not present
 *        • Average Case: O(N)
 *    - Space Complexity: O(1) - Constant auxiliary memory
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. When should you use Linear Search vs Binary Search?
 *    - Linear Search works on ANY collection (unsorted, sorted, linked lists).
 *    - Binary Search requires the collection to be SORTED and provide random access (arrays),
 *      achieving O(log N) time.
 * 
 * 2. What is Sentinel Linear Search?
 *    - Sentinel search eliminates the loop boundary check `i < n` in every iteration
 *      by placing the target element at the very end of the array, improving CPU branch prediction.
 * 
 * 3. How does Linear Search perform in terms of cache locality?
 *    - Because arrays are contiguous in memory, sequential access has optimal spatial cache locality,
 *      making Linear Search very fast for small values of N (e.g. N < 32).
 * 
 * 4. What if there are multiple occurrences of the target?
 *    - Standard search returns the first occurrence index.
 *    - To return all occurrences, collect matching indices in a vector.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 704: Binary Search (Easy)
 * 2. GeeksforGeeks: Search an Element in an array (Basic)
 * 3. Coding Ninjas: Linear Search (Easy)
 * 4. LeetCode 35: Search Insert Position (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Sequential Traversal
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to perform linear search on an array
int linearSearch(int n, int num, const vector<int> &arr) {
    // Traverse the array from start to end
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i; // Element found, return 0-based index
        }
    }
    return -1; // Element not found
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int num = 4;

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int result = linearSearch(n, num, arr);

    if (result == -1) {
        cout << "Number " << num << " not found" << endl;
    } else {
        cout << "Number " << num << " found at index: " << result << endl;
    }

    return 0;
}