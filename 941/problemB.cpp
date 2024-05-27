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

void solve(){
    //code here...
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    fl(i,0,n){
        fl(j,0,m){
            char a;cin>>a;
            arr[i][j]=a;
        }
    }
    int minrb=INT_MAX,maxrb=INT_MIN,minrw=INT_MAX,maxrw=INT_MIN;
    int mincb=INT_MAX,maxcb=INT_MIN,mincw=INT_MAX,maxcw=INT_MIN;
    bool w=false,b=false;
    if(n==1 || m==1){
        fl(i,0,n){
        fl(j,0,m){
            if(arr[i][j]=='W')w=true;
            else b=true;
        }
        
    }
    if(w && b)cout<<"NO";else cout<<"YES";cout<<endl;
    return;
    }
        while(true){
    bool inw=false,inb=false;
    
    fl(i,0,n){
        fl(j,0,m){
            if(arr[i][j]=='W'){
                w=true;
                if(i<minrw)minrw=i;
                if(i>maxrw)maxrw=i;
                if(i<mincw)mincw=i;
                if(j>maxcw)maxcw=i;
            }else{
                b=true;
                if(i<minrb)minrb=i;
                if(i>maxrb)maxrb=i;
                if(i<mincb)mincb=i;
                if(j>maxcb)maxcb=i;
            }
        }
    } 
    if(w==false || b==false){
        break;
    }
    int wl=maxcw-mincw;
    int wb=maxrw-minrw;
    int bl=maxcb-mincb;
    int bb=maxrb-minrb;
    int war=wl*wb;
    int bar=bl*bb;
    char col;
    if(war>bar){
        fl(i,minrw,maxrw){
            fl(j,mincw,maxcw){
                arr[i][j]='W';
            }
        }
    }else{
        fl(i,minrb,maxrb){
            fl(j,mincb,maxcb){
                arr[i][j]='B';
            }
        }
    }
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