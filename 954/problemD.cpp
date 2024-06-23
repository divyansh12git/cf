#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string.h>
#include<cmath>
#include<limits.h>
#include<algorithm>
#include<time.h>
using namespace std;

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

#define     F                       first
#define     S                       second

#define     INF                     1e18
#define     PI                      3.141592653589793238462

#define     ll                      long long
#define     pii                     pair<int,int>
#define     pll                     pair<ll,ll>
#define     llfl(i,s,e)             for(long long i=s;i<e;i++)
#define     fl(i,s,e)               for(int i=s;i<e;i++)
#define     fa(i,z)                 for(auto i:z)

#define     pb                      push_back
#define     pf                      push_front

#define     vsort(v)                sort(v.begin(),v.end())
#define     vreverse(v)             reverse(v.begin(),v.end())

#define     mapit(it,d1,d2,map)     unordered_map<d1,d2>::iterator it=map.begin()
#define     vecit(it,dt,vec)        vector<dt>:: iterator it=vec.begin();

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

ll gcd(ll a, ll b){ if(a==b)return a;    if(a>b)a-=b;    if(b>a)b-=a;    return gcd(a,b);    }  //m
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

void debug(int t=1) {cout << "Case #" << t << ": ";}
void tres(bool t){ t?cout<<"YES":cout<<"NO";cout<<endl; }

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/


int getInt(char a,char b){
    int x=a-48;
    int y=b-48;
    return x*10+y;
}
void solve(){
    //code here...    
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool isZero=false;
    int ones=0;
    if(n==2){
        cout<<getInt(s[0],s[1])<<endl;
        return;
    }
    fl(i,0,n){
        if(s[i]=='0')isZero=true;
        if(s[i]=='1')ones++;
    }
    
    int ans=0;
    if(isZero){
        if(n==3){
            if(s[0]=='0' || s[2]=='0'){cout<<ans<<endl;return;}
        }else{
            cout<<ans<<endl;return;
        }
    }
    int min2=getInt(s[0],s[1]);
    // int oneUtil=INT_MAX;
    int i1=0,i2=1;
    // bool isele=false;
    // bool isonemin=false;
    // int e1=0,e2=0;
    // int z1=0,z2=0;
    fl(i,1,n-1){
        int o=0;
        int num=getInt(s[i],s[i+1]);
        if(s[i]=='1')o++;
        if(s[i+1]=='1')o++;
        int cal1=0,cal2=0;
        cal1+=min2;
        cal2+=num;
        if(cal1==1)cal1=0;
        if(cal2==1)cal2=0;
        if(s[i]!='1' && i!=i2)cal1+=getInt('0',s[i]);
        if(s[i+1]!='1')cal1+=getInt('0',s[i+1]);
        if(s[i1]!='1')cal2+=getInt('0',s[i1]);
        if(s[i2]!='1' && i!=i2)cal2+=getInt('0',s[i2]);
            // cout<<cal1<<" | "<<cal2<<endl;
        if(cal1>cal2){
            min2=num;   
            i1=i,i2=i+1;
        }
    }
    int ans1=0;
    
    fl(i,0,n){
        // cout<<ans1<<" | "<<ans2<<endl;
        if(i==i1){ 
            int num=getInt(s[i1],s[i2]);
            if(num!=1 || ans1==0) ans1+=getInt(s[i1],s[i2]);
            i++;
            continue;
        }
        if(s[i]=='1')continue;
        ans1+=getInt('0',s[i]);
    }
    
    // cout<<" "<<i1<<" "<<min2<<endl;
    cout<<ans1<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif 
    ll t; cin>>t; while(t--)solve();
    // cout<<getInt('0','8');
}