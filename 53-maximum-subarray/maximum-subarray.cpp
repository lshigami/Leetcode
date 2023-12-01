class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int Max=INT_MIN;
        int Max_cur=0;
        for(int i=0;i<a.size();i++){
            Max_cur=max(Max_cur+a[i],a[i]);
            Max=max(Max,Max_cur);
        }
        return Max;
    }
};