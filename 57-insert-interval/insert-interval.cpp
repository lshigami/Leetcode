class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        stack<vector<int>>st;
        int i=0;
        while(i<intervals.size()){
            if(st.empty()) st.push(intervals[i]);
            if(intervals[i][0] <= st.top()[1] ){
                vector<int>temp=st.top();
                temp[0]=min(intervals[i][0],st.top()[0]);
                temp[1]=max(intervals[i][1],st.top()[1]);
                st.pop();
                st.push(temp);
            }
            else st.push(intervals[i]);
            i++;
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};