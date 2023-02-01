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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        auto temp=head;
        while(temp){
            if(temp->next and temp->next->next){
                temp=temp->next->next;
                len+=2;
            }
            temp=temp->next;
            ++len;
        }
        if(len<=1 || k%len==0)
            return head;
        k=len-k%len-1;
        temp=head;
        while(k){
            temp=temp->next;
            k--;
        }
        auto heas=head;
        head=temp->next;
        temp->next=nullptr;
        temp=head;
        while(temp and temp->next){temp=temp->next;}
        if(temp)
        temp->next=heas;
        return head;
    }
};