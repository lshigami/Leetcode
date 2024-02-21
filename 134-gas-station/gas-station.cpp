class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tank=0;
        int start=0;
        for(int i=0;i<2*n && start<n;i++){
            int idx=i%n;
            tank+=gas[idx]-cost[idx];
            if(tank<0){
                start=i+1;
                tank=0;
            }
            if(i-start==n) return start;
        }
        return -1;
    }
};