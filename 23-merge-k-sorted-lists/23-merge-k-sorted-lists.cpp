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
struct comp{
   bool operator()(ListNode* a,ListNode *b)
   {
       return a->val>b->val;
   }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr)
            {
                pq.push(lists[i]);
            }
        }
        ListNode *head=nullptr,*tail=nullptr;
        while(!pq.empty())
        {
            if(head==nullptr)
            {
                head=tail=pq.top();
                pq.pop();
            }
            else
            {
                tail->next=pq.top();
                pq.pop();
                tail=tail->next;
            }
            if(tail->next!=nullptr)
            {
                pq.push(tail->next);
            }
            tail->next=nullptr;
        }
        return head;
    }
};