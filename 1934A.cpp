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
    fl(i,0,n){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<(arr[n]+arr[n-1]-arr[0]-arr[1])<<1<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}