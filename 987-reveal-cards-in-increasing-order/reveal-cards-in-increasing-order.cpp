class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        //[17]
        //[13 17]
        //[11 17 13]
        //[7 13 11 17]
        //[5 17 7 13 11 ]
        //[3 11 5 17 7 13  ]
        //[2 13 3 11 5 17 7 ]
        queue<int>q;
        //2 3 5 7 11 13 17
        sort(deck.begin(),deck.end(),greater<int>());
        for(auto x:deck){
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            q.push(x);
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }  
};