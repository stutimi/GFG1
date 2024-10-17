//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

vector<int> subarraySum(vector<int> &arr, int s) {
    int n = arr.size();
    int start = 0;
    int curr_sum = 0;

    for (int end = 0; end < n; end++) {
      
        curr_sum += arr[end];

        while (curr_sum > s && start < end) {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == s) {
            return {start + 1, end + 1}; 
        }
    }

    return {-1};
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends