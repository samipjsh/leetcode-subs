#include<algorithm>
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string reversed(s.rbegin(), s.rend());
        if(x<0) return false;
        else if(x<10) return true;
        return (reversed == s);
    }
};