CSES - Sum of Four Values
Bạn được cho một mảng gồm N số nguyên và nhiệm vụ của bạn là tìm bốn giá trị (tại các vị trí
phân biệt) có tổng là X.
Dữ liệu
• Dòng đầu tiên gồm số nguyên dương N(N ≤ 1000) và số nguyên X (1 ≤ X ≤ 109).
• Dòng thứ hai chứa N số nguyên ai(1 ≤ ai ≤ 109).
Kết quả
• In bốn số nguyên: vị trí của các giá trị. Nếu có một số lời giải, bạn có thể in bất kỳ lời giải
nào trong số đó. Nếu không có lời giải nào, in IMPOSSIBLE.
Ví dụ
Sample Input
8 15
3 2 5 8 1 3 2 3
Sample Output
2 4 6 7



Ý tưởng: lưu tất cả các tổng có thể của 2 trong 4 số, rồi lấy số cần tính - tổng rồi check phần dư xem có trong các tổng đã lưu không rồi xuất ra vị trí.


CODE:
- Cách này bị bộ nhớ tối đa



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    map<ll, vector<pair<int, int>>> mp;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            mp[a[i] + a[j]].push_back({i, j});
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ll du = x - (a[i] + a[j]);
            if(mp.find(du) != mp.end()){
                for(auto [k, l] : mp[du]){
                    if(k != i && k != j && l != i && l != j){
                        cout << k+1 << " " << l+1 << " " << i+1 << " " << j+1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}



- Cách này tốt hơn



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    unordered_map<ll, pair<int, int>> mp;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ll sum = a[i] + a[j];
            ll need = x - sum;
            if(mp.count(need)){
                auto [k, l] = mp[need];
                if(k != i && k != j && l != i && l != j){
                    cout << k+1 << " " << l+1 << " " << i+1 << " " << j+1 << "\n";
                    return 0;
                }
            }
        }
        for(int k = 0; k < i; ++k){
            mp[a[k] + a[i]] = {k, i};
        }
    }
    cout << "IMPOSSIBLE\n";
}
