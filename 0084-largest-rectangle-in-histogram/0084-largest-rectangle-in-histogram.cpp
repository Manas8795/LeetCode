
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        vector<int> nse;
        vector<int> pse;
        pse = psc(nums);
        nse = nsc(nums);
        int maxarea = 0;
        for (int i : nse)
            cout << i << " ";
        for(int i = 0;i<nums.size();i++)
        {
           maxarea = max(maxarea,(nse[i] - pse[i] - 1) * nums[i]); 
        }
        return maxarea;
    }

    vector<int> nsc(const vector<int>& arr) {
        vector<int> fin(arr.size());
        stack<int> s;

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (s.empty())
                fin[i] = arr.size();
            else {
                while (!s.empty() && arr[i] <= arr[s.top()]) {
                    s.pop();
                }

                if (s.empty())
                    fin[i] = arr.size();
                else
                    fin[i] = s.top();
            }

            s.push(i);
        }

        return fin;
    }

    vector<int> psc(const vector<int>& nums) {
        vector<int> fin(nums.size());
        stack<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.empty())
                fin[i] = -1;
            else {
                while (!s.empty() && nums[s.top()] > nums[i]) {
                    s.pop();
                }

                if (s.empty())
                    fin[i] = -1;
                else
                    fin[i] = s.top();
            }

            s.push(i);
        }

        return fin;
    }
};
