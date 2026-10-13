/**
 * ============================================================================
 * PROBLEM: Single Number (Find the Element that Appears Once)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a non-empty array of integers `nums`, every element appears twice 
 *    except for one. Find that single one.
 *    You must implement a solution with a linear runtime complexity and use 
 *    only constant extra space.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force (Linear Scan for Pairs):
 *        • Time Complexity:  O(N^2) - For each element, count its occurrences
 *        • Space Complexity: O(1)
 *    - 2. Better 1 (Sorting):
 *        • Time Complexity:  O(N log N) - Sorting the array + linear check
 *        • Space Complexity: O(1) or O(N) depending on sort
 *    - 3. Better 2 (Hashing):
 *        • Time Complexity:  O(N) - Hash map frequency counting
 *        • Space Complexity: O(N) - Auxiliary space for hash table
 *    - 4. Optimal Approach (Bitwise XOR):
 *        • Time Complexity:  O(N) - Single pass through array of size N
 *        • Space Complexity: O(1) - Constant auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does Bitwise XOR solve this problem in O(1) space?
 *    - XOR properties:
 *        • `a ^ a = 0` (any number XORed with itself is 0)
 *        • `a ^ 0 = a` (any number XORed with 0 is itself)
 *        • XOR is commutative and associative: order of operations does not matter.
 *    - All duplicate pairs cancel each other out: `(a ^ a) ^ (b ^ b) ^ c = 0 ^ 0 ^ c = c`.
 * 
 * 2. What if every element appears THREE times except one? (LeetCode 137)
 *    - Cannot use simple XOR because 3 occurrences do not cancel to 0.
 *    - Solved by bit-counting modulo 3 or using two state variables (`ones`, `twos`) in O(N) and O(1).
 * 
 * 3. What if TWO elements appear once, and all others appear twice? (LeetCode 260)
 *    - XOR all elements to get `xor = a ^ b`.
 *    - Find the rightmost set bit in `xor` to divide elements into two groups and XOR each group.
 * 
 * 4. Can we handle negative numbers?
 *    - Yes, bitwise operations naturally operate on 2's complement binary representation.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 136: Single Number (Easy)
 * 2. LeetCode 137: Single Number II (Medium)
 * 3. LeetCode 260: Single Number III (Medium)
 * 4. GeeksforGeeks: Find the element that appears once in sorted array (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Nested Counting
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int getSingleElementBrute(const vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count == 1) return arr[i];
    }
    return -1;
}

// ============================================================================
// 2. BETTER APPROACH 1: Sorting
// Time Complexity: O(N log N) | Space Complexity: O(1)
// ============================================================================

int getSingleElementSort(vector<int> arr) {
    int n = arr.size();
    if (n == 1) return arr[0];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i += 2) {
        // If last element or not equal to next element
        if (i == n - 1 || arr[i] != arr[i + 1]) {
            return arr[i];
        }
    }
    return -1;
}

// ============================================================================
// 3. BETTER APPROACH 2: Hashing
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

int getSingleElementHash(const vector<int> &arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;

    for (const auto &it : freq) {
        if (it.second == 1) return it.first;
    }
    return -1;
}

// ============================================================================
// 4. OPTIMAL APPROACH: Bitwise XOR
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int getSingleElement(const vector<int> &arr) {
    int xorr = 0;
    // XOR all elements; duplicate pairs evaluate to 0, leaving the unique element
    for (int x : arr) {
        xorr ^= x;
    }
    return xorr;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Single Element (Brute Force): " << getSingleElementBrute(arr) << endl;
    cout << "Single Element (Sorting):     " << getSingleElementSort(arr) << endl;
    cout << "Single Element (Hashing):     " << getSingleElementHash(arr) << endl;
    cout << "Single Element (Bitwise XOR): " << getSingleElement(arr) << endl;

    return 0;
}
