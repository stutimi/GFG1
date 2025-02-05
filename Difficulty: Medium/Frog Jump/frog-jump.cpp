//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0; 
        int prev = 0, prev2 = 0; 
        for (int i = 1; i < n; i++) {
            int jumpOne = prev + abs(height[i] - height[i - 1]);
            int jumpTwo = INT_MAX;
            if (i > 1)
                jumpTwo = prev2 + abs(height[i] - height[i - 2]);
            int cur = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};



//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends