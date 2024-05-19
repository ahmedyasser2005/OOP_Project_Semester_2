#include <iostream>
using namespace std;

class information{
protected:
    string account_name, 
};

class bank_account{
private:
    
    string accountName, pinCode;
    unsigned int accountNumber;
    double balance = 0;

public:
    
    // Constructors
    bank_account(string name, string pin, unsigned int num): accountName(name), pinCode(pin), accountNumber(num) {}

    // Main Methods
    unsigned short deposit(double amount){
        if (amount < 5)
        
            return 1;
        
        else if (amount > 10000)

            return 2;
        
        else{
        
            balance += amount;
            return 3;

        }
    }
    unsigned short withdraw(double amount){
        if (amount < 5)
        
            return 1;
        
        else if (amount > 10000)

            return 2;
        
        else{
        
            balance -= amount;
            return 3;
            
        }
    }
    bool transfer(double amount, bank_account& account){
        if (amount < 5){
            cout << "|[BANK]| Transaction Failed, amount to transfer must be at least 5$\n";
            return false;
        }else if (amount > balance){
            cout << "|[BANK]| Transaction Failed, insufficient balance.\n";
            return false;
        }else{
            balance -= amount;
            account.balance += amount;
            cout << "|[BANK]| " << amount << "$ is successfully transferred to " << account.accountName << ".\n";
            return true;
        }
    }
    void display() const {
        cout << "|[BANK]| Account Name   : " << accountName << '\n'
             << "       | Account Number : " << accountNumber << '\n'
             << "       | Balance        : " << balance << "$\n\n";
    }

    // Set Methods
    void setName(string name)        { accountName = name;  }
    void setNumber(unsigned int num) { accountNumber = num; }
    void setBalance(double b)        { balance = b;         }
    void setPinCode(string pc)       { pinCode = pc;        }

    // Get Methods
    string getName()         const { return accountName;   }
    unsigned int getNumber() const { return accountNumber; }
    double getBalance()      const { return balance;       }
    string getPinCode()      const { return pinCode;       }

};
class user_account{
private:

    string username, email, password; // Account Security Settings
    string fullname, nationality, phone_number; // Student Profile
    bool gender; // Male(1), Female(0)
    unsigned short age;
    unsigned short degree_lvl; // Highschool(1), Undergraduate(2), Postgraduate(3)
    unsigned short english_lvl; // A1(1), A2(2), B1(3), B2(4), C1(5), C2(6)
    float gpa; // Out of 4 grading system

public:

    // Constructors
    user_account(string un, string em, string pw): username(un), email(em), password(pw) {}

    // Operator Overloading
    bool operator >(user_account student) const { // Compare student profiles
        unsigned int score1 = 0, score2 = 0;
        (english_lvl > student.english_lvl && english_lvl != student.english_lvl) ? ++score1 : ++score2;
        (gpa > student.gpa && gpa != student.gpa) ? ++score1 : ++score2;

        return (score1 > score2) ? true : false;
    }

    friend bool basedOnProfile(user_account&, university&);

    // Set Methods
    void setUsername(string un) { username = un; }
    void setEmail(string em)    { email = em;    }
    void setPassword(string pw) { password = pw; }

    void setFullname(string fn)             { fullname = fn;       }
    void setNationality(string nat)         { nationality = nat;   }
    void setPhoneNumber(string pn)          { phone_number = pn;   }
    void setGender(bool g)                  { gender = g;          }
    void setAge(unsigned short a)           { age = a;             }
    void setDegreeLvl(unsigned short dl)    { degree_lvl = dl;     }
    void setEnglishLvl(unsigned short el)   { english_lvl = el;    }
    void setGPA(float g)                    { gpa = g;             }

    // Get Methods
    string getUsername() const { return username; }
    string getEmail()    const { return email;    }
    string getPassword() const { return password; }

    string getFullname()           const { return fullname;      }
    string getNationality()        const { return nationality;   }
    string getPhoneNumber()        const { return phone_number;  }
    bool getGender()               const { return gender;        }
    unsigned short getAge()        const { return age;           }
    unsigned short getDegreeLvl()  const { return degree_lvl;    }
    unsigned short getEnglishLvl() const { return english_lvl;   }
    float getGPA()                 const { return gpa;           }

};
class university{
private:

    string name, country, desc, contact;
    unsigned short age;
    unsigned short programme; // Computer Science(1), Medicine(2), Business(3), Arts & Design(4), Media(5)
    unsigned short degree_lvl; // Highschool(1), Undergraduate(2), Postgraduate(3)
    unsigned short english_lvl; // A1(1), A2(2), B1(3), B2(4), C1(5), C2(6)
    unsigned int ranking; // Based on QS ranking system
    double tution_fees;
    float gpa; // Out of 4 grading system
    float duration; // In years
    bank_account bank = {name, "000", ranking};

public:

    university(string _name, string _country, string _desc, string _contact, unsigned short _prog,
        unsigned short _age, unsigned short _degree_lvl, unsigned short _english_lvl,
        double _tution_fees, float _gpa, float _duration, int _ranking):
            name(_name), country(_country), desc(_desc), contact(_contact), programme(_prog), age(_age),
            degree_lvl(_degree_lvl), english_lvl(_english_lvl), tution_fees(_tution_fees),
            gpa(_gpa), duration(_duration), ranking(_ranking) {}

    bool operator >(const university& uni) const { // Compare universities
        
        unsigned short score1 = 0, score2 = 0; // Score of acceptance difficulty

        (english_lvl > uni.english_lvl && english_lvl != uni.english_lvl) ? ++score1 : ++score2;
        (gpa > uni.gpa && gpa != uni.gpa) ? ++score1 : ++score2;

        return (score1 > score2) ? true : false;
    }

    void showInList(int i) const {
        cout << "|[" << i+1 << "]| Uni: " << name << " | Country: " << country << " | Degree: " << degree_lvl << " | Programme: " << programme << " | Tuition Fees: " << tution_fees << "$.\n"
             << desc << "\n\n";
    }

    friend bool basedOnProfile(user_account&, university&);

    double getTuitionFees()         const { return tution_fees; }
    unsigned int getRanking()       const { return ranking;     }
    unsigned short getDegreeLvl()   const { return degree_lvl;  }
    unsigned short getEnglishLvl()  const { return english_lvl; }
    float getGPA()                  const { return gpa;         }

};