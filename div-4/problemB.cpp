#include<iostream>
// #include <bits/stdc++.h>
#include<vector>
// #include<stack>
// #include<unordered_map>
using namespace std;


#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)


void solve(){
    //code here...
    int n;
    cin>>n;
    int flag=0;
    int input,no1;

    fl(i,0,n){
        cin>>input;
        fl(j,0,n){
            no1+=input%10;
            input/=10;
        }
        if(no1==1){
            flag=1;
        }
    }
    flag?cout<<"TRIANGLE"<<endl:cout<<"SQUARE"<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}