#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define eps                   0.000000001
#define all(c)               (c).begin(),(c).end()
#define present(c,x)         ((c).find(x) != (c).end())
#define cpresent(c,x)        (find(all(c),x) != (c).end())
//#define pi                   pair<int,int>
#define pll                  pair<ll,ll>
#define endl                 '\n'
#define ull                  unsigned long long
using namespace std;
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#define debug(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}

inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }

template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
//using namespace __gnu_pbds;
//typedef tree<int, null_type, int>, rb_tree_tag,tree_order_statistics_node_update> policy;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector< int > vi;
typedef vector< vi > vvi;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,-1,1,2,-2,2,-2};
vector<int> vis(200010,0),dis(200010,0),par(200010,0),ed(200010,0);
vector<pair<int,int>> adj[200010];
vector<vector<int>> ad;
int myrandom (int i) { return std::rand()%i;}
const int MAX=200010;
const ull inf = 1000000007;
inline ll hilbertOrder(ll x, ll y, ll pow, ll rotate)
{
    if (pow == 0) {
        return 0;
    }
    ll hpow = 1 << (pow-1);
    ll seg = (x < hpow) ? (
                           (y < hpow) ? 0 : 3
                           ) : (
                                (y < hpow) ? 1 : 2
                                );
    seg = (seg + rotate) & 3;
    const ll rotateDelta[4] = {3, 0, 0, 1};
    ll nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    ll nrot = (rotate + rotateDelta[seg]) & 3;
    ll subSquareSize = 1ll << (2*pow - 2);
    ll ans = seg * subSquareSize;
    ll add = hilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query
{
    ll l, r,idx;
    ll ord;
    inline void calcOrder() {
        ord = hilbertOrder(l, r, 21, 0);
    }
};
inline bool operator<(const Query &a,const Query &b){
    return a.ord<b.ord;
}
// code in int main of mo's algo
vector<Query> q(n);
for(int i=0;i<n;i++){
    q[i].l=dis[i+1];
    q[i].r=dis[i+1]+sz[i+1]-1;
    q[i].idx=i+1;
    q[i].calcOrder();
}
sort(all(q));
int l=1,r=n;
map<ll,ll> mt;
for(int i=1;i<=n;i++){
    mt[v[temp[i]]]++;
}
for(int i=0;i<n;i++){
    while(l>q[i].l){
        mt[v[temp[l-1]]]++;
        l--;
    }
    while(r<q[i].r){
        mt[v[temp[r+1]]]++;
        r++;
    }
    while(l<q[i].l){
        if(mt[v[temp[l]]]==1){
            mt.erase(v[temp[l]]);
        }
        else{
            mt[v[temp[l]]]--;
        }
        l++;
    }
    while(r>q[i].r){
        if(mt[v[temp[r]]]==1){
            mt.erase(v[temp[r]]);
        }
        else{
            mt[v[temp[r]]]--;
        }
        r--;
    }
    ans[q[i].idx]=(int)mt.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //ofstream fout;
    //fin.open("input.txt");
    //fout.open("output.txt");
    //clock_t launch=clock();
    
}
