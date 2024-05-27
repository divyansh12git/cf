
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

string solve(){
    //code here...
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> dc(4);
    llfl(i,0,n){
        if(s[i]=='N')dc[0]++;
        if(s[i]=='S')dc[1]++;
        if(s[i]=='E')dc[2]++;
        if(s[i]=='W')dc[3]++;
    }
    ll vec,hor;
    if(dc[0]>dc[1]){
        vec=dc[0]-dc[1];
    }else{
        vec=dc[1]-dc[0];
    }
    if(dc[2]>dc[3]){
        vec=dc[2]-dc[3];
    }else{
        vec=dc[3]-dc[2];
    }
    if(vec!=hor || vec&1 || hor&1){
        return "NO";
    }
    string ans="";
    bool irover=false;
    bool ihel=false;
    ll rvc=0;
    for(ll i=0;i<n-1;i+=2){
        // if((s[i]=='N' && (s[i+1]=='S' || s[i+1]=='E' || s[i+1]=='W'))||(s[i]=='S' && (s[i+1]=='N' || s[i+1]=='E' || s[i+1]=='W')))
        if((s[i]=='N' && s[i+1]=='S' )||(s[i]=='S' && s[i+1]=='N' )||(s[i]=='E' && s[i+1]=='W' )||(s[i]=='W' && s[i+1]=='E' )){
            if(!irover){
                ans+="RR";
                irover=true;
                continue;
            }else if(!ihel){
                ans+="HH";
                ihel=true;
                continue;
            }else{
                ans+="RR";
            }
        }
        else if(){

        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        string ans=solve();

    }

}