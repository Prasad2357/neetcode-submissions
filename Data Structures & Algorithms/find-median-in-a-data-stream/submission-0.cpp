class MedianFinder {
public:
    //max heap
    priority_queue <int> small;
    //min heap
    priority_queue <int, vector<int>, greater<int>> large;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);

        large.push(small.top()); //move max of small to large
        small.pop();

        if(large.size() > small.size())
        {
            small.push(large.top());  //move min of large to small (size overflow)
            large.pop();
        }
        
    }
    
    double findMedian() {
        if(small.size()> large.size())
        {
            //odd number
            return small.top(); //max of small (max) heap 
        }

        //even number
        return (small.top() + large.top())/2.0;   
        
    }
};
