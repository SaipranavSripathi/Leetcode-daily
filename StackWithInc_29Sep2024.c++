class CustomStack {
public:
    vector<int> a;
    int s=0;
    CustomStack(int maxSize) {
        s=maxSize;
    }
    
    void push(int x) {
        if(a.size()<s){
            a.push_back(x);
        }
    }
    
    int pop() {
        if(a.size()>0){
            int x=a[a.size()-1];
            a.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)a.size());i++){
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */