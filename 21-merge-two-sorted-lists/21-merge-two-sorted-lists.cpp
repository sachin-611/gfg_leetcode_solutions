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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto temp=list1,last=list1;
        temp=last=nullptr;
        while(list1 and list2)
        {
            if(list1->val<list2->val)
            {
                if(temp==nullptr)
                {
                    last=temp=list1;
                    list1=list1->next;
                }
                else
                {
                    last->next=list1;
                    list1=list1->next;
                    last=last->next;
                }
                last->next=nullptr;
            }
            else
            {
                if(temp==nullptr)
                {
                    last=temp=list2;
                    list2=list2->next;
                }
                else
                {
                    last->next=list2;
                    list2=list2->next;
                    last=last->next;
                }
                last->next=nullptr;
            }
        }
        while(list1)
        {
            if(temp==nullptr)
            {
                last=temp=list1;
                list1=list1->next;
            }
            else
            {
                last->next=list1;
                list1=list1->next;
                last=last->next;
            }
            last->next=nullptr;
        }
        while(list2)
        {
            if(temp==nullptr)
                {
                    last=temp=list2;
                    list2=list2->next;
                }
                else
                {
                    last->next=list2;
                    list2=list2->next;
                    last=last->next;
                }
                last->next=nullptr;
        }
        return temp;
    }
};