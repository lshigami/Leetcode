class Solution {
public:
    int maxArea(vector<int>& h) {
        int left=0;
        int right=h.size()-1;
        int maxWater=0;
        while(left<right){
            int width=right-left;
            int height=min(h[left],h[right]);
            int area=width*height;
            maxWater=max(maxWater,area);
            if(h[left]>h[right]) right-=1;
            else left+=1;
        }
        return maxWater;
    }
};