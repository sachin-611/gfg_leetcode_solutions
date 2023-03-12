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
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* fin=nullptr,*cur=nullptr;
        priority_queue<ListNode*,vector<ListNode*>,comp>p;
        for(auto i:lists){
            if(i){
                p.push(i);
            }
        }
        while(!p.empty()){
            auto top=p.top();
            p.pop();
            if(cur==nullptr){
                cur=fin=top;
            }else{
                cur->next=top;
            }
            if(top->next){{
                p.push(top->next);
            }}
            top->next=nullptr;
            cur=top;
        }
        return fin;
    }
};