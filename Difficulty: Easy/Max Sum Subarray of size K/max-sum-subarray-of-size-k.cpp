//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        long long maxSum = INT_MIN;
    int left = 0;
    int right = 0;
    long long windowSum = 0;
    // Tính tổng của cửa sổ ban đầu
    for (right = 0; right < k; right++) {
        windowSum += arr[right];
    }
    maxSum = windowSum;
    // Di chuyển cửa sổ sang phải
    for (right = k; right < n; right++) {
        windowSum = windowSum - arr[left] + arr[right];
        left++;
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends