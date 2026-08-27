    class Solution {
    public:
        vector<int> nsc(vector<int>&fin,const vector<int>&arr)
        {
            stack<int> s;
            for(int i = arr.size()-1;i>=0;i--)
            {
                if(s.empty()) fin[i] = arr.size();
                else
                {
                    while(!s.empty() && arr[i]<=arr[s.top()])
                    {
                        s.pop();
                    }
                    if(s.empty()) fin[i] = arr.size();
                    else fin[i] = s.top();
                } 
                s.push(i);
            }
            return fin;
        }
        vector<int> psc(vector<int>&fin,const vector<int>&nums)
        {
            stack<int> s;
            for(int i = 0;i<nums.size();i++)
            {
                if(s.empty()) fin[i] = -1;
                else
                {
                    while(!s.empty() && nums[s.top()]>nums[i])
                    {
                        s.pop();
                    }
                    if(s.empty()) fin[i] = -1;
                    else fin[i] = s.top();
                }
                s.push(i);
            }
            return fin;
        }
        int sumSubarrayMins(vector<int>& arr) {
            vector<int> nextsmall(arr.size());
            vector<int> prevsmall(arr.size());
            nsc(nextsmall,arr);
            psc(prevsmall,arr);
            int total = 0;
            int mod = (int)(1e9 + 7);
            for(int i = 0;i<arr.size();i++)
            {
                
                int left = i - prevsmall[i];
                int right = nextsmall[i] - i;
                total = (total + (( right * left * 1LL)%mod)%mod * arr[i])%mod;
            }
            return total;
        }

    };