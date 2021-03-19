#include <bits/stdc++.h>
#define lli long long
#define pii pair<int, int>

using namespace std;
ifstream fi, fo, fa;

char TestPath[1000], CurrPath[1000];
char fINP[1000], fOUT[1000], fANS[1000];

void themis_init(const char* inName, const char* outName){
    gets(TestPath);
    gets(CurrPath);

    sprintf(fINP, "%s\\%s", TestPath, inName);
    sprintf(fANS, "%s\\%s", TestPath, outName);
    sprintf(fOUT, "%s\\%s", CurrPath, outName);
    fi.open(fINP, ifstream::in);
    fa.open(fANS, ifstream::in);
    fo.open(fOUT, ifstream::in);
}

void themis_close(){
    fi.close();
    fa.close();
    fo.close();
}


void check(){
    /*
    const string PATH = "/home/datbeohbbh/Desktop/MY_PROJECT/HVT_DpBitmasks/DpBitmasks_HVT/tests_DpBitmasks/D/mock_test";
    
    fi.open(PATH + "/D.inp",ifstream::in);
    fa.open(PATH + "/D.ans",ifstream::in);
    fo.open(PATH + "/D.out",ifstream::in);
    */
    
    bool ok = true;
    
    function < int(pair < int,int >,pair < int,int > v) > dist = [](pair < int,int > u,pair < int,int > v) -> int{
        return (u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second);
    };

    vector < pair < int,int > > coordinates;
    int x,y; fi>>x>>y;
    coordinates.emplace_back(make_pair(x,y));
    
    int n; fi>>n;
    
    while(fi>>x>>y){
        coordinates.emplace_back(make_pair(x,y));
    }

    int expected_dist;
    fo >> expected_dist;
    
    int cper_dist;
    fa >> cper_dist;

    if(cper_dist != expected_dist){
        ok &= false;
    } else {
        vector < int > cper_path;
        int val;
        while(fa >> val){
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
    
    cout<<(ok ? "1.0\n" : "0.0\n");
}

int main(){
    char fin[] = "D.inp";
    char fou[] = "D.out";
    themis_init(fin, fou);
    check();
    themis_close();
    return 0;
}
