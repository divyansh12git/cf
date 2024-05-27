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
    int x,y;
    cin>>x>>y;
    int scr4=y/2;
    y%=2;
    int extra=y;
    int rem=7*scr4+11*extra;
    int scr1=0;
    if(x>rem){
        x-=rem;
        float z=x;
        scr1=ceil(z/15);
    }
    // cout<<scr1<<" "<<scr4<<" "<<extra<<endl;
    cout<<scr1+scr4+extra<<endl;


}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}