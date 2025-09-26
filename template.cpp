#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
using vpii = vector<pii>;
using vvpii= vector<vpii>;
using vvi = vector<vi>;
using piii=pair<int,pair<int,int>>;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using si=set<int>;
using sl=set<ll>;
using sc=set<char>;
using PQ=priority_queue<int>;
using minPQ=priority_queue<int,vector<int>,greater<int>>;
#define int long long
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

struct segmax {
    vector<int> arr;     // array
    vector<int> tree;    // segment tree
    int n;               // size of array

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    segmax(vector<int>& input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n);
        build(0, 0, n - 1); // builds segment tree
    }

    int queryAns(int node, int start, int end, int left, int right) {
        if (start > right || end < left) return INT_MIN;
        if (start >= left && end <= right) return tree[node];
        int mid = start + (end - start) / 2;
        return max(queryAns(2 * node + 1, start, mid, left, right),
                   queryAns(2 * node + 2, mid + 1, end, left, right));
    }

    int query(int left, int right) {
        return queryAns(0, 0, n - 1, left, right);
    }

    void updateVal(int node, int start, int end, int index) {
        if (start > index || end < index) return;
        if (start == end && start == index) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        updateVal(2 * node + 1, start, mid, index);
        updateVal(2 * node + 2, mid + 1, end, index);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int index, int val) {
        arr[index] = val;
        updateVal(0, 0, n - 1, index);
    }
};
struct segsum{
    vector<int> arr;     // array
    vector<int> tree;    // segment tree
    int n;               // size of array

    void build(int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
            return ;
        }
        int mid=start+(end-start)/2;
        // left child
        build(2*node+1,start,mid);
        // right child
        build(2*node+2,mid+1,end);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    segsum(vector<int>& input){
        n=input.size();
        arr=input;
        tree.resize(4*n);
        build(0,0,n-1); // builds segment tree
    }

    int queiryAns(int node,int start,int end,int left,int right){
        if(start>right||end<left)
            return 0;
        if(start>=left&&end<=right)
            return tree[node];
        int mid=start+(end-start)/2;
        return queiryAns(2*node+1,start,mid,left,right)+queiryAns(2*node+2,mid+1,end,left,right);
    }

    int queiry(int left,int right){
        return queiryAns(0,0,n-1,left,right);
    }

    void updateVal(int node,int start,int end,int index){
        if(start>index||end<index)
            return ;
        if(start==end&&start==index){
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        updateVal(2*node+1,start,mid,index);
        updateVal(2*node+2,mid+1,end,index);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    void update(int index,int val){
        arr[index]=val;
        updateVal(0,0,n-1,index);
    }
};
struct segmin{
    vector<int> arr;     // array
    vector<int> tree;    // segment tree
    int n;               // size of array

    void build(int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
            return ;
        }
        int mid=start+(end-start)/2;
        // left child
        build(2*node+1,start,mid);
        // right child
        build(2*node+2,mid+1,end);
        tree[node]=min(tree[2*node+1],tree[2*node+2]);
    }

    segmin(vector<int>& input){
        n=input.size();
        arr=input;
        tree.resize(4*n);
        build(0,0,n-1); // builds segment tree;
    }

    int queiryAns(int node,int start,int end,int left,int right){
        if(start>right||end<left)
            return INT_MIN;
        if(start>=left&&end<=right)
            return tree[node];
        int mid=start+(end-start)/2;
        return min(queiryAns(2*node+1,start,mid,left,right),queiryAns(2*node+2,mid+1,end,left,right));
    }

    int query(int left,int right){
        return queiryAns(0,0,n-1,left,right);
    }

    void updateVal(int node,int start,int end,int index){
        if(start>index||end<index)
            return ;
        if(start==end&&start==index){
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        updateVal(2*node+1,start,mid,index);
        updateVal(2*node+2,mid+1,end,index);
        tree[node]=min(tree[2*node+1],tree[2*node+2]);
    }

    void update(int index,int val){
        arr[index]=val;
        updateVal(0,0,n-1,index);
    }
};
struct TrieNode {
    TrieNode* child[26];
    bool isEndOfWord;
    TrieNode() {
        for(int i=0;i<26;i++) child[i]=NULL;
        isEndOfWord=false;
    }
};

struct trie {
public:
    TrieNode* root;
    trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(char c:word){
            int index=c-'a';
            if(node->child[index]==NULL){
                node->child[index]=new TrieNode();
            }
            node=node->child[index];
        }
        node->isEndOfWord=1;
    }
    bool search(string word){
        TrieNode* node = root;
        for(char c:word){
            int index=c-'a';
            if(node->child[index]==NULL) return 0;
            node=node->child[index];
        }
        return node->isEndOfWord;
    }
    bool isEmpty(TrieNode* node){
        for(int i=0;i<26;i++){
            if(node->child[i]) return 0;
        }
        return 1;
    }
    bool Delete(TrieNode* node,string &word,int depth){
        if(depth==word.size()){
            if(!node->isEndOfWord) return false;
            node->isEndOfWord=false;
            return isEmpty(node);
        }
        int index=word[depth]-'a';
        if(!node->child[index]) return false;
        bool shouldDeleteChild=Delete(node->child[index],word,depth+1);
        if(shouldDeleteChild){
            delete node->child[index];
            node->child[index]=NULL;
            return !node->isEndOfWord && isEmpty(node);
        }
        return false;
    }
    void DeleteWord(string word){
        Delete(root,word,0);
    }
};
struct BitTrieNode {
    BitTrieNode* child[2];
    int count;
    BitTrieNode() {
        child[0] = child[1] = NULL;
        count = 0;
    }
    bool containsBit(int bit) { return child[bit] != NULL; }
    void put(int bit, BitTrieNode* node) { child[bit] = node; }
    BitTrieNode* get(int bit) { return child[bit]; }
};

struct bit_trie {
    BitTrieNode* root;
    bit_trie() { root = new BitTrieNode(); }

    void insert(int num) {
        BitTrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsBit(bit)) node = node->get(bit);
            else { node->put(bit, new BitTrieNode()); node = node->get(bit); }
            node->count++;
        }
    }

    void eraseNum(BitTrieNode* node, int num, int i) {
        if(i < 0) { node->count--; return; }
        BitTrieNode* child = node->get((num >> i) & 1);
        eraseNum(child, num, i - 1);
        if(!child->count) {
            delete(child);
            node->child[(num >> i) & 1] = NULL;
        }
        node->count--;
    }

    void erase(int num) { eraseNum(root, num, 31); }

    int getMax(int num) {
        int maxNum = 0;
        BitTrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsBit(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }

    int getMin(int num) {
        int minNum = 0;
        BitTrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsBit(bit)) node = node->get(bit);
            else {
                minNum |= (1 << i);
                node = node->get(1 - bit);
            }
        }
        return minNum;
    }
};
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
int32_t main(){
    fast_io();
    int T;
    cin>>T;
    while(T--)
    solve();
}