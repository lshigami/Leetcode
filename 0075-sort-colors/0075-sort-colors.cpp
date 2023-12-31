class Solution {
public:
    //Bubble Sort
    
    // void sortColors(vector<int>& v) {
    //     int n=v.size();
    //     for(int i=0;i<n-1;i++){
    //         for(int j=0;j<n-i-1;j++){
    //             if(v[j]>v[j+1]) swap(v[j],v[j+1]);
    //         }
    //     }
    // }
    
    //Selection Sort

    // void sortColors(vector<int>& a){
    //          int n=a.size();
    //     for(int i=0;i<n-1;i++){
    //         int minidx=i;
    //         for(int j=i+1;j<n;j++){
    //             if(a[j]<a[minidx]) minidx=j;
    //         }
    //         swap(a[i],a[minidx]);
    //     }
    // }
    
    // Insertion Sort
    
     void sortColors(vector<int>& a){
         int n=a.size();
         for(int i=1;i<n;i++){
             int pos=i-1;
             int val=a[i];
             while(pos>=0 && a[pos]>val){
                 a[pos+1]=a[pos];
                 pos--;
             }
             a[pos+1]=val;
         }
     }
    
};