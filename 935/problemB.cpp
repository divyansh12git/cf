#include<iostream>
#include <bits/stdc++.h>
// #include<vector>
// #include<stack>
// #include<unordered_map>
using namespace std;

#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)




void solve(){
    //code here...
    ll a,b,m;
    cin>>a>>b>>m;
    long double md=m;
    ll ans=0;
    ans+=ceil(md/a) +ceil(md/b);
    if(m%a==0){
        ans+=1;
    }
    if(m%b==0){
        ans+=1;
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