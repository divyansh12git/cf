#include <bits/stdc++.h>
#include<iostream>
#include<vector>
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
    ll n,k;
    cin>>n>>k;
    vector<ll> dur(n);
    fl(i,0,n){
        cin>>dur[i];
    }
    ll p1=0,p2=n-1;
    while(p1<=p2){
        if(k<dur[p1] && k<dur[p2]){
            break;
        }
        else if(k<p1 && k>p2){
            int attack=k;
            while(k>2*dur[p2]){
                k-=2*dur[p2];
                p2--;
            }
        }
        else if(k>p1 && k<p2){
            int attack=k;
            while(k>2*dur[p1]){
                k-=2*dur[p1];
                p1--;
            }
        }
        else{
            if(dur[p1]+dur[p2]>=k){
                k-=dur[p1]+dur[p2];
                p1++;p2--;
            }
            else if(dur[p1]<=k){
                while(k>2*dur[p2]){
                    k-=2*dur[p2];
                    p2--;
            }
            }else{
                while(k>2*dur[p1]){
                    k-=2*dur[p1];
                    p1++;
            }
        }
    }
    if(p2-p1>=0){
        cout<<p2-p1+1<<endl;
    }else{
        cout<<0<<endl;
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