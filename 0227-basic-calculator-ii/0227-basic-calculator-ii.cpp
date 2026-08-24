class Solution {
public:
    int calculate(string sf) {
        string s="";
        for(char i : sf)
        {
            if(i != ' ')
            {
                s += i;
            }
        }
        vector<string> st;
        int j = 0;
        unordered_map<char,int> f;
        f['+'] = 1;
        f['-'] = 1;
        f['/'] = 1;
        f['*'] = 1;
        for(int i = 0;i<s.size();i++)
        {
            if(f[s[i]]>0) 
            {
                st.push_back(s.substr(j,i-j));
                st.push_back(string(1,s[i]));
                j = i+1;
            }
        }
        st.push_back(s.substr(j,s.size()-j));
        unordered_map<string,int> op;
        op["+"] = 1;
        op["-"] = 1;
        op["/"] = 2;
        op["*"] = 2;
        stack<int> operand;
        stack<string> operat;
        for(string x : st)
        {
            if(op[x]>0)
            {
                if(operat.empty())
                {
                    operat.push(x);
                }
                else if(op[x]<=op[operat.top()])
                {
                    while (!operat.empty() && op[operat.top()] >= op[x])
                    {
                        int b = operand.top();operand.pop();
                        int a = operand.top();operand.pop();
                        string y = operat.top();
                        int z;
                        if(y=="+") z = a+b;
                        if(y=="-") z = a-b;
                        if(y=="/") z = a/b;
                        if(y=="*") z = a*b;
                        operand.push(z);
                        operat.pop();                            
                    }
                    operat.push(x);
                }
                else
                {
                    operat.push(x);
                }
            }
            else
            {
                operand.push(stoi(x));
            }
        }
        while (!operat.empty()) {

            int b = operand.top();
            operand.pop();

            int a = operand.top();
            operand.pop();

            string y = operat.top();
            operat.pop();

            int z;

            if (y == "+") z = a + b;
            if (y == "-") z = a - b;
            if (y == "/") z = a / b;
            if (y == "*") z = a * b;

            operand.push(z);
        }
        int a = operand.top();operand.pop();
        return a;
    }
};