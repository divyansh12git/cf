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



    void solve(){
        //code here...    
        ll n,a,b;
        cin>>n>>a>>b;
        ll k=b-a;
        if(k<0 ){
            k=0;
        }
        else if( k>min(n,b)){
            k=min(n,b);
        }
        ll p1=0;
        if(k!=0) p1=k*b+k-(k*(k+1))/2;

        
        // cout<<p1<<"|"<<k<<endl;
        cout<<p1+(n-k)*a<<endl;
    }


    int main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
            freopen("Error.txt", "w", stderr);
        #endif 
        ll t; cin>>t; while(t--)solve();
    
    }