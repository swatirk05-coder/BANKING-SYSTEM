#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class BankAccount{
    
   string type;
   string accountNumber;
   string name;
   int age;
   double balance;
   int password;
   string status;
   
   string AccountNumber(){
       string num;
       num = num + to_string(1+rand() % 9);
       for(int i=1;i<=11;i++){
           num = num + to_string(rand() % 10);
       }   
       return num;
   }
   
   string Status(){
       if(age < 18){
           return "Inactive";
       }
       else if(balance < 2500 ){
           return "Inactive";
       }
       else{
           return "Active";
       }
   }
   
   public:
   
   BankAccount(string type, string name, int age, double balance, int password){
       this->type=type;
       this->accountNumber = AccountNumber();
       this->name = name;
       this->age = age;
       this->balance = balance;
       this->password=password;
       this->status = Status();
   }
   
   string getAccountNumber(){
       return accountNumber;
   }
   
   string getType(){
       return type;
   }
   
   string getName(){
       return name;
   }
   
   int getAge(){
       return age;
   }
   
   double getBalance(){
       return balance;
   }
   
   int getPassword(){
       return password;
   }
   
   string getStatus(){
       return status;
   }
   
   void deposit(double amount, int p){
       
         if(this->password == p){ 
       
       if(status == "Inactive"){
           cout << "Deposit decline, your account is inactive" << endl;
       }
            if(amount < 0){
             cout << "Enter the amount " << endl;
           }
           else if(amount > 0){
               balance = balance + amount;
               cout <<" Amount credited successfully" << endl;
           }
         }
         if(this->password!=p){
             cout << "Your pin is incorrect" << endl;
         }
       }
       
       void withdrawl(double amount, int p){
          if(this->password == p){  
         if(status == "Inactive"){
           cout << "debite decline, your account is inactive" << endl;
       }
       if(amount <= balance){
           balance = balance - amount;
           cout << "Amount debited successfully" << endl;
       }
       else if(amount > balance) {
           cout << "Insuffecient balance" << endl;
       }
          }
          if(this->password!=p){
             cout << "Your pin is incorrect" << endl;
         }
       }
          
       
       void transfer(BankAccount &account2 , double amount, int p){
           if(this->password == p){ 
          if(status == "Inactive"){
           cout << "debite decline, your account is inactive" << endl;
       }
       if(amount > balance){
           cout << "Insuffecient balance" << endl;
       }
       else if(amount <= balance){
           balance = balance - amount;
           account2.balance= account2.balance + amount;
           cout << "transfer successful" << endl;
       }
           }
           if(this->password!=p){
             cout << "Your pin is incorrect" << endl;
         }
           
       
       }
       
       void display(int p){
           if(this->password == p){ 
            cout << "Account Type:" << type << endl;   
           cout << "Account Number:" << accountNumber << endl;
           cout << "Name:" << name << endl;
           cout << "Age:" << age << endl;
           cout << "Balance:" << balance << endl;
           cout << "Status:" << status << endl;
       }
       if(this->password!=p){
             cout << "Your pin is incorrect" << endl;
         }
       }
       
}; 

int main(){
    srand(time(0));
    string type;
    string name;
    int age;
    double balance;
    int password;
    int choose;
    double amount;
    
    cout <<"------Bank Account Opening Form------" << endl;
    
    cout << "Enter the Account type:";
    cin >> type;
    
    cout << "Enter the Account holder name:" ;
    cin >> name;
    
    cout << "Enter the age:" ;
    cin >> age;
    
    cout << "Enter the initial balance:";
    cin >> balance;
    
    cout << "create your pin:";
    cin >> password;
    
    cout << "Account created successfully" << endl;
    
    BankAccount account1(type, name, age, balance, password);
    
    BankAccount account2("saving", "Suraj", 34, 30000, 123456);
    
    do{
        cout << "------MENU------" << endl;
        cout << "1. See your details" << endl;
        cout << "2. See details of account 2" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. withdrawl" << endl;
        cout << "5. Transfer fund" << endl;
        cout << "6. Check balance" << endl;
        cout << "7. Exit" << endl;
        cout << "enter the no. you want see:";
        cin >> choose;
        
        switch(choose){
            case 1:
            cout << "enter the pin:";
            cin >>password;
            account1.display(password);
            break;
            
            case 2:
            cout << "enter the pin:";
            cin >>password;
            account2.display(123456);
            break;
            
            case 3:
            cout << "Enter the amount you want to deposit" << endl;
            cin >> amount;
            cout << "enter the pin:";
            cin >>password;
            account1.deposit(amount, password);
            break;
            
            case 4:
            cout << "Enter the amount you want to withdrawl" << endl;
            cin >> amount;
            cout << "enter the pin:";
            cin >>password;
            account1.withdrawl(amount, password);
            break;
            
            case 5:
            cout << "Enter the amount you want to transfer" << endl;
            cin >> amount;
            cout << "enter the pin:";
            cin >>password;
            account1.transfer(account2, amount, password);
            break;
            
            case 6:
            cout << "Your balance:" << account1.getBalance() << endl;
            break;
            
            case 7:
            cout << "Thank you" << endl;
            break;
            
            default:
            cout << "wrong option" << endl;
            break;
        }
            
    }  while(choose !=7);
    
    return 0;
}