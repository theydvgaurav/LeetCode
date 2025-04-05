class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int longest=1;
                int nums=it;
                while(st.find(nums+1)!=st.end()){
                    longest++;
                    nums=nums+1;
                }
                ans=max(ans,longest);
            }
            
        }
        return ans;

    }
};