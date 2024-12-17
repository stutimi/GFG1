//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end()); 
        int l = 1; 
        int r = stalls[n - 1] - stalls[0]; 
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (canPlaceCows(stalls, k, mid)) {
                ans = mid; 
                l = mid + 1; 
            } else {
                r = mid - 1; 
            }
        }
        return ans;
    }
private:
    bool canPlaceCows(vector<int> &stalls, int k, int dist) {
        int count = 1; 
        int lastPos = stalls[0]; 
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) { 
                count++;
                lastPos = stalls[i];
                if (count == k) {
                    return true; 
                }
            }
        }
        return false; 
    }
};




//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends