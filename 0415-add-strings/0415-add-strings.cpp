class Solution {
public:
    string addStrings(string num1, string num2) {
    int a=num1.length()-1 , b= num2.length()-1,carry=0;
    string ans;
    while (a >= 0 || b >= 0 || carry) {
        int x = (a >= 0) ? num1[a] - '0' : 0;
        int y = (b >= 0) ? num2[b] - '0' : 0;

        int sum = x + y + carry;

        ans.push_back(sum % 10 + '0');
        carry = sum / 10;

        a--;
        b--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};