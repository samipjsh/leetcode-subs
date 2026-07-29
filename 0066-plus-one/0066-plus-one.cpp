class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int a=digits.size()-1;
        while(true){
            if(digits.at(a)==9){
                digits.at(a)=0;
                if(a==0){

                    digits.insert(digits.begin(),1);
                    return digits;
                }
                a--;
            }
            else{
                digits.at(a)++;
                return digits;
            }
        }
        return digits;
    }
};