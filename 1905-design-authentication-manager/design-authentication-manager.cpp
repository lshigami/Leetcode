class AuthenticationManager {
private:
    int timeOut;
    map<string,int>m;
public:
    AuthenticationManager(int timeToLive) {
        this->timeOut=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId]=currentTime+timeOut;
    }
    
    void renew(string tokenId, int currentTime) {
        if(m.find(tokenId)==m.end()) return;
        if(m[tokenId]>currentTime){
            m[tokenId]=currentTime+timeOut;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
       int cnt=0; 
        for(auto x:m){
            if(x.second>currentTime){
                cnt+=1;
            }
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */