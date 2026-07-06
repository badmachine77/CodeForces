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

ll a[5050];
ll b[5050];
ll dp[5050][5050];
ll n,m;
ll wha[5050][11],whb[5050][11];
ll wha0[5050],whb0[5050];
void solve(){
    string st1,st2;

    cin>>st1>>st2;
    n = st1.size();
    m = st2.size();
    for(ll i=0;i<n;++i){
        a[i+1]=st1[i]-'0';
    }
    for(ll i=0;i<m;++i){
        b[i+1]=st2[i]-'0';
    }

    for(ll i=1;i<=n;++i){
        for(ll j=0;j<=10;++j)wha[i][j]=-1;
        ll x=0;
        for(ll j=i;j>0;--j){
            x=(x+a[j])%10;
            if(wha[i][x]==-1)wha[i][x]=j-1;
        }
    }
    for(ll i=1;i<=m;++i){
        for(ll j=0;j<=10;++j)whb[i][j]=-1;
        ll x=0;
        for(ll j=i;j>0;--j){
            x=(x+b[j])%10;
            if(whb[i][x]==-1)whb[i][x]=j-1;
        }
    }
    
    for(ll i=1,x=0;i<=n;++i){
        x=(x+a[i])%10;
        for(ll j=1,y=0;j<=m;++j){
            y=(y+b[j])%10;
            if(x==y)dp[i][j]=1;
            else dp[i][j]=0;
        }
    }

    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=m;++j){
            if(wha[i][0]!=-1)dp[i][j]=max(dp[i][j],dp[wha[i][0]][j]);
            if(whb[j][0]!=-1)dp[i][j]=max(dp[i][j],dp[i][whb[j][0]]);
            
            for(ll h=0;h<10;++h){
                if(wha[i][h]<1 || whb[j][h]<1 || dp[wha[i][h]][whb[j][h]]==0)continue;
                dp[i][j]=max(dp[i][j], dp[wha[i][h]][whb[j][h]]+1);
            }
        }
    }

    if(dp[n][m]==0)cout<<"-1"<<endl;
    else cout<<dp[n][m]<<endl;
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