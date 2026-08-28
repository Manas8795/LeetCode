class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return 1LL* sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
    vector<int> nsc(vector<int>& fin, const vector<int>& arr) {
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
    vector<int> psc(vector<int>& fin, const vector<int>& nums) {
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
    long long sumSubarrayMins(vector<int> arr) {
        vector<int> nextsmall(arr.size());
        vector<int> prevsmall(arr.size());
        nsc(nextsmall, arr);
        psc(prevsmall, arr);
        long long  total = 0;
        for (int i = 0; i < arr.size(); i++) {

            int left = i - prevsmall[i];
            int right = nextsmall[i] - i;
            total = (total + right * left * 1LL* arr[i]);
        }
        return total;
    }
    vector<int> nsg(vector<int>& fin, const vector<int>& arr) {
        stack<int> s;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (s.empty())
                fin[i] = arr.size();
            else {
                while (!s.empty() && arr[i] >= arr[s.top()]) {
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
    vector<int> psg(vector<int>& fin, const vector<int>& nums) {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.empty())
                fin[i] = -1;
            else {
                while (!s.empty() && nums[s.top()] < nums[i]) {
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
    long long sumSubarrayMaxs(vector<int> arr) {
        vector<int> nextgreat(arr.size());
        vector<int> prevgreat(arr.size());
        nsg(nextgreat, arr);
        psg(prevgreat, arr);
        long long total = 0;
        
        for (int i = 0; i < arr.size(); i++) {

            int left = i - prevgreat[i];
            int right = nextgreat[i] - i;
            total = (total + right * left * 1LL* arr[i]);
        }
        return total;
    }
};