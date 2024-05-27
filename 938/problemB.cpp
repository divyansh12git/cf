#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <algorithm>
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
    int n;ll c,d;
    cin>>n>>c>>d;
    bool flag=true;
    

    vector<ll> elem(n*n);
    fl(i,0,n*n){
        cin>>elem[i];
    }
    vsort(elem);
    ll st=elem[0];
    

    
    vector<ll> add;
    ll r,col=st;
    fl(i,0,n){
        if(i!=0){
            col+=c;
        }
        r=col;
        add.push_back(r);
        fl(j,1,n){
            r+=d;
            add.push_back(r);
        }
    }
    vsort(add);
    fl(i,0,n*n){
        if(add[i]!=elem[i]){
            flag=false;
            break;
        }
    }
    flag? cout<<"YES"<<endl:cout<<"NO"<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}