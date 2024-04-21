class DSU{
private:
    vector<int>Parent,Size;
public :
	// O(N)
    DSU(int n){
        Parent.resize(n);
        Size.resize(n);
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Size[i]=1;
        }
    }
    // O(N)
    int Find(int x){
        if(x==Parent[x]) return x;
        return Parent[x]=Find(Parent[x]);
    }
    //O(N)
    bool Union(int x,int y){
        x=Find(x);
        y=Find(y);
        if(x==y) return false;
        // if(Size[x]<Size[y]){
        //     swap(x,y);
        // }
        // Parent[y] = x;
        // Size[x] += Size[y];
        if(x<y) Parent[y]=x;
        else Parent[x]=y;
        return true;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        DSU dsu(n);
        for(auto x:edges){
            dsu.Union(x[0],x[1]);
        }
        if(dsu.Union(source,des)) return false;
        return true;
    }
};