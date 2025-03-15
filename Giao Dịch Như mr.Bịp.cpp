Ý TƯỞNG: Tìm kiếm nhị phân cho phần tiền sao cho tại số tiền đó thì tổng người bán >= tổng người mua.

*CODE theo cách 1:

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200001

int main(){
    int n, m;
    cin >> n >> m;
    int a[MAX], b[MAX];
    ll r = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        r += a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        r += b[i];
    }
    ll l = 1, mid;
    mid = (l + r) / 2;
    ll gia = r;
    do{
        int nguoiban = 0;
        int nguoimua = 0;
        for(int i = 0; i < n; i++){
            if(a[i] <= mid) nguoiban++;
        }
        for(int i = 0; i < m; i++){
            if(b[i] >= mid) nguoimua++;
        }
        if(nguoiban >= nguoimua){
            r = mid;
            gia = mid;
        }
        else l = mid;
        mid = (l + r) / 2;
    } while(l != r - 1);
    cout << gia;
}

---------------------------------------------------------------------------------------------------------
*CODE theo cách 2:

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b, int x){
    int nguoi_ban = upper_bound(a.begin(), a.end(), x) - a.begin();
    int nguoi_mua = b.end() - lower_bound(b.begin(), b.end(), x);
    return nguoi_ban >= nguoi_mua;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(n + m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        c[i + n] = b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int l = 0, r = n + m - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(a, b, c[mid])){
            cout << c[mid];
            return 0;
        }
        else{
            if(check(a, b, c[mid - 1])){
                cout << c[mid - 1];
                return 0;
            }
            else if(check(a, b, c[mid + 1])){
                cout << c[mid + 1];
                return 0;
            }
            else if(c[mid] < c[mid + 1]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    
}
