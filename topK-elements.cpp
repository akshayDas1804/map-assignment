class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for (auto& [num, freq] : hash) {
            maxHeap.push({freq, num});
        }

        vector<int> topK;
        for (int i = 0; i < k; ++i) {
            topK.push_back(maxHeap.top().second);
            maxHeap.pop();
        }


        return topK;
    }
};
