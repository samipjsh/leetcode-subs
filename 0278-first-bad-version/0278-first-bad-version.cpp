// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1,mid=0,high=n,bad;

        while(low<=high){

            mid=low+(high-low)/2;

            if(isBadVersion(mid)){
                bad=mid;
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }
        return bad;
    }
};