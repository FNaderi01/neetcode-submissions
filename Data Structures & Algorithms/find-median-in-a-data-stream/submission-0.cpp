class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }

    void addNum(int num) {
        if(left.empty()) {
            left.push(num);
            return;
        }
        if(right.empty()) {
            int l = left.top();
            if(l <= num) {
                right.push(num);
                return;
            }

            left.pop();
            left.push(num);
            right.push(l);
            return;
        }

        int l = left.top();
        int r = right.top();

        if(num <= l) {
            if(left.size() <= right.size()) {
                left.push(num);
            } else {
                left.pop();
                right.push(l);
                left.push(num);
            }
        } else if(num >= r) {
            if(right.size() <= left.size()) {
                right.push(num);
            } else {
                right.pop();
                left.push(r);
                right.push(num);
            }
        } else {
            if(left.size() <= right.size()) {
                left.push(num);
            } else {
                right.push(num);
            }
        }

        return;

    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }

        if(left.size() > right.size()) {
            return left.top();
        }

        return right.top();
    }
};
