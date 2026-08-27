/**
 * ============================================================================
 * PROBLEM: Count Inversions in an Array (Modified Merge Sort)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `a`, count the number of inversions.
 *    An inversion is defined as a pair of indices `(i, j)` such that 
 *    `i < j` and `a[i] > a[j]`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Modified Merge Sort):
 *        • Time Complexity:  O(N log N) - Dividing into halves and merging in linear time
 *        • Space Complexity: O(N) auxiliary space for temporary array during merge
 *    - Brute Force Approach (Check all pairs):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does Merge Sort count inversions in O(N log N)?
 *    - When merging two sorted halves `arr[low..mid]` and `arr[mid+1..high]`, 
 *      if `arr[left] > arr[right]`, then because the left half is SORTED, all elements 
 *      from `left` to `mid` are strictly greater than `arr[right]`.
 *      Thus, we add `(mid - left + 1)` to the inversion count in one step!
 * 
 * 2. What is the relation between Inversion Count and Bubble Sort?
 *    - The number of inversions in an array equals the EXACT number of adjacent swaps 
 *      required by Bubble Sort to sort the array.
 * 
 * 3. Can Inversions be counted using Data Structures (Fenwick Tree / Segment Tree)?
 *    - Yes! By inserting elements into a Binary Indexed Tree (BIT) / Fenwick Tree with coordinate compression,
 *      we can query and count inversions in O(N log N) time online.
 * 
 * 4. What is the maximum possible number of inversions for an array of size N?
 *    - For a reverse sorted array [N, N-1, ... 1], max inversions = N * (N - 1) / 2.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Inversion of array (Medium)
 * 2. Coding Ninjas: Count Inversions (Medium)
 * 3. LeetCode 493: Reverse Pairs (Hard)
 * 4. LeetCode 315: Count of Smaller Numbers After Self (Hard)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Modified Merge Sort
// Time Complexity: O(N log N) | Space Complexity: O(N)
// ============================================================================

// Function to merge two sorted halves and count cross-inversions
long long merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;      // Temporary buffer for sorted elements
    int left = low;        // Starting index of left half [low .. mid]
    int right = mid + 1;   // Starting index of right half [mid + 1 .. high]
    long long cnt = 0;     // Inversion counter

    // Merge elements in sorted order while counting inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            // arr[left] > arr[right] -> all elements from left to mid form inversions with arr[right]
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // Copy remaining elements of left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Transfer back sorted elements to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

// Recursive function to perform merge sort and accumulate inversion counts
long long mergeSort(vector<int> &arr, int low, int high) {
    long long cnt = 0;
    if (low >= high) return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);       // Inversions in left half
    cnt += mergeSort(arr, mid + 1, high);  // Inversions in right half
    cnt += merge(arr, low, mid, high);     // Cross-inversions during merge

    return cnt;
}

// Wrapper function to calculate total number of inversions
long long numberOfInversions(vector<int> &a, int n) {
    return mergeSort(a, 0, n - 1);
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();

    cout << "Original Array: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    long long cnt = numberOfInversions(a, n);

    cout << "The number of inversions is: " << cnt << endl;

    return 0;
}
