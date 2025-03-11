Find MEX

Bài toán:

Cho trước một mảng có N phần tử. Hãy in ra MEXi với 0 <= i < n.

Biết rằng, MEXi là số nguyên nhỏ nhất lớn hơn hoặc bằng 0 mà không xuất hiện trong từ đầu mảng cho đến phần tử i.

Input :

Dòng đầu tiên là N (1 <= N <= 2 * 10^5) thể hiện số phần tử của mảng
Dòng tiếp theo chứ N số nguyên là các phần tử của mảng
 
Output:

N số nguyên tương ứng với MEXi
 
Ví dụ:

INPUT:
5

1 0 5 5 3

OUTPUT:

0 2 2 2 2

GIẢi THÍCH:

- Với i = 0, thì số nhỏ nhất chưa xuất hiện từ đầu mảng đến phần tử 0 là 0.

- Với i = 1, thì số nhỏ nhất chưa xuất hiện từ đầu mảng đến phần tử 1 là 2.

- Với i = 2, thì số nhỏ nhất chưa xuất hiện từ đầu mảng đến phần tử 2 là 2.

- Với i = 3, thì số nhỏ nhất chưa xuất hiện từ đầu mảng đến phần tử 3 là 2.

Với i = 4, thì số nhỏ nhất chưa xuất hiện từ đầu mảng đến phần tử 4 là 2.


-Ý TƯỞNG:
1/ Dùng 1 mảng bool (N + 1) để kiểm tra giá trị đó được duyệt qua chưa.
for(int i = 0 -> N)
cập nhật giá trị đã duyệt A[i] trong B
kiểm tra và cập nhật MEXi
in MEXi

2/ dùng 1 set lưu các giá trị từ 1 đến giá trị lớn nhất trong mảng, khi duyệt tới phần tử nào thì cứ xóa phần tử đó trong set rồi in ra *set.begin() là được.
nếu dùng vector.erase thì trước hết phải dùng iterator trỏ tới chỉ số của giá trị đó trong mảng mới xóa được
không những khó khăn mà cứ mỗi lần xóa thì độ phức tạp là O(N) lặp lại liên tục nên không tối ưu vì thế mới dùng set độ phức tạp O(logN) rất tiện lợi và tối ưu.


CODE:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max_a = 0;
    for (int &x : a) {
        cin >> x;
        max_a = max(max_a, x);
    }
    set<int> mex;
    for (int i = 0; i <= max_a + 1; i++) mex.insert(i);
    
    for (int i = 0; i < n; i++) {
        mex.erase(a[i]);
        cout << *mex.begin() << " ";
    }
}
