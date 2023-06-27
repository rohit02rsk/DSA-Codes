class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i : nums) {
            if(minHeap.size() < k) minHeap.push(i);
            else if (minHeap.top() < i) {
                minHeap.pop();
                minHeap.push(i);
            }
        }
        return minHeap.top();
    }
};