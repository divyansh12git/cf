#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


#define INF 1e18
#define PI 3.141592653589793238462

#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)


#define vsort(v) sort(v.begin(),v.end())
#define vreverse(v) reverse(v.begin(),v.end())



void solve(){
    //code here...
    int n;
    cin>>n;
    vector<int> len(n);
    fl(i,0,n)cin>>len[i];
    unordered_map<int,int> mp;
    fl(i,0,n){
        mp[len[i]]+=1;
    }
    unordered_map<int,int>::iterator it=mp.begin();
    int ans=0;
    while(it!=mp.end()){
        if(it->second>2){
            // cout<<it->first<<" " <<it->second<<" ";
            ans+=(it->second)/3;
        }
        it++;
    }
    cout<<ans<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}