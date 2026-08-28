class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i : asteroids)
        {
            while(!s.empty() && s.top() > 0 && i < 0)
            {
                if(abs(s.top()) == abs(i)) 
                {
                    s.pop();
                    i = 0;
                    break;
                }
                else if(abs(s.top()) > abs(i)) 
                {
                    i = 0;
                    break;
                }
                else 
                {
                    s.pop();
                }
            }
            
            if(i != 0) 
            {
                s.push(i);
            }
        }

        vector<int> fin;
        while(!s.empty()) 
        {
            fin.push_back(s.top());
            s.pop();
        }
        reverse(fin.begin(), fin.end());
        return fin;
    }
};