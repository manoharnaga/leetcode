class MedianFinder {
private:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        
        minH.push(maxH.top());
        maxH.pop();
        
        if(maxH.size()<minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size()>minH.size()) return maxH.top();
        else{
            return (maxH.top()+minH.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */