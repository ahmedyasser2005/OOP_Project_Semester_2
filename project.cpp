#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

// Classes Pre-Definitions
class person;
class account;
class bankAccount;
class studyFinderAccount;
class university;

// Colour codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";

// Essential Functions
inline void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
inline void clearScreen() {
    system("cls");
}

inline void displayHeader(const string& title) {
    clearScreen();
    cout << BOLD << BLUE << "=-=-=-=-=-=-=- " << title << " -=-=-=-=-=-=-=-\n" << RESET << "\n";
}
void displayOptions(const vector<string>& options) {
    for (size_t i = 0; i < options.size(); ++i) {
        if (i == options.size() -1){
            cout << BOLD << CYAN << "|[0]| " << RESET << options[i] << '\n';
            break;
        }
        cout << BOLD << CYAN << "|[" << i+1 << "]| " << RESET << options[i] << '\n';
    }
    cout << "\n";
}
void displayErrorMessage(unsigned short msg, const vector<string>& messages) {
    if (msg < messages.size()) {
        cout << RED << messages[msg] << RESET << "\n\n";
    }
}

unsigned short choose(unsigned short from, unsigned short to) {
    unsigned short choice;
    while (true) {
        cout << "|[USER-INPUT]| Select an option (" << from << "-" << to << "): ";
        cin >> choice;

        if (cin.fail()) {
            // If input is not a number
            clearInput();
            cout << "|[CONSOLE]| Invalid Input, please enter a number between " << from << " and " << to << ".\n";
        } else if (choice >= from && choice <= to) {
            break;
        } else {
            cout << "|[CONSOLE]| Invalid Input, please enter a number between " << from << " and " << to << ".\n";
        }
    }
    return choice;
}

// Enums
enum region { Africa = 1, Europe, America, Asia };
enum gender { Male = false, Female = true };
enum degree_level { Highschool = 1, Undergraduate, Postgraduate };
enum english_level { A1 = 1, A2, B1, B2, C1, C2 };
enum study_programme { ComputerScience = 1, Engineering, Business, Arts, Media, Law};

// Implementations of Input Function of the Enums
region inputRegion() {
    int choice;
    while (true) {
        cout << "Select region (1: Africa, 2: Europe, 3: America, 4: Asia): ";
        cin >> choice;
        if (!cin.fail() && choice >= Africa && choice <= Asia) {
            return static_cast<region>(choice);
        } else {
            clearInput();
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
        }
    }
}
gender inputGender() {
    int choice;
    while (true) {
        cout << "Select gender (0: Male, 1: Female): ";
        cin >> choice;
        if (!cin.fail() && (choice == Male || choice == Female)) {
            return static_cast<gender>(choice);
        } else {
            clearInput();
            cout << "Invalid input. Please enter 0 for Male or 1 for Female.\n";
        }
    }
}
degree_level inputDegreeLevel() {
    int choice;
    while (true) {
        cout << "Select degree level (1: Highschool, 2: Undergraduate, 3: Postgraduate): ";
        cin >> choice;
        if (!cin.fail() && choice >= Highschool && choice <= Postgraduate) {
            return static_cast<degree_level>(choice);
        } else {
            clearInput();
            cout << "Invalid input. Please enter a number between 1 and 3.\n";
        }
    }
}
english_level inputEnglishLevel() {
    int choice;
    while (true) {
        cout << "Select English level (1: A1, 2: A2, 3: B1, 4: B2, 5: C1, 6: C2): ";
        cin >> choice;
        if (!cin.fail() && choice >= A1 && choice <= C2) {
            return static_cast<english_level>(choice);
        } else {
            clearInput();
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
        }
    }
}
study_programme inputStudyProgramme() {
    int choice;
    while (true) {
        cout << "Select study programme (1: Computer Science, 2: Engineering, 3: Business, 4: Arts, 5: Media): ";
        cin >> choice;
        if (!cin.fail() && choice >= ComputerScience && choice <= Media) {
            return static_cast<study_programme>(choice);
        } else {
            clearInput();
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        }
    }
}

// Classes
class person {
protected:
    string real_name;
    gender p_gender;
    region p_region;
    unsigned short age;
    float gpa;
    degree_level degree_lvl;
    english_level english_lvl;

public:

    // Default Constructor
    person()
            : real_name(""), p_gender(gender::Male), p_region(region::Africa), age(0), gpa(0), degree_lvl(degree_level::Highschool), english_lvl(english_level::A1) {}

    // Constructor
    person(const string& name, gender g, region r, unsigned short a, float gpa, degree_level dl, english_level el)
            : real_name(name), p_gender(g), p_region(r), age(a), gpa(gpa), degree_lvl(dl), english_lvl(el) {}

    // Constructor for derived classes
    person(region r, float gpa, degree_level dl, english_level el)
            : real_name(""), p_gender(gender::Male), p_region(r), age(0), gpa(gpa), degree_lvl(dl), english_lvl(el) {}
    
    friend bool qualificationCheck(const studyFinderAccount& user, const university& org);

    virtual void display() const {}

};
class account {
protected:
    string user_name;
    string user_password;
    unsigned int user_id;

public:

    // Constructor
    account(const string& username = "", const string& password = "", unsigned int id = 0)
            : user_name(username), user_password(password), user_id(id) {}

    friend bool qualificationCheck(const studyFinderAccount& user, const university& org);

};
class bankAccount : public account {
private:

    double balance = 0;
    static int counter;

public:
    // Constructor
    bankAccount(const string& un = "", const string& pw = "", double bal = 0.0)
            : account(un, pw, 100100 + counter), balance(bal) {
        counter += 100;
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
    unsigned short transfer(double amount, bankAccount& account) {
        if (amount < 5) {
            return 1;
        } else if (amount > balance) {
            return 2;
        } else {
            balance -= amount;
            account.balance += amount;
            return 4;
        }
    }

    void display() const {
        cout << "|[BANK]| Account Name   : " << user_name << '\n'
             << "       | Account ID     : " << user_id << '\n'
             << "       | Balance        : " << balance << "$\n\n";
    }

    // Set Methods
    void setName(const string& name) { user_name = name; }
    void setNumber(unsigned int num) { user_id = num; }
    void setBalance(double b) { balance = b; }
    void setPinCode(const string& pc) { user_password = pc; }

    // Get Methods
    string getName() const { return user_name; }
    unsigned int getNumber() const { return user_id; }
    double getBalance() const { return balance; }
    string getPinCode() const { return user_password; }
};
class studyFinderAccount : public person, public account {
private:
    bankAccount personal_account;

public:
    // Constructors
    studyFinderAccount(const string& un = "", const string& pw = "")
            : account(un, pw) {}

    studyFinderAccount(const string& un, const string& pw, unsigned int id, const string& rn,
                       gender g, region r, unsigned short a, float gpa,
                       degree_level dl, english_level el, const bankAccount& ba)
            : person(rn, g, r, a, gpa, dl, el), account(un, pw, id), personal_account(ba) {}

    // Set Methods
    void setUsername(const string& un) { user_name = un; }
    void setPassword(const string& pw) { user_password = pw; }
    void setRealName(const string& rn) { real_name = rn; }
    void setRegion(region r) { p_region = r; }
    void setGender(gender g) { p_gender = g; }
    void setAge(unsigned short a) { age = a; }
    void setDegreeLvl(degree_level dl) { degree_lvl = dl; }
    void setEnglishLvl(english_level el) { english_lvl = el; }
    void setGPA(float g) { gpa = g; }
    void setBank(const bankAccount& pb) { personal_account = pb; }

    // Get Methods
    string getUsername() const { return user_name; }
    string getPassword() const { return user_password; }
    string getRealName() const { return real_name; }
    region getRegion() const { return p_region; }
    gender getGender() const { return p_gender; }
    unsigned short getAge() const { return age; }
    degree_level getDegreeLvl() const { return degree_lvl; }
    english_level getEnglishLvl() const { return english_lvl; }
    float getGPA() const { return gpa; }
    bankAccount getBank() const { return personal_account; }
};
class university: public person {
private:

    string name;
    string desc;
    study_programme programme;
    double tuition_fees;
    static int counter;
    bankAccount uniBank;

public:
    // Constructor
    university(const string& _name = "", region _region = Africa, const string& _desc = "", study_programme _prog = {ComputerScience}, degree_level _degree_lvl = Highschool, english_level _english_lvl = A1,
               double _tuition_fees = 0.0, float _gpa = 0.0)
            : person(_region, _gpa, _degree_lvl, _english_lvl),
              name(_name), desc(_desc), programme(_prog), tuition_fees(_tuition_fees), uniBank(name, "", 100000 + counter) {
        ++counter;
    }

    // Comparison operator of acceptance chance
    bool operator >(const university& uni) const {
        unsigned short score1 = 0, score2 = 0;
        (english_lvl < uni.english_lvl) ? ++score1 : ++score2;
        (gpa < uni.gpa) ? ++score1 : ++score2;
        return (score1 <= score2);
    }
    bool operator <(const university& uni) const {
        unsigned short score1 = 0, score2 = 0;
        (english_lvl > uni.english_lvl) ? ++score1 : ++score2;
        (gpa > uni.gpa) ? ++score1 : ++score2;
        return (score1 >= score2);
    }

    // Display in list
    void display() const override {
        cout << "Uni: " << name << '\n'
             << " | Region: " << p_region << '\n'
             << " | Degree: " << degree_lvl << '\n'
             << " | Programme: " << programme << '\n'
             << " | Minimum GPA Required: " << gpa << '\n'
             << " | Minimum English Level Required: " << english_lvl << '\n'
             << " | Tuition Fees: " << tuition_fees << "$ / Year.\n"
             << desc << "\n\n";
    }
    void showInList(int i) const {
        cout << "|[" << i + 1 << "]| Uni: " << name << " | Region: " << p_region
             << " | Degree: " << degree_lvl << " | Programme: " << programme
             << " | Tuition Fees: " << tuition_fees << "$.\n" << desc << "\n\n";
    }

    // Get Methods
    double getTuitionFees()         const { return tuition_fees; }
    degree_level getDegreeLvl()     const { return degree_lvl;   }
    english_level getEnglishLvl()   const { return english_lvl;  }
    float getGPA()                  const { return gpa;          }
    bankAccount getBank()           const { return uniBank;      }
    int getCounter()                const { return counter;      }
};
class receipt {
private:
    string transactionType;
    double amount;
    double balance;
    unsigned int accountNumber;

public:
    receipt(const string& transactionType, double amount, double balance, unsigned int accountNumber)
        : transactionType(transactionType), amount(amount), balance(balance), accountNumber(accountNumber) {}

    void display() const {
        cout << BOLD << GREEN << "Transaction Receipt\n"
             << "--------------------\n"
             << "Transaction Type: " << transactionType << "\n"
             << "Amount: $" << amount << "\n"
             << "Remaining Balance: $" << balance << "\n"
             << "Account Number: " << accountNumber << "\n"
             << "--------------------\n" << RESET;
    }

