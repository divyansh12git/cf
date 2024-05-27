#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
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
    int n;
    cin>>n;
    vector<int>x;
    int max=INT_MIN;
    fl(i,0,n){
        int y;
        cin>>y;
        if(y>max)max=y;
        x.push_back(y);
    }
    vector<ll>a;
    a.push_back(max+1);
    fl(i,0,n-1){
        a.push_back(a[i]+x[i]);
    }
    fl(i,0,n)cout<<a[i];
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}