class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // Max-heap for the smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-heap for the larger half

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        // Add to maxHeap (smaller half)
        maxHeap.push(num);
        
        // Balance heaps: maxHeap should not have more elements than minHeap + 1
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */