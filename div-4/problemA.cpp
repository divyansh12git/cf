#include<iostream>
// #include <bits/stdc++.h>
// #include<vector>
// #include<stack>
// #include<unordered_map>
using namespace std;
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)




void solve(){
    string s;
    cin>>s;
    int count=0;
    fl(i,0,s.length()){
        if(s[i]=='A'){
            count++;
        }else{
            count--;
        }
    }
    if(count>0)cout<<"A"<<endl;
    else{
        cout<<"B"<<endl;
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}