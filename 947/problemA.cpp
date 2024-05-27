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
    int n;
    cin>>n;
    vector<ll>a(n);
    fl(i,0,n)cin>>a[i];
    ll last=a[n-1];
    bool ans=true;
    ll cmp=a[0];
    fl(i,0,n-1){
        
        if(a[i]>a[i+1]){
            // cout<<cmp<<" "<<last<<endl;
            if(cmp>=last){
                last=a[i];
                cmp=a[i+1];
            }else{
                ans=false;
                break;
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