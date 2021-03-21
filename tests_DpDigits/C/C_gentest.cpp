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

    void solve(){
        auto genNumber = [&](const bool is_max,int L,int R) -> string{
            if(is_max){
                return "1" + string(50,'0');
            } else {
                int Len = L + rand(R - L + 1);
                string ret = "";
                bool is_first = true;
                while(Len--){
                    int lhs = (is_first ? 1 : 0);
                    int rhs = (is_first ? 9 : 10);
                    ret += (char)((lhs + rand(rhs)) + '0');
                    is_first = false;
                }
                assert(len(ret) > 0);
                assert(len(ret) <= 50);
                assert(ret[0] != '0');
                return ret;
            }
        };
        auto genTest = [&](const tuple < int,int,int,int,bool > t) -> void{
            bool is_max;
            int L_L,R_L;
            int L_R,R_R;
            tie(L_L,R_L,L_R,R_R,is_max) = t;
            string l = genNumber(is_max,L_L,R_L);
            string r = genNumber(is_max,L_R,R_R);
            cout<<l<<' '<<r<<'\n';
        };
        tuple < int,int,int,int,bool > T[] = {
            {1,10,11,20,false},
            {5,15,16,30,false},
            {20,30,31,45,false},
            {45,47,48,50,false},
            {1,10,45,50,false},
            {1,2,47,50,false}
        };
        int nTest = 1 + rand(100); 
        cout<<nTest<<'\n';
        while(nTest--){
            int coins = rand(7);
            if(coins == 6){
                cout<<genNumber(false,1,10)<<' '<<genNumber(true,-1,-1)<<'\n';
            } else {
                genTest(T[coins]);
            }
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Task::solve();
}

