#include<iostream>
// #include <bits/stdc++.h>
// #include<vector>
// #include<stack>
// #include<unordered_map>
using namespace std;

#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)




void solve(){
    //code here...
    int a, b,c;
    cin>>a>>b>>c;
    ll ans=0;
    bool flag=true;
    
    if(b%3!=0){
        int rem=3- b%3;
        if(c>=rem){
            c-=rem;
            b+=rem;
        }else{
            flag=false;
            ans=-1;
        }
    }
    
    if(flag){
        ans+=a+b/3+c/3;
        int r=c%3;
        if(r!=0){
            ans+=1;
        }
    }
    cout<<ans<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}