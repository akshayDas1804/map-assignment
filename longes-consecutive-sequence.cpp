#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> length;
        int ans = 0;

        for (int num : nums) {
            if (length.find(num) != length.end()) {
                continue; 
            }

            int left = 0, right = 0;
            if (length.find(num - 1) != length.end()) {
                left = length[num - 1];
            }
            if (length.find(num + 1) != length.end()) {
                right = length[num + 1];
            }
            int len = left + right + 1;
            length[num] = len; 
            length[num - left] = len; 
            length[num + right] = len;

            ans = max(ans, len);
        }

        return ans;
    }
};
