class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int>m;
        for(auto x:students){
            m[x]++;
        }
        for(int i=0;i<sandwiches.size();i++){
            if(m[sandwiches[i]]){
                m[sandwiches[i]]-=1;
            }
            else return sandwiches.size()-i;
        }
        return 0;
    }
};