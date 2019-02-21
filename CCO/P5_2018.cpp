#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#define FILL(S,V) memset(S,V,sizeof(S))
#define INF 0x3f3f3f3f
#define FAST_IO std::cin.tie(NULL);std::cout.tie(NULL);std::ios_base::sync_with_stdio(false);
typedef unsigned long long ull;
typedef long long ll;

#define MAXN 1000001
#define MAX_SEG 4000004

ll vtree[MAX_SEG];
ll utree[MAX_SEG];
ll values[MAXN];

ll n;

void construct_utree(ll lo, ll hi, ll pos) {
    if (lo == hi) {
        utree[pos]=lo;
        return;
    }
    ll mid = (lo+hi)/2;
    ll left=2*pos;
    ll right=left+1;
    construct_utree(lo,mid,left);
    construct_utree(mid+1,hi,right);
    if(values[utree[left]]>values[utree[right]]) {
        utree[pos]=utree[left];
    } else {
        utree[pos]=utree[right];
    }
}

void update_vtree(ll lo, ll hi, ll pos, ll e, ll v) {
    if(lo > e || hi < e) return;
    if(lo==hi) {
        vtree[pos]=v;
        return;
    }
    ll mid=(lo+hi)/2;
    ll left=2*pos;
    ll right=left+1;
    update_vtree(lo,mid,left,e,v);
    update_vtree(mid+1,hi,right,e,v);
    vtree[pos]=std::max(vtree[left],vtree[right]);
}

void update_utree(ll lo,ll hi, ll pos, ll e) {
    if(lo > e || hi < e) return;
    if(lo==hi) {
        vtree[pos]=lo;
        return;
    }
    ll mid=(lo+hi)/2;
    ll left=2*pos;
    ll right=left+1;
    update_utree(lo,mid,left,e);
    update_utree(mid+1,hi,right,e);
    utree[pos]=utree[values[utree[left]]>values[utree[right]]?left:right];
}

ll max_query(ll lo, ll hi, ll qlo, ll qhi, ll pos) {
    if(lo >qhi || hi < qlo || qlo > qhi) return n;
    if(lo >= qlo && hi <= qhi) return utree[pos];
    ll mid=(lo+hi)/2;
    ll lchild=2*pos;
    ll rchild=lchild+1;
    ll lv=max_query(lo,mid,qlo,qhi,lchild);
    ll rv=max_query(mid+1,hi,qlo,qhi,rchild);
    return values[lv]>values[rv]?lv:rv;
}

int main() {
    FAST_IO

    ll k, q;
    std::cin >> n >> k >> q;

    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    construct_utree(0,n-1,1);
    for(int i = 0; i < n; ++i) {
        ll left=max_query(0,n-1,std::max(0ll,i-k+1),i-1,1);
        ll right=max_query(0,n-1,i+1,std::min(n-1,i+k-1),1);
        if(values[i]>=values[left]&&values[i]>values[right]) {
            update_vtree(0,n-1,1,i,values[i]+std::max(values[left],values[right]));
        }
    }

    std::cout << vtree[1] << "\n";
    for(int i = 0; i < q; ++i) {
        ll j,x;
        std::cin >> j >> x;
        j-=1;
        values[j]=x;
        update_utree(0,n-1,1,j);
        ll left=max_query(0,n-1,std::max(0ll,j-k+1),j-1,1);
        ll right=max_query(0,n-1,j+1,std::min(n-1,j+k-1),1);
        if(values[j]>=values[left]&&values[j]>values[right]) {
            update_vtree(0,n-1,1,j,values[j]+std::max(values[left],values[right]));
        } else {
            update_vtree(0,n-1,1,j,0);
            if(values[left]) {
                ll lv=max_query(0,n-1,left+1,std::min(n-1,left+k-1),1);
                ll rv=max_query(0,n-1,std::max(0ll,left-k+1),left-1,1);
                if(values[left]>=values[rv]&&values[left]>values[lv]) {
                    update_vtree(0,n-1,1,left,values[left]+std::max(values[lv],values[rv]));
                }
            }
            if(values[right]) {
                ll lv=max_query(0,n-1,right+1,std::min(n-1,right+k-1),1);
                ll rv=max_query(0,n-1,std::max(0ll,right-k+1),right-1,1);
                if(values[right]>=values[rv]&&values[right]>values[lv]){
                    update_vtree(0,n-1,1,right,values[right]+std::max(values[lv],values[rv]));
                }
            }
        }
        std::cout << vtree[1] << "\n";
    }
}