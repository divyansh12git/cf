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

ll gcd(ll a,ll b){
    if(a==b)return a;
    else if(a>b)a-=b;
    else b-=a;

    return gcd(a,b);
    
}


void solve(){
    //code here...
    ll m,n;
    cin>>m>>n;
    // cout<<gcd(m,n)<<endl;
    ll ans=0;
    llfl(i,0,n){
        llfl(j,0,m){
            if((i+j+2)%((j+1)*gcd(i+1,j+1))==0)ans++;
        }
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