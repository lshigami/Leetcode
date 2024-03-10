class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int>s1;
        stack<int>s2;
        int n=v.size();
        int left[n];
        int right[n];
        for(int i=0;i<n;i++){
            while(!s1.empty() && v[s1.top()]>=v[i]) s1.pop();
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && v[s2.top()]>=v[i]) s2.pop();
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*v[i]);
        }
        return ans;
    }
};