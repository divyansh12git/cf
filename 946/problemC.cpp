
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
#include <map>
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

ll map_count(map<pair<int,int>,vector<int>>map12){
    ll ans=0;
    for(auto i:map12){
        vector<ll>samecount;
        ll total=i.second.size();
        if(i.second.size()==1)continue;
        ll cnt=1;
        llfl(j,1,i.second.size()){
            if(i.second[j]==i.second[j-1]){
                cnt++;
            }else{
                samecount.push_back(cnt);
                cnt=1;
                
            }
        }
        ll same=0;
        llfl(z,0,samecount.size()){
            ll t=samecount[z];
            if(t!=1)same+=t*(t-1)/2;
        }
        ans+=((total*(total-1))/2)-same;
    }
    return ans;
}

void solve(){
    //code here...
    ll n;
    cin>>n;
    vector<ll>a(n);
    llfl(i,0,n){
        cin>>a[i];
    }
    
    map<pair<int,int>,vector<int>>map12;
    map<pair<int,int>,vector<int>>map13;
    map<pair<int,int>,vector<int>>map23;
    llfl(i,0,n-2){
        map12[{a[i],a[i+1]}].push_back(a[i+2]);
        map13[{a[i],a[i+2]}].push_back(a[i+1]);
        map23[{a[i+1],a[i+2]}].push_back(a[i]);
    }
    ll ans=map_count(map12)+map_count(map23)+map_count(map13);
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