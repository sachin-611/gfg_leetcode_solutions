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
    vector<ListNode*>a;
    int len;
    Solution(ListNode* head) {
        len=0;
        for(int i=0;head!=nullptr;i++){
            a.push_back(head);
            head=head->next;
            len++;
        }
    }
    int getRandom() {
        return a[(rand()%(len))]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */