class DSU{
private:
    vector<int>Parent,Size;
public :
    void setParent(vector<int>v){
        Parent=v;
    }
    vector<int>getParent(){
        return Parent;
    }
    DSU(int n){
        Parent.resize(n);
        Size.resize(n);
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Size[i]=1;
        }
    }
    int Find(int x){
        if(x==Parent[x]) return x;
        return Parent[x]=Find(Parent[x]);
    }
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int saveCommon =findSave(n,edges,dsu,3);
        DSU dsu1(n);
        dsu1.setParent(dsu.getParent());
        DSU dsu2(n);
        dsu2.setParent(dsu.getParent());
        int saveAlice =findSave(n,edges,dsu1,1);
        if(saveAlice==-1) return -1;
        int saveBob =findSave(n,edges,dsu2,2);
        if(saveBob==-1) return -1;
        return saveCommon+saveAlice+saveBob;
    }
    int findSave(int n, vector<vector<int>>& edges,DSU &dsu,int type){
        int save=0;
        for(auto e:edges){
            if(e[0]!=type) continue;
            if(!dsu.Union(e[1]-1,e[2]-1)) {
                save+=1;
                continue;
            }

        }
        if(type==3) return save;
        for(int i=0;i<n;i++){
            int p=dsu.Find(i);
            if(p!=0) return -1;
        }
        return save;
    }
};