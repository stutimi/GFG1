//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        // Code here.
        bool canPair(vector<int> nums, int k) {
    vector<int> freq(k, 0);

    // Count frequencies of remainders
    for (int num : nums) {
        int remainder = ((num % k) + k) % k;  // Handling negative remainders
        freq[remainder]++;
    }

    // Check for pairing conditions
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            // For remainder 0, frequency must be even
            if (freq[i] % 2 != 0) return false;
        } else if (i == k - i) {
            // If k is even, frequency of remainder k/2 must be even
            if (freq[i] % 2 != 0) return false;
        } else {
            // For remainder i, freq[i] must match freq[k-i]
            if (freq[i] != freq[k - i]) return false;
        }
    }

    return true;  // All pairs can be formed
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends