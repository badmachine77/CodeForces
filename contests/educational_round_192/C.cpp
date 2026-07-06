#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

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

vector<ll> cnts;
ll a[300300];
ll n,k;
void solve(){
    cin>>n>>k;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }

    cnts.clear();
    ll am = 1;
    for(ll i=2;i<=n;++i){
        if(a[i]!=a[i-1]){
            cnts.push_back(am);
            am=0;
        }
        ++am;
    }
    cnts.push_back(am);

    ll lef = n;
    ll bynow=0;
    sort(cnts.rbegin(),cnts.rend());
    
    //for(ll i : cnts)cout<<i<<" ";cout<<endl;

    ll res=0;
    while(true){
        if(cnts.size()==0)break;        

        lef -= cnts.size()*((cnts[cnts.size()-1]-1)-bynow);
        bynow=cnts[cnts.size()-1];
        ll gg = cnts[cnts.size()-1];

        //cout<<lef<<" "<<bynow<<" "<<gg<<" "<<k<<endl;

        if(k-lef>=0 && (k-lef)%cnts.size()==0){
            ++res;
        }

        lef-=cnts.size();

        while(!cnts.empty()){
            if(cnts[cnts.size()-1]==gg)cnts.pop_back();
            else break;
        }
    }
    cout<<res<<endl;
    //cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
/*

*/