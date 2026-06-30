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

ll n;
ll a[200200];
ll b[200200];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    for(ll i=1;i<=n;++i){
        cin>>b[i];
    }

    for(ll i=n;i>0;--i){
        if(a[i]<b[i])continue;
        if(a[i]>b[i]){
            a[i-1]+=a[i]-b[i];
        }
    }

    if(a[1]>b[1]){
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }
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