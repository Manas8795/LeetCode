class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (string c : tokens) {
            s.push(c);
        }
        unordered_map<string, int> op;
        op["+"] = 1;
        op["-"] = 1;
        op["*"] = 1;
        op["/"] = 1;

        x(s, op);
        return stoi(s.top());
    }

    void x(stack<string>& s, unordered_map<string, int> op) {
        if (s.size() == 1) return;

        string c = s.top();
        s.pop();

        string c1 = s.top();
        if (op[c1] == 1) {
            x(s, op);
            c1 = s.top();
        }
        s.pop();
        int a = stoi(c1);

        string c2 = s.top();
        if (op[c2] == 1) {
            x(s, op);
            c2 = s.top();
        }
        s.pop();
        int b = stoi(c2);

        if (c == "+") s.push(to_string(b + a));
        if (c == "-") s.push(to_string(b - a));
        if (c == "*") s.push(to_string(b * a));
        if (c == "/") s.push(to_string(b / a));
    }
};