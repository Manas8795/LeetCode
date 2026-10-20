class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> divisors;
        int sd = 0;
        for(int i = 1;i<=nums.size();i++)
        {
            if(nums.size()%i == 0) 
            {
                divisors.push_back(i);
                sd+=i;
            }
        }
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        if(nums == sorted) return sd;
        bool flag = true;
        int sum = 0;
        
        for(int ii = 1;ii<divisors.size();ii++)
        {
            flag = true;
            vector<pair<int,int>> check;
            int k = divisors[ii];
            for(int i = 0;i+k<=nums.size(); i+=k)
            {   
                
                int j = i+k-1;
                int count = 0;
                int xmin = INT_MAX;
                int xmax = INT_MIN;
                for(int p = i;p<j;p++)
                {
                    xmin = min(xmin,nums[p]);
                    xmax = max(xmax,nums[p]);
                    if(nums[p]>nums[p+1])
                    {
                        count++;
                    }
                }
                xmin = min(xmin,nums[j]);
                xmax = max(xmax,nums[j]);
                check.push_back({xmin,xmax});
                if((count == 1 && nums[i]>=nums[j]) || count<1)
                {
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false) continue;
            for(int a = 0;a<check.size()-1;a++)
            {
                if(check[a].second > check[a+1].first)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false ) continue;
            sum += divisors[ii];
        }
        
        return sum;
    }
};