#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
#include<algorithm>
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

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return (a.second<b.second);
}


void solve(){
    //code here...
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> a;
    llfl(i,0,n){
        ll x;
        cin>>x;
        pair<ll,ll>p={i+1,x};
        a.push_back(p);
    }
    sort(a.begin(),a.end(),compare);
    ll sm=a[0].second;
    ll diff=n-1;
    ll tr=1;
    llfl(i,0,n-1){
        
        if(k==0){
            break;
        }
        ll *y=&a[i].second;
        ll *n=&a[i+1].second;
        
        ll up=(*n-*y)*(i+1);
        if(up<=k){
            tr++;
            sm=a[i+1].second;
            // *y+=up;
            diff--;
            k-=up;
            // cout<<up<<endl;

        }else{
            
            break;
        }

    }
    if(k>=tr){
        ll q=k/tr;
        sm+=q;
        k=k%tr;
    }
    // sort(a.begin(),a.end(),compare);
    // ll sm=a[0].first;
    // ll diff=0;
    
    ll ans=(n)*(sm-1)+diff+k+1;
    // cout<<sm<<" "<<diff<<" "<<tr<<" "<< k<<" "<<endl;
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