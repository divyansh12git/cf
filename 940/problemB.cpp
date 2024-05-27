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

#define mapit(it,d1,d2,map) unordered_map<d1,d2>::iterator it=map.begin(); 
#define vecit(it,dt,vec) vector<dt>:: iterator it=vec.begin();


int convertToBinary(int a){
    int ans=0;
    int i=0;
    while(a){
        int x=a%2;
        ans+=pow(10,i)*x;
        a/=2;
        i++;
    }
    return ans;
}

void solve(){
    //code here...
    ll n,k;
    cin>>n>>k;
    if(n==1){
        cout<<k<<endl;
    }else{
        ll x=log2(k+1);
        ll ans=pow(2,x)-1;
        cout<<ans<<" "<<k-ans<<" ";
        llfl(i,0,n-2)cout<<" 0 ";
        cout<<endl;

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