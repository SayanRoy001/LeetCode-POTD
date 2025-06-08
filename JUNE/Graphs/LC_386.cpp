#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
//TC-o(n(logn)^2)
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        priority_queue<string,vector<string>,greater<string>>pq;
        for(int i=1;i<=n;i++){
            pq.push(to_string(i));
        }
        while(!pq.empty()){
            ans.push_back(stoi(pq.top()));
            pq.pop();
        }
        return ans;
    }
};