class Solution {
public:
    int minimumPushes(string word) {
        int a=word.size();
        int push=0;
        if(a<9) return a;
        int freq[26]={0};
        for(int i=0;i<a;i++){
            freq[word[i]-'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            if(i<8){
                push+=freq[i];
            }
            else if(i<16) push+=(freq[i]*2);
            else if(i<24) push+=(freq[i]*3);
            else push+=(freq[i]*4);
        }
        return push;
    }
};