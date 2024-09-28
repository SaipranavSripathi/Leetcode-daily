class MyCircularDeque {
public:
    list<int> a;
    int k;
    MyCircularDeque(int kg) {
        k=kg;
    }
    
    bool insertFront(int value) {
        if(a.size()<k)
        a.push_front(value);
        else 
        return false;
        return true;
    }
    
    bool insertLast(int value) {
        if(a.size()<k){
            a.push_back(value);
            return true;
        }
        else
        return false;
        
    }
    
    bool deleteFront() {
        if(a.size()==0)
        return false;
        a.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(a.size() ==0)
        return false;
        a.pop_back();
        return true;
    }
    
    int getFront() {
        if(a.size()>0)
        return a.front();
        return -1;
    }
    
    int getRear() {
        if(a.size()>0)
        return a.back();
        return -1;
    }
    
    bool isEmpty() {
        return a.size()==0;
    }
    
    bool isFull() {
        return (a.size()==k);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */