class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        int mx = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            res = max(res, mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        return res;
    }
};