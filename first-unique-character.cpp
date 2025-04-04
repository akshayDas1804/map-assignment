class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> freq;

        for(int i = 0; i < s.length(); i++)
        {
            if(freq.find(s[i]) == freq.end())
            {
                freq[s[i]] = {1,i};
            }
            else
            {
                freq[s[i]].first++;
            }
        }

        int first_unique_idx = s.length();
        char character;
        int frequency, index;

        for(auto itr = freq.begin(); itr != freq.end(); itr++)
        {
            character = itr->first;
            frequency = itr->second.first;
            index = itr->second.second;

            if(frequency == 1)
            {
                first_unique_idx = min(first_unique_idx, index);
            }
        }

        if(first_unique_idx == s.length()) return -1;
        return first_unique_idx;
    }
};
