Kiểm kê 2
   Cửa hàng X có nhiều loại hàng, mỗi loại hàng đều có mã khác nhau. Tuy nhiên, trong lúc bán hàng, nhân viên quên không nhập số lượng mỗi loại mà chỉ nhập mã các loại hàng trên từng dòng. Bạn hãy cho biết với mỗi loại hàng thì cửa hàng đã bán được bao nhiêu?  


Ví dụ: Có một số loại hàng có mã lần lượt là  [123, 45, 8, 19, 1, 2333]. 

Bạn nhân viên sẽ nhập theo từng dòng [123, 45, 45, 8, 1, 123, 123, 8, 8]. 

Từ đây có thể biết:

Với loại hàng có mã là 1 thì cửa hàng đã bán 1.

Với loại hàng có mã là 8 thì cửa hàng đã bán 3.

Với loại hàng có mã là 45  thì cửa hàng đã bán 2.

Với loại hàng có mã là 123 thì cửa hàng đã bán 3.



Input: 

Dòng đầu tiên là  số nguyên 
(1 ≤ N ≤ 5 × 10^4)
 là số lượng mã loại hàng được nhập.

N dòng tiếp theo, mỗi dòng là một mã của loại hàng được nhập, độ dài của mã có thể lên tới 100.

Output:

Gồm nhiều dòng, mỗi dòng gồm 2 thành phần là mã số của một loại hàng và số lượng loại hàng đó. In kết quả theo thứ tự giảm dần theo số lượng từng loại hàng, nếu số lượng bằng nhau thì in theo mã số tăng dần.

Chú ý:

So sánh 2 mã theo thứ tự số tự nhiên.
Sử dụng '\n' để xuống dòng thay vì endl để tránh bị Time Limit Exceeded (TLE)

Input:
10

123

123444

123444

12

1

8

1

455

455

9

Output:
1 2

455 2

123444 2

8 1

9 1

12 1

123 1

Bài này cấm: sort, stable_sort, partial_sort, partial_sort_copy, sort_heap, set, multi_set, map, unordered_map, priority_queue.

- Ý Tưởng: Bài này là mã nhập vào là chuỗi ký tự chứ không phải int, dùng Merge_Sort để độ phức tạp ổn định ở O(nlogn), dùng sort cho mảng a đầu vào
và sort cho 1 vector pair dùng lưu mã và tần xuất của nó.
CHÚ Ý: bài này lúc nhập vào từng mã đừng dùng cin.ignore() rồi getline(cin,...) vì wecode có thể có 1 vài kí tự bị lỗi nên rất hên xui để đúng hay sai
do đó cứ dùng cin từng mã như bình thường

CODE:

#include <bits/stdc++.h>
using namespace std;

bool Compare(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void Merge(vector<string> &a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Compare(L[i], R[j])) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void MergeSort(vector<string> &a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

bool ComparePair(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second != b.second) return a.second > b.second;
    return Compare(a.first, b.first);
}

void Merge(vector<pair<string, int>> &a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<pair<string, int>> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (ComparePair(L[i], R[j])) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void MergeSort(vector<pair<string, int>> &a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    MergeSort(a, 0, n - 1);
    vector<pair<string, int>> v;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            v.push_back({a[i - 1], count});
            count = 1;
        } else {
            count++;
        }
    }
    v.push_back({a[n - 1], count});
    MergeSort(v, 0, v.size() - 1);
    for (const auto &p : v) {
        cout << p.first << ' ' << p.second << '\n';
    }
}
