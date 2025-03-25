Chênh lệch nhỏ nhất
Cho mảng số nguyên gồm N phần tử không trùng lặp. Tìm tất cả các cặp số trong
mảng sao cho chênh lệch giữa chúng là nhỏ nhất.
Lưu ý: Khi in các cặp số, in theo thứ tự tăng dần.
INPUT
- Dòng đầu tiên là số nguyên dương n (2 ≤ 𝑛 ≤ 200000)
- Dòng tiếp theo chứa n số 𝑎ଵ
, 𝑎ଶ
, … , 𝑎ே với (−10଻ ≤ 𝑎௜ ≤ 10଻) là các phần tử
trong mảng.
OUTPUT
- Tất cả các cặp số trong mảng sao cho chênh lệch giữa chúng là nhỏ nhất
EXAMPLE
Input:
12
-20 -3916237 -357920 -3620601 7374819 -7330761 30
6246457 -6461594 266854 -520 -470
-------------------------------------------------
4
5 4 3 2
Output:
-520 -470 -20 30
------------------------------------------------
2 3 3 4 4 5


Ta thấy rằng: ở test 1 số trước trừ số sau = 50
- Ý Tưởng: sắp xếp bằng Quick_Sort hay sort nào có độ phức tạp thấp để chạy vừa đủ thời gian, lấy min của diff số trước và sau 
nếu diff == min thì thêm cặp vào 1 vector nếu diff > min thì cặp nhật min = diff và xóa hết các phần tử trong vector vừa rồi đã lưu


CODE:

#include <bits/stdc++.h>
using namespace std;

void Quick_Sort(vector<int> &a, int low, int high) {
    if (low >= high) return;
    int pivot = a[low + (high - low) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    Quick_Sort(a, low, j);
    Quick_Sort(a, i, high);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    Quick_Sort(a, 0, n - 1);
    int min_val = INT_MAX;
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++) {
        int diff = a[i] - a[i - 1];
        if (diff < min_val) {
            min_val = diff;
            v.clear();
        }
        if (diff == min_val) {
            v.emplace_back(a[i - 1], a[i]);
        }
    }
    for (auto &[x, y] : v) {
        cout << x << " " << y << ' ';
    }
}
