#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    long count(long curr, long next, int n){
        long cnt=0;
        while(curr<=n){
            cnt+=next-curr;
            curr*=10;
            next*=10;
            next=min(next,long(n+1));
        }
        return cnt;
    }
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k-=1;
        while(k>0){
            long cnt=count(curr,curr+1,n);
            if(cnt<=k){
                k-=cnt;
                curr++;
            }
            else{
                curr*=10;
                k-=1;
            }
        }
        return curr;
    }
};