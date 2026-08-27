/**
 * ============================================================================
 * PROBLEM: Find Second Largest and Second Smallest Element in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `arr` of size `n`, find the second largest 
 *    and second smallest elements without sorting the array.
 *    If no such element exists (e.g. array size < 2 or all elements equal),
 *    return -1 or appropriate indicator.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Single-Pass Traversal):
 *        • Time Complexity:  O(N) - One single pass over the array
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Better Approach (Two-Pass Traversal):
 *        • Time Complexity:  O(2N) = O(N) - Pass 1 to find max/min, Pass 2 to find 2nd max/min
 *        • Space Complexity: O(1)
 *    - Brute Force Approach (Sorting):
 *        • Time Complexity:  O(N log N) - Sorting the array
 *        • Space Complexity: O(1) or O(N)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does `arr[n - 2]` fail after sorting if there are duplicates?
 *    - If the array is [10, 10, 10, 9], after sorting the last two elements are
 *      both 10. The true second largest is 9, not `arr[n - 2]`. We must scan backwards
 *      from the end until an element smaller than `arr[n - 1]` is found.
 * 
 * 2. How do you find the second largest in a single pass O(N)?
 *    - Maintain two variables: `largest` and `secondLargest`.
 *    - When `arr[i] > largest`: `secondLargest = largest`, `largest = arr[i]`.
 *    - Else if `arr[i] < largest && arr[i] > secondLargest`: `secondLargest = arr[i]`.
 * 
 * 3. What if all elements in the array are identical (e.g., [7, 7, 7, 7])?
 *    - `secondLargest` will remain at its initial sentinel value (-1 or INT_MIN),
 *      signifying that no distinct second largest element exists.
 * 
 * 4. What if the array contains negative numbers?
 *    - Initialize `secondLargest` to `INT_MIN` instead of `-1` to handle negative arrays correctly.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 414: Third Maximum Number (Easy)
 * 2. GeeksforGeeks: Second Largest (Easy)
 * 3. Coding Ninjas: Second Largest Number (Easy)
 * 4. LeetCode 215: Kth Largest Element in an Array (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Single-Pass Traversal
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to find second largest in a single pass
int secondLargest(vector<int> &a, int n) {
    if (n < 2) return -1;

    int largest = a[0];
    int slargest = -1; // Or INT_MIN for negative numbers

    for (int i = 1; i < n; i++) {
        if (a[i] > largest) {
            slargest = largest; // Previous largest becomes second largest
            largest = a[i];     // Current element is new largest
        }
        else if (a[i] < largest && a[i] > slargest) {
            slargest = a[i];    // Element is between largest and second largest
        }
    }
    return slargest;
}

// Function to find second smallest in a single pass
int secondSmallest(vector<int> &a, int n) {
    if (n < 2) return -1;

    int smallest = a[0];
    int ssmallest = INT_MAX;

    for (int i = 1; i < n; i++) {
        if (a[i] < smallest) {
            ssmallest = smallest; // Previous smallest becomes second smallest
            smallest = a[i];      // Current element is new smallest
        }
        else if (a[i] != smallest && a[i] < ssmallest) {
            ssmallest = a[i];     // Element is between smallest and second smallest
        }
    }
    return (ssmallest == INT_MAX) ? -1 : ssmallest;
}

// Returns both second largest and second smallest
vector<int> getSecondOrderElement(int n, vector<int> a) {
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);
    return {slargest, ssmallest};
}

// ============================================================================
// 2. BETTER APPROACH: Two-Pass Traversal
// Time Complexity: O(2N) = O(N) | Space Complexity: O(1)
// ============================================================================

int secLarTwoPass(vector<int> &arr, int n) {
    if (n < 2) return -1;

    // Pass 1: Find largest element
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Pass 2: Find largest element strictly smaller than max
    int slargest = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > slargest && arr[i] != largest) {
            slargest = arr[i];
        }
    }
    return slargest;
}

// ============================================================================
// 3. BRUTE FORCE APPROACH: Sorting
// Time Complexity: O(N log N) | Space Complexity: O(1)
// ============================================================================

int secLarSorting(vector<int> &arr, int n) {
    if (n < 2) return -1;

    sort(arr.begin(), arr.end());
    int largest = arr[n - 1];
    int secondLar = -1;

    // Scan backwards to find the first distinct smaller element
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != largest) {
            secondLar = arr[i];
            break;
        }
    }
    return secondLar;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() { 
    vector<int> arr = {4, 7, 2, 8, 9, 1};
    int n = arr.size();
    
    vector<int> result = getSecondOrderElement(n, arr);
    
    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Second Largest: " << result[0] << endl;
    cout << "Second Smallest: " << result[1] << endl;

    return 0;
}