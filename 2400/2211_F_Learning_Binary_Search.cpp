#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll mod197 = 1e9 + 7;
const ll mod67 = 676767677;

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

void initC(ll n, ll mod){
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

ll n,m,totalcomb,res,t;
ll used[2002000];
ll vals[2002000];

void make_f(ll l, ll r,ll cnt){
    if(l>r)return ;
    ll mid=floor((l+r)/2);

    ll cur = totalcomb;
    ll left0;
    if(l==1)left0 = 0;
    else {
        if(used[n+m-1-(mid-l+1)]!=t){
            used[n+m-1-(mid-l+1)]=t;
            vals[n+m-1-(mid-l+1)]=C(n+m-1-(mid-l+1),m-1,mod67);
        }
        left0 = vals[n+m-1-(mid-l+1)];
    }
    ll right0;
    if(r==n)right0=0;
    else {
        if(used[n+m-1-(r-mid+1)]!=t){
            used[n+m-1-(r-mid+1)]=t;
            vals[n+m-1-(r-mid+1)]=C(n+m-1-(r-mid+1),m-1,mod67);
        }
        right0 = vals[n+m-1-(r-mid+1)];
    }
    
    ll leftright00;
    if(r==n || l==1)leftright00 = 0;
    else {
        if(used[n+m-1-(r-l+2)]!=t){
            used[n+m-1-(r-l+2)]=t;
            vals[n+m-1-(r-l+2)]=C(n+m-1-(r-l+2),m-1,mod67);
        }
        leftright00 = vals[n+m-1-(r-l+2)];
    }

    //cout<<l<<" "<<r<<" - "<<cnt<<endl;
    //cout<<cur<<" "<<left0<<" "<<right0<<" "<<leftright00<<endl<<endl;

    cur=(cur-left0+mod67)%mod67;
    cur=(cur-right0+mod67)%mod67;
    cur=(cur+leftright00)%mod67;
    res = (res+(cur*cnt)%mod67)%mod67;

    make_f(l,mid-1,cnt+1);
    make_f(mid+1,r,cnt+1);
}

void solve(){
    cin>>n>>m;
    
    totalcomb = C(n+m-1,m-1,mod67);
    res = 0;

    make_f(1,n,1);

    cout<<res<<endl;
}

int main(){
    initC(2000100,mod67);
    fill_n(used,size(used),-1);

    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
/*
1 1 1
1 1 2
1 1 3
1 2 2 - l
1 2 3 - l
1 3 3 - l
2 2 2
2 2 3
2 3 3 - l
3 3 3


1 1
1 2
2 2
*/