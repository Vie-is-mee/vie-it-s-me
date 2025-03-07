#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Account{
    private:
    string Username, Password;
    public:
    Account(string username, string password){
        Username = username;
        Password = password;
    }
    Account(){
        Username = "";
        Password = "";
    }

    string getUsername(){
        return Username;
    }

    string getPassword(){
        return Password;
    }

    void setUsername(string username){
        Username = username;
    }

    void setPassword(string password){
        Password = password;
    }
};

struct Date{
    private:
    int Day, Month, Year;
    public:
    Date(int day, int month, int year){
        Day = day;
        Month = month;
        Year = year;
    }
    Date(){
        Day = 0;
        Month = 0;
        Year = 0;
    }

    int getDay(){
        return Day;
    }

    int getMonth(){
        return Month;
    }

    int getYear(){
        return Year;
    }

    void setDay(int day){
        Day = day;
    }

    void setMonth(int month){
        Month = month;
    }

    void setYear(int year){
        Year = year;
    }
};

struct Person{
    private:
    string Name, Address;
    int Age;
    Date DateOfBirth;
    public:
    Person(string name, string address, int age, Date birthday){
        Name = name;
        Address = address;
        Age = age;
        DateOfBirth = birthday;
    }
    Person(){
        Name = "";
        Address = "";
        Age = 0;
        DateOfBirth = Date();
    }

    string getName(){
        return Name;
    }

    string getAddress(){
        return Address;
    }

    int getAge(){
        return Age;
    }

    Date getBirthDay(){
        return DateOfBirth;
    }

    void inthongtin(){
        cout << Name << ' ' << Address << ' ' << Age << ' ' << DateOfBirth.getDay() << "/" << DateOfBirth.getMonth() << "/" << DateOfBirth.getYear() << endl;
    }
};

struct Student: public Person{
    private:
    string ID, Email, EmailPassword, Class;
    double gpa;
    Account Acc;
    public:
    Student(){
        ID = "";
        Class = "";
        gpa = 0;
    }

    Student(string name, string address, int age, Date birthday, string id, string className, double _gpa) : Person(name, address, age, birthday){
        ID = id;
        Class = className;
        gpa = _gpa;
    }

    void setEmail(){
        string ans = "";
        string temp = Person::getName();
        vector<string> v;
        stringstream ss(temp);
        string token;
        while(ss >> token){
            v.push_back(token);
        }
        for(char x : v.back()) ans += tolower(x);
        for(int i = 0; i < v.size() - 1; i++){
            ans += tolower(v[i][0]);
        }
        ans += "@gm.uit.edu.vn";
        Email = ans;
    }

    void setEmailPassword(){
        string ans = "";
        string temp = Person::getName();
        for(char x : temp){
            if(x != ' '){
                ans += tolower(x);
            }
        }
        for(char x : ID){
            ans += tolower(x);
        }
        EmailPassword = ans;
    }

    void setAccount(){
        string user = "";
        string pass = "";
        string temp = Person::getName();
        for(char x : temp){
            if(x != ' '){
                user += tolower(x);
            }
        }
        Date date = Person::getBirthDay();
        user += to_string(date.getDay());
        user += to_string(date.getMonth());
        user += to_string(date.getYear());
        Acc.setUsername(user);
        Acc.setPassword(pass);
    }

    void inthongtin(){
        Person::inthongtin();
        cout << ID <<  ' ' << Class << ' ' << fixed << setprecision(1) << gpa << ' ' << Email << ' ' << EmailPassword << endl;
        cout << Acc.getUsername() << ' ' << Acc.getPassword() << endl;
    }
};

int main() {
    Date date(22, 5, 2007);
    Student a("NguyenVanNam", "HaNoi", 17, date, "24521989", "HSK16", 4.0);
    a.setEmail();
    a.setEmailPassword();
    a.setAccount();
    a.inthongtin();
} 

