class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,bool>visited;
        map<char,pair<int,int>>m;
        m['N']={0,1};
        m['E']={1,0};
        m['S']={0,-1};
        m['W']={-1,0};
        pair<int,int>location={0,0};
        visited[location]=true;
        for(auto x:path){
            location.first+=m[x].first;
            location.second+=m[x].second;
            if(visited[location]) return true;
            else visited[location]=true;
        }
        return false;
    }
};