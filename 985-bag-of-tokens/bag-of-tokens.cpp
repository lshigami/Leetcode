class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int left=0;
        int right=tokens.size()-1;
        int ans=0;
        while(left<=right){
            if(tokens[left]<=power){
                ans+=1;
                power-=tokens[left];
                left+=1;
            }
            else if(ans && left!=right){
                    power+=tokens[right];
                    ans-=1;
                    right-=1;
            }
            else{
                left+=1;
            }
        }
        return ans;
    }
};