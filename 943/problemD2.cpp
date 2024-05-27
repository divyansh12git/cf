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

ll score(vector<ll>p,vector<ll>a,ll k,ll pb){
    vector<ll>path;
    path.push_back(pb);
    while(p[path[path.size()-1]]!=pb){
        path.push_back(p[path[path.size()-1]]);
    }
    int max=path[0];    
    ll in=0;
    llfl(i,1,path.size()){
        if(a[max]<a[path[i]]){
            max=path[i];
            in=i;
        }
    }
    if(k<in+1){
        int max=path[0];
        llfl(i,1,k){
        if(a[max]<a[path[i]]){
            max=path[i];
            in=i;
        }
        }
    }
    // llfl(i,0,path.size())cout<<path[i]<<" ";cout<<endl;
    // cout<<max<<endl;
    ll score=0;
    ll i=0;
    while(path[i]!=max){
        
        k--;
        score+=a[path[i]];
        i++;
    }
    // cout<<score<<endl;
    while(k--){
        score+=a[max];
    }
    // cout<<score<<endl;
    // score+=a[max];
    return score;
}

void solve(){
    //code here...
    ll n,k,pb,ps;
    cin>>n>>k>>pb>>ps;
    vector<ll>p(n),a(n);
    llfl(i,0,n){
        ll x;
        cin>>x;
        x--;
        p[i]=x;
    }
    llfl(i,0,n)cin>>a[i];
    ll bscore=score(p,a,k,pb-1);
    ll sscore=score(p,a,k,ps-1);
    cout<<bscore<<" "<<sscore<<endl;
    if(bscore>sscore)cout<<"Bodya";
    else if(bscore==sscore)cout<<"Draw";
    else cout<<"Sasha";cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}