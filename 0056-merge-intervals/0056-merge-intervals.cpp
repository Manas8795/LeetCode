#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // If merged is empty OR there's no overlap with the last added interval
            if (merged.empty() || interval[0] > merged.back()[1]) {
                merged.push_back(interval);
            } else {
                // Overlap exists! Extend the end of the last interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};