class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i,a=nums.size();
        if (target>nums[a-1]) return a;
        for(i=0;i<a;i++){
            if(target == nums[i]) return i;
            
            if(target>nums[i] && target < nums[i+1]) return i+1;
        }
        return 0;
    }
};