#include <bits/stdc++.h>

using namespace std;

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

// success signal is 0, else fail

ifstream finp,fout,fans;

void init_ifstream(string init_finp,string init_fout,string init_fans){
    finp.open(init_finp,ifstream::in);
    fout.open(init_fout,ifstream::in);
    fans.open(init_fans,ifstream::in);
}

void close_ifstream(){
    finp.close();
    fout.close();
    fans.close();
}

int message(int flag){
    if(!flag){
        // success message
        cout<<"> competitor's answer is OK!!\n";
    } else {
        cout<<"> competitor found wrong answer.\n";
    }
    return flag;
}

int check(){
    // ok show if competitor's answer is correct - 0/1 <=> wrong/correct.
    int ok = 1;
    function < int(pair < int,int >,pair < int,int > v) > dist = [](pair < int,int > u,pair < int,int > v) -> int{
        return (u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second);
    };

    vector < pair < int,int > > coordinates;
    int x,y; finp>>x>>y;
    coordinates.emplace_back(make_pair(x,y));
    
    int n; finp>>n;
    
    while(finp>>x>>y){
        coordinates.emplace_back(make_pair(x,y));
    }

    int expected_dist;
    fout >> expected_dist;
    
    int cper_dist;
    fans >> cper_dist;

    if(cper_dist != expected_dist){
        ok &= false;
    } else {
        vector < int > cper_path;
        int val;
        while(fans >> val){
            cper_path.emplace_back(val);
        }
        if((int)cper_path.size() <= 2){
            ok &= false;
        } else {
            if(cper_path[0] != 0 || cper_path.back() != 0){
                ok &= false;
            } else {
                int lst = 0;
                bool check_carried_object = true;
                for(int i = 1;i < (int)cper_path.size();++i){
                    if(cper_path[i] == 0){
                        if(i - lst - 1 > 2){
                            check_carried_object = false;
                            break;
                        }
                        lst = i;
                    }
                    pair < int,int > u = coordinates[cper_path[i - 1]];
                    pair < int,int > v = coordinates[cper_path[i]];
                    expected_dist -= dist(u,v);
                }
                ok &= (expected_dist == 0 && check_carried_object ? true : false);
            }
        }
    }
    // do not edit 'return' line.
    return message(ok ? 0 : 1);
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(argc != 4){
        exit(1);
    } else {
        init_ifstream(argv[1],argv[2],argv[3]);
        int signal = check();
        close_ifstream();
        cout<<'\n';
        exit(signal);
    }
}


