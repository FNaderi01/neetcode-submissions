class MinStack {
private:
int* stk;
int* min_stk;
int size, capacity;

public:
    MinStack() {
        capacity = 1;
        size = 0;
        stk = new int[capacity];
        min_stk = new int[capacity];
    }
    
    void push(int val) {
        if(size==capacity)
            resize();
        
        stk[size] = val;
        if(size-1>=0)
            min_stk[size] = min(val, min_stk[size-1]);
        else min_stk[size] = val;
        size++;
    }
    
    void pop() {
        min_stk[size] = min_stk[size-1];
        size-=1;
    }
    
    int top() {
        return stk[size-1];
    }
    
    int getMin() {
        return min_stk[size-1];
    }
private:
    void resize(){
        capacity = capacity *2;
        int* b = new int[capacity];
        for(int i=0; i<size;i++){
            b[i] = stk[i];
        }
        stk  = b;

        int *new_min = new int[capacity];
        for(int i=0; i<size; i++){
            new_min[i] = min_stk[i];
        }
        min_stk = new_min;
    }

};
