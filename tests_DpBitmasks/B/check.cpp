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
    const string PATH = "/home/datbeohbbh/Desktop/MY_PROJECT/HVT_DpBitmasks/DpBitmasks_HVT/tests_DpBitmasks/B/mock_test";
    
    fi.open(PATH + "/B.inp",ifstream::in);
    fa.open(PATH + "/B.ans",ifstream::in);
    fo.open(PATH + "/B.out",ifstream::in);
    
    */
    
    bool ok = true;

    int n,val,diff = 0;
    fi>>n;
    
    vector < int > a;
    while(fi >> val){
        a.emplace_back(val);
    }
    
    vector < int > author_ans;
    while(fo >> val){
        author_ans.emplace_back(val);
    }
    for(int i = 0;i < n;++i){
        diff += (int)abs(a[i] - author_ans[i]);
    }
    
    vector < int > cper_ans;
    while(fa >> val){
        cper_ans.emplace_back(val);
    }
    
    if((int)cper_ans.size() != n){
        ok = false;
    } else {
        int chk = true;
        for(int i = 0;i < n;++i){
            for(int j = i + 1;j < n;++j){
                if(__gcd(cper_ans[i],cper_ans[j]) != 1){
                    chk = false;
                }
            }
        }
        
        for(int i = 0;i < n;++i){
            diff -= (int)abs(a[i] - cper_ans[i]);
        }
        
        if(!chk or diff != 0){
            ok = false;
        }
    }
    cout<<(ok ? "1.0\n" : "0.0\n");
}

int main(){
    char fin[] = "B.inp";
    char fou[] = "B.out";
    themis_init(fin, fou);
    check();
    themis_close();
    return 0;
}


