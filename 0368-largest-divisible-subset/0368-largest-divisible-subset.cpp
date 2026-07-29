class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int i, a = nums.size();
        vector<int> ans;

        vector<int> dp(a, 1);
        vector<int> parent(a, -1);

        for(i = 1; i < a; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0) {

                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        int k = 0;

        for(i = 1; i < a; i++) {
            if(dp[i] > dp[k])
                k = i;
        }

        while(k != -1) {
            ans.push_back(nums[k]);
            k = parent[k];
        }

        return ans;
    }
};