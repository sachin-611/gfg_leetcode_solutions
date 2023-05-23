class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>p;
    int k,i;
    KthLargest(int k, vector<int>& nums) {
        this->i=0;
        for(int i=0;i<k and i<nums.size();i++){
            p.push(nums[i]);
            this->i++;
        }
        this->k=k;
        for(int i=k;i<nums.size();i++){
            if(p.top()<nums[i]){
                p.pop();
                p.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(i<k){
            p.push(val);
            i++;
        }
        else if(p.top()<val){
            p.pop();
            p.push(val);
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */