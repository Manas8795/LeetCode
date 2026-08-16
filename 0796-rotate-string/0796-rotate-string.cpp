class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string m = s+s;
        if(m.find(goal)!=std::string::npos) return true;
        else return false;
    }
};