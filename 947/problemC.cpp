#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<limits.h>
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

template <class T> bool sorting(T x1, T x2)
{ // return type is bool
    return x1.second <= x2.second;
}


void solve(){
    //code here...
    ll n;
    cin>>n;
    vector<ll>a(n);
    llfl(i,0,n)cin>>a[i];
    if(n==2){
        cout<<min(a[0],a[1])<<endl;
        return;
    }
    vector<pair<ll,ll>>b;
    llfl(i,0,n){
        b.push_back({i,a[i]});
    }
    sort(b.begin(),b.end(),sorting<pair<ll,ll>>);
    // for(auto i:b){
    //     cout<<i.first<<" "<<i.second<<",";
    // }cout<<endl;
    ll maxi=INT_MIN;
    ll inl=b[b.size()-1].first;
    vector<ll>temp=a;
    vsort(temp);
    bool f=false;
    for(ll i=b.size()-1;i>0;i--){
        // cout<<b[i].second<<"+"<<b[i-1].second<<endl;
        if(b[i].second==b[i-1].second){
            f=true;
            continue;
        }
        if(b[i].second!=b[i-1].second){
            // cout<<"HI"<<endl;
            
            ll ins;
            if(f){
                ins=b[i].first;
                if(inl<ins)swap(ins,inl);
                f=false;
            }else{
                 ins=b[i-1].first;
            }
            
            
            // cout<<ins<<"+"<<inl<<endl;
            // cout<<maxi<<endl;
            // cout<<<<endl;
            // sort(temp.begin()+ins,temp.begin()+inl);
            ll size=inl-ins+1;
            ll m=(size+1)/2 -1+ins;
            maxi=max(maxi,temp[m]); 
            inl=b[i].first;
        }
        
    }
    cout<<maxi<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}