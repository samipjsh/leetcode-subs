class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int sum=0,count=0;
        for(int i=cost.size()-1;i>=0;i--){
            count++;
            count%=3;
            if (count==0) continue;
            sum+= cost[i];
        }
        return sum;
    }
};