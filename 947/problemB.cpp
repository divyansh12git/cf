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

void solve(){
    //code here...
    
    ll n;
    cin>>n;
    vector<ll>a(n);
    fl(i,0,n)cin>>a[i];
    
    sort(a.begin(),a.end());
    
    
    ll x=a[0];
    ll y=1;
    bool sec=false;
    bool ans=true;
    if(x!=1){
    fl(i,1,n){
        
        if(!sec && a[i]%x!=0){
            y=a[i];
            sec=true;
        }
        else if(sec && (a[i]%x!=0 && a[i]%y!=0)){
            ans=false;break; 
        }
    }
    }
    ans?cout<<"YES":cout<<"NO";cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}