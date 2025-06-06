#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
         int n = s.size();
        
        // suffix
        vector<char> suffixMin(n+1);
        suffixMin[n] = '{';
        for (int i = n-1; i >= 0; i--) {
            suffixMin[i] = min(s[i], suffixMin[i+1]);
        }
        
        stack<char> st;
        string ans = "";
        
        int i = 0;
        while (i < n) {
            // if(!st.empty()&&st.top()<s[i]){
            //     while (!st.empty() && st.top() <= suffixMin[i+1]) {
            //     ans += st.top();
            //     st.pop();
            // }
            // }
            st.push(s[i]);

            while (!st.empty() && st.top() <= suffixMin[i+1]) {
                ans += st.top();
                st.pop();
            }
            i++;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};