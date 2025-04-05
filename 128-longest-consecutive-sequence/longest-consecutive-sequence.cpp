class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int res = 0;
        for (auto it: st){
            if(st.find(it-1)==st.end()){
                int j = it;
                int cnt = 1;
                while(st.find(j+1)!=st.end()){
                    j++;
                    cnt++;
                }
                res=max(res,cnt);
            }
        }
        return res;

    }
};