class Solution {
public:
    double distanceBetween(int a,int b, int x, int y){
        return sqrt(pow((a-x),2)+pow((b-y),2));
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>s;
        for(auto cir:circles){
            for(int x=cir[0]-cir[2];x<=cir[0]+cir[2];x+=1){
                for(int y=cir[1]-cir[2];y<=cir[1]+cir[2];y+=1){
                    if(distanceBetween(x,y,cir[0],cir[1])<=cir[2]){
                        s.insert({x,y});
                    }
                }
            }
        }
        return s.size();
    }
};