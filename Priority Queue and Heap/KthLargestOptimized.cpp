class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num : nums) {
            addHelper(num);
        }
    }

    int add(int val) {
        addHelper(val);
        return minHeap.top();
    }

private:
    void addHelper(int val) {
        if (minHeap.size() < kth) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
    }
};
//Optimized solution. Instead of using a max heap we can just use a min heap and check the top. Just fill the min heap up to K and then from there on check if newest value is bigger than the 
//top (which is the smallest). If it is then that means it has a place as one of the largest and the top isn't needed anymore so pop it. The add function just calls addHelper with its own values.