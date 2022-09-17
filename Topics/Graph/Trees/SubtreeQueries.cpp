/*
   CSES Subtree Queries
   https://cses.fi/problemset/task/1137

   Flatten tree using first visited time
   Also store the time when the node is out
   Now we have the starting index tin[u] and ending index tout[u]
   In these range all the nodes of subtree of u exists
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
int a[N], tin[N], tout[N], val[N];
ll tr[4*N];
ll lz[4*N];

///1. Merge left and right
ll combine (ll left, ll right) {
    return left + right;
}

///2. Push lazy down and merge lazy
void propagate(int u, int st, int en) {
    if (!lz[u]) return;
    tr[u] += (en-st+1)*lz[u];
    if (st!=en) {
        lz[2*u] += lz[u];
        lz[2*u+1] += lz[u];
    }
    lz[u] = 0;
}


void build(int u, int st, int en) {
    if (st==en) {
        tr[u] = a[st];          ///3. Initialize
        lz[u] = 0;
    }
    else {
        int mid = (st+en)/2;
        build(2*u, st, mid);
        build(2*u+1, mid+1, en);
        tr[u] = combine(tr[2*u], tr[2*u+1]);
        lz[u] = 0;              ///3. Initialize
    }
}

void update(int u, int st, int en, int l, int r, int x) {
    propagate(u, st, en);
    if (r<st || en<l)  return;
    else if (l<=st && en<=r) {
        lz[u] += x;             ///4. Merge lazy
        propagate(u, st, en);
    }
    else {
        int mid = (st+en)/2;
        update(2*u, st, mid, l, r, x);
        update(2*u+1, mid+1, en, l, r, x);
        tr[u] = combine(tr[2*u], tr[2*u+1]);
    }
}

ll query(int u, int st, int en, int l, int r) {
    propagate(u, st, en);
    if (r<st || en<l)  return 0;        /// 5. Proper null value
    else if (l<=st && en<=r)    return tr[u];
    else {
        int mid = (st+en)/2;
        return combine(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}

void debug(int u, int st, int en) {
    cout<<"--->"<<u<<" "<<st<<" "<<en<<" "<<tr[u]<<" "<<lz[u]<<endl;
    if (st==en) return;
    int mid = (st+en)/2;
    debug(2*u, st, mid);
    debug(2*u+1, mid+1, en);
}

vector<vector<int>> g;

void dfs(int u, int p=-1){
    static int timer = 0;
    tin[u] = ++timer;
    a[timer] = val[u];

    for(auto v:g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    tout[u] = timer;
}

int main() {
    int n,q;
    cin>>n>>q;
    
    g = vector<vector<int>>(n+1);

    for(int i=1;i<=n;i++){
        cin>>val[i];
    } 
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    dfs(1);
    build(1,1,n);

    while(q--){
        int c,s,x;
        cin>>c>>s;
        if(c==1){
            cin>>x;
            update(1,1,n,tin[s],tin[s], x-val[s]);
            val[s] = x;
        } else {
            cout<<query(1,1,n,tin[s],tout[s])<<"\n";
        }
    }
}
