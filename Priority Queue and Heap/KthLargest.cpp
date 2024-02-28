
class KthLargest {
public:
priority_queue<int> maxHeap;
priority_queue<int> temp;
int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int a = 0; a < nums.size(); a++)
        {
            maxHeap.push(nums[a]);
        }
        temp = maxHeap;
    }
    
    int add(int val) {
        temp = maxHeap;
        maxHeap.push(val);
        int popamount = kth - 1;
        temp.push(val);
        for(int a = 0; a < popamount; a++)
        {
            temp.pop();
        }
        return temp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 //Unoptimized solution. It works but does not scale very well