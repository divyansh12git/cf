#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll cnt(ll len){
  return ((len*(len+1))>>1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin>>a[i];
    ll tot=cnt(n);
    int i = 0;
    ll inv=0,maxione=0;
    while (i < n) {
        if (a[i] == 1) {
            int j = i;
            while (j<n && a[j] == 1) j++;
            ll l = j - i;
            inv += cnt(l);
            maxione = max(maxione,l);
            i = j;
        } else {
            i++;
        }
    }
    ll ans=tot-(inv-(cnt(maxione)))+cnt(maxione-1);
    cout<<ans<<endl;
}


int main() {
    solve();
    return 0;
}
