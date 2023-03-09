/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>ok;
        while(head){
            if(ok.count(head)){
                return head;
            }
            ok.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};