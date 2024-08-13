class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>children(k,0);
        int optimal=INT_MAX;
        distribute(children,cookies,0,optimal,k);
        return optimal;
    }
    void distribute(vector<int>&children,vector<int>cookies,int index,int &optimal,int k){
        for(int i=0;i<k;i++){
            children[i]+=cookies[index];
            if(index==cookies.size()-1){
                int MAX=INT_MIN;
                for(auto x:children){
                    MAX=max(x,MAX);
                }
                optimal=min(optimal,MAX);
            }
            else{
                distribute(children,cookies,index+1,optimal,k);
            }
            children[i]-=cookies[index];
        }
    }
};