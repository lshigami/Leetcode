class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 2 3 5 7 11 13 17
        int n=deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[q.front()]=deck[i];
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};