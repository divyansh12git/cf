
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
#include<limits>
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
    ll x;
    cin>>x;
    vector<int>ans(32,0);
    int size=log2(x);
    // cout<<size<<endl;
    bool sats=false;
    int time=2;
    while(time--){
        
  
        // ll y=pow(2,size);
      
        //     vector<int>temp=ans;
        //     temp[size]=1;
        //     if(y==x){
        //         ans=temp;
        //         sats=true;
        //         break;
        //     }
        if(x==1){
            sats=true;
            ans[0]=1;break;
        }if(x==2){
            sats=true;
            ans[1]=1;break;
        }
        
        
        bool gret=false;
        for(int j=size-2;j>=0;j--){
            ll y=pow(2,size);
            // cout<<y<<endl;
            vector<int>temp=ans;
            temp[size]=1;
            if(y==x){
                ans=temp;
                sats=true;
                break;
            }
        for(int i=j;i>=0;i-=2){
            ll z=pow(2,i);
            if(y<x){
                if(y+z>x)gret=true;
                temp[i]=1;
                y+=z;
            }
            else if(y>x){
                if(y-z<x)gret=false;
                temp[i]=-1;
                y-=z;
            }
            if(y==x){
                ans=temp;
                sats=true;
                break;
            }
            // for(auto i:temp){
            //     cout<<i<<" ";
            // }cout<<endl;
        }
        if(sats)break;
    
    }
    
    if(sats)break;
    size++;
    }
    cout<<size+1<<endl;
    fl(i,0,size+1){
        cout<<ans[i]<<" ";
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