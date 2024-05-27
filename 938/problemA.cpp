#include <bits/stdc++.h>
#include<iostream>
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
    int n,a,b;
    cin>>n>>a>>b;
    int cost=0;
    if(2*a>b){
        cost+=(n/2)*b;
        n%=2;
        cost+=n*a;
    }else{
        cost+=n*a;    }
    cout<<cost<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}