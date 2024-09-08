/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode*temp=head;
        while(temp){
            size+=1;
            temp=temp->next;
        }
        int baseSize=size/k;
        int bonusSize=size%k;
        vector<int>v;
        for(int i=1;i<=k;i++){
            if(bonusSize) {
                v.push_back(baseSize+1);
                bonusSize-=1;
            }
            else v.push_back(baseSize);
        }
        temp=head;
        vector<ListNode*>res;
        for(auto x:v){
            if(x==0){
                res.push_back(nullptr);
            }else{
                ListNode*run=temp;
                ListNode*re=temp;
                for(int i=1;i<=x-1;i++){
                    run=run->next;
                }
                temp=run->next;
                run->next=nullptr;
                res.push_back(re);
            }
        }
        return res;
    }
};