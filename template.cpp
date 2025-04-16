#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
using piii=pair<int,pair<int,int>>;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using si=set<int>;
using sl=set<ll>;
using sc=set<char>;
using PQ=priority_queue<int>;
using minPQ=priority_queue<int,vector<int>,greater<int>>;
#define MOD 1000000007
#define PI = 3.1415926535897932384626433832795
#define pb push_back
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define fi first
#define se second
#define endl "\n"
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin(), (x).rend() //reverse traversal
// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())
// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
#define yes "YES"
#define no "NO"
template<class T> ostream &operator<<(ostream &dout,vector<T> &vec){for (auto i: vec)dout<< i <<" ";return dout;}
vector<bool> seive(ll n){vector<bool>primes(n+1,1);primes[0]=primes[1]=0;for(ll i=2;i<n;i++){for(ll j=2*i;j<n;j+=i){primes[j]=0;}}return primes;}
//2D--------------------------------------------
vector<vector<ll>>ncr(int n){ vector<vector<ll>>c(n+1,vector<ll>(n+1)); for(int i=0;i<=n;i++){c[i][0]=1;for(int j=1;j<=i;j++){c[i][j]=c[i-1][j-1]+c[i-1][j];}}return c;}
//1D---------------------------------------------------
vector<ll> ncr1D(int n){ vector<ll>c(n+1);c[0]=1;for(int i=1;i<=n;i++){for(int j=i;j>0;j--){c[j]=c[j]+c[j-1];}}return c;}

//Include the following header files in your code to use PBDS:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//Namespace
using namespace __gnu_pbds;
//Templates
 //defining template when all elements are distinct
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 //defining template when duplicate elements are also used
template <class T> using multi_ordered_set = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    for0(i,n)
    cin>>arr[i];
    
}
int main(){
    fast_io();
    int T;
    cin>>T;
    while(T--)
    solve();
}
