class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a=nums.size();
        return max(nums[0]*nums[1]*nums[a-1],nums[a-1]*nums[a-2]*nums[a-3]);
    }
};