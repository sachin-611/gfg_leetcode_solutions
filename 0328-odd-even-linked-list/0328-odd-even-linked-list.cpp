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
    void add(ListNode **even_head,ListNode** temp,ListNode**etemp){
        if(!(*even_head)){
            *even_head=*temp;
            *etemp=*temp;
            *temp=(*temp)->next;
            (*etemp)->next=nullptr;
        }else{
            (*etemp)->next=*temp;
            *temp=(*temp)->next;
            *etemp=(*etemp)->next;
            (*etemp)->next=nullptr;
        }
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        
        ListNode* even_head=nullptr;
        auto etemp=even_head;
        ListNode* odd_head=nullptr;
        auto otemp=odd_head;
        auto temp=head;
        int cnt=0;
        while(temp){
            if(cnt%2==0){
                add(&even_head,&temp,&etemp);
            }else{
                add(&odd_head,&temp,&otemp);
            }
            cnt++;
        }
        if(etemp)
        etemp->next=odd_head;
        return even_head;
    }
};