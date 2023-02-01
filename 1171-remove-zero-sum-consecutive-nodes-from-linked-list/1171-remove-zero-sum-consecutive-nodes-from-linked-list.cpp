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
        unordered_map<int,ListNode*>m;
public:
    void print(){
        for(auto i:m){
            cout<<"{"<<i.first<<" "<<i.second->val<<"}"
        ;}
        cout<<endl;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum=0;
        auto temp=head;
        int cnt=0;
        while(temp){
            sum+=temp->val;
            if(sum==0){
                head=temp->next;
                m.clear();
            }
            else if(m.count(sum)){
                auto rms=m[sum]->next;
                int sms=sum;
                bool beg=1;
                // print();
                while(sms!=sum or beg){
                    beg=0;
                    sms+=rms->val;
                    if(sms!=sum)
                    m.erase(sms);
                    rms=rms->next;
                }
                // print();
                m[sum]->next=temp->next;
                cnt++;
            }
            else{
                m[sum]=(temp);
            }
                temp=temp->next;
        }
        temp=head;
        auto prev=temp;
        while(temp){
            if(temp->val==0){
                if(temp==head){
                    head=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
            }
            prev=temp;
            temp=temp->next;
        }
        // cout<<endl;
        return head;
    }
};