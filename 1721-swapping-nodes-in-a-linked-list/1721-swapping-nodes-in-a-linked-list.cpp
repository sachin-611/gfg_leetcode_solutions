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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*>ok;
        ListNode*a=head;
        for(;a!=nullptr;a=a->next){
                ok.push_back(a);
        }
        int l=0,r=ok.size()-1;
            l+=(k-1);
            r-=(k-1);
            l%=ok.size();
            r=(r+ok.size()*100)%ok.size();
            // if(l<r)
            swap(ok[l]->val,ok[r]->val);
        return head;
    }
};