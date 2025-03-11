Equal Diverse Teams

Bài toán:

Alice có N học sinh trong lớp, được đánh số từ 1 đến N. Sinh viên thứ i có chuyên môn về môn học Ai.

Alice phải chia học sinh thành hai đội. Tính duy nhất của một nhóm được định nghĩa là số lượng môn học riêng biệt sao cho có ít nhất một sinh viên trong nhóm có chuyên môn về môn học đó. Ví dụ: tính duy nhất của một nhóm được biểu diễn bằng A = [1, 3, 1, 4, 4] là 3.

Alice muốn chia học sinh của lớp thành hai đội sao cho mỗi học sinh thuộc đúng một đội và điểm duy nhất của mỗi đội chính xác là K. Liệu anh ấy có làm được như vậy không?

Input :

Dòng đầu tiên chứa số nguyên T là số bộ test. Mô tả của từng trường hợp thử nghiệm như sau:
Dòng đầu tiên của mỗi test chứa hai số nguyên N và K
Dòng thứ hai của mỗi test chứa N số nguyên A1, A2, ... AN.
 
Ràng buộc:

1 <= T <= 10^5
2 <= N <= 10^5
1 <= K <= N
1 <= Ai <= N
Tổng của N trên tất cả các test case không quá 3x10^5

Output:

Đối với mỗi trường hợp thử nghiệm, in YES nếu Alice có thể tạo ra hai đội thỏa mãn các điều kiện đã cho, nếu không thì in NO.

Ví dụ:

INPUT:
2

6 2

1 4 4 6 2 1

4 2

1 1 1 1

OUTPUT:

YES

NO



- Ý TƯỞNG: ta thấy rằng 1 số xuất hiện 2 lần thì sẽ có lợi hơn là xuất hiện 1 lần vì có thể số đó ở bên nhóm này và số đó ở bên nhóm kia luôn hoặc số đó đều ở cùng 1 nhóm, và dễ biết nếu nó xuất hiện hơn 2 lần thì dù tính điểm thế nào thì cũng có thể quy về như xuất hiện 2 lần thôi.
nhiệm vụ của ta là cần tìm trong mảng những phần tử nào xuất hiện 1 lần và xuất hiện từ 2 lần trở lên bằng unordered_map.
Đương nhiên số phần tử riêng biệt trong mảng phải <= 2 * k vì nếu lớn hơn thì dù chia thành 2 nhóm cũng sẽ có 1 nhóm điểm lớn hơn k, nếu số phần tử riêng biệt mà bé hơn 2 * k thì các phần tử xuất hiện từ 2 lần trở lên sẽ vớt vác lại điểm cho bằng k.
Và tổng số phần tử ban đầu trong mảng (không phân biệt giống hay khác nhau) phải >= 2 * k vì nếu lớn hơn thì phần tử có số lần xuất hiện nhiều có thể ở chung 1 nhóm để điểm chỉ quy về 1 và giảm bớt điểm cho nhóm để bằng k, nếu bé hơn thì dù chia thế nào thì điểm 1 trong 2 nhóm cũng sẽ bé hơn k.

CODE: 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int q; cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        unordered_map<int, int> map;
        vector<int> v(n);
        for(int &x : v){
            cin >> x;
            map[x]++;
        }
        if(map.size() <= 2 * k){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(map[v[i]] > 1){
                    sum += 2;
                    map[v[i]] = 0;
                }
                else if(map[v[i]] == 1) sum++;
            }
            if(sum >= 2 * k) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
}


 
