#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// ==================== 交易记录 ====================
enum class TransactionType {
    DEPOSIT,    // 存款
    WITHDRAW,   // 取款
    TRANSFER,   // 转账
    INTEREST    // 利息
};

struct Transaction {
    string date;
    TransactionType type;
    double amount;
    double balance;
    string description;
    string fromAccount;  // 转账来源
    string toAccount;    // 转账目标
    
    Transaction(string d, TransactionType t, double a, double b, string desc = "", 
                string from = "", string to = "")
        : date(d), type(t), amount(a), balance(b), description(desc), 
          fromAccount(from), toAccount(to) {}
    
    string getTypeString() const {
        switch(type) {
            case TransactionType::DEPOSIT:  return "存款";
            case TransactionType::WITHDRAW: return "取款";
            case TransactionType::TRANSFER: return "转账";
            case TransactionType::INTEREST: return "利息";
            default: return "未知";
        }
    }
};

// ==================== 账户类 ====================
class Account {
private:
    string accountNumber;
    string password;        // 密码
    string createDate;
    string ownerName;       // 户主姓名
    double balance;
    bool isFrozen;          // 是否冻结
    vector<Transaction> transactions;
    
public:
    Account(string accNum, string pwd, string name, double initialBalance = 0)
        : accountNumber(accNum), password(pwd), ownerName(name), 
          balance(initialBalance), isFrozen(false) {
        createDate = getCurrentDate();
        transactions.push_back(Transaction(createDate, TransactionType::DEPOSIT, 
                                               initialBalance, balance, "开户初始存款"));
    }
    
    // 获取当前时间
    static string getCurrentTime() {
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return string(buffer);
    }
    
    static string getCurrentDate() {
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
        return string(buffer);
    }
    
    // 验证密码
    bool verifyPassword(const string& pwd) const {
        return password == pwd;
    }
    
    // 修改密码
    bool changePassword(const string& oldPwd, const string& newPwd) {
        if (!verifyPassword(oldPwd)) {
            cout << "原密码错误！" << endl;
            return false;
        }
        if (newPwd.length() < 6) {
            cout << "密码长度不能少于6位！" << endl;
            return false;
        }
        password = newPwd;
        cout << "密码修改成功！" << endl;
        return true;
    }
    
    // 存款（客户端）
    bool deposit(double amount) {
        if (isFrozen) {
            cout << "账户已冻结，无法操作！" << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "存款金额必须大于0！" << endl;
            return false;
        }
        
        balance += amount;
        string currentTime = getCurrentTime();
        transactions.push_back(Transaction(currentTime, TransactionType::DEPOSIT, 
                                           amount, balance, "客户存款"));
        cout << " 存款成功！金额：" << amount << "，当前余额：" << balance << endl;
        return true;
    }
    
    // 取款（客户端）
    bool withdraw(double amount) {
        if (isFrozen) {
            cout << "账户已冻结，无法操作！" << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "取款金额必须大于0！" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "余额不足！当前余额：" << balance << "，需要：" << amount << endl;
            return false;
        }
        
        balance -= amount;
        string currentTime = getCurrentTime();
        transactions.push_back(Transaction(currentTime, TransactionType::WITHDRAW, 
                                           amount, balance, "客户取款"));
        cout << " 取款成功！金额：" << amount << "，当前余额：" << balance << endl;
        return true;
    }
    
    // 转账（客户端）
    bool transfer(Account& target, double amount) {
        if (isFrozen) {
            cout << "账户已冻结，无法操作！" << endl;
            return false;
        }
        if (target.isFrozen) {
            cout << "目标账户已冻结，无法转账！" << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "转账金额必须大于0！" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "余额不足！当前余额：" << balance << "，需要：" << amount << endl;
            return false;
        }
        // 执行转账
        balance -= amount;
        target.balance += amount;
        string currentTime = getCurrentTime();
        // 记录转出
        transactions.push_back(Transaction(currentTime, TransactionType::TRANSFER, 
                                           amount, balance, "转出", 
                                           accountNumber, target.accountNumber));
        
        // 记录转入（目标账户）
        target.transactions.push_back(Transaction(currentTime, TransactionType::TRANSFER, 
                                                  amount, target.balance, "转入", 
                                                  accountNumber, target.accountNumber));
        
        cout << " 转账成功！向 " << target.ownerName << "(" << target.accountNumber
             << ") 转账 " << amount << " 元" << endl;
        cout << "  当前余额：" << balance << endl;
        return true;
    }
    
