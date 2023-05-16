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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next==nullptr)
            return head;
        auto dummy=new ListNode;
        dummy->next=head;
        auto test=dummy;
        while(test->next){
            if(test->next->next){
                auto ok=test->next;
                test->next=test->next->next;
                ok->next=test->next->next;
                test->next->next=ok;
                test=test->next->next;
            }else{
                test=test->next;
            }
        }
        return dummy->next;
    }
};