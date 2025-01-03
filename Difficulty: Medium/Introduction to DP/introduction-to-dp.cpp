//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int mod = 1e9+7;
class Solution {
  public:
  
    long long int fib(int n, vector<long long int> &v)
    {
        if(n<=1) return n;
        if(v[n] != -1) return v[n];
        
        return v[n] = (fib(n-1,v) + fib(n-2,v))%mod;
        
    }
    long long int topDown(int n) {
        vector<long long int> v(n+1,-1);
        
        return fib(n,v);
        
    }
    long long int bottomUp(int n) {
        if(n<=1) return n;
        int cur , prev2 = 0 , prev = 1;
        
        for(long long int i=2;i<=n;i++)
        {
            cur = (prev2 + prev)%mod;
            prev2 = prev;
            prev = cur;
        }
        
        return prev;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends