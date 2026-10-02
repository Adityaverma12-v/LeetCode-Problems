#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        string s;
        int open;
        int close;
    };

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<Node> st;

        Node start;
        start.s = "";
        start.open = 0;
        start.close = 0;

        st.push(start);

        while (!st.empty()) {
            Node curr = st.top();
            st.pop();

            if (curr.s.length() == 2 * n) {
                ans.insert(ans.end(), curr.s); // no push_back
                continue;
            }

            if (curr.open < n) {
                Node next1;
                next1.s = curr.s + "(";
                next1.open = curr.open + 1;
                next1.close = curr.close;
                st.push(next1);
            }

            if (curr.close < curr.open) {
                Node next2;
                next2.s = curr.s + ")";
                next2.open = curr.open;
                next2.close = curr.close + 1;
                st.push(next2);
            }
        }
        return ans;
    }
};
