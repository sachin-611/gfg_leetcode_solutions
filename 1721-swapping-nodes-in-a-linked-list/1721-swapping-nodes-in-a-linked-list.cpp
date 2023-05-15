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
        auto temp=head,left=head,right=head;
        int cnt=1;
        while(temp){
            if(cnt<k){
                left=left->next;
            }
            else if(cnt>k){
                right=right->next;
            }
            cnt++;
            temp=temp->next;
        }
        swap(left->val,right->val);
        return head;
    }
};