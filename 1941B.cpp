#include<iostream>
#define ll long long
using namespace std;

void solve(){
    ll n;
    cin>>n;
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    for(ll i=1;i<n-1;i++){
        if(arr[i]>1 && arr[i-1]>=1){
            int f=arr[i-1];
            arr[i-1]-=f;
            arr[i+1]-=f;
            arr[i]-=2*f;
        }
        else{
            continue;
        }
    }
    bool check=true;
    for(ll i=0;i<n;i++){
        if(arr[i]!=0){
            check=false;
        }
    }
    check?cout<<"YES"<<endl:cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}