class Solution {
public:
    int lengthOfLastWord(string s) {
        int a=s.size();
        int count=0;
        int test=0;
        for(int i=a-1;i>=0;i--){
            if(!isalpha(s[i])) test=1;
            else count++;
            if(test==1){
                if(count==0) test=0;
                else return count;
            }
        }
        return count;
    }
};