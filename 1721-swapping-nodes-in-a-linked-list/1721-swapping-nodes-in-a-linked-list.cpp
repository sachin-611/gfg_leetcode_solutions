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
    ListNode* reverse(ListNode*head){
        ListNode*nhead=head;
        head=head->next;
        nhead->next=nullptr;
        while(head){
            auto temp=head;
            head=head->next;
            temp->next=nhead;
            nhead=temp;
        }
        return nhead;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        auto ok1=head,ok2=head;
        auto tem=head;
        for(int i=0;i<k;i++){
            ok1=tem;
            tem=tem->next;
        }
        head=reverse(head);
        tem=head;
        for(int i=0;i<k;i++){
            ok2=tem;
            tem=tem->next;
        }
        swap(ok1->val,ok2->val);
        return reverse(head);
    }
};