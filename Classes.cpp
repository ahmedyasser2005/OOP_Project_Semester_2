#include <iostream>
#include <string>

using namespace std;

enum region { Africa = 1, Europe, America, Asia };
enum gender { Male = false, Female = true };
enum degree_level { Highschool = 1, Undergraduate, Postgraduate };
enum english_level { A1 = 1, A2, B1, B2, C1, C2 };
enum study_programme { ComputerScience = 1, Engineering, Business, Arts, Media };

class person {
protected:
    string real_name;
    gender p_gender;
    region p_region;
    unsigned short age;
    float gpa;
    degree_level degree_lvl;
    english_level english_lvl;
};
class account {
protected:
    string user_name;
    string user_password;
    unsigned int user_id;
};
class studyFinderAccount : public person, public account {
public:
    // Constructor
    studyFinderAccount(string un, string pw) {
        user_name = un;
        user_password = pw;
    }

    // Friend function
    friend bool basedOnProfile(studyFinderAccount&, university&);

    // Set Methods
    void setUsername(string un) { user_name = un; }
    void setPassword(string pw) { user_password = pw; }
    void setFullname(string rn) { real_name = rn; }
    void setNationality(region r) { p_region = r; }
    void setGender(gender g) { p_gender = g; }
    void setAge(unsigned short a) { age = a; }
    void setDegreeLvl(degree_level dl) { degree_lvl = dl; }
    void setEnglishLvl(english_level el) { english_lvl = el; }
    void setGPA(float g) { gpa = g; }

    // Get Methods
    string getUsername() const { return user_name; }
    string getPassword() const { return user_password; }
    string getFullname() const { return real_name; }
    region getRegion() const { return p_region; }
    gender getGender() const { return p_gender; }
    unsigned short getAge() const { return age; }
    degree_level getDegreeLvl() const { return degree_lvl; }
    english_level getEnglishLvl() const { return english_lvl; }
    float getGPA() const { return gpa; }
};
class bankAccount : public account {
private:
    double balance = 0;

public:
    // Constructor
    bankAccount(string un, string pw, unsigned int id) {
        user_name = un;
        user_password = pw;
        user_id = id;
    }

    // Main Methods
    unsigned short deposit(double amount) {
        if (amount < 5) {
            return 1;
        } else if (amount > 10000) {
            return 2;
        } else {
            balance += amount;
            return 3;
        }
    }

    unsigned short withdraw(double amount) {
        if (amount < 5) {
            return 1;
        } else if (amount > 10000) {
            return 2;
        } else {
            balance -= amount;
            return 3;
        }
    }

    bool transfer(double amount, bankAccount& account) {
        if (amount < 5) {
            cout << "|[BANK]| Transaction Failed, amount to transfer must be at least 5$\n";
            return false;
        } else if (amount > balance) {
            cout << "|[BANK]| Transaction Failed, insufficient balance.\n";
            return false;
        } else {
            balance -= amount;
            account.balance += amount;
            cout << "|[BANK]| " << amount << "$ is successfully transferred to " << account.getName() << ".\n";
            return true;
        }
    }

    void display() const {
        cout << "|[BANK]| Account Name   : " << user_name << '\n'
             << "       | Account ID     : " << user_id << '\n'
             << "       | Balance        : " << balance << "$\n\n";
    }

    // Set Methods
    void setName(string name) { user_name = name; }
    void setNumber(unsigned int num) { user_id = num; }
    void setBalance(double b) { balance = b; }
    void setPinCode(string pc) { user_password = pc; }

    // Get Methods
    string getName() const { return user_name; }
    unsigned int getNumber() const { return user_id; }
    double getBalance() const { return balance; }
    string getPinCode() const { return user_password; }
};
class university : public person {
private:
    string name;
    string desc;
    study_programme programme;
    double tuition_fees;

public:
    // Constructor
    university(string _name, region _region, string _desc, study_programme _prog,
               unsigned short _age, degree_level _degree_lvl, english_level _english_lvl,
               double _tuition_fees, float _gpa) {
        name = _name;
        p_region = _region;
        desc = _desc;
        programme = _prog;
        age = _age;
        degree_lvl = _degree_lvl;
        english_lvl = _english_lvl;
        tuition_fees = _tuition_fees;
        gpa = _gpa;
    }

    // Comparison operator
    bool operator >(const university& uni) const {
        unsigned short score1 = 0, score2 = 0;
        (english_lvl > uni.english_lvl) ? ++score1 : ++score2;
        (gpa > uni.gpa) ? ++score1 : ++score2;
        return (score1 > score2);
    }

    // Display in list
    void showInList(int i) const {
        cout << "|[" << i + 1 << "]| Uni: " << name << " | Region: " << p_region
             << " | Degree: " << degree_lvl << " | Programme: " << programme
             << " | Tuition Fees: " << tuition_fees << "$.\n" << desc << "\n\n";
    }

    // Get Methods
    double getTuitionFees() const { return tuition_fees; }
    degree_level getDegreeLvl() const { return degree_lvl; }
    english_level getEnglishLvl() const { return english_lvl; }
    float getGPA() const { return gpa; }
};

