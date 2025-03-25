VƯỢT MỨC PICKLEBALL (PHIÊN BẢN DSA) 
Sau khi khóa đầu tiên của lớp Pickleball kết thúc, giáo sư Pickleball PMQ lại mở lớp học chơi Pickleball cho các bạn UIT và USSH. Vào kỳ thi cuối kỳ, mỗi bạn được đánh bóng n lần, với lần thứ i được chấm x điểm. Trong quá trình đánh bóng, một cú đánh bóng được xem là vượt mức Pickleball nếu điểm của cú đánh đó lớn hơn hoặc bằng 2 lần giá trị điểm trung vị của d lần đánh trước đó (Lưu ý: Nếu giá trị d chẵn, giá trị trung vị được xác định là giá trị trung bình của 2 phần tử ở giữa). 
Cho n điểm đánh bóng của một bạn sinh viên bất kỳ, bạn hãy viết chương trình kiểm tra xem bạn đó đã vượt mức Pickleball bao nhiêu lần? 
INPUT 
Dòng đầu tiên là 2 số nguyên dương n và d (1 ≤ n ≤ 2 x 105; 1≤ d ≤n) 
Dòng tiếp theo chứa n số a1, a2,..., an với (0 ≤ a ≤ 200) là điểm số mà sinh viên đó đạt được trong n lần đánh bóng. 
OUTPUT 
Số lần sinh viên đó vượt mức Pickleball. 
EXAMPLE

Input:
9 5
2 3 4 2 3 6 8 4 5
------------------------
5 4
1 2 3 4 4
Output:
2
------------------------
0


- Ý Tưởng: dùng kĩ thuật sắp xếp bằng 2 mảng chứ không dùng sort vì khỏi bị việc cứ bị mất độ phức tạp O gì gì đó khi duyệt dần từng giá trị
bắt đầu từ giá trị thứ 6 của mảng trở đi tới cuối mảng
1. Cấu trúc dữ liệu
Chúng ta sử dụng hai multiset:

be (nhóm bé): chứa nửa nhỏ hơn của cửa sổ.

lon (nhóm lớn): chứa nửa lớn hơn của cửa sổ.

Quy ước:

Nếu số lượng phần tử là lẻ, be sẽ chứa nhiều hơn lon đúng 1 phần tử.

Nếu số lượng phần tử là chẵn, be và lon chứa số phần tử bằng nhau.

2. Chức năng chính
a) Chèn phần tử vào cửa sổ (insert)
Nếu be rỗng hoặc 𝑥 ≤ max (𝑏𝑒)
x ≤ max (be) thì chèn vào be.

Ngược lại, chèn vào lon.

Gọi hàm balance() để cân bằng số lượng phần tử.

b) Xóa phần tử khỏi cửa sổ (erase)
Nếu phần tử cần xóa nằm trong be, ta xóa khỏi be.

Nếu không, ta xóa khỏi lon.

Gọi balance() để đảm bảo be và lon vẫn cân bằng.

c) Cân bằng hai multiset (balance)
Nếu be có nhiều hơn lon hơn 1 phần tử, ta chuyển phần tử lớn nhất của be sang lon.

Nếu lon có nhiều phần tử hơn be, ta chuyển phần tử nhỏ nhất của lon sang be.

d) Tính trung vị (TB)
Nếu be có nhiều phần tử hơn lon, trung vị chính là max(be).

Nếu hai tập có số phần tử bằng nhau, trung vị là trung bình của max(be) và min(lon).

Độ phức tạp
Thêm/Xóa phần tử trong multiset: 𝑂(log𝑘)
Cập nhật trung vị: 𝑂(1)
Tổng thời gian chạy: 𝑂(𝑛log𝑘)

BÀI TOÁN CẤM: define, include, using, std, algorithm
*CHÚ Ý: đầu tiên cần phải biết trung vị là gì trước, trung vị trong bài không nói nhưng trung vị là phải tính trong mảng đã được SẮP XẾP TĂNG DẦN


CODE:


#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct TimTB{
    multiset<int> be, lon;

    void insert(int x){
        if(be.empty() or x <= *be.rbegin()) be.insert(x);
        else lon.insert(x);
        balance();
    }

    void erase(int x){
        if(be.find(x) != be.end()) be.erase(be.find(x));
        else lon.erase(lon.find(x));
        balance();
    }

    void balance(){
        while(be.size() > lon.size() + 1){
            lon.insert(*be.rbegin());
            be.erase(prev(be.end()));
        }
        while(be.size() < lon.size()){
            be.insert(*lon.begin());
            lon.erase(lon.begin());
        }
    }

    double TB(){
        if(be.size() > lon.size()) return *be.rbegin();
        return (*be.rbegin() + *lon.begin()) / 2.0;
    }
};

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    TimTB result;
    int count = 0;
    for(int i = 0; i < k; i++) result.insert(a[i]);
    for(int i = k; i < n; i++){
        if(a[i] >= 2 * result.TB()) count++;
        result.insert(a[i]);
        result.erase(a[i - k]);
    }
    cout << count;
}
