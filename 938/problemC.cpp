#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<deque>
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
    deque<ll> dur;
    fl(i,0,n){
        ll a;
        cin>>a;
        dur.push_back(a); 
    }
    while(!dur.empty()){
        ll f=dur.front();
        ll e=dur.back();
        if(k==1 && f==1){
            k--;
            dur.pop_front();
        }
        if(k<=0)
            break;
        if(dur.front()==dur.back()){
            if(k>=f){
                dur.pop_back();
            }else{
                break;
            }
        }
        
        else if(k>=2*min(f,e)){
            if(f>e){
                dur.front()-=e;
                dur.pop_back();
                k-=2*e;
            }
            else if(f==e){
                dur.pop_back();
                dur.pop_front();
                k-=2*f;
            }
            else{
                dur.back()-=f;
                dur.pop_front();
                k-=2*f;
            }

        }
        else{
            break;
        }
    }
    // deque<ll>::iterator it=dur.begin();
    // ll c=0;
    // while(it!=dur.end()){
    //     c++;
    //     it++;
    // }
    cout<<n-(dur.end()-dur.begin())<<endl;
    
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}