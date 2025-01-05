// Author: *   Divyansh Gupta ( divyansh_8 )   *

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<string.h>
#include<cmath>
#include<limits.h>
#include<algorithm>
#include<time.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

#define     F                       first
#define     S                       second

#define     INF                     1e18
#define     PI                      3.141592653589793238462
#define     MOD1                    1e9+7
#define     MOD2                    1e9+9
#define     MOD3                    998244353

#define     llfl(i,s,e)             for(long long i=s;i<e;i++)
#define     fl(i,s,e)               for(int i=s;i<e;i++)
#define     fa(i,z)                 for(auto i:z)

#define     frl(i,s,e)              for(int i=s;i>=e;i--)

#define     pb                      push_back
#define     pf                      push_front
#define     ppb                     pop_back

#define     all(x)                  (x).begin(), (x).end()

#define     vsort(v)                sort(v.begin(),v.end())
#define     vreverse(v)             reverse(v.begin(),v.end())

#define     mapit(it,d1,d2,map)     unordered_map<d1,d2>::iterator it=map.begin()
#define     vecit(it,dt,vec)        vector<dt>:: iterator it=vec.begin();

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>>vvll;
typedef pair<int,int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<pii>>vvpii;
typedef vector<vector<pll>>vvpll;
typedef priority_queue<int> pqmax;
typedef priority_queue<ll> pqmaxll;
typedef priority_queue<int,vector<int>,greater<int>> pqmin;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqminll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key//ordered set

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ll t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

ll gcd(ll a, ll b) {if (b == 0) {return a;}return gcd(b, a % b);} //m
bool isPrime(ll n) {if (n == 2) return true;if (n < 2) return false;for (int i = 2; i * i <= n; i++)if (n % i == 0) return false;return true;}
bool isSorted(vector<ll> v) {llfl(i,0,v.size() - 1) {if (v[i] > v[i + 1])return 0;}return 1;}
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
ll mod_inverse(ll a,ll M){return expo(a,M-2,M);}
// void precomp(){fact[0]=1;for(int i=1;i<=N;i++){fact[i]=(fact[i-1]*i)%mod;modinv[i]=power(fact[i],mod-2);}}
// ll ncr(ll n,ll r){if(r>n)return 0;ll numo=fact[n];ll invdeno=(modinv[r]*modinv[n-r])%mod;ll ans=(numo*invdeno)%mod;return ans;}
ll ncr2(ll n,ll r){if(n<r)return 0;ll ans=1;fl(i,0,r){ans=(ans*(n-i))/(i+1);}return ans;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

void debug(int t=1) {cout << "Case #" << t << ": ";}
void tres(bool t){ t?cout<<"YES":cout<<"NO";cout<<endl; }
void alice(bool t=1){t?cout<<"Alice":cout<<"Bob";cout<<endl;}

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

bool istc=1;
bool judge=1;


void solve(){
    //code here...    
    ll n,m,k;
    cin>>n>>m>>k;
    vll a(n);
    fl(i,0,n)cin>>a[i];
    vi quant(n,0);
    vpll b;
    fl(i,0,n)b.pb({a[i],i});
    vsort(b);
    fl(i,0,n){
        if(k>=m){
            quant[b[i].S]=m;
            k-=m;
        }else{
            quant[b[i].S]=k;
            k=0;break;
        }
    }
    ll ans=0;
    ll bou=0;
    fl(i,0,n){
        if(quant[i]>0){
            ans+=(a[i]+bou)*quant[i];
            bou+=quant[i];
        }
    }
    cout<<ans<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    if(judge){
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
            freopen("Error.txt", "w", stderr);
        #endif
    }
    ll t; if(istc)cin>>t;else t=1; while(t--)solve();
 
}