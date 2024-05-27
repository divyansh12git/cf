#include<iostream>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        for(ll i=0;i<n;i++){
            if(i+2<n && s[i]=='m' && s[i+1]=='a' && s[i+2]=='p'){
                ans++;
                i+=2;
                continue;
            }
            if(i+2<n && s[i]=='p' && s[i+1]=='i' && s[i+2]=='e'){
                ans++;
                i+=2;
            }
        }
        cout<<ans<<endl;
    }
}