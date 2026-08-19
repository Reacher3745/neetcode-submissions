class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for (int i = 0; i<n; i++){
            if(tokens[i] == "*") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x * y);
            }
            else if(tokens[i] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x + y);
            }
            else if(tokens[i] == "/") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(x / y);
            }
            else if(tokens[i] == "-") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(x - y);
            }

            else st.push(stoi(tokens[i]));
        }

        return st.top();

    }
};
