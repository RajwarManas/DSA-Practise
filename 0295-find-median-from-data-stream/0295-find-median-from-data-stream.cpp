class MedianFinder {
    priority_queue<int> smaller;
    priority_queue<int,vector<int>,greater<int>> larger;
public:
    MedianFinder() {
    }
    void addNum(int num) {
        if(smaller.empty()||num<=smaller.top()) smaller.push(num);
        else larger.push(num);
        if(smaller.size()>larger.size()+1)  {
            int top=smaller.top();
            smaller.pop();
            larger.push(top);
        } else if(larger.size()>smaller.size()) {
            int top=larger.top();
            larger.pop();
            smaller.push(top);
        }
    }
    double findMedian() {
        if(smaller.size()>larger.size()) return (double)smaller.top();
        else return ((double)smaller.top()+larger.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */