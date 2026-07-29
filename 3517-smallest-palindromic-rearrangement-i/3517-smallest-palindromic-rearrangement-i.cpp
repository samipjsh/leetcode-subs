class Solution {
public:
    string smallestPalindrome(string s) {
        int a=s.size();
        int freq[26] ={0};
        for (int i=0;i<a/2;i++){
            freq[s[i]-'a']++;
        }
        int left=0,right=a-1;
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                char ch=i+'a';
                s[left++]=ch;
                s[right--]=ch;
                freq[i]--;
            }
        }
        return s;
    }
};