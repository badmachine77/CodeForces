#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pq[100100];
ll qp[100100];
ll bestsums[100100];
ll a[100100];
ll n,k,p,q;

void solve(){
    cin>>n>>k>>p>>q;

    for(int i=1;i<=n;++i){
        cin>>a[i];
        pq[i] = pq[i-1] + (a[i]%p)%q;
        qp[i] = qp[i-1] + (a[i]%q)%p;
    }

    for(ll i=1;i<=n;++i){
        bestsums[i] = bestsums[i-1] + min(pq[i]-pq[i-1],qp[i]-qp[i-1]);
    }


    ll res = pq[n];
    for(int i=k;i<=n;++i){
        res = min(res, min(pq[i]-pq[i-k],qp[i]-qp[i-k]) + (bestsums[i-k]) + (bestsums[n]-bestsums[i]));
    }
    
    cout<<res<<endl;
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
6
1 1 3 4
2026
3 2 10 20
31 41 59
4 3 3 4
1 2 3 4
6 4 9 20
18 27 180 9 45 99
7 4 3 5
6 7 14 12 100 78 4
9 4 244 353
9982 4435 3998 2443 5399 8244 3539 9824 4353


2
7 4 3 5
6 7 14 12 100 78 4
9 4 244 353
9982 4435 3998 2443 5399 8244 3539 9824 4353
*/