#include <bits/stdc++.h>
using namespace std;

bool check_specialletter(char x) {
    return string("!@#$%^&*_?~").find(x) != string::npos;
}

bool check_letter(char x) {
    return (x >= 'a' && x <= 'z');
}

bool check_number(char x) {
    return (x >= '0' && x <= '9');
}

bool check_upper(char x) {
    return (x >= 'A' && x <= 'Z');
}

bool check_all(string s) {
    return all_of(s.begin(), s.end(), check_letter);
}

bool check_all_number(string s) {
    return all_of(s.begin(), s.end(), check_number);
}

int count_upper(string s) {
    return count_if(s.begin(), s.end(), check_upper);
}

int count_number(string s) {
    return count_if(s.begin(), s.end(), check_number);
}

int count_special(string s) {
    return count_if(s.begin(), s.end(), check_specialletter);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string s; 
    cin >> s;
    int l = s.length();

    if (l < 8 || s.find(',') != string::npos || s.find('.') != string::npos || 
        s.find('/') != string::npos || s.find('\\') != string::npos || 
        s.find('\'') != string::npos || s.find('"') != string::npos) {
        cout << "KhongHopLe";
        return 0;
    }

    int BaseScore = 40, Bonus_Excess = 3, Bonus_Upper = 4, Bonus_Numbers = 5, Bonus_Symbols = 5;
    
    int Number_Execess = l - 8;
    int Number_Upper = count_upper(s);
    int Number_Numbers = count_number(s);
    int Number_Symbols = count_special(s);
    
    int Bonus_FlatLower = check_all(s) ? -15 : 0;
    int Bonus_FlatNumber = check_all_number(s) ? -35 : 0;

    int Bonus_Combo;
    if (Number_Upper > 0 && Number_Numbers > 0 && Number_Symbols > 0) 
    Bonus_Combo = 25;
    else if ((Number_Upper > 0 && Number_Numbers > 0) || 
            (Number_Numbers > 0 && Number_Symbols > 0) || 
            (Number_Symbols > 0 && Number_Upper > 0)) 
        Bonus_Combo = 15;
    else 
        Bonus_Combo = 0;

    int score = BaseScore + (Number_Execess * Bonus_Excess) + (Number_Upper * Bonus_Upper) 
                + (Number_Numbers * Bonus_Numbers) + (Number_Symbols * Bonus_Symbols) 
                + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;

    if (score < 50) cout << "Yeu";
    else if (score < 75 && score >= 50) cout << "Vua";
    else if (score < 100 && score >= 75) cout << "Manh";
    else cout << "RatManh";
}
