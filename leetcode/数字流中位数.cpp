#include <queue>
#include <vector>
using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > maxheap;//大根堆
    priority_queue<int, vector<int>, greater<int> > minheap;//小根堆

    MedianFinder() {

    }

    void addNum(int num) {
        if(maxheap.size() == minheap.size()) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        int maxSize = maxheap.size(), minSize = minheap.size();
        int mid1 = maxheap.top(), mid2 = minheap.top();
        return maxSize == minSize ? ((mid1 + mid2) * 0.5) : mid2;
    }
};
