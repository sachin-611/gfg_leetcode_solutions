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
    int pairSum(ListNode* head) {
        vector<int>re;
        auto temp=head;
        int res=0;
        for(;temp;temp=temp->next)
            re.push_back(temp->val);
        int n=re.size();
        for(int i=0;i<n;i++){
            res=max(res,re[i]+re[n-1-i]);
        }
        return res;
    }
};