    ~receipt() {
        cout << BOLD << RED << "Take a screenshot for the reciept before it gets destroyed.\n\n" << RESET;
    }
};

// Initial Value for the Static Variables
int bankAccount::counter = 0;
int university::counter = 0;

// Testing Data
university uni1("Oxford University", region::Europe, "The University of Oxford is a collegiate research university in Oxford, England. There is evidence of teaching as early as 1096, making it the oldest university in the English-speaking world and the world's second-oldest university in continuous operation.", study_programme::ComputerScience, degree_level::Undergraduate, english_level::B2, 50000, 3.9);
university uni2("Harvard University", region::America, "Established in 1636, Harvard is the oldest higher education institution in the United States, and is widely regarded in terms of its influence, reputation, and academic pedigree as a leading university in not just the US but also the world.", study_programme::ComputerScience, degree_level::Undergraduate, english_level::B2, 40000, 3.8);
university uni3("Cambridge University", region::Europe, "The University of Cambridge is one of the world's oldest universities and leading academic centres, and a self-governed community of scholars. Established in 1209, the University is rich in history.", study_programme::ComputerScience, degree_level::Undergraduate, english_level::B2, 30000, 3.7);
university uni4("Stanford University", region::America, "A private research university located in Stanford, California. Known for its entrepreneurial culture and proximity to Silicon Valley.", study_programme::Engineering, degree_level::Undergraduate, english_level::C1, 60000, 3.95);
university uni5("National University of Singapore", region::Asia, "A leading research university in Singapore. Offers a broad range of disciplines in engineering, science, business, and the arts and humanities.", study_programme::Business, degree_level::Postgraduate, english_level::B2, 45000, 3.8);
university uni6("Massachusetts Institute of Technology (MIT)", region::America, "A private research university focused on science, technology, engineering, and mathematics. Renowned for its innovation and entrepreneurship.", study_programme::ComputerScience, degree_level::Undergraduate, english_level::C2, 70000, 4.0);
university uni7("University of Tokyo", region::Asia, "A public research university located in Tokyo, Japan. Considered one of the most prestigious universities in Asia.", study_programme::Arts, degree_level::Undergraduate, english_level::B1, 35000, 3);
university uni8("University of Toronto", region::America, "A public research university in Toronto, Canada. Consistently ranked among the top universities worldwide.", study_programme::Media, degree_level::Undergraduate, english_level::B2, 42000, 3.8);
university uni9("École Polytechnique Fédérale de Lausanne (EPFL)", region::Europe, "A Swiss public research university in Lausanne, focused on science and technology. Renowned for its engineering and computer science programs.", study_programme::Engineering, degree_level::Postgraduate, english_level::C1, 55000, 3.9);
university uni10("The University of Melbourne", region::Asia, "A public research university in Melbourne, Australia. One of Australia's oldest universities and a member of the prestigious Group of Eight research universities.", study_programme::Business, degree_level::Undergraduate, english_level::B2, 38000, 3.7);
university uni11("University of Cape Town (UCT)", region::Africa, "A public research university in Cape Town, South Africa. The oldest university in South Africa and a renowned institution for research and teaching.", study_programme::Arts, degree_level::Undergraduate, english_level::B1, 25000, 3.6);
university uni12("Peking University", region::Asia, "A national research university in Beijing, China. Considered one of China's most prestigious universities, with a strong focus on humanities and social sciences.", study_programme::Law, degree_level::Postgraduate, english_level::C2, 40000, 3.9);

// Vectors To Store Data
vector<bankAccount> bank_accounts_data = {uni1.getBank(), uni2.getBank(), uni3.getBank(), uni4.getBank(), uni5.getBank(), uni6.getBank(), uni7.getBank(), uni8.getBank(), uni9.getBank(), uni10.getBank(), uni11.getBank(), uni12.getBank()};
vector<studyFinderAccount> user_accounts_data;
vector<university> universities_data = {uni1, uni2, uni3, uni4, uni5, uni6, uni7, uni8, uni9, uni10, uni11, uni12};

// Friend function to check whether the applicant is qualified for the university he chose
bool qualificationCheck(const studyFinderAccount& user, const university& org) {
    if (user.gpa >= org.gpa && user.english_lvl >= org.english_lvl) {
        return true;
    }else{
        return false;
    }
}

// Comparison Functions
bool sortByHigherTuition(const university& a, const university& b){
    return a.getTuitionFees() > b.getTuitionFees();
}
bool sortByLowerTuition(const university& a, const university& b){
    return a.getTuitionFees() < b.getTuitionFees();
}
bool sortByHigherAcceptance(const university& a, const university& b){
    return a > b;
}
bool sortByLowerAcceptance(const university& a, const university& b){
    return a < b;
}

// Display Functions ========================================================
// Start Display
inline void startDisplay() {
    displayHeader("OOP Project");
    vector<string> options = {
        "Open StudyFinder",
        "Open BankingSystem",
        "Exit"
    };
    displayOptions(options);
}

// Bank Display
inline void bankHomeDisplay() {
    displayHeader("BankingSystem");
    vector<string> options = {
        "Log in to your bank account",
        "Create a new bank account",
        "Back"
    };
    displayOptions(options);
}
inline void bankLoginDisplay(unsigned int accountNumber, const string& pinCode, unsigned short msg) {
    displayHeader("BankingSystem - Login");
    cout << BOLD << CYAN << "|[1]| " << RESET << (accountNumber ? to_string(accountNumber) : "*** Account Number") << "\n"
         << BOLD << CYAN << "|[2]| " << RESET << (pinCode.empty() ? "Enter PIN Code" : pinCode) << "\n"
         << BOLD << CYAN << "|[3]| " << RESET << "Log in\n"
         << BOLD << CYAN << "|[0]| " << RESET << "Back\n\n";
    vector<string> messages = {
        "",
        "Incorrect PIN code! Please try again.",
        "Account does not exist! Please try again."
    };
    displayErrorMessage(msg, messages);
}
inline void bankRegisterDisplay(const string& accountName, const string& pinCode, unsigned short msg, unsigned int accountNumber) {
    displayHeader("BankingSystem - Register");
    cout << BOLD << CYAN << "|[1]| " << RESET << (accountName.empty() ? "Enter Account Name" : accountName) << "\n"
         << BOLD << CYAN << "|[2]| " << RESET << (pinCode.empty() ? "Enter PIN Code" : pinCode) << "\n"
         << BOLD << CYAN << "|[3]| " << RESET << "Create Account\n"
         << BOLD << CYAN << "|[0]| " << RESET << "Back\n\n";
    vector<string> messages = {
        "",
        "Account already exists! Try a different name.",
        "New bank account created! Your account number is " + to_string(accountNumber) + "."
    };
    displayErrorMessage(msg, messages);
}
inline void bankMainMenuDisplay(const string& accountName, double balance) {
    displayHeader("BankingSystem - Main Menu");
    cout << BOLD << YELLOW << "| " << accountName << " | Balance: $" << balance << " |\n\n" << RESET;
    vector<string> options = {
        "Deposit",
        "Withdraw",
        "Transfer",
        "View Account Info",
        "Change PIN Code",
        "Sign Out"
    };
    displayOptions(options);
}
inline void bankDepositWithdrawDisplay(const string& accountName, double balance, const string& amount, bool type, unsigned short msg) {
    displayHeader(type ? "BankingSystem - Deposit" : "BankingSystem - Withdraw");
    cout << BOLD << YELLOW << "| " << accountName << " | Balance: $" << balance << " |\n\n" << RESET
         << BOLD << CYAN << "|[1]| " << RESET << (amount.empty() ? "Enter Amount" : "$" + amount) << "\n"
         << BOLD << CYAN << "|[2]| " << RESET << (type ? "Deposit" : "Withdraw") << "\n"
         << BOLD << CYAN << "|[0]| " << RESET << "Back\n\n";
    vector<string> messages = type ? vector<string>{
        "",
        "Failed: Minimum deposit is $5.",
        "Failed: Maximum deposit is $10,000.",
        "Success: $" + amount + " deposited."
    } : vector<string>{
        "",
        "Failed: Minimum withdrawal is $5.",
        "Failed: Maximum withdrawal is $10,000.",
        "Success: $" + amount + " withdrawn."
    };
    displayErrorMessage(msg, messages);
}
inline void bankTransferDisplay(const string& accountName, double balance, const string& amount, unsigned int accountNumber, unsigned short msg) {
    displayHeader("BankingSystem - Transfer");
    cout << BOLD << YELLOW << "| " << accountName << " | Balance: $" << balance << " |\n\n" << RESET
         << BOLD << CYAN << "|[1]| Amount: " << RESET << (amount.empty() ? "Enter Amount" : "$" + amount) << '\n'
         << BOLD << CYAN << "|[2]| To Account Number: " << RESET << (accountNumber == 0 ? "Enter Account Number" : to_string(accountNumber)) << '\n'
         << BOLD << CYAN << "|[3]| Transfer\n"
         << BOLD << CYAN << "|[0]| Back\n\n" << RESET;
    vector<string> messages = {
        "",
        "Failed: Minimum transfer is $5.",
        "Failed: Insufficient balance.",
        "Failed: Account not found.",
        "Success: $" + amount + " transferred to account " + to_string(accountNumber) + "."
    };
    displayErrorMessage(msg, messages);
}
inline void bankChangePINDisplay(const string& accountName, double balance, const string& c_pin, const string& n_pin, unsigned short msg) {
    displayHeader("BankingSystem - Change PIN");
    cout << BOLD << YELLOW << "| " << accountName << " | Balance: $" << balance << " |\n\n" << RESET
         << BOLD << CYAN << "|[1]| Current PIN: " << RESET << (c_pin.empty() ? "Enter Current PIN" : "*****") << "\n"
         << BOLD << CYAN << "|[2]| New PIN: " << RESET << (n_pin.empty() ? "Enter New PIN" : "*****") << "\n"
         << BOLD << CYAN << "|[3]| Confirm\n"
         << BOLD << CYAN << "|[0]| Back\n\n" << RESET;
    vector<string> messages = {
        "",
        "Incorrect current PIN.",
        "PIN changed successfully."
    };
    displayErrorMessage(msg, messages);
}

// StudyFinder Display
inline void studyFinderHomeDisplay() {
    displayHeader("StudyFinder");
    vector<string> options = {
        "Log in",
        "Create a new account",
        "Back"
    };
    displayOptions(options);
}
inline void studyFinderLoginDisplay(const string& username, const string& password, unsigned short msg) {
    displayHeader("StudyFinder - Login");
    cout << BOLD << CYAN << "|[1]| " << RESET << (username.empty() ? "Enter Username" : username) << "\n"
         << BOLD << CYAN << "|[2]| " << RESET << (password.empty() ? "Enter Password" : password) << "\n"
         << BOLD << CYAN << "|[3]| Log in\n"
         << BOLD << CYAN << "|[0]| Back\n\n" << RESET;
    vector<string> messages = {
        "",
        "Incorrect password! Please try again.",
        "Account does not exist! Please try again."
    };
    displayErrorMessage(msg, messages);
}
inline void studyFinderRegisterDisplay(const string& username, const string& password, unsigned short msg) {
    displayHeader("StudyFinder - Register");
    cout << BOLD << CYAN << "|[1]| " << RESET << (username.empty() ? "Enter Username" : username) << "\n"
         << BOLD << CYAN << "|[2]| " << RESET << (password.empty() ? "Enter Password" : password) << "\n"
         << BOLD << CYAN << "|[3]| Create Account\n"
         << BOLD << CYAN << "|[0]| Back\n\n" << RESET;
    vector<string> messages = {
        "",
        "Account already exists! Try a different username.",
        "Account created successfully."
    };
    displayErrorMessage(msg, messages);
}
inline void studyFinderMainMenuDisplay(const string& username) {
    displayHeader("StudyFinder - Main Menu");
    cout << BOLD << YELLOW << "| Welcome, " << username << " |\n\n" << RESET;
    vector<string> options = {
        "Search for Study Opportunities",
        "Update Student Profile",
        "Account Security Settings",
        "Sign Out"
    };
    displayOptions(options);
}
inline void studyFinderApplyDisplay(const string& username, university& selectedUni) {
    displayHeader("StudyFinder");
    cout << BOLD << YELLOW << "| Welcome, " << username << " |\n\n" << RESET
         << "=======================|  Show All |=======================\n";
    selectedUni.display();
    cout << "\n"
         << BOLD << CYAN << "|[1]| Apply\n"
         << BOLD << CYAN << "|[0]| Back\n" << RESET;
}
inline void studyFinderSelectDisplay(const string& username, university& selectedUni) {
    displayHeader("StudyFinder");
    cout << BOLD << YELLOW << "| Welcome, " << username << " |\n\n" << RESET
         << "=======================|  Show All |=======================\n";
    selectedUni.display();
    cout << "\n"
         << BOLD << CYAN << "|[1]| Apply\n"
         << BOLD << CYAN << "|[0]| Back\n" << RESET;
}
inline void studyFinderShowAllOptionsDisplay(const string& username, int counter) {
    displayHeader("StudyFinder");
    cout << BOLD << YELLOW << "| Welcome, " << username << " |\n\n"
         << "===========|  Show All | ==== | Found: " << counter << " |===========|\n" << RESET;
    vector<string> options = {
        "Sort by higher tuition fees",
        "Sort by lower tuition fees",
        "Sort by higher acceptance chance",
        "Sort by lower acceptance chance",
        "Back"
    };
    displayOptions(options);
    cout << "==================================================================\n\n";
}
inline void studentProfileSettingsDisplay(const string& username, const string& realname, region reg, gender gen, unsigned short age, degree_level degree_lvl, english_level english_lvl, float gpa) {
    displayHeader("StudyFinder - Profile Settings");
    cout << BOLD << YELLOW << "| Welcome, " << username << " |\n\n" << RESET
         << "| \"*\" indicates required fields |\n"
         << BOLD << CYAN << "|[1]| Real Name: " << RESET << realname << '\n'
         << BOLD << CYAN << "|[2]| Gender: " << RESET << gen << '\n'
         << BOLD << CYAN << "|[3]| Age: " << RESET << age << '\n'
         << BOLD << CYAN << "|[4]| Region: " << RESET << reg << '\n'
         << BOLD << CYAN << "|[5]| Degree Level*: " << RESET << degree_lvl << '\n'
         << BOLD << CYAN << "|[6]| GPA*: " << RESET << gpa << " (out of 4.0)\n"
         << BOLD << CYAN << "|[7]| English Level*: " << RESET << english_lvl << '\n'
         << BOLD << CYAN << "|[0]| Back\n" << RESET;
}
inline void accountSecuritySettingsDisplay(const string& username, unsigned short msg) {
    displayHeader("StudyFinder - Account Security");
    cout << BOLD << CYAN << "|[1]| Username: " << RESET << username << '\n'
         << BOLD << CYAN << "|[2]| Change Password\n"
         << BOLD << CYAN << "|[0]| Back\n\n" << RESET;
    vector<string> messages = {
        "",
        "Incorrect current password",
        "Password changed successfully"
    };
    displayErrorMessage(msg, messages);
}

// Main Functions Definitions ========================================================
// Bank
void bankLogin(unsigned int, string, unsigned short);
void bankRegister(string, string, unsigned short, unsigned int);
void bank();
void bankMainMenu(bankAccount&, bool);
void bankDeposit(bankAccount&, string, double, unsigned short);
void bankWithdraw(bankAccount&, string, double, unsigned short);
void bankTransfer(bankAccount&, string, double, unsigned int, unsigned short);

// StudyFinder
void studyFinderLogin(string, string, unsigned short);
void studyFinderRegister(string, string, unsigned short);
void studyFinderProfileSettings(studyFinderAccount&);
void studyFinderAccountSecuritySettings(studyFinderAccount&, unsigned short);
void studyFinderSelect(studyFinderAccount&, university&);
void studyFinderShowResults(studyFinderAccount&);
void studyFinder();
void studyFinderMainMenu(studyFinderAccount&);

// Start
void start();

// Starting Point
int main(){
    start();
    return 0;
}

// Main Functions ========================================================
// Bank
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
            for (int i = 0; i < bank_accounts_data.size(); ++i){
                if (accountName == bank_accounts_data[i].getName()){
                    bankRegister(accountName, pinCode, 1);
                    return;
                }
            }

