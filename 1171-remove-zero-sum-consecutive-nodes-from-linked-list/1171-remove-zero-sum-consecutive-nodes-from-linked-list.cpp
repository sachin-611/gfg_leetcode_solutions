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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>m;
        int sum=0;
        auto temp=head;
        int cnt=0;
        while(temp){
            sum+=temp->val;
            if(sum==0){
                head=temp->next;
            }
            else if(m.count(sum)){
                m[sum]->next=temp->next;
                cnt++;
            }
            else{
                m[sum]=temp;
            }
                temp=temp->next;
        }
        if(cnt==0)return head;
        return removeZeroSumSublists(head);
    }
};