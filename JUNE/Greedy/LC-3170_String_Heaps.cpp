#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comp{
        bool operator()(pair<char,int>&p1,pair<char,int>&p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       comp>
            pq;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    pq.pop();
                }
            } 
            else {
                pq.push({s[i], i});
            }
        }
        vector<int> index(n, 0);
        while (!pq.empty()) {
            int i = pq.top().second;
            index[i] = 1;
            pq.pop();
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (index[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};