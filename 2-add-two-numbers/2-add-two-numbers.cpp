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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode;
        ListNode *temp=result;
        bool carry=0;
        while(l1 and l2)
        {
            temp->next=new ListNode((l1->val+l2->val+carry)%10);
            temp=temp->next;
            if(l1->val+l2->val+carry>=10)
                carry=1;
            else
                carry=0;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            temp->next=new ListNode((l1->val+carry)%10);
            temp=temp->next;
            if(l1->val+carry>=10)
                carry=1;
            else
                carry=0;
            l1=l1->next;
        }
        while(l2)
        {
            temp->next=new ListNode((l2->val+carry)%10);
            temp=temp->next;
            if(l2->val+carry>=10)
                carry=1;
            else
                carry=0;
            l2=l2->next;
        }
        if(carry)
        {
            temp->next=new ListNode(carry);
        }
        return result->next;
    }
};