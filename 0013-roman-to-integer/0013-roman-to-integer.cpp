class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        int i=0;
        while(i!=s.length()){
            if(s[i]=='I') num+=1;

            else if(s[i]=='V') {
                if(i!=0&&s[i-1]=='I') num-=2;
                num+=5;
            }

            else if(s[i]=='X') {
                if(i!=0&&s[i-1]=='I') num-=2;
                num+=10;
            }

            else if(s[i]=='L') {
                if(i!=0&&s[i-1]=='X') num-=20;
                num+=50;
            }

            else if(s[i]=='C') {
                if(i!=0&&s[i-1]=='X') num-=20;
                num+=100;
            }

            else if(s[i]=='D') {
                if(i!=0&&s[i-1]=='C') num-=200;
                num+=500;
            }

            else {
                if(i!=0&&s[i-1]=='C') num-=200;
                num+=1000;
            }

            i++;
        }
        return num;
    }
};