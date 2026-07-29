class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums.size();
        return max((nums[0]-1)*(nums[1]-1),(nums[a-1]-1)*(nums[a-2]-1));
    }
};