            bankAccount newBankAccount(accountName, pinCode);
            bank_accounts_data.emplace_back(newBankAccount);
            bankRegister("*** Account Name...", "*** PIN Code...", 2, newBankAccount.getNumber());

        }
            break;
        case 0: bank(); return;
    }
}
void bankDeposit(bankAccount& account, string amount = "*** Amount to deposit...", double cash = 0, unsigned short msg = 0){

    bankDepositWithdrawDisplay(account.getName(), account.getBalance(), amount, true, msg);

    if (msg == 3){
        receipt deposit_receipt("Deposit", cash, account.getBalance(), account.getNumber());
        deposit_receipt.display();
    }

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
void bankTransfer(bankAccount& senderAccount, string amount = "*** Amount to transfer...", double cash = 0, unsigned int receiverAccountNumber = 0, unsigned short msg = 0) {

    bankTransferDisplay(senderAccount.getName(), senderAccount.getBalance(), amount, receiverAccountNumber, msg);

    if (msg == 4){
        receipt deposit_receipt("Transfer", cash, senderAccount.getBalance(), senderAccount.getNumber());
        deposit_receipt.display();
    }

    switch (choose(0, 3)) {
        case 1:
            cout << "|[USER-INPUT]| Enter amount to transfer: ";
            cin >> cash;
            amount = to_string(cash) + '$';
            bankTransfer(senderAccount, amount, cash, receiverAccountNumber, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Enter account number: ";
            cin >> receiverAccountNumber;
            bankTransfer(senderAccount, amount, cash, receiverAccountNumber, msg);
            break;
        case 3:
            for (auto& receiverAccount : bank_accounts_data) {
                if (receiverAccount.getNumber() == receiverAccountNumber) {
                    bankTransfer(senderAccount, amount, cash, receiverAccountNumber, senderAccount.transfer(cash, receiverAccount));
                    return;
                }
            }
            bankTransfer(senderAccount, amount, cash, receiverAccountNumber, 3);
            break;
        case 0: bankMainMenu(senderAccount, false); return;
    }

}
void bankWithdraw(bankAccount& account, string amount = "*** Amount to withdraw...", double cash = 0, unsigned short msg = 0){

    bankDepositWithdrawDisplay(account.getName(), account.getBalance(), amount, false, msg);

    if (msg == 3){
        receipt deposit_receipt("Withdraw", cash, account.getBalance(), account.getNumber());
        deposit_receipt.display();
    }

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
void bankChangePIN(bankAccount& account, string c_pin = "*** Current PIN Code...", string n_pin = "*** New PIN Code...", unsigned short msg = 0){

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
void bankMainMenu(bankAccount& account, bool showInfo = false){

    bankMainMenuDisplay(account.getName(), account.getBalance());

    if (showInfo) account.display();

    switch(choose(0, 5)){
        case 1: bankDeposit(account); break;
        case 2: bankWithdraw(account); break;
        case 3: bankTransfer(account); break;
        case 4: bankMainMenu(account, true); break;
        case 5: bankChangePIN(account); break;
        case 0: bank(); return;
    }

}

// StudyFinder
void studyFinderLogin(string username = "*** Username...", string password = "*** Password...", unsigned short msg = 0){

    studyFinderLoginDisplay(username, password, msg);

    switch(choose(0, 3)){
        case 1:
            cout << "|[USER-INPUT]| Enter your username: ";
            cin >> username;
            studyFinderLogin(username, password, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Enter your password: ";
            cin >> password;
            studyFinderLogin(username, password, msg);
            break;
        case 3:
        {

            // Mahrous Task Here ***
            // Make your code here to search for the desired data

            // For now I will use vectors as database so I can test the project --Ahmed Yasser Eissa
            for (int i = 0; i < user_accounts_data.size(); ++i){
                if (username == user_accounts_data[i].getUsername()){
                    if (password == user_accounts_data[i].getPassword()){

                        // Successfully logged in

                        studyFinderMainMenu(user_accounts_data[i]);
                        return;

                    }else{

                        // Password doesn't match the account

                        studyFinderLogin(username, password, 1);
                        return;

                    }
                }
            }

            // Username doesn't match any account

            studyFinderLogin(username, password, 2);

        }
            break;
        case 0: studyFinder(); return;
    }

}
void studyFinderRegister(string username = "*** Username...", string password = "*** Password...", unsigned short msg = 0){

    studyFinderRegisterDisplay(username, password, msg);

    switch(choose(0, 4)){
        case 1:
            cout << "|[USER-INPUT]| Create your username: ";
            cin >> username;
            studyFinderRegister(username, password, msg);
            break;
        case 2:
            cout << "|[USER-INPUT]| Create your password: ";
            cin >> password;
            studyFinderRegister(username, password, msg);
            break;
        case 3:
        {
            for (int i = 0; i < user_accounts_data.size(); ++i){
                if (username == user_accounts_data[i].getUsername()){

                    // Found an existed account with same username

                    studyFinderRegister(username, password, 1);
                    return;
                }
            }

            // Creating a new account

            studyFinderAccount newUserAccount(username, password);
            user_accounts_data.emplace_back(newUserAccount);
            studyFinderRegister(username, password, 2);

        }
            break;
        case 0: studyFinder(); return;
    }

}
void studyFinderProfileSettings(studyFinderAccount& account){

    studentProfileSettingsDisplay(account.getUsername(), account.getRealName(), account.getRegion(), account.getGender(), account.getAge(), account.getDegreeLvl(), account.getEnglishLvl(), account.getGPA());

    switch(choose(0, 7)){
        case 1:
        {
            string input;
            cout << "|[USER-INPUT]| Enter your Real Name: ";
            cin >> input;
            account.setRealName(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 2:
        {
            gender input = inputGender();
            cout << "|[USER-INPUT]| Enter your Gender: ";
            account.setGender(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 3:
        {
            unsigned short input;
            cout << "|[USER-INPUT]| Enter your Age: ";
            cin >> input;
            account.setAge(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 4:
        {
            region input = inputRegion();
            cout << "|[USER-INPUT]| Enter your Region: ";
            account.setRegion(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 5:
        {
            degree_level input = inputDegreeLevel();
            cout << "|[USER-INPUT]| Enter your recent finished degree level: ";
            account.setDegreeLvl(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 6:
        {
            float input;
            cout << "|[USER-INPUT]| Enter your GPA: ";
            cin >> input;
            account.setGPA(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 7:
        {
            english_level input = inputEnglishLevel();
            cout << "|[USER-INPUT]| Enter your English level: ";
            account.setEnglishLvl(input);
            studyFinderProfileSettings(account);
        }
            break;
        case 0: studyFinderMainMenu(account); return;
    }
}
void studyFinderAccountSecuritySettings(studyFinderAccount& account, unsigned short msg = 0){

    accountSecuritySettingsDisplay(account.getUsername(), msg);

    switch(choose(0, 2)){
        case 1:
        {
            string input;
            cout << "|[USER-INPUT]| Enter your new username: ";
            cin >> input;
            account.setUsername(input);
            studyFinderAccountSecuritySettings(account);
        }
            break;
        case 2:
        {
            string input;
            cout << "|[USER-INPUT]| Enter your current Password: ";
            cin >> input;
            if (input == account.getPassword()){
                cout << "|[USER-INPUT]| Enter your new Password: ";
                cin >> input;
                account.setPassword(input);
                studyFinderAccountSecuritySettings(account, 2);
            }else{
                studyFinderAccountSecuritySettings(account, 1);
            }
        }
            break;
        case 0: studyFinderMainMenu(account); return;
    }
}
void studyFinderSelect(studyFinderAccount& account, university& selectedUni) {

    studyFinderSelectDisplay(account.getUsername(), selectedUni);

    switch (choose(0, 1)) {
        case 1:
            if (qualificationCheck(account, selectedUni)) {
                cout << "|[STUDY-FINDER]| Congratulations, You are qualified for this study opportunity!\n"
                     << "|[STUDY-FINDER]| Please head to the bank application and transfer " << selectedUni.getTuitionFees() << "$ to the following account number: " << selectedUni.getBank().getNumber() << "\n\n"
                     << "|| [1] Pay Tuition Fees...\n"
                     << "|| [0] Back.\n\n";
                if (choose(0, 1)) {
                    bank();
                }else{
                    studyFinderShowResults(account); return;
                }
            } else {
                cout << "|[STUDY-FINDER]| Unfortunately, you do not qualify for this study opportunity.\n"
                     << "|[STUDY-FINDER]| Type '0' to continue...\n";
                switch (choose(0, 0)){
                    case 0: studyFinderShowResults(account); return;
                }
            }
            break;
        case 0: studyFinderShowResults(account); return;
    }
}
void studyFinderShowResults(studyFinderAccount& account){

    int counter = universities_data.begin()->getCounter();

    studyFinderShowAllOptionsDisplay(account.getUsername(), counter);

    switch(choose(0, 4)){
        case 1:
            { // higher to lower tuition fees
                studyFinderShowAllOptionsDisplay(account.getUsername(), counter);
                
                sort(universities_data.begin(), universities_data.end(), sortByHigherTuition);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 2:
            { // lower to higher tuition fees
                studyFinderShowAllOptionsDisplay(account.getUsername(), counter);

                sort(universities_data.begin(), universities_data.end(), sortByLowerTuition);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 3:
            { // higher to lower acceptance chance
                studyFinderShowAllOptionsDisplay(account.getUsername(), counter);
                
                sort(universities_data.begin(), universities_data.end(), sortByHigherAcceptance);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 4:
            { // lower to higher acceptance chance
                studyFinderShowAllOptionsDisplay(account.getUsername(), counter);

                sort(universities_data.begin(), universities_data.end(), sortByHigherAcceptance);

                for (int i = 0; i < universities_data.size(); ++i){
                    
                    universities_data[i].showInList(i);

                }
            }
            break;
        case 0: studyFinderMainMenu(account); return;
    }

    cout << "|[STUDY-FINDER]| Enter '0' to cancel selection...\n";
    
    unsigned short choice = choose(0, universities_data.size());
    if (choice){
        studyFinderSelect(account, universities_data[choice-1]);
    }
    else{
        studyFinderShowResults(account);
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
void studyFinderMainMenu(studyFinderAccount& account){

    studyFinderMainMenuDisplay(account.getUsername());

    switch(choose(0, 3)){
        case 1: studyFinderShowResults(account); break;
        case 2: studyFinderProfileSettings(account); break;
        case 3: studyFinderAccountSecuritySettings(account); break;
        case 0: studyFinder(); return;
    }

}

// Start
void start(){
    startDisplay();
    switch(choose(0, 2)){
        case 1: studyFinder(); break;
        case 2: bank(); break;
        case 0: return; //Exit
    }
}