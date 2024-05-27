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

void calScore(vector<ll>p,vector<ll>a,ll score,ll k,ll pb,ll &finscore){
    // cout<<finscore<<endl;
    if(k<=0){
        if(score>finscore)finscore=score;
        return;
    }
    score+=a[pb];
    calScore(p,a,score,k-1,pb,finscore);
    calScore(p,a,score,k-1,p[pb]-1,finscore);
}


void solve(){
    //code here...
    ll n,k,pb,ps;
    cin>>n>>k>>pb>>ps;
    vector<ll>p(n),a(n);
    llfl(i,0,n)cin>>p[i];
    llfl(i,0,n)cin>>a[i];
    ll bscore=0;
    calScore(p,a,0, k,pb-1,bscore);
    ll sscore=0;
    calScore(p,a,0,k,ps-1,sscore);
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