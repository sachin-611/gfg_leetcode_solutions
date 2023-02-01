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
        vector<ListNode*>ok(k);
        auto temp=head;
        int len=0;
        while(temp){len++;temp=temp->next;}
        int cnt=len/k;
        int carry=len%k;
        temp=head;
        for(int i=0;i<k;i++){
            ok[i]=temp;
            int cnts=cnt;
            auto prev=temp;
            while(temp and cnts){
                cnts--;
                prev=temp;
                temp=temp->next;
            }
            if(carry>0 and temp){
                prev=temp;
                temp=temp->next;
                carry--;
            }
            if(prev)
            prev->next=nullptr;
        }
        return ok;
    }
};