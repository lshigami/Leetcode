class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left=0;
        int right=people.size()-1;
        int ans=0;
        sort(people.begin(),people.end());
        while(left<=right){
            if(people[left]==limit) left+=1;
            else if(people[right]==limit) right-=1;
            else if(people[left]+people[right]<=limit) {
                left+=1;
                right-=1;
            }
            else right-=1;
            ans+=1;
        }
        return ans;
    }
};