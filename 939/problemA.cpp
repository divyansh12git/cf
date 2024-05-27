#include <bits/stdc++.h>
#include<algorithm>
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
    int k,q;
    cin>>k>>q;
    vector<int>a(k);
    vector<int>pep(q);
    fl(i,0,k)cin>>a[i];
    fl(i,0,q)cin>>pep[i];
    vsort(a);
    int min=a[0];
    fl(i,0,q){
        if(pep[i]<min){
            cout<<pep[i]<<" ";
        }else{
            cout<<min-1<<" ";
        }
    }cout<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}