    // 查询余额（客户端）
    void showBalance() const {
        cout << "\n========== 账户余额 ==========" << endl;
        cout << "账号：" << accountNumber << endl;
        cout << "户主：" << ownerName << endl;
        cout << "余额：" << fixed << setprecision(2) << balance << " 元" << endl;
        cout << "状态：" << (isFrozen ? "已冻结" : "正常") << endl;
        cout << "================================\n" << endl;
    }
    
    // 查询所有交易明细（客户端）
    void showAllTransactions() const {
        if (transactions.empty()) {
            cout << "暂无交易记录" << endl;
            return;
        }
        
        cout << "\n========== 全部交易明细 ==========" << endl;
        cout << "账号：" << accountNumber << " | 户主：" << ownerName << endl;
        cout << "当前余额：" << balance << " 元" << endl;
        cout << "-----------------------------------" << endl;
        cout << setw(20) << "交易日期" 
             << setw(10) << "类型" 
             << setw(12) << "金额" 
             << setw(15) << "交易后余额" 
             << setw(20) << "描述" << endl;
        cout << "-----------------------------------" << endl;
        
        for (const auto& trans : transactions) {
            cout << setw(20) << trans.date.substr(0, 19)
                 << setw(10) << trans.getTypeString()
                 << setw(12) << fixed << setprecision(2) << trans.amount
                 << setw(15) << trans.balance
                 << setw(20) << trans.description;
            
            if (trans.type == TransactionType::TRANSFER) {
                if (!trans.fromAccount.empty() && trans.fromAccount != accountNumber) {
                    cout << "(来自:" << trans.fromAccount << ")";
                } else if (!trans.toAccount.empty()) {
                    cout << "(至:" << trans.toAccount << ")";
                }
            }
            cout << endl;
        }
        cout << "===================================\n" << endl;
    }
    
    // 查询近一个月交易记录（客户端）
    void showRecentMonthTransactions() const {
        if (transactions.empty()) {
            cout << "暂无交易记录" << endl;
            return;
        }
        
        time_t now = time(nullptr);
        time_t oneMonthAgo = now - 30 * 24 * 3600;
        tm* monthAgoTM = localtime(&oneMonthAgo);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", monthAgoTM);
        string cutoffDate = string(buffer);
        
        cout << "\n========== 近一个月交易记录 ==========" << endl;
        cout << "统计区间：" << cutoffDate << " 至今" << endl;
        cout << "账号：" << accountNumber << " | 户主：" << ownerName << endl;
        cout << "当前余额：" << balance << " 元" << endl;
        cout << "---------------------------------------" << endl;
        
        bool hasTransaction = false;
        double totalDeposit = 0, totalWithdraw = 0;
        
        cout << setw(20) << "交易日期" 
             << setw(10) << "类型" 
             << setw(12) << "金额" 
             << setw(15) << "交易后余额" 
             << setw(20) << "描述" << endl;
        cout << "---------------------------------------" << endl;
        
        for (const auto& trans : transactions) {
            string transDate = trans.date.substr(0, 10);
            if (transDate >= cutoffDate) {
                cout << setw(20) << trans.date.substr(0, 19)
                     << setw(10) << trans.getTypeString()
                     << setw(12) << fixed << setprecision(2) << trans.amount
                     << setw(15) << trans.balance
                     << setw(20) << trans.description << endl;
                hasTransaction = true;
                
                if (trans.type == TransactionType::DEPOSIT) {
                    totalDeposit += trans.amount;
                } else if (trans.type == TransactionType::WITHDRAW) {
                    totalWithdraw += trans.amount;
                }
            }
        }
        
        if (!hasTransaction) {
            cout << "近一个月内没有交易记录" << endl;
        } else {
            cout << "---------------------------------------" << endl;
            cout << "本月总存款：" << totalDeposit << " 元" << endl;
            cout << "本月总取款：" << totalWithdraw << " 元" << endl;
            cout << "净变动：" << (totalDeposit - totalWithdraw) << " 元" << endl;
        }
        cout << "=========================================\n" << endl;
    }
    
