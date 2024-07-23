class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int,int>m;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()) {
                m[nums2[i]]=-1;
            }else{
                //1 4 3 5 2
                while(!st.empty() && nums2[i]>=nums2[st.top()]){
                    st.pop();
                }
                if(st.empty()) m[nums2[i]]=-1;
                else m[nums2[i]]=nums2[st.top()];
            }
            st.push(i);
        }
        vector<int>ans;
        for(auto x:nums1){
            ans.push_back(m[x]);
        }
        return ans;
    }
};