/**
 * ============================================================================
 * PROBLEM: Largest and Smallest Element in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array/vector of integers `arr` of size `n`, find the largest 
 *    (maximum) and smallest (minimum) elements present in the array.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Single Pass / Linear Scan):
 *        • Time Complexity:  O(N) - Single traversal of array of size N
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Brute Force Approach (Sorting):
 *        • Time Complexity:  O(N log N) - Sorting the array
 *        • Space Complexity: O(1) or O(N) depending on sorting algorithm
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is linear scan preferred over sorting to find the largest element?
 *    - Linear scan takes O(N) time and O(1) space, whereas sorting takes O(N log N)
 *      time. Modifying the array order may also violate requirements.
 * 
 * 2. How do you handle an empty array or an array of size 1?
 *    - For size 1, the single element is both largest and smallest.
 *    - For size 0 (empty), return an error code, throw an exception, or return INT_MIN / INT_MAX.
 * 
 * 3. What if the array contains negative numbers or INT_MIN values?
 *    - Initialize the tracking variable with `arr[0]` rather than `0` or `INT_MIN`
 *      to correctly handle all negative values.
 * 
 * 4. What is the minimum number of comparisons needed to find BOTH min and max?
 *    - By comparing elements in pairs, we can find both min and max in 3*(N/2) comparisons
 *      instead of 2*N comparisons.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 414: Third Maximum Number (Easy)
 * 2. LeetCode 215: Kth Largest Element in an Array (Medium)
 * 3. GeeksforGeeks: Largest Element in Array (Basic)
 * 4. GeeksforGeeks: Maximum and Minimum in an Array (Basic)
 * 5. Coding Ninjas: Largest Element in the Array (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Linear Scan
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to find the largest element in an array
int largestElemnt(vector<int> &arr, int n) {
    int largest = arr[0]; // Initialize with first element
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if current element is greater
        }
    }
    return largest;
}

// Function to find the smallest element in an array
int smallestElement(vector<int> &arr, int n) {
    int smallest = arr[0]; // Initialize with first element
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i]; // Update smallest if current element is smaller
        }
    }
    return smallest;
}

// ============================================================================
// BRUTE FORCE APPROACH: Sorting
// Time Complexity: O(N log N) | Space Complexity: O(1)
// ============================================================================

int largestElementSort(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1]; // Last element after sorting is the largest
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {2, 5, 6, 2, 8, 9};
    int n = arr.size();

    // Optimal Linear Scan
    int largest = largestElemnt(arr, n);
    int smallest = smallestElement(arr, n);

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Largest element is: " << largest << endl;
    cout << "Smallest element is: " << smallest << endl;

    return 0;
}
