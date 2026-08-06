class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(num){
            int temp=num,mul=1;

            while(num!=0){
                mul=mul*(num%10);
                num/=10;
            }
            num=temp;
            if(mul%t==0) return num;
            num++;
        }
        return num;
    }
};