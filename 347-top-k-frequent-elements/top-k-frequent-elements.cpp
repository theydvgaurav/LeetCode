class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        res.clear();

        for(auto it: nums)
            freq[it]++;
        
        for(auto it: freq)
            pq.push({it.second,it.first});
            
        while(k--){
            int ans = pq.top().second;
            res.push_back(ans);
            pq.pop();
        }
        return res;
    }
};