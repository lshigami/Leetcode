class TopVotedCandidate {
    vector<int>times;
    vector<int>leader;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times=times;
        int n=persons.size();
        map<int,int>personVote;
        int maxVote=0;
        int leaderNow=-1;
        for(int i=0;i<n;i++){
            personVote[persons[i]]+=1;

            if(personVote[persons[i]]>=maxVote){
                leaderNow=persons[i];
                maxVote=personVote[persons[i]];
            }

            leader.push_back(leaderNow);
        }
    }
    
    int q(int t) {
        auto it = lower_bound(times.begin(),times.end(),t);
        int index;
        if(it==times.end()) return leader[leader.size()-1];
        if(*it==t) index=it-times.begin();
        else index=it-times.begin()-1;
        return leader[index];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */