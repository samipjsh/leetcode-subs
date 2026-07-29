class Solution {
public:
    int mySqrt(int x) {
        long long int low=1,high=x,mid,sqrt;
        while(low<=high){
            mid=(low+high)/2;
            if(mid*mid<=x){
                sqrt=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return sqrt;
    }
};