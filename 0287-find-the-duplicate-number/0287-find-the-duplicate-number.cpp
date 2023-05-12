class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL) ;
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int start = 0;
        while(start != slow) {
            start = nums[start];
            slow = nums[slow];
        }
        return slow;
    }
};