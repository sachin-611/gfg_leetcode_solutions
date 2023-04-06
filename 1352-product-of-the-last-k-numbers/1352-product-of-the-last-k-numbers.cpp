class ProductOfNumbers {
public:
    int *a;
    int n;
    ProductOfNumbers() {
        a=new int[100000];
        n=0;
    }
    
    void add(int num) {
        a[n++]=(num);
    }
    
    int getProduct(int k) {
        int ans=1;
        for(int i=0;i<k;i++){
            ans=ans*a[n-1-i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */