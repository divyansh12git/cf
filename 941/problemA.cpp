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
    int n,k;
    cin>>n>>k;
    vector<int>c(n);
    unordered_map<int, int> count;
    fl(i,0,n){
        int a;
        cin>>a;
        count[a]++;
    }
    bool f=false;
    while(true){
    //     unordered_map<int,int>::iterator al=count.begin();
    // while(al!=count.end()){
    //     cout<<al->first<<" "<<al->second<<"||";
    //     al++;
    // }cout<<endl;
        unordered_map<int,int>::iterator it=count.begin();
        while(it!=count.end()){
            int *c=&it->second;
            if(*c>=k){
                f=true;
                *c-=k;
                unordered_map<int,int>::iterator inc=count.begin();
                int x=k-1;
                while(inc!=count.end()){
                    if(x==0)break;
                    if(inc->second!=0){
                        int diff=k-inc->second;
                        if(diff<=x){
                            inc->second+=diff;
                            x-=diff;
                        }else{
                            inc->second+=x;
                            x=0;
                        }  
                    }
                    inc++;
                }
                if(x!=0){
                    *c+=x;
                    x=0;
                }
                break;
            }

            it++;
        }
    
        if(f==false)break;
        f=false;
    }
    int ans=0;
    unordered_map<int,int>::iterator it=count.begin();
    while(it!=count.end()){
        ans+=it->second;
        it++;
    }
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