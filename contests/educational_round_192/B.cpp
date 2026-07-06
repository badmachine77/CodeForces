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

ll bin[800800];
ll lazy[800800];
ll cnt1[200200];
ll cnt2[200200];
ll cnt3[200200];
ll a[200200];
ll n;

void buildbin(ll pos,ll l,ll r){
    if(l==r){
        bin[pos]=cnt1[l]+cnt2[l]-cnt3[l];
        lazy[pos]=0;
        return ;
    }
    ll mid=(l+r)/2;
    buildbin(pos*2,l,mid);
    buildbin(pos*2+1,mid+1,r);
    bin[pos]=max(bin[pos*2],bin[pos*2+1]);
    lazy[pos]=0;
}

void upd(ll pos){
    bin[pos*2]+=lazy[pos];
    bin[pos*2+1]+=lazy[pos];
    lazy[pos*2]+=lazy[pos];
    lazy[pos*2+1]+=lazy[pos];
    lazy[pos]=0;
}

void rem(ll pos,ll l,ll r,ll w){
    if(l==r){
        bin[pos]=-1e9;
        return ;
    }
    ll mid=(l+r)/2;
    upd(pos);

    if(w<=mid)rem(pos*2,l,mid,w);
    else rem(pos*2+1,mid+1,r,w);
    
    bin[pos]=max(bin[pos*2],bin[pos*2+1]);
}

void printbin(ll pos, ll l, ll r){
    cout<<pos<<" "<<l<<" "<<r<<" "<<bin[pos]<<endl;
    if(l==r)return ;
    ll mid=(l+r)/2;
    printbin(pos*2,l,mid);
    printbin(pos*2+1,mid+1,r);
}

void solve(){
    cin>>n;
    cnt1[0]=0;
    cnt2[0]=0;
    cnt3[0]=0;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
        cnt3[i]=cnt3[i-1];
        if(a[i]==1)++cnt1[i];
        else if(a[i]==2)++cnt2[i];
        else ++cnt3[i];
    }

    buildbin(1,1,n-1);

    for(ll i=1;i<=n-2;++i){
        rem(1,1,n-1,i);
        if(a[i]==3){
            bin[1]+=1;
            lazy[1]+=1;
        }
        else {
            bin[1]-=1;
            lazy[1]-=1;
        }
        upd(1);
        //cout<<"-----"<<i<<endl;
        //printbin(1,1,n-1);

        if(cnt1[i]>=cnt2[i]+cnt3[i]){

            //cout<<i<<" "<<bin[1]<<" "<<endl;
            if(bin[1]>=0){
                cout<<"YES"<<endl;
                return ;
            }
        }
    }

    cout<<"NO"<<endl;

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
10
8
2 1 1 3 3 1 2 3
7
2 1 3 3 3 2 3
4
1 3 3 2
6
2 2 2 1 1 1
8
3 2 1 2 1 1 2 3
3
2 1 2
3
1 2 3
5
1 3 3 1 1
5
1 1 3 3 1
3
1 3 1


1
7
2 1 3 3 3 2 3
*/