#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod197 = 1e9 + 7;

ll fastpow(ll number,ll power,ll mod){
    ll answer = 1;
    
    while(power){
        if(power%2){
            answer = (answer * number) % mod;
        }
        number = (number * number) % mod;
        power /= 2;
    }

    return answer;
}

vector<ll> v[5050];
ll res[5050];
ll p[5050];
ll q[5050];
ll n,curnum;

void place(int pos){
    if(res[pos]!=-1)return ;

    bool flag = true;
    while(flag){
        flag = false;
        for(ll i : v[pos]){
            if(res[i]==-1 && q[i]==0){
                res[i] = curnum;
                --curnum;
                flag = true;

                for(ll j : v[i]){
                    if(res[j]==-1){
                        --q[j];
                    }
                }
                break;
            }
        }
    }

    res[pos] = curnum;
    --curnum;
    for(ll i : v[pos]){
        if(res[i]==-1){
            --q[i];
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p[i];
        res[i]=-1;
    }
    for(int i=1;i<=n;++i){
        cin>>q[i];
    }

    for(int i=n;i>0;--i){
        v[i] = {};
        for(ll j=1;j<i;++j){
            if(p[i]>p[j]){
                v[i].push_back(j);    
            }
        }
    }

    curnum = n;
    for(int i=n;i>0;--i){
        place(i);
    }

    for(int i=1;i<=n;++i){
        if(q[i]!=0 || res[i]==-1){
            cout<<"-1\n";
            return ;
        }
    }

    for(int i=1;i<n;++i){
        cout<<res[i]<<" ";
    }cout<<res[n]<<"\n";

}

int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
7
3
2 3 1
1 0 0
4
3 4 1 2
2 1 1 0
5
2 3 1 4 5
2 2 1 1 0
1
1
0
5
3 1 4 2 5
1 1 1 1 0
4
3 4 2 1
1 1 1 0
8
7 6 3 1 2 5 4 8
1 1 2 2 2 1 1 0

*/