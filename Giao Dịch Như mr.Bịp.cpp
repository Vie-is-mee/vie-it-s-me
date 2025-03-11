Ý TƯỞNG: Tìm kiếm nhị phân cho phần tiền sao cho tại số tiền đó thì tổng người bán >= tổng người mua.

CODE:

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
