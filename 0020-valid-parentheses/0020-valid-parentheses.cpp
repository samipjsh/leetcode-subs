class Solution {
public:
    bool isValid(string s) {
        int top = -1;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                top++;
                s[top] = c;
            } else {
                if (top < 0) return false;
                
                char last = s[top];
                if ((c == ')' && last != '(') ||
                    (c == ']' && last != '[') ||
                    (c == '}' && last != '{')) {
                    return false;
                }
                top--;
            }
        }
        
        return top == -1;
    }
};