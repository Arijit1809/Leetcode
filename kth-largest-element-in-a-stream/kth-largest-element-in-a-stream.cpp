class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap; 
    int maxSize = 0;
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for(int i = 0;i<nums.size();i++){ //tc - O(N)
            minHeap.push(nums[i]); //tc -> O(logK)
            if(minHeap.size()>k) minHeap.pop();
        } //total tc-> O(NLogK)
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>maxSize) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */