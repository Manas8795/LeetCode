class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> m;
        int l = 0;
        int r = 0;
        int maxlength = 0;
        while (r < nums.size()) {
            m[nums[r]]++;
            while (m.size() > 2) {
                m[nums[l]]--;
                if (m[nums[l]] == 0)
                    m.erase(nums[l]);
                l++;
            }

            maxlength = max(maxlength, r - l + 1);

            r++;
        }
        return maxlength;
    }
};