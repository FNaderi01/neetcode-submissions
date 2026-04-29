class DynamicArray {
private:
int capacity, size;
int* a;

public:

    DynamicArray(int capacity) {
        this-> capacity = capacity;
        a = new int[capacity];
        size =0;
    }

    int get(int i) {
        return a[i];
    }

    void set(int i, int n) {
        a[i] = n;
    }

    void pushback(int n) {
        if(size < capacity){
            a[size] = n;
            size++;
        }
        else{
            resize();
            a[size] = n;
            size++;
        }
    }

    int popback() {
        int r = a[size-1];
        size --;
        return r;

    }

    void resize() {
        int new_cap = capacity *2;
        int* new_arr = new int[new_cap];

        for(int i =0; i< size; i++){
            new_arr[i] = a[i];
        }
        a = new_arr;
        capacity = new_cap;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
