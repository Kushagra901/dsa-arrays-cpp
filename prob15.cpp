/**
 * ============================================================================
 * PROBLEM: Single Number (Find the Number That Appears Once, Others Twice)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a non-empty array of integers `arr`, every element appears twice 
 *    except for one unique element which appears exactly once. 
 *    Find and return that single unique element.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Bitwise XOR):
 *        • Time Complexity:  O(N) - Single pass through the array
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Hash Map Approach:
 *        • Time Complexity:  O(N)
 *        • Space Complexity: O(N) - Extra frequency map
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does XOR work so effectively here?
 *    - a ^ a = 0 (Duplicated pairs cancel out).
 *    - a ^ 0 = a (Identity element).
 *    - Associative & Commutative properties ensure that element order does not matter.
 *    - Therefore: (a ^ a) ^ (b ^ b) ^ c = 0 ^ 0 ^ c = c.
 * 
 * 2. How do you solve Single Number II (every element appears 3 times, one appears once - LeetCode 137)?
 *    - Count the sum of bits at each of the 32 bit positions modulo 3, OR use bitwise state machines (ones, twos).
 * 
 * 3. How do you solve Single Number III (two elements appear once, all others twice - LeetCode 260)?
 *    - XOR all numbers to get X = a ^ b.
 *    - Find the lowest set bit in X and partition array elements into two groups to isolate a and b.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 136: Single Number (Easy)
 * 2. LeetCode 137: Single Number II (Medium)
 * 3. LeetCode 260: Single Number III (Medium)
 * 4. GeeksforGeeks: Find the element that appears once in sorted array (Medium)
 * 5. Coding Ninjas: Find The Single Element (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Bitwise XOR
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to find the single element that appears once
int getSingleElement(const vector<int> &arr) {
    int xorr = 0;
    // XOR all elements; duplicate pairs evaluate to 0, leaving the unique element
    for (int i = 0; i < (int)arr.size(); i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int result = getSingleElement(arr);

    cout << "The element that appears only once is: " << result << endl;

    return 0;
}