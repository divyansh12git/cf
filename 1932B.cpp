#include<iostream>
// #include <bits/stdc++.h>
#include<vector>
// #include<stack>
// #include<unordered_map>
using namespace std;

#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)




void solve(){
    //code here...
    int n;
    cin>>n;
    vector<ll> arr(n);
    fl(i,0,n)cin>>arr[i];

    ll yp=0;
    fl(i,0,n){
        yp=(yp/arr[i] +1)*arr[i]; 
    }
    cout<<yp<<endl;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}