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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> sign;
    fl(i,0,n){
        sign.push_back(s[i]);
    }
    bool turn=true;//alice
    while(sign.size()>2){
        
        bool isflipped=false;
        fl(i,0,sign.size()){
            if(sign[i]=='U'){
                isflipped=true;
                //toggle back;
                int b;
                if(i-1<0){
                     b=sign.size()-1;   
                }else{
                    b=i-1;
                }
                char x=sign[b];
                if(x=='U')sign[b]='D';
                else sign[b]='U';
                // toggle next
                int f;
                if(i+1>=sign.size()){
                     f=0;   
                }else{
                    f=i+1;
                }
                 x=sign[f];
                if(x=='U')sign[f]='D';
                else sign[f]='U';
                //removing element
                sign.erase(sign.begin()+i);
                turn=!turn;
                break;
            }
        }
        // fl(i,0,sign.size())cout<<sign[i];cout<<endl;
        if(!isflipped){
            break;
        }
        
    }
    
    if(sign.size()==2){
        if((sign[0]=='U' && sign[1]=='D') || (sign[0]=='D' && sign[1]=='U')){
            turn=!turn;
        }
    }
    if(sign.size()==1){
        if(sign[0]=='U')turn=!turn;
    }
    if(turn)cout<<"No";else cout<<"Yes";cout<<endl;
   
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}