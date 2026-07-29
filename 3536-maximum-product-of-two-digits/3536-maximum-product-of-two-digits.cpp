class Solution {
public:
    int maxProduct(int n) {
        int p1=0,p2=0,a=n;
        while(a!=0){
            if(a%10>p1){
                if(p1>p2) p2=p1;
                p1=a%10;
            }
            else if(a%10>p2) p2=a%10;
            a=a/10;
        }
        return (p1*p2);
    }
};