    // ========== Getter 方法 ==========
    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    string getCreateDate() const { return createDate; }
    double getBalance() const { return balance; }
    bool getIsFrozen() const { return isFrozen; }
    size_t getTransactionCount() const { return transactions.size(); }
    
    // ========== Setter 方法（管理员专用） ==========
    void freeze() { isFrozen = true; }
    void unfreeze() { isFrozen = false; }
    void setBalance(double newBalance) { balance = newBalance; }
};

// ==================== 银行管理类 ====================
class Bank {
private:
    vector<Account> accounts;
    bool adminLoggedIn;
    
    // 查找账户（返回索引）
    int findAccountIndex(const string& accountNumber) const {
        for (size_t i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return i;
            }
        }
        return -1;
    }
    
    // 查找账户（返回指针）
    Account* findAccount(const string& accountNumber) {
        int idx = findAccountIndex(accountNumber);
        if (idx != -1) {
            return &accounts[idx];
        }
        return nullptr;
    }
    
public:
    Bank() : adminLoggedIn(false) {}
    
    // ========== 管理员功能 ==========
    
    // 管理员登录
    bool adminLogin(const string& password) {
        if (password == "admin123") {  // 默认管理员密码
            adminLoggedIn = true;
            cout << "管理员登录成功！" << endl;
            return true;
        }
        cout << "管理员密码错误！" << endl;
        return false;
    }
    
    // 管理员登出
    void adminLogout() {
        adminLoggedIn = false;
        cout << "管理员已登出" << endl;
    }
    
    // 创建账户（管理员）
    void createAccount(const string& accNum, const string& pwd, 
                       const string& name, double initialBalance = 0) {
        if (!adminLoggedIn) {
            cout << "请先登录管理员！" << endl;
            return;
        }
        
        if (findAccountIndex(accNum) != -1) {
            cout << "错误：账号 " << accNum << " 已存在！" << endl;
            return;
        }
        
        if (pwd.length() < 6) {
            cout << "密码长度不能少于6位！" << endl;
            return;
        }
        
        accounts.push_back(Account(accNum, pwd, name, initialBalance));
        cout << "  账户创建成功！" << endl;
        cout << "  账号：" << accNum << endl;
        cout << "  户主：" << name << endl;
        cout << "  初始余额：" << initialBalance << " 元" << endl;
        cout << "  创建日期：" << Account::getCurrentDate() << endl;
    }
    
    // 查看所有账户（管理员）
    void showAllAccounts() const {
        if (!adminLoggedIn) {
            cout << "请先登录管理员！" << endl;
            return;
        }
        
        if (accounts.empty()) {
            cout << "当前银行没有账户" << endl;
            return;
        }
        
        cout << "\n========== 所有账户信息 ==========" << endl;
        cout << "总计：" << accounts.size() << " 个账户" << endl;
        cout << setw(15) << "账号" 
             << setw(12) << "户主" 
             << setw(12) << "创建日期" 
             << setw(12) << "余额" 
             << setw(10) << "状态" 
             << setw(12) << "交易笔数" << endl;
        cout << "---------------------------------------------" << endl;
        
        for (const auto& acc : accounts) {
            cout << setw(15) << acc.getAccountNumber()
                 << setw(12) << acc.getOwnerName()
                 << setw(12) << acc.getCreateDate()
                 << setw(12) << fixed << setprecision(2) << acc.getBalance()
                 << setw(10) << (acc.getIsFrozen() ? "已冻结" : "正常")
                 << setw(12) << acc.getTransactionCount() << endl;
        }
        cout << "=============================================\n" << endl;
    }
    
    // 冻结账户（管理员）
    void freezeAccount(const string& accNum) {
        if (!adminLoggedIn) {
            cout << "请先登录管理员！" << endl;
            return;
        }
        
        Account* acc = findAccount(accNum);
        if (acc == nullptr) {
            cout << "账号不存在！" << endl;
            return;
        }
        
        if (acc->getIsFrozen()) {
            cout << "账户已处于冻结状态" << endl;
            return;
        }
        
        acc->freeze();
        cout << " 账户 " << accNum << " 已冻结" << endl;
    }
    
    // 解冻账户（管理员）
    void unfreezeAccount(const string& accNum) {
        if (!adminLoggedIn) {
            cout << "请先登录管理员！" << endl;
            return;
        }
        
        Account* acc = findAccount(accNum);
        if (acc == nullptr) {
            cout << "账号不存在！" << endl;
            return;
        }
        
        if (!acc->getIsFrozen()) {
            cout << "账户未冻结" << endl;
            return;
        }
        
        acc->unfreeze();
        cout << "账户 " << accNum << " 已解冻" << endl;
    }
    
    // 管理员查询任意账户明细
    void adminShowTransactions(const string& accNum) {
        if (!adminLoggedIn) {
            cout << "请先登录管理员！" << endl;
            return;
        }
        
        Account* acc = findAccount(accNum);
        if (acc == nullptr) {
            cout << "账号不存在！" << endl;
            return;
        }
        
        acc->showAllTransactions();
    }
    
    // ========== 客户端功能 ==========
    
    // 用户登录（返回账户指针）
    Account* clientLogin(const string& accNum, const string& pwd) {
        Account* acc = findAccount(accNum);
        if (acc == nullptr) {
            cout << "账号不存在！" << endl;
            return nullptr;
        }
        
        if (!acc->verifyPassword(pwd)) {
            cout << "密码错误！" << endl;
            return nullptr;
        }
        
        cout << " 登录成功！欢迎 " << acc->getOwnerName() << endl;
        return acc;
    }
    
    // 获取账户（用于客户端操作）
    Account* getAccount(const string& accNum) {
        return findAccount(accNum);
    }
};

// ==================== 主函数 ====================
int main() {
    Bank bank;
    Account* currentUser = nullptr;
    string currentAccNum;
    bool running = true;
    int choice;
    
    cout << "=====================================" << endl;
    cout << "   欢迎使用银行账户管理系统" << endl;
    cout << "=====================================\n" << endl;
    
    // 管理员先登录创建一些测试账户
    cout << "【初始化】管理员登录创建测试账户..." << endl;
    bank.adminLogin("admin123");
    bank.createAccount("1001", "123456", "张三", 1000);
    bank.createAccount("1002", "123456", "李四", 500);
    bank.createAccount("1003", "123456", "王五", 2000);
    bank.adminLogout();
    cout << "\n初始化完成！\n" << endl;
    
    while (running) {
        if (currentUser == nullptr) {
            // ========== 未登录菜单 ==========
            cout << "\n========== 主菜单 ==========" << endl;
            cout << "1. 用户登录" << endl;
            cout << "2. 管理员登录" << endl;
            cout << "3. 退出系统" << endl;
            cout << "============================" << endl;
            cout << "请选择：";
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    string accNum, pwd;
                    cout << "请输入账号：";
                    cin >> accNum;
                    cout << "请输入密码：";
                    cin >> pwd;
                    currentUser = bank.clientLogin(accNum, pwd);
                    if (currentUser != nullptr) {
                        currentAccNum = accNum;
                    }
                    break;
                }
                case 2: {
                    string pwd;
                    cout << "请输入管理员密码：";
                    cin >> pwd;
                    if (bank.adminLogin(pwd)) {
                        // 管理员菜单
                        bool adminRunning = true;
                        while (adminRunning) {
                            cout << "\n========== 管理员菜单 ==========" << endl;
                            cout << "1. 创建账户" << endl;
                            cout << "2. 查看所有账户" << endl;
                            cout << "3. 冻结账户" << endl;
                            cout << "4. 解冻账户" << endl;
                            cout << "5. 查询任意账户明细" << endl;
                            cout << "6. 退出管理员" << endl;
                            cout << "================================" << endl;
                            cout << "请选择：";
                            cin >> choice;
                            
                            switch (choice) {
                                case 1: {
                                    string accNum, pwd, name;
                                    double balance;
                                    cout << "请输入账号：";
                                    cin >> accNum;
                                    cout << "请输入密码（至少6位）：";
                                    cin >> pwd;
                                    cout << "请输入户主姓名：";
                                    cin >> name;
                                    cout << "请输入初始余额：";
                                    cin >> balance;
                                    bank.createAccount(accNum, pwd, name, balance);
                                    break;
                                }
                                case 2:
                                    bank.showAllAccounts();
                                    break;
                                case 3: {
                                    string accNum;
                                    cout << "请输入要冻结的账号：";
                                    cin >> accNum;
                                    bank.freezeAccount(accNum);
                                    break;
                                }
                                case 4: {
                                    string accNum;
                                    cout << "请输入要解冻的账号：";
                                    cin >> accNum;
                                    bank.unfreezeAccount(accNum);
                                    break;
                                }
                                case 5: {
                                    string accNum;
                                    cout << "请输入要查询的账号：";
                                    cin >> accNum;
                                    bank.adminShowTransactions(accNum);
                                    break;
                                }
                                case 6:
                                    bank.adminLogout();
                                    adminRunning = false;
                                    break;
                                default:
                                    cout << "无效选择，请重新输入" << endl;
                            }
                        }
                    }
                    break;
                }
                case 3:
                    cout << "感谢使用，再见！" << endl;
                    running = false;
                    break;
                default:
                    cout << "无效选择，请重新输入" << endl;
            }
        } else {
            // ========== 用户已登录菜单 ==========
            cout << "\n========== 用户菜单 ==========" << endl;
            cout << "当前用户：" << currentAccNum << endl;
            cout << "1. 查询余额" << endl;
            cout << "2. 存款" << endl;
            cout << "3. 取款" << endl;
            cout << "4. 转账" << endl;
            cout << "5. 查看全部交易明细" << endl;
            cout << "6. 查看近一个月交易" << endl;
            cout << "7. 修改密码" << endl;
            cout << "8. 退出登录" << endl;
            cout << "==============================" << endl;
            cout << "请选择：";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    currentUser->showBalance();
                    break;
                case 2: {
                    double amount;
                    cout << "请输入存款金额：";
                    cin >> amount;
                    currentUser->deposit(amount);
                    break;
                }
                case 3: {
                    double amount;
                    cout << "请输入取款金额：";
                    cin >> amount;
                    currentUser->withdraw(amount);
                    break;
                }
                case 4: {
                    string targetAcc;
                    double amount;
                    cout << "请输入目标账号：";
                    cin >> targetAcc;
                    Account* target = bank.getAccount(targetAcc);
                    if (target == nullptr) {
                        cout << "目标账号不存在！" << endl;
                        break;
                    }
                    if (target == currentUser) {
                        cout << "不能给自己转账！" << endl;
                        break;
                    }
                    cout << "请输入转账金额：";
                    cin >> amount;
                    currentUser->transfer(*target, amount);
                    break;
                }
                case 5:
                    currentUser->showAllTransactions();
                    break;
                case 6:
                    currentUser->showRecentMonthTransactions();
                    break;
                case 7: {
                    string oldPwd, newPwd;
                    cout << "请输入原密码：";
                    cin >> oldPwd;
                    cout << "请输入新密码（至少6位）：";
                    cin >> newPwd;
                    currentUser->changePassword(oldPwd, newPwd);
                    break;
                }
                case 8:
                    cout << "已退出登录，再见 " << currentUser->getOwnerName() << endl;
                    currentUser = nullptr;
                    currentAccNum = "";
                    break;
                default:
                    cout << "无效选择，请重新输入" << endl;
            }
        }
    }
    
    return 0;
}