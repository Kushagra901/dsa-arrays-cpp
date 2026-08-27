/**
 * ============================================================================
 * PROBLEM: Two Sum (Check Pair with Given Target Sum)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `book` of size `n` and an integer `target`, 
 *    determine whether there exists a pair of elements in the array whose sum 
 *    equals `target`. Return "YES" if such a pair exists, otherwise "NO".
 *    (Variation 2: Return the 0-based indices of the two elements).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal for Returning YES/NO (Sorting + Two Pointers):
 *        • Time Complexity:  O(N log N) for sorting + O(N) for two pointers = O(N log N)
 *        • Space Complexity: O(1) auxiliary space (in-place)
 *    - Optimal for Returning INDICES (Hash Map / Unordered Map):
 *        • Time Complexity:  O(N) average time
 *        • Space Complexity: O(N) auxiliary space for hash map
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does Hash Map achieve O(N) time for Two Sum?
 *    - For each element `x`, we check if `target - x` is already in the map in O(1) average time.
 *      If found, we immediately get the matching index.
 * 
 * 2. Why is Two-Pointer preferred when only a boolean ("YES"/"NO") is required and space is restricted?
 *    - Sorting + Two Pointers uses O(1) extra space without hash collision or allocation overhead.
 * 
 * 3. What if the array is ALREADY sorted? (LeetCode 167: Two Sum II)
 *    - Two Pointers runs in strictly O(N) time and O(1) space directly.
 * 
 * 4. Can an element be used twice (e.g. `arr[i] + arr[i] == target`)?
 *    - No, the two elements must reside at distinct indices.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1: Two Sum (Easy)
 * 2. LeetCode 167: Two Sum II - Input Array Is Sorted (Medium)
 * 3. LeetCode 15: 3Sum (Medium)
 * 4. GeeksforGeeks: Key Pair / Two Sum (Easy)
 * 5. Coding Ninjas: Reading (Two Sum Variety) (Easy)
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// ============================================================================
// 1. TWO POINTERS APPROACH: (Returns YES/NO using O(1) extra space)
// Time Complexity: O(N log N) | Space Complexity: O(1)
// ============================================================================

string read(int n, vector<int> book, int target) {
    int left = 0, right = n - 1;
    sort(book.begin(), book.end()); // Sort the array

    while (left < right) {
        int sum = book[left] + book[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) {
            left++; // Need a larger sum, advance left pointer
        }
        else {
            right--; // Need a smaller sum, retreat right pointer
        }
    }
    return "NO";
}

// ============================================================================
// 2. HASH MAP APPROACH: (Returns Indices in O(N) time)
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

vector<int> twoSumIndices(const vector<int> &nums, int target) {
    unordered_map<int, int> mpp; // {element -> index}
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (mpp.find(complement) != mpp.end()) {
            return {mpp[complement], i};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> book = {4, 1, 2, 3, 1};
    int n = book.size();
    int target = 5;

    cout << "Array elements: ";
    for (int x : book) cout << x << " ";
    cout << "\nTarget: " << target << endl;

    string result = read(n, book, target);
    cout << "Pair with target sum exists: " << result << endl;

    vector<int> indices = twoSumIndices(book, target);
    if (indices[0] != -1) {
        cout << "Indices of pair: [" << indices[0] << ", " << indices[1] << "]" << endl;
    }

    return 0;
}
