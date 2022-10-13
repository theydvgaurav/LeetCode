class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        while(i>=0 || j>=0){
            int x = (i>=0) ? num1[i] - '0' : 0;
            int y = (j>=0) ? num2[j] - '0' : 0;
            int sum = carry + x + y;
            res+=to_string(sum%10);
            carry = sum/10;
            j--;
            i--;
        }
        
        if(carry) res+=to_string(carry);
        
        reverse(res.begin(),res.end());
        return res;
    }
};