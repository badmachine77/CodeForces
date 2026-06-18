#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll mod197 = 1e9 + 7;

vector<ll> fact;

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

void init_fact(ll n, ll mod){
    fact = vector<ll>(n+1);

    fact[0]=1;
    for(ll i=1;i<=n;++i){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

ll C(ll from,ll take, ll mod){
    ll res = fact[from];
    res = (res*fastpow(fact[take],mod-2,mod))%mod;
    res = (res*fastpow(fact[from-take],mod-2,mod))%mod;
    return res;
}

bool used[2020];
ll n;
ll a[2020];
ll b[2020];

void solve(){
    cin>>n;
    fill(used,used+(n+1),0);

    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    for(ll i=1;i<=n;++i){
        cin>>b[i];
    }
    
    for(ll i=1;i<=n;++i){
        ll cnt=0;
        for(ll j=1;j<=n;++j){
            if(a[j]<=b[i])++cnt;
        }
        if(cnt<i){
            cout<<"-1"<<endl;
            return ;
        }
    }

    ll opcnt = 0;
    for(ll i=1;i<=n;++i){
        for(ll j=i;j<=n;++j){
            if(a[j]<=b[i]){
                for(ll h=j-1;h>=i;--h){
                    ++opcnt;
                    swap(a[h],a[h+1]);
                }
                break;
            }
        }
    }

    cout<<opcnt<<endl;
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

*/