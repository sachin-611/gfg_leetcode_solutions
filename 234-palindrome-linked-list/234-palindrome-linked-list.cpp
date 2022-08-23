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
    bool isPalindrome(ListNode* head) {
        auto slow=head,fast=head;
        while(slow and fast and fast->next and slow->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        auto nhead=head,tail=head;
        nhead=nullptr;
        tail=nullptr;
        while(slow->next!=nullptr)
        {
            if(nhead==nullptr)
            {
                nhead=slow->next;
                slow->next=slow->next->next;
                nhead->next=nullptr;
            }
            else
            {
                tail=slow->next;
                slow->next=slow->next->next;
                tail->next=nhead;
                nhead=tail;
            }
        }
        slow->next=nhead;
        fast=head;
        tail=nhead;
        while(fast and tail)
        {
            if(fast->val != tail->val)
                return false;
            fast=fast->next;
            tail=tail->next;
        }
        return true;
    }
};