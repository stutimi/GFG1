//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int search(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid element is the key
        if (arr[mid] == key) return mid;
        
        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if key is in the left half
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } 
        // Otherwise, the right half must be sorted
        else {
            // Check if key is in the right half
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    
    // If key is not found, return -1
    return -1;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends