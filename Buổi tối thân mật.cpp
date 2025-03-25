Bữa tối thân mật của các anh tài 
Vào một đêm trăng thanh gió mát, bốn anh tài Quân, CG, CN, BN rủ nhau đi uống lúa mạch để khắng khít tình anh em. Khi đôi mắt lim dim cũng chính là lúc đôi môi lên tiếng, mọi người bắt đầu chia sẻ nhau về kinh nghiệm đi dạy IT003. Quân mở đầu: 
- Tôi đố các chú, cho các chú mảng A gồm 3 phần tử [2, 3, 1], tôi hỏi các chú cần tối thiểu bao nhiêu lần hoán đổi (swap) để sắp xếp mảng A thành mảng có trật tự? 
CG trả lời: 
- 2 lần. 
CN phản bác: 
- Tôi chỉ cần 1 lần thôi, đâu mà 2 lần dữ dị chèn. 
Trong lúc CG và CN đang tranh cãi, BN đã mở laptop lên và lập trình ra được chương trình để giải bài toán trên và trả lời đáp án là 1 lần. Sau đó, mọi người tụ lại để kiểm tra chương trình của BN với những trường hợp khác nhau và xác nhận là chương trình của BN đã giải được bài toán trên. Cả bốn người đều thấy bài toán này khá thú vị và nghĩ rằng các bông hoa nhỏ ham học ở UIT sẽ rất thích thú khi giải bài toán này. Phải bạn không, cùng thử nhé! 
Cho mảng số nguyên gồm N phần tử. Tìm số lần tối thiểu hoán đổi vị trí giữa 2 phần tửsao cho mảng đã cho có trật tự.
Input: 
Dòng đầu tiên chứa số nguyên N (1 ≤ N ≤ 105) 
Dòng tiếp theo chứa N số a1, a2,..., an với (1 ≤ a ≤ 2 × 10) là các phần tửtrong mảng ban đầu. 
Output: 
Số lần tối thiểu hoán đổi vị trí giữa 2 phần tử sao cho mảng đã cho có trật tự. 
Input:
3
2 3 1
--------------------------
4 
5 20 13 2
Output:
1
-------------------------
2


- Ý Tưởng: dùng 1 biến bool để nhận biết sort tằng dần và sort giảm dần, dùng Heap_Sort hoặc Merge_Sort để tối ưu hóa độ phức tạp
QUAN TRỌNG NHẤT: dùng 1 chu trình để tính số lần tối thiểu khi sort tăng và sort giảm rồi cuối cùng lấy min của 2 đó là ra.

CODE:

#include <iostream>
#include <vector>

using namespace std;

struct Thanh_Phan {
    int value, index;
};

void heapify(vector<Thanh_Phan> &arr, int n, int i, bool Tang) {
    int largest = i;  
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && (Tang ? arr[left].value > arr[largest].value : arr[left].value < arr[largest].value))
        largest = left;
    if (right < n && (Tang ? arr[right].value > arr[largest].value : arr[right].value < arr[largest].value))
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, Tang);
    }
}

void heapSort(vector<Thanh_Phan> &arr, bool Tang) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, Tang);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, Tang);
    }
}

int countSwaps(vector<int> arr, bool Tang) {
    int n = arr.size();
    vector<Thanh_Phan> elems(n);
    for (int i = 0; i < n; i++) {
        elems[i] = {arr[i], i};
    }
    heapSort(elems, Tang);
    vector<bool> visited(n, false);
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || elems[i].index == i) continue;
        int cycle_size = 0, j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = elems[j].index;
            cycle_size++;
        }
        if (cycle_size > 1) swaps += (cycle_size - 1);
    }
    return swaps;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;
    cout << min(countSwaps(A, true), countSwaps(A, false)) << endl;
}
