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

    const int MAXTEST = 100;
    const llong MAXVALUE = (llong)1e18;
    const llong MAXVALUE_2 = (llong)1e15;

    void solve(){
        auto gentest = [&](const tuple < int,llong,llong,llong,llong,int,int > &t) -> void{
            int test,L_K,R_K;
            llong L_L,R_L,L_R,R_R;
            tie(test,L_L,R_L,L_R,R_R,L_K,R_K) = t;
            while(test--){
                llong l = L_L + rand(R_L - L_L + 1);
                llong r = L_R + rand(R_R - L_R + 1);
                int k = L_K + rand(R_K - L_K + 1);
                assert(1 <= l and l <= r and r <= MAXVALUE);
                assert(0 <= k and k <= 9);
                cout<<l<<' '<<r<<' '<<k<<'\n';
            }
        };
        tuple < int,llong,llong,llong,llong,int,int> T[] = {
            {1,1,MAXVALUE_2 * 50,MAXVALUE_2 * 80,MAXVALUE_2 * 100,0,5},
            {1,MAXVALUE_2,MAXVALUE_2 * 2,MAXVALUE_2 * 4,MAXVALUE_2 * 8,6,9},
            {1,MAXVALUE / 4,MAXVALUE / 2,MAXVALUE - 10000,MAXVALUE,0,9},
            {1,1,30,MAXVALUE - 5,MAXVALUE,0,9}
        };
        int coins = rand(4);
        gentest(T[coins]);
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Task::solve();
}




