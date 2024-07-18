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
#define ch cout<<"$"<<endl;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 1000000009
#define MOD2 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define yes cout<<"Yes"
#define no cout<<"No"
#define int long long
#define for_(x) for(int i=0;i<x;i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
// void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<int> decimalToBinary(int n) {  vector<int> binary(32, 0); int index = 31;  while (n > 0) {    int remainder = n % 2;    binary[index] = remainder;    n /= 2;    index--; } reverse(all(binary)); return binary;}
ll binpow(long long a, long long b) { if (b == 0)   return 1;  long long res = binpow(a, b / 2);  if (b % 2)return res * res * a; else return res * res;}
ll binaryToDecimal(const std::vector<int>& binary) { int decimal = 0; int power = 1;for (int i = binary.size() - 1; i >= 0; --i) { decimal += binary[i] * power; power *= 2;}return decimal;}
ll binaryToDecimal(string binary) {long long decimal = 0;long long power = 1;for (long long i = binary.size() - 1; i >= 0; --i) {decimal += (binary[i]-'0') * power; power *= 2;}return decimal;}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
 
 
void solve() {
  int n,m,k;cin>>n>>m>>k; 
  string s;cin>>s; 
  int swim_len=0;  
  bool croc=false;  
  int croc_pos=0;  
  int rem=k;  
  for(int i=0;i<=n;i++){
 
    if(i==n||s[i]=='L' ){
 
      if(swim_len>=m) {
        
      if(croc){
        if(croc_pos>=m){
          no;return;
        }
        else {
        if(swim_len>=rem+m){
          no;return; 
        }
        }
         
      }
      else {
        if(swim_len>=rem+m){
          no;return; 
        }
      }
 
      }
      
        
        rem -= max(0ll, swim_len+1 - m);
        debug(swim_len)
        debug(rem)
        if(rem<0){
          no;return;
        }
        swim_len=0;
        croc=false;
        croc_pos=-1; 
      
    }
    else {
      swim_len++; 
      if(s[i]=='C'){
        croc=true; 
        croc_pos=swim_len; 
      }
 
    }
 
  }
  yes;
  
 
}
 
int32_t main() {
 
 
  fastio();
 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
 
 
 
   
 
  int t=1;
  cin >> t;
  
 
  while (t--) {
    
 
    
    solve();
    cout << "\n";
  }
 
 
 
 
 
  return 0;
}