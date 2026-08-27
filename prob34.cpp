/**
 * ============================================================================
 * PROBLEM: Reverse Pairs (LeetCode 493)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `nums`, return the number of reverse pairs in the array.
 *    A reverse pair is defined as a pair `(i, j)` where `0 <= i < j < nums.length` 
 *    and `nums[i] > 2 * nums[j]`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Modified Merge Sort with Disjoint Count Step):
 *        • Time Complexity:  O(2N log N) = O(N log N) (counting pairs takes O(N), merge takes O(N))
 *        • Space Complexity: O(N) auxiliary space for temporary array during merge
 *    - Brute Force Approach (Check all pairs):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why can we NOT count reverse pairs inside the merge step like standard Inversion Count?
 *    - In standard inversion count, the condition is `arr[i] > arr[j]`.
 *    - In Reverse Pairs, the condition is `arr[i] > 2 * arr[j]`. 
 *      Comparing `arr[i]` with `arr[j]` for sorting does NOT tell us the relative order of `arr[i]` vs `2 * arr[j]`.
 *      Therefore, we MUST run a dedicated `countPairs` pass across both sorted halves BEFORE merging!
 * 
 * 2. Why does `countPairs` run in linear O(N) time for two sorted halves?
 *    - Pointer `right` only advances forward across all iterations of `i` because both halves are sorted!
 *      This two-pointer scan takes at most O(n1 + n2) steps.
 * 
 * 3. How do we prevent 32-bit integer overflow when calculating `2 * nums[j]`?
 *    - In C++, if `nums[j]` is large (e.g. 1.5 * 10^9), `2 * nums[j]` overflows 32-bit `int`.
 *      Always cast to 64-bit integer: `1LL * arr[i] > 2LL * arr[right]`.
 * 
 * 4. Can this be solved using Binary Indexed Tree (BIT / Fenwick Tree)?
 *    - Yes, by applying coordinate compression on all values {x, 2x} and querying prefix counts in BIT.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 493: Reverse Pairs (Hard)
 * 2. LeetCode 315: Count of Smaller Numbers After Self (Hard)
 * 3. LeetCode 327: Count of Range Sum (Hard)
 * 4. Coding Ninjas: Team Contest / Reverse Pairs (Hard)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Modified Merge Sort with Separate Two-Pointer Counting
// Time Complexity: O(N log N) | Space Complexity: O(N)
// ============================================================================

// Standard merge step for two sorted subarrays
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Two-pointer count step to count pairs where arr[i] > 2 * arr[right]
int countPairs(const vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++) {
        // Cast to long long to prevent integer overflow
        while (right <= high && (1LL * arr[i] > 2LL * arr[right])) {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

// Recursive merge sort function
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);              // Count pairs in left half
    cnt += mergeSort(arr, mid + 1, high);         // Count pairs in right half
    cnt += countPairs(arr, low, mid, high);       // Count cross reverse pairs
    merge(arr, low, mid, high);                   // Merge the two sorted halves

    return cnt;
}

// Wrapper function
int team(vector<int> &skill, int n) {
    return mergeSort(skill, 0, n - 1);
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {4, 1, 2, 3, 1};
    int n = a.size();

    cout << "Original Array: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int cnt = team(a, n);
    cout << "The number of reverse pairs (arr[i] > 2 * arr[j]) is: " << cnt << endl;

    return 0;
}
