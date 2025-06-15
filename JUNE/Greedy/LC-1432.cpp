#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        char ch1 = 'a';
        char ch2='a';
        for (auto it : s) {
            if (it != '9' && ch1 == 'a') {
                ch1 = it;
                break;
            }
           }
        for(int i=0;i<s.size();i++){
            if(s[i]==ch1){
                s[i]='9';
            }
        }
        cout<<s<<endl;
        int maxi=stoi(s);
        int index=0;
             string s1=to_string(num);
        for(int i=0;i<s1.size();i++){
             if(s1[i]!='1'&&s1[i]!='0'&&ch2=='a'){
                ch2=s1[i];
                index=i;
                break;
            }
        }
        cout<<ch2<<endl;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==ch2&&index==0){
                s1[i]='1';
            }
            if(s1[i]==ch2&&index!=0){
                s1[i]='0';
            }
        }
        cout<<s1<<endl;
        int mini=stoi(s1);
        return maxi-mini;
    }
};