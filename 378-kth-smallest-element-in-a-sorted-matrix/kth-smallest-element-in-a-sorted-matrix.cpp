class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(auto x:matrix){
            for(auto i:x){
                pq.push(-i);
            }
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return -pq.top();
    }
};