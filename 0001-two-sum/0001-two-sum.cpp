class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> reverse;

        for (int i=0;i<nums.size();i++){
            int rev=target-nums[i];

            if(reverse.find(rev)!=reverse.end(rev)) return {reverse[rev],i};

            reverse[nums[i]] = i;
        }
        return {};
    }
};