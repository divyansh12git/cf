#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
#include<set>
using namespace std;


#define INF 1e18
#define PI 3.141592653589793238462

#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)


#define vsort(v) sort(v.begin(),v.end())
#define vreverse(v) reverse(v.begin(),v.end())

#define mapit(it,d1,d2,map) unordered_map<d1,d2>::iterator it=map.begin()
#define vecit(it,dt,vec) vector<dt>:: iterator it=vec.begin();

void solve(){
    //code here...
    ll n;
    cin>>n;
    // vector<ll>a(n);
    set<ll>a;
    llfl(i,0,n){
        ll x;
        cin>>x;
        a.insert(x);
    }
    set<ll>::iterator it=a.begin();
    vector<ll>vec;
    while(it!=a.end()){
        vec.push_back(*it);
        it++;
    }
    vsort(vec);
    bool turn=true;//alice
    llfl(i,0,n){
        ll s=n-i;
        if(!s&1){
            if(vec[i]>1){
                
            }
        }
    }
    
    
    

}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}