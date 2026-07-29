class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].length();i++)
        {
            char temp=strs[0][i];
            for(const string& str:strs){
                if(i>=str.length()||str.at(i)!=temp) return ans;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};