#include<bits/stdc++.h>
class MedianFinder {
public:

    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxPQ.size() == 0){
            maxPQ.push(num);
            return;
        }

        if(maxPQ.size() == minPQ.size()){
            // Surely we will push in maxPQ.
            // But need to check with the top element
            // of minPQ too.
            int val1 = minPQ.top();
            minPQ.pop();

            minPQ.push(max(num, val1));
            maxPQ.push(min(num, val1));
            return;
        }

        // Otherwise surely maxPQ.size() > minPQ.size(). So,
        // we need to push in minPQ.
        int val1 = maxPQ.top();
        maxPQ.pop();
        minPQ.push(max(num, val1));
        maxPQ.push(min(num, val1));
        return;
    }
    
    double findMedian() {
        if(maxPQ.size() > minPQ.size())
            return maxPQ.top() * 1.0;
        
        return (maxPQ.top() + minPQ.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */