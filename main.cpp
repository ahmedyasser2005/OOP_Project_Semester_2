#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Pre-Definitions
class user_account;
class university;
bool basedOnProfile(user_account&, university&);
// Classes ========================================================
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

bool basedOnProfile(user_account& student, university& uni){
    if (student.getGPA() >= uni.getGPA()
    && student.getEnglishLvl() >= uni.getEnglishLvl()
    && student.getDegreeLvl() == uni.getDegreeLvl())
        return true;
    else
        return false;
}

// Global Variables ========================================================
inline unsigned short choose(unsigned short from,unsigned short to){
    unsigned short choice;
    while(true){
        cout << "|[USER-INPUT]| Select an option: ";
        cin >> choice;
        if (choice >= from && choice <= to){
            break;
        }else{
            cout << "|[CONSOLE]| Invalid Input, try Again...\n";
        }
    }
    return choice;
}

const university uni1("Oxford University", "The UK", "The University of Oxford is a collegiate research university in Oxford, England. There is evidence of teaching as early as 1096, making it the oldest university in the English-speaking world and the world's second-oldest university in continuous operation.", "617-495-1000.", 1, 18, 2, 5, 50000, 3.9, 4, 1);
const university uni2("Harvard University", "The US", "Established in 1636, Harvard is the oldest higher education institution in the United States, and is widely regarded in terms of its influence, reputation, and academic pedigree as a leading university in not just the US but also the world.", "617-495-1000.", 1, 18, 2, 4, 40000, 3.7, 4, 2);
const university uni3("Cambridge University", "The UK", "The University of Cambridge is one of the world's oldest universities and leading academic centres, and a self-governed community of scholars. Established in 1209, the University is rich in history.", "617-495-1000.", 1, 18, 2, 4, 30000, 3.8, 4, 3);

bool compareUniverisitiesByAcceptance(const university& un1, const university& uni2){
    return !(uni1 > uni2);
}
bool compareUniverisitiesByTuitionFees(const university& un1, const university& uni2){
    return uni1.getTuitionFees() > uni2.getTuitionFees();
}
bool compareUniverisitiesByRanking(const university& un1, const university& uni2){
    return uni1.getRanking() < uni2.getRanking();
}

// Data System Here (Mahrous Task)
vector<bank_account> bank_accounts_data;

vector<user_account> user_accounts_data;

vector<university> universities_data = {uni1, uni2, uni3};


// Display Functions ========================================================
inline void startDisplay(){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    OOP Project    |=-=-=-=-=|\n\n"
         << "|[1]| Open StudyFinder.\n"
         << "|[2]| Open BankingSystem.\n"
         << "|[0]| Exit.\n\n";
}



inline void bankHomeDisplay(){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    BankingSystem    |=-=-=-=-=|\n\n"
         << "|[1]| Login into your bank account.\n"
         << "|[2]| Create a new bank account.\n"
         << "|[0]| Back.\n\n";
}
inline void bankLoginDisplay(unsigned int accountNumber, string pinCode, unsigned short msg){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    BankingSystem    |=-=-=-=-=|\n\n"
         << "|[1]| " << (accountNumber ? to_string(accountNumber) : "*** Account Number...") << "\n"
         << "|[2]| " << pinCode << "\n"
         << "|[3]| Login.\n"
         << "|[0]| Back.\n\n" <<
        ( // msg [0] for no errors, [1] for wrong PIN Code, [2] for account does NOT exist
            (msg == 1) ? "|[BANK]| Wrong PIN code!, Try again...\n\n" :
            (msg == 2) ? "|[BANK]| Account does NOT exist, Try again...\n\n" : ""
        );
}
inline void bankRegisterDisplay(string accountName, string pinCode, unsigned short msg, unsigned int accountNumber){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    BankingSystem    |=-=-=-=-=|\n\n"
         << "|[1]| " << accountName << "\n"
         << "|[2]| " << pinCode << "\n"
         << "|[3]| Create a new account.\n"
         << "|[0]| Back.\n\n" <<
        ( // msg [0] for no errors, [1] for already exist, [2] for created a new bank account
            (msg == 1) ? "|[BANK]| This account is already exist, try different name.\n\n" :
            (msg == 2) ? "|[BANK]| You've created a new bank account with account number '" + to_string(accountNumber) + "', DO NOT forget it!\n\n" : ""
        );
}
inline void bankMainMenuDisplay(string accountName, double balance){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    BankingSystem    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    " << accountName << " | " << balance << "$    |=-=-=-=-=|\n\n"
         << "|[1]| Deposit.\n"
         << "|[2]| Withdraw.\n"
         << "|[3]| Transfer.\n"
         << "|[4]| Display Account Info.\n"
         << "|[5]| Change PIN Code.\n"
         << "|[0]| Sign Out.\n\n";
}
inline void bankDepositWithdrawDisplay(string accountName, double balance, string amount, bool type, unsigned short msg){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    BankingSystem    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    " << accountName << " | " << balance << "$    |=-=-=-=-=|\n\n"
         << "|[1]| " << amount << "\n"
         << "|[2]| " << (type ? "Deposit.\n" : "Withdraw.\n")
         << "|[0]| Cancel Transaction.\n\n" <<
        ( type ?
            ((msg == 1) ? "|[BANK]| Transaction Failed, amount to deposit must be at least 5$.\n\n"      :
             (msg == 2) ? "|[BANK]| Transaction Failed, amount to deposit must NOT exceed 10,000$.\n\n"  :
             (msg == 3) ? "|[BANK]| " + amount + "$ is successfully deposited into your account.\n\n"   : "")
        :
            ((msg == 1) ? "|[BANK]| Transaction Failed, amount to withdraw must be at least 5$.\n\n"     :
             (msg == 2) ? "|[BANK]| Transaction Failed, amount to withdraw must NOT exceed 10,000$.\n\n" :
             (msg == 3) ? "|[BANK]| " + amount + "$ is successfully withdrawn from your account.\n\n"   : "")
        );
}
inline void bankChangePINDisplay(string accountName, double balance, string c_pin, string n_pin, unsigned short msg){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    BankingSystem    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    " << accountName << " | " << balance << "$    |=-=-=-=-=|\n\n"
         << "|[1]| " << c_pin << "\n" // "*** Current PIN Code..."
         << "|[2]| " << n_pin << "\n" // "*** New PIN Code..."
         << "|[3]| Confirm.\n"
         << "|[0]| Back.\n\n" <<
        ( // msg [0] for no errors, [1] for Wrong PIN code, [2] for Successfully changed
            (msg == 1) ? "|[BANK]| Wrong PIN code...\n\n" :
            (msg == 2) ? "|[BANK]| Successfully changed your PIN code.\n\n" : ""
        );
}



inline void studyFinderHomeDisplay(){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n\n"
         << "|[1]| Login.\n"
         << "|[2]| Create a new account.\n"
         << "|[0]| Back.\n\n";
}
inline void studyFinderLoginDisplay(string username_or_email, string password, unsigned short msg){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n\n"
         << "|[1]| " << username_or_email << "\n"
         << "|[2]| " << password << "\n"
         << "|[3]| Login.\n"
         << "|[0]| Back.\n\n" <<
        ( // msg [0] for no errors, [1] for Wrong Password, [2] for account does NOT exist
            (msg == 1) ? "|[STUDY-FINDER]| Wrong Password!, Try again...\n\n" :
            (msg == 2) ? "|[STUDY-FINDER]| Account does NOT exist, Try again...\n\n" : ""
        );
}
inline void studyFinderRegisterDisplay(string username, string email, string password, unsigned short msg){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n\n"
         << "|[1]| " << username << "\n"
         << "|[2]| " << email << "\n"
         << "|[3]| " << password << "\n"
         << "|[4]| Create a new account.\n"
         << "|[0]| Back.\n\n" <<
        ( // msg [0] for no errors, [1] for Wrong Password, [2] for account does NOT exist
            (msg == 1) ? "|[STUDY-FINDER]| This account is already exist, try different username/email.\n\n" :
            (msg == 2) ? "|[STUDY-FINDER]| Account created successfully.\n\n" : ""
        );
}
inline void studyFinderMainMenuDisplay(string username){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    Hi, " << username << "    |=-=-=-=-=|\n\n"
         << "|[1]| Open Search Engine.\n"
         << "|[2]| Display Accepted Applications.\n"
         << "|[3]| Display Pending Applications.\n"
         << "|[4]| Display Rejected Applications.\n"
         << "|[5]| Student Profile Settings.\n"
         << "|[6]| Account Security Settings.\n"
         << "|[0]| Sign Out.\n\n";
}

inline void studyFinderSearchEngineDisplay(string username){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    Hi, " << username << "    |=-=-=-=-=|\n\n"
         << "=======================| Search Engine |=======================\n"
         << "|| |[1]| Custom Search.\n"
         << "|| |[2]| Search based on profile.\n"
         << "|| |[3]| Show all options...\n"
         << "|| |[0]| Back.\n"
         << "==================================================================\n\n";
}
inline void studyFinderProfileSearchDisplay(string username){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    Hi, " << username << "    |=-=-=-=-=|\n\n"
         << "=======================| Search based on Profile |=======================\n"
         << "|| |[1]| Country         :\n"
         << "|| |[2]| Study Programme :\n"
         << "|| |[3]| Tuition Fees    :\n"
         << "|| |[4]| Search...\n"
         << "|| |[0]| Back.\n"
         << "==================================================================\n\n";
}
inline void studyFinderCustomisedSearchDisplay(string username, string country, string deg_lvl, string stu_prog, string gpa, string eng_lvl, string tuition){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    Hi, " << username << "    |=-=-=-=-=|\n\n"
         << "=======================| Custom Search |=======================\n"
         << "|| |[1]| Country         :" << "         " << country << '\n'
         << "|| |[2]| Degree Level    :" << "         " << deg_lvl << '\n'
         << "|| |[3]| Study Programme :" << "         " << stu_prog << '\n'
         << "|| |[4]| GPA             :" << "         " << gpa << '\n'
         << "|| |[5]| English Level   :" << "         " << eng_lvl << '\n'
         << "|| |[6]| Tuition Fees    :" << "         " << tuition << '\n'
         << "|| |[7]| Search...\n"
         << "|| |[0]| Back.\n"
         << "==================================================================\n\n";
}
inline void studyFinderShowAllOptionsDisplay(string username){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    Hi, " << username << "    |=-=-=-=-=|\n\n"
         << "=======================|  Show All |=======================\n"
         << "|| |[1]| Sort from higher to lower tuition fees...\n"
         << "|| |[2]| Sort from lower to higher tuition fees...\n"
         << "|| |[3]| Sort from higher to lower ranking...\n"
         << "|| |[4]| Sort from lower to higher ranking...\n"
         << "|| |[5]| Sort from higher to lower acceptance chance...\n"
         << "|| |[6]| Sort from lower to higher acceptance chance...\n"
         << "|| |[0]| Back.\n"
         << "==================================================================\n\n";
}

inline void studentProfileSettingsDisplay(string username, string fullname, string nationality, string phone_number, bool gender, unsigned short age, unsigned short degree_lvl, unsigned short english_lvl, float gpa){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n"
         << "|=-=-=-=-=|    Hi, " << username << "    |=-=-=-=-=|\n\n"
         << "|=-=-=-=-=| \"*\" means field required |=-=-=-=-=|\n"
         << "|[1]| Set Fullname: " << fullname << '\n'
         << "|[2]| Set Gender: " << (gender ? "Female" : "Male") << " |--- Male(0), Female(1).\n"
         << "|[3]| Set Age: " << age << '\n'
         << "|[4]| Set Nationality: " << nationality << '\n'
         << "|[5]| Set Phone Number: " << phone_number << '\n'
         << "|[6]| Set Degree Level*: " << degree_lvl << " |--- Highschool(1), Undergraduate(2), Postgraduate(3).\n"
         << "|[7]| Set GPA*: " << gpa << " |--- Out of 4.\n"
         << "|[8]| Set English Level*: " << english_lvl << " |--- A1(1), A2(2), B1(3), B2(4), C1(5), C2(6).\n"
         << "|[0]| Back.\n";
}
inline void accountSecuritySettingsDisplay(string username, string email, unsigned short msg){
    cout << "\033[2J\033[1;1H";
    cout << "|=-=-=-=-=|    StudyFinder    |=-=-=-=-=|\n\n"
         << "|[1]| Username: " << username << '\n'
         << "|[2]| Email: " << email << '\n'
         << "|[3]| Change password...\n"
         << "|[0]| Back.\n\n" <<
        ( // msg [0] for no errors, [1] for Wrong Password, [2] for Successfully changed
            (msg == 1) ? "|[STUDY-FINDER]| Wrong Password...\n\n" :
            (msg == 2) ? "|[STUDY-FINDER]| Successfully changed your Password.\n\n" : ""
        );
}

// Main Functions Definitions ========================================================
void bankLogin(unsigned int, string, unsigned short);
void bankRegister(string, string, unsigned short, unsigned int);
void bank();
void bankMainMenu(bank_account&, bool);
void bankDeposit(bank_account&, string, double, unsigned short);
void bankWithdraw(bank_account&, string, double, unsigned short);



void studyFinderLogin(string, string, unsigned short);
void studyFinderRegister(string, string, string, unsigned short);
void studentProfileSettings(user_account&);
void accountSecuritySettings(user_account&, unsigned short);
void studyFinderSearchEngine(user_account&);
void studyFinderCustomSearch(user_account&, string, string, string, string, string, string);
void studyFinderShowAllOptions(user_account&);
void studyFinder();
void studyFinderMainMenu(user_account&);


void start();



// Starting Point
int main(){
    start();
    return 0;
}



// Main Functions ========================================================
void bankLogin(unsigned int accountNumber = 0, string pinCode = "*** PIN Code...", unsigned short msg = 0){
    
    bankLoginDisplay(accountNumber, pinCode, msg);

    switch(choose(0, 3)){
        case 1:
            cout << "|[USER-INPUT]| Enter your account number: ";
            cin >> accountNumber;
            bankLogin(accountNumber, pinCode, 0);
            break;
        case 2:
            cout << "|[USER-INPUT]| Enter your PIN code: ";
            cin >> pinCode;
            bankLogin(accountNumber, pinCode, 0);
            break;
        case 3:
            {

                // Mahrous Task Here ***
                // Make your code here to search for the desired data

                // For now I will use vectors as database so I can test the project --Ahmed Yasser Eissa
                for (int i = 0; i < bank_accounts_data.size(); ++i){
                    if (accountNumber == bank_accounts_data[i].getNumber()){
                        if (pinCode == bank_accounts_data[i].getPinCode()){
                            
                            // SUCCESSFULLY LOGGED IN

                            bankMainMenu(bank_accounts_data[i], false);
                            return;

                        }else{

                            // Wrong PIN Code

                            bankLogin(accountNumber, pinCode, 1);
                            return;
                        }
                    }
                }

                // Account does NOT exist

                bankLogin(accountNumber, pinCode, 2);

            }
            break;
        case 0: bank(); return;
    }

}
void bankRegister(string accountName = "*** Account Name...", string pinCode = "*** PIN Code...", unsigned short msg = 0, unsigned int accountNumber = 0){

    bankRegisterDisplay(accountName, pinCode, msg, accountNumber);

    switch(choose(0, 3)){
        case 1:
            cout << "|[USER-INPUT]| Create your account name: ";
            cin >> accountName;
            bankRegister(accountName, pinCode, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Create your PIN code: ";
            cin >> pinCode;
            bankRegister(accountName, pinCode, msg);
            break;
        case 3:
            {

                // Mahrous Task Here ***
                // Make your code here to save the new data 

                // For now I will use vectors as database so I can test the project --Ahmed Yasser Eissa
                for (int i = 0; i < bank_accounts_data.size(); ++i){
                    if (accountName == bank_accounts_data[i].getName()){
                        
                        // Found an existed account with same account name

                        bankRegister(accountName, pinCode, 1);
                        return;
                    }
                }
                
                // Creating a new account

                bank_account newBankAccount(accountName, pinCode, (bank_accounts_data.size() ? bank_accounts_data.back().getNumber() + 100 : 100100));
                bank_accounts_data.emplace_back(newBankAccount);
                bankRegister("*** Account Name...", "*** PIN Code...", 2, newBankAccount.getNumber());

            }
            break;
        case 0: bank(); return;
    }

}
void bankDeposit(bank_account& account, string amount = "*** Amount to deposit...", double cash = 0, unsigned short msg = 0){

    bankDepositWithdrawDisplay(account.getName(), account.getBalance(), amount, true, msg);

    switch(choose(0, 2)){
        case 1:
            cout << "|[USER-INPUT]| Enter amount to deposit: ";
            cin >> cash;
            amount = to_string(cash) + '$';
            bankDeposit(account, amount, cash);
            break;
        case 2:
            bankDeposit(account, amount, cash, account.deposit(cash));
            break;
        case 0: bankMainMenu(account, false); return;
    }

}
void bankWithdraw(bank_account& account, string amount = "*** Amount to withdraw...", double cash = 0, unsigned short msg = 0){

    bankDepositWithdrawDisplay(account.getName(), account.getBalance(), amount, false, msg);

    switch(choose(0, 2)){
        case 1:
            cout << "|[USER-INPUT]| Enter amount to withdraw: ";
            cin >> cash;
            amount = to_string(cash) + '$';
            bankWithdraw(account, amount, cash);
            break;
        case 2:
            bankWithdraw(account, amount, cash, account.withdraw(cash));
            break;
        case 0: bankMainMenu(account, false); return;
    }

}
void bankChangePIN(bank_account& account, string c_pin = "*** Current PIN Code...", string n_pin = "*** New PIN Code...", unsigned short msg = 0){
    
    bankChangePINDisplay(account.getName(), account.getBalance(), c_pin, n_pin, msg);

    switch(choose(0, 3)){
        case 1:
            cout << "|[USER-INPUT]| Enter your current PIN code: ";
            cin >> c_pin;
            bankChangePIN(account, c_pin, n_pin, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Enter your new PIN code: ";
            cin >> n_pin;
            bankChangePIN(account, c_pin, n_pin, msg);
            break;
        case 3:
            if (c_pin != account.getPinCode()){
                bankChangePIN(account, c_pin, n_pin, 1);
            }else{
                account.setPinCode(n_pin);
                bankChangePIN(account, c_pin, n_pin, 2);
            }
            break;
        case 0: bankMainMenu(account, false); return;
    }

}
void bank(){
    bankHomeDisplay();
    switch(choose(0, 2)){
        case 1: bankLogin(); break;
        case 2: bankRegister(); break;
        case 0: start(); return;
    }
}
void bankMainMenu(bank_account& account, bool showInfo = false){

    bankMainMenuDisplay(account.getName(), account.getBalance());

    if (showInfo) account.display();

    switch(choose(0, 5)){
        case 1: bankDeposit(account); break;
        case 2: bankWithdraw(account); break;
        case 3: bankMainMenu(account); break;
        case 4: bankMainMenu(account, true); break;
        case 5: bankChangePIN(account); break;
        case 0: bank(); return;
    }

}

void studyFinderLogin(string username_or_email = "*** Username/Email...", string password = "*** Password...", unsigned short msg = 0){

    studyFinderLoginDisplay(username_or_email, password, msg);    

    switch(choose(0, 3)){
        case 1:
            cout << "|[USER-INPUT]| Enter your username: ";
            cin >> username_or_email;
            studyFinderLogin(username_or_email, password, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Enter your password: ";
            cin >> password;
            studyFinderLogin(username_or_email, password, msg);
            break;
        case 3:
            {

                // Mahrous Task Here ***
                // Make your code here to search for the desired data

                // For now I will use vectors as database so I can test the project --Ahmed Yasser Eissa
                for (int i = 0; i < user_accounts_data.size(); ++i){
                    if (username_or_email == user_accounts_data[i].getUsername() || username_or_email == user_accounts_data[i].getEmail()){
                        if (password == user_accounts_data[i].getPassword()){

                            // Successfully logged in

                            studyFinderMainMenu(user_accounts_data[i]);
                            return;

                        }else{

                            // Password doesn't match the account

                            studyFinderLogin(username_or_email, password, 1);
                            return;

                        }
                    }
                }

                // Username/Email doesn't match any account

                studyFinderLogin(username_or_email, password, 2);

            }
            break;
        case 0: studyFinder(); return;
    }

}
void studyFinderRegister(string username = "*** Username...", string email = "*** Email...", string password = "*** Password...", unsigned short msg = 0){

    studyFinderRegisterDisplay(username, email, password, msg);

    switch(choose(0, 4)){
        case 1:
            cout << "|[USER-INPUT]| Create your username: ";
            cin >> username;
            studyFinderRegister(username, email, password, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Enter your email: ";
            cin >> email;
            studyFinderRegister(username, email, password, msg);
            break;
        case 3:
            cout << "|[USER-INPUT]| Create your password: ";
            cin >> password;
            studyFinderRegister(username, email, password, msg);
            break;
        case 4:
            {

                // Mahrous Task Here ***
                // Make your code here to save the new data 

                // For now I will use vectors as database so I can test the project --Ahmed Yasser Eissa
                for (int i = 0; i < user_accounts_data.size(); ++i){
                    if (username == user_accounts_data[i].getUsername() || email == user_accounts_data[i].getEmail()){
                        
                        // Found an existed account with same username/email

                        studyFinderRegister(username, email, password, 1);
                        return;
                    }
                }
                
                // Creating a new account

                user_account newUserAccount(username, email, password);
                user_accounts_data.emplace_back(newUserAccount);
                studyFinderRegister(username, email, password, 2);

            }
            break;
        case 0: studyFinder(); return;
    }

}
void studentProfileSettings(user_account& account){

    studentProfileSettingsDisplay(account.getUsername(), account.getFullname(), account.getNationality(), account.getPhoneNumber(), account.getGender(), account.getAge(), account.getDegreeLvl(), account.getEnglishLvl(), account.getGPA());

    switch(choose(0, 8)){
        case 1:
            {
                string input;
                cout << "|[USER-INPUT]| Enter your Fullname: ";
                cin >> input;
                account.setFullname(input);
                studentProfileSettings(account);
            }
            break;
        case 2:
            {
                bool input;
                cout << "|[USER-INPUT]| Enter your Gender: ";
                cin >> input;
                account.setGender(input);
                studentProfileSettings(account);
            }
            break;
        case 3:
            {
                unsigned short input;
                cout << "|[USER-INPUT]| Enter your Age: ";
                cin >> input;
                account.setAge(input);
                studentProfileSettings(account);
            }
            break;
        case 4:
            {
                string input;
                cout << "|[USER-INPUT]| Enter your Nationality: ";
                cin >> input;
                account.setNationality(input);
                studentProfileSettings(account);
            }
            break;
        case 5:
            {
                string input;
                cout << "|[USER-INPUT]| Enter your Phone Number: ";
                cin >> input;
                account.setPhoneNumber(input);
                studentProfileSettings(account);
            }
            break;
        case 6:
            {
                unsigned short input;
                cout << "|[USER-INPUT]| Enter your recent finished degree level: ";
                cin >> input;
                account.setDegreeLvl(input);
                studentProfileSettings(account);
            }
            break;
        case 7:
            {
                float input;
                cout << "|[USER-INPUT]| Enter your GPA: ";
                cin >> input;
                account.setGPA(input);
                studentProfileSettings(account);
            }
            break;
        case 8:
            {
                unsigned short input;
                cout << "|[USER-INPUT]| Enter your English level: ";
                cin >> input;
                account.setEnglishLvl(input);
                studentProfileSettings(account);
            }
            break;
        case 0: studyFinderMainMenu(account); return;
    }
}
void accountSecuritySettings(user_account& account, unsigned short msg = 0){

    accountSecuritySettingsDisplay(account.getUsername(), account.getEmail(), msg);

    switch(choose(0, 3)){
        case 1:
            {
                string input;
                cout << "|[USER-INPUT]| Enter your new username: ";
                cin >> input;
                account.setUsername(input);
                accountSecuritySettings(account);
            }
            break;
        case 2:
            {
                string input;
                cout << "|[USER-INPUT]| Enter your new Email: ";
                cin >> input;
                account.setEmail(input);
                accountSecuritySettings(account);
            }
            break;
        case 3:
            {
                string input;
                cout << "|[USER-INPUT]| Enter your current Password: ";
                cin >> input;
                if (input == account.getPassword()){
                    cout << "|[USER-INPUT]| Enter your new Password: ";
                    cin >> input;
                    account.setPassword(input);
                    accountSecuritySettings(account, 2);
                }else{
                    accountSecuritySettings(account, 1);
                }
            }
            break;
        case 0: studyFinderMainMenu(account); return;
    }
}


void studyFinderCustomSearch(user_account& account, string country = "___", string deg_lvl = "___", string stu_prog = "___", string gpa = "___", string eng_lvl = "___", string tuition = "___"){

    studyFinderCustomisedSearchDisplay(account.getUsername(), country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);

    switch(choose(0, 7)){
        case 1:
            {
                cout << "|[USER-INPUT]| Enter your desired country name: ";
                cin >> country;
                studyFinderCustomSearch(account, country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);
            }
            break;
        case 2:
            {
                cout << "|[USER-INPUT]| Enter your desired degree level: ";
                cin >> deg_lvl;
                studyFinderCustomSearch(account, country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);
            }
            break;
        case 3: 
            {
                cout << "|[USER-INPUT]| Enter your desired study programme: ";
                cin >> stu_prog;
                studyFinderCustomSearch(account, country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);
            }
            break;
        case 4: 
            {
                cout << "|[USER-INPUT]| Enter minimum GPA: ";
                cin >> gpa;
                studyFinderCustomSearch(account, country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);
            }
            break;
        case 5: 
            {
                cout << "|[USER-INPUT]| Enter minimum English level: ";
                cin >> eng_lvl;
                studyFinderCustomSearch(account, country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);
            }
            break;
        case 6: 
            {
                cout << "|[USER-INPUT]| Enter maximum tuition fees: ";
                cin >> tuition;
                studyFinderCustomSearch(account, country, deg_lvl, stu_prog, gpa, eng_lvl, tuition);
            }
            break;
        case 0: studyFinderSearchEngine(account); return;
    }

}
void studyFinderSearchBasedOnProfile(user_account& account){

    for (int i = 0; i < universities_data.size(); ++i){
    
        if (basedOnProfile(account, universities_data[i])){
    
            universities_data[i].showInList(i);
    
        }
    }
}
void studyFinderShowAllOptions(user_account& account){

    studyFinderShowAllOptionsDisplay(account.getUsername());

    switch(choose(0, 6)){
        case 1:
            { // higher to lower tuition fees
                studyFinderShowAllOptionsDisplay(account.getUsername());

                sort(universities_data.begin(), universities_data.end(), compareUniverisitiesByTuitionFees);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 2:
            { // lower to higher tuition fees
                studyFinderShowAllOptionsDisplay(account.getUsername());

                sort(universities_data.rbegin(), universities_data.rend(), compareUniverisitiesByTuitionFees);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 3:
            { // higher to lower ranking
                studyFinderShowAllOptionsDisplay(account.getUsername());

                sort(universities_data.begin(), universities_data.end(), compareUniverisitiesByRanking);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 4:
            { // lower to higher ranking
                studyFinderShowAllOptionsDisplay(account.getUsername());

                sort(universities_data.rbegin(), universities_data.rend(), compareUniverisitiesByRanking);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 5:
            { // higher to lower acceptance chance
                studyFinderShowAllOptionsDisplay(account.getUsername());

                sort(universities_data.begin(), universities_data.end(), compareUniverisitiesByAcceptance);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 6:
            { // lower to higher acceptance chance
                studyFinderShowAllOptionsDisplay(account.getUsername());

                sort(universities_data.rbegin(), universities_data.rend(), compareUniverisitiesByAcceptance);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 0: studyFinderSearchEngine(account); return;
    }

    cout << "|[STUDY-FINDER]| Enter '0' to cancel selection...\n";
    if (choose(0, universities_data.size())){
        // Ahmed ElTweel Task

        

    }else{
        studyFinderShowAllOptions(account);
    }


}
void studyFinderSearchEngine(user_account& account){

    studyFinderSearchEngineDisplay(account.getUsername());

    switch(choose(0, 3)){
        case 1: studyFinderCustomSearch(account); break;
        case 2: studyFinderSearchBasedOnProfile(account); break;
        case 3: studyFinderShowAllOptions(account); break;
        case 0: studyFinderMainMenu(account); return;
    }

}
void studyFinder(){
    studyFinderHomeDisplay();
    switch(choose(0, 2)){
        case 1: studyFinderLogin(); break;
        case 2: studyFinderRegister(); break;
        case 0: start(); return;
    }
}
void studyFinderMainMenu(user_account& account){

    studyFinderMainMenuDisplay(account.getUsername());

    switch(choose(0, 6)){
        case 1: studyFinderSearchEngine(account); break;
        case 2: 
        case 3: 
        case 4: 
        case 5: studentProfileSettings(account); break;
        case 6: accountSecuritySettings(account); break;
        case 0: studyFinder(); return;
    }

}

void start(){
    startDisplay();
    switch(choose(0, 2)){
        case 1: studyFinder(); break;
        case 2: bank(); break;
        case 0: return; //Exit
    }
}