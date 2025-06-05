#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<char>  parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (char i = 'a'; i <= 'z'; i++) {
            parent[i] = i;
        }
    }

    int findUPar(char node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByLex(char u, char v) {
        char ulp_u = findUPar(u);
        char ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (ulp_u < ulp_v) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(128);
        int n=s1.size();
        for(int i=0;i<n;i++){
            char c1=s1[i],c2=s2[i];
            ds.unionByLex(c1,c2);
        }
        string ans="";
        int size=baseStr.size();
        for(int i=0;i<size;i++){
            char c1=baseStr[i];
            char UPc1=ds.findUPar(c1);
            ans+=UPc1;
        }
        return ans;
    }
};