class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==1 ) {
            if(flowerbed[0]==1) return false; else return true;
        }
        for(int i=0;i<flowerbed.size();i++){
            if(i==0 && i+1<flowerbed.size() && flowerbed[i]==0 && flowerbed[i+1]==0) {
                n--;
                flowerbed[i]=1;
            }
            if(i+1<flowerbed.size() && i-1>=0 && flowerbed[i+1]==0 && flowerbed[i-1]==0 && flowerbed[i]==0) {
                n--;
                flowerbed[i]=1;
            }
            if(i==flowerbed.size()-1 && i-1>=0 && flowerbed[i]==0 && flowerbed[i-1]==0) {
                n--;
                flowerbed[i]=1;
            }
            if(n==0) return true;
        }
        return false;
    }
};