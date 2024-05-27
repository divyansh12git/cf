#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include <cstdlib>

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
    ll n;cin>>n;
    string s;
    cin>>s;
    vector<pair<ll,ll>> sat(n+1,make_pair(0,0));
    ll p1=0,p2=0;
    unordered_map<ll,pair<ll,ll>>map;
    llfl(i,0,n+1){
    	double d1=i,d2=n-i;
    	pair<double,double> pai=make_pair(ceil(d1/2),ceil(d2/2));
    	map[i]=pai;
    	
    	if(i==0){
    		pair<ll,ll> p=make_pair(0,0);
    		sat[i]=p;
    		sat[n]=p;
    		
    		continue;
		}
		if(s[i-1]=='0')p1++;
		if(s[n-i]=='1')p2++;
		
    	sat[i].first=p1;
    		
    	sat[n-i].second=p2;
		
	}
	// llfl(i,0,n+1){
	// 	cout<<sat[i].first<<" "<<sat[i].second<<" map: "<<map[i].first<<" " <<map[i].second<<endl;
	// }
	ll ans=INF;
	ll mind=INF;
	llfl(i,0,n+1){
		double l=n;
		ll mid=ceil(l/2);
		if(sat[i].first>=map[i].first && sat[i].second>=map[i].second){
			// cout<<i<<" ";
			ll d=llabs(n/2 -i);
			if(d<=mind){
				mind=d;
				if(i<=mid){
					ans=i;
				}else{
					ans=min(ans,i);
				}
			
			}

		}
	}
	cout<<ans<<endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
 
}