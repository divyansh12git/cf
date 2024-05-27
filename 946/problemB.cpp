#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
#include<set>
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

void solve(){
    //code here...
    ll n;
    cin>>n;
    string b;
    cin>>b;
    set<char> alp;
    
    llfl(i,0,n){
        alp.insert(b[i]);
    }
    vector<char>v;
    // cout<<alp.size()<<endl;;
    for (auto i : alp) {
        
        v.push_back(i);
    }
    // llfl(i,0,v.size()){
    //     cout<<v[i]<<" ";
    // }cout<<endl;
    unordered_map<char,char>map;
    llfl(i,0,v.size()){
        map[v[i]]=v[v.size()-i-1];
    }
    
    string ans="";
    llfl(i,0,b.length()){
        ans.push_back(map[b[i]]);
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