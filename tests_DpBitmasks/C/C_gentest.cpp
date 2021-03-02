#include <bits/stdc++.h>

using namespace std;
namespace DEBUG {
    void __print(int x) {cerr << x;}
    void __print(long x) {cerr << x;}
    void __print(long long x) {cerr << x;}
    void __print(unsigned x) {cerr << x;}
    void __print(unsigned long x) {cerr << x;}
    void __print(unsigned long long x) {cerr << x;}
    void __print(float x) {cerr << x;}
    void __print(double x) {cerr << x;}
    void __print(long double x) {cerr << x;}
    void __print(char x) {cerr << '\'' << x << '\'';}
    void __print(const char *x) {cerr << '\"' << x << '\"';}
    void __print(const string &x) {cerr << '\"' << x << '\"';}
    void __print(bool x) {cerr << (x ? "true" : "false");}

    template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
    mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
    template <class T = int>
    T rand(T range = numeric_limits <T> :: max()){
        return (T) (generator() % range);
    }
}
using namespace DEBUG;

template <class T,class U>
void maximize(T &lhs,U rhs){
    if(lhs < rhs)lhs = rhs;
}
template <class T,class U>
void minimize(T &lhs,U rhs){
    if(lhs > rhs)lhs = rhs;
}
template <class T>
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong int64_t
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define file_name "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */

namespace Task{

    const llong N = (llong)1e18;
    const int M = 100;

    void solve(){
        auto func = [](const tuple < llong,llong,int,int > &t){
            llong L,R;
            int L_M,R_M;
            tie(L,R,L_M,R_M) = t;
            llong n = L + rand(R - L + 1);
            int m = L_M + rand(R_M - L_M + 1);
            cout<<n<<' '<<m<<'\n';
        };
        tuple < llong,llong,int,int > t[] = {{1,10000,1,50},{1000000,10000000,50,100},{1000000000,10000000000,50,70},{N / (llong)2,N,77,90},{N - 5,N,50,100}};
        int coins = rand(5);
        func(t[coins]);
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Task::solve();
}

