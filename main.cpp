/*
Krrishiv Kohli
Jash Patel
2/10/2022
Going beyond the Bank Project
Extras: 
- We Added an option to the menu called account settings where user can change account type or delete account. 
- We also used file authentication for our preset account for log in option. 
- We also gave the user a menu to choose from if they made a transaction over 5k
- 
*/

#include <iostream>
#include <string>
#include "GetData.h"
#include <iostream>
#include <fstream>
// Add all other needed header files

using namespace std;

int main()
{
  //Creating variables
  bool runAgain = true, runAgain2 = false, runAgain3 = false, runAgain4 = false, runAgain5 = true, runAgain6 = true, useName1 = false, passWord1 = false, accountInfo = true;
  //declaring all the int variables
  int answer, answer2, account, iSecret, accounttype2, why1, why2;
  //declaring all the string variables 
  string answer3 = "n", answer4 = "n", answer5 = "n", userName, password, name1 = "Transaction History", name2 = "Account Information", name3 = "Account Settings", name4 = "Withdraw from Amount", name5 = "Deposit to Amount", dummy = " ", accountType = "Checking Account";

  //Variables for log in and sign up
  double accountBalance, accountBal = 250;
  bool eitherOr = true, either2Or;

  // Create and open a text file
  ofstream Account1("Account1.txt");
  ofstream Account2("Account2.txt");

  //Text file for transaction history
  ofstream transactionHistory("Transaction History.txt");

  cout << "Welcome to the Morris County Nation Bank Denville Branch!\n" << endl;

  do {
    //Error trapping users response to program does not crash
    do {
      cout << "Please choose an option to proceed: \n1) Sign up for an Account\n2) Log in to Account\n";
    } while(!(getValidInt(account) || account > 2 || account < 0));

    if (account == 1) {
      cout << "\nPlease enter a username here: ";
      cin >> userName;

      cout << "Please enter a strong password: ";
      cin >> password;
      getline(cin, dummy);

      cout << "\nJust a reminder that all new users signing up recieve a checking account with $250 already in it!\n";

      //Calling function that signs the user up for an account
      // writing to the account2 file... the file will store username and password
      //generate random number for account numb: 
      int iSecret = rand() % 100 + 1;
      Account2 << "Account Number: " << iSecret;
      Account2 << "\nUser Name: " << userName;
      Account2 << "\nPassword: " << password;
      //Must change to actual variable for balance
      accountBalance = 250;
      Account2.close();

      transactionHistory << "Transaction History for: " << userName << endl << endl;

      eitherOr = false;
      either2Or = false;
      useName1 = true;
      passWord1 = true;
    }

    else if(account == 2) {
      cout << "\nPlease enter your username here: ";
      cin >> userName;
      cout << "Please enter your password: ";
      cin >> password;
      getline(cin, dummy);
      
      //generate random number for account numb: 
      iSecret = rand() % 100 + 1;
      //The correct username and password
      string accountUsername = "jk";
      string accountPassword = "69";
      Account1 << "Account Number: " << iSecret;
      Account1 << "\nUser Name: " << accountUsername;
      Account1 << "\nPassword: " << accountPassword;
      //Must change to actual variable for balance
      accountBalance = 100000;
      //closing the text file
      Account1.close();

      transactionHistory << "Transaction History for: " << accountUsername << endl << endl;
      //this block of code will be executed only when the user inputs the correct username/password
      if (userName == accountUsername && password == accountPassword) {
        cout << "\nLog in succesful!";
        accountBalance = 100000;
        useName1 = true;
        passWord1 = true;
      }
      else if (userName != accountUsername) {
        cout << "\nInvalid User Name" << endl;
        useName1 = false;
      }
      else if (password != accountPassword) {
        cout << "\nInvalid password";
        passWord1 = false;
      }

      eitherOr = true;
      either2Or = true;
    }
  } while (useName1 == false || passWord1 == false);
  
  //Error trapping
  do {
      do {
        cout << "\n\n---- MAIN MENU ----\n" << endl;
        //3 Options for user
        cout << "1. Account Settings" << endl; //Still in development 
        cout << "2. Account Information" << endl;
        cout << "3. Withdraw from Amount" << endl;
        cout << "4. Deposit to Amount" << endl;
        cout << "5. Transaction History" << endl;
        cout << "6. Quit" << endl;
        cout << "\nPlease choose an option from the menu: ";
      } while (!(getValidInt(answer) || answer > 6 || answer < 0));

      if (answer == 1) {
        do {
          do {
            cout << "\nAccount Settings for: " << userName << endl;
            cout << "1. Change Account Type" << endl;
            cout << "2. Delete Account" << endl;
            cout << "3. Back to Main Menu" << endl;
            cout << "\nPlease choose an option from the menu: ";
          } while (!(getValidInt(answer2) || answer > 3 || answer < 0));
                                                          
          if (answer2 == 1) {
            do {
              cout << "\nACCOUNT TYPES" << endl;
              cout << "1) Banking Account \n2) Checking Account (Default)\n3) Money Market Account (MMA) \n4) Salary Account";
              cout << "\nWhich account type would you like? ";
            } while (!(getValidInt(accounttype2) || answer > 4 || answer < 0));
            
            if (accounttype2 == 1) {
              accountType = "Banking Account";
            }

            else if (accounttype2 == 2) {
              accountType = "Checking Account";
            }
            
            else if (accounttype2 == 3) {
              accountType = "Money Market Account";
            }

            else if (accounttype2 == 4) {
              accountType = "Salary Account";
            }

            cout << "Your Account Type had been updated! Check Account Information to view it" << endl;
          }

          if (answer2 == 2) {
            cout << "\nAre you sure about that? (y/n): ";
            cin >> answer5;
            getline(cin, dummy);
            
            if (answer5 == "y" || answer5 == "Y") {
              runAgain = false;
              runAgain5 = false;
              transactionHistory.close ();
              remove("Account2.txt");
              remove("Account1.txt");
              remove("Transaction History.txt");
              cout << endl << "Account Deleted!\nGoodbye! Thank you for using our application!";
              runAgain = false;
            }
            else {
              accountInfo = true;
            }
          }

          if (answer2 == 3) {
            accountInfo = false;
          }
        } while (accountInfo == true);
      }
  
      if (answer == 2) {
          do {
            //running the account information worksheet
            if (either2Or == true) {
              // Create a text string, which is used to output the text file
              string myText;
              // Read from the text file
              ifstream MyReadFile("Account1.txt");
              
              while (getline (MyReadFile, myText)) {
                // Output the text from the file
                cout << myText << endl;
              }

              cout << "Account type: " << accountType << endl;
              cout << "Account Balance: $" << accountBalance << endl; 
            }

            else if (either2Or == false) {
              // Create a text string, which is used to output the text file
              string myText2;
              // Read from the text file
              ifstream MyReadFile("Account2.txt");
              
              while (getline (MyReadFile, myText2)) {
                // Output the text from the file
                cout << myText2 << endl;
              }

              cout << "Account type: " << accountType << endl;
              cout << "Account Balance: $" << accountBalance << endl; 
            }

            //Asking user if they want to see their account again
            cout << "\nPress y/Y to view again. Any other character to proceed: ";
            cin >> answer3;
            getline(cin, dummy);
            if (answer3 == "y" || answer3 == "Y") {
              runAgain2 = true;
            }
            else {
              runAgain2 = false;
            }
          } while (runAgain2 == true);
      }

      if (answer == 3) {
        do {
          //Running withdrawl program
          double withdrawedAmount;
          string answer;
          bool runAgain = true;
          //Declaring Variables
          cout << "Current Account balance: $" << accountBalance << endl;
          do {
            cout << "Please enter the amount you want to withdraw from your account: ";
          } while (!(getValidDouble(withdrawedAmount)));

          //Checking if user can deposit this much
          if (withdrawedAmount >= 5000) {
            cout << "Uh Oh!\nYou can not deposit more than $5000 into your account\nWould you mind taking a short survey on the reason behind your deposit?\n";

            //Can ask user reasons for deposit over 5k here:
            do {
              cout << "1. There is a medical emergancy in which you need money" << endl;
              cout << "2. You are a gambler and want more money to spend" << endl;
              cout << "3. You wish to purchase something expansive for family or friends" << endl;
              cout << "4. You are just unresponsible with money" << endl;
              cout << "5. Other\n" << endl;
              cout << "Please choose an option from the menu: ";
            } while (!(getValidInt(why1) || why1 > 5 || why1 < 0));
            
            if (why1 == 1 || why1 == 3) {
              cout << "You must be a very kind individual, however we do not offer transactions over 5k online.\nYou must come into our office to complete this transaction." << endl;
            }

            else if (why1 == 2 || why1 == 4) {
              cout << "Well thats not good! You should learn to be more responsible with money!" << endl;
            }


            else if (why1 == 5) {
              cout << "\nPlease enter your reason why: ";
              getline(cin, dummy);

              cout << "We understand, however we do not offer transactions over 5k online.\nYou must come into our office to complete this transaction." << endl;
            }
          }

          else if (withdrawedAmount > 0 && withdrawedAmount <= accountBalance){ 
            accountBalance = accountBalance - withdrawedAmount;
            cout << "The transaction is complete...\nCurrect Balance: $" << accountBalance << endl; 
          }

          else if (withdrawedAmount < 0) {
            cout << "You cant withdraw a negative amount silly!" << endl;
            runAgain = true;
          }

          else if (withdrawedAmount > accountBalance) {
            cout << "\nYou can not withdraw more money than your current balance... you would be in debt" << endl;
          }

          //Adding withdrawl to transaction history: 
          transactionHistory << "\nTransaction type: Withdrawl from account";
          transactionHistory << "\n Withdrawl Amount: " << withdrawedAmount;
          transactionHistory << "\nTransaction status: Completed\n" << endl;

          //Asking user if they want to withdraw from their account again
          cout << "\nPress y/Y to withdraw again. Any other character to proceed: ";
          cin >> answer4;
          getline(cin, dummy);
          if (answer4 == "y" || answer4 == "Y") {
            runAgain3 = true;
          }
          else {
            runAgain3 = false;
          }
        } while (runAgain3 == true);
      }

    if (answer == 4) {
      do {
        //Running the deposit to amount code
        //deposit an account
        double depositAmount;
        string answer;
        bool runAgain = true;
        //Declaring Variables
        cout << "Current Account balance: $" << accountBalance << endl;
        do {
          cout << "Please enter the amount you want to deposit into your account: ";
        } while (!(getValidDouble(depositAmount)));

        //Checking if user can deposit this much
        if (depositAmount >= 5000) {
          cout << "Uh Oh!\nYou can not deposit more than $5000 into your account\nWould you mind taking a short survey on the reason behind your deposit?" << endl;

          //Can ask user reasons for deposit over 5k here:
          do {
            cout << "1. You have a high income and you are depositing a lot of money because you are wealthy\n";
            cout << "2. You recently made a huge profit from your business and you want to deposit the money you just made\n";
            cout << "3. You like to deposit large amoounts of money at once because you want to avoid transactions\n";
            cout << "4. You are involved in a money laundering incident so you have a lot of cash from that\n";
            cout << "5. Other" << endl;
            cout << "\nPlease choose an option from the menu: ";
          } while (!(getValidInt(why2) || why2 > 5 || why2 < 0));
          
          if (why2 == 1 || why2 == 2) {
            cout << "Congratulations! however we do not offer transactions over 5k online.\nYou must come into our office to complete this transaction." << endl;
          }

          else if (why2 == 3) {
            cout << "Well thats not good! You should learn to be more responsible with money!" << endl;
          }

          else if (why2 == 4) {
            cout << "That is not cool. Be a better person and do the right thing next time. We will not make this transaction.";
          }

          else if (why1 == 5) {
            cout << "\nPlease enter your reason why: ";
            getline(cin, dummy);

            cout << "We understand, however we do not offer transactions over 5k online.\nYou must come into our office to complete this transaction." << endl;
          }
        }

        else if (depositAmount > 0 && depositAmount <= 5000){ 
          //adding the deposit amount
          accountBalance += depositAmount;
          cout << "The transaction is complete...\nCurrect Balance: $" << accountBalance << endl; 
        }

        //this will run when the deposit amount is negative
        else if (depositAmount < 0) {
          cout << "You cant deposit a negative amount silly!";
          runAgain = true;
        }

        else {
          runAgain = false;
        }

        //Adding withdrawl to transaction history: 
        transactionHistory << "\nTransaction type: Deposit to account";
        transactionHistory << "\n Deposit Amount: " << depositAmount;
        transactionHistory << "\nTransaction status: Completed\n" << endl;

        //Asking user if they want to deposit in their account again again
        cout << "\nPress y/Y to deposit again. Any other character to proceed: ";
        cin >> answer5;
        getline(cin, dummy);
        if (answer5 == "y" || answer5 == "Y") {
            runAgain4 = true;
        }
        else {
          runAgain4 = false;
        }
      } while (runAgain4 == true);
    }

    if (answer == 5) {
      do {
        //Add code here:
        // Create a text string, which is used to output the text 
        string myText2;
        // Read from the text file
        ifstream MyReadFile("Transaction History.txt");
              
        cout << endl;
        
        while (getline (MyReadFile, myText2)) {
          // Output the text from the file
          cout << myText2 << endl;
        }

        cout << "Current account Balance: $" << accountBalance << endl; 

        //Asking user if they want to deposit in their account again again
        cout << "\nPress y/Y to view transaction history again. Any other character to proceed: ";
        cin >> answer5;
        getline(cin, dummy);
        if (answer5 == "y" || answer5 == "Y") {
            runAgain6 = true;
        }
        else {
          runAgain6 = false;
        }
      } while (runAgain6 == true);
    }

    if (answer == 6) {
      //quitting
      cout << "\nAre you sure about that? (y/n): ";
      cin >> answer5;
      getline(cin, dummy);
      if (answer5 == "y" || answer5 == "Y") {
            runAgain = false;
            runAgain5 = false;
            transactionHistory.close ();
            //deleting the text files 
            remove("Account2.txt");
            remove("Account1.txt");
            remove("Transaction History.txt");
            cout << endl << "Goodbye! Thank you for using our application!";
        }
        else {
          runAgain5 = true;
        }
    }
    //Asking user if they want to run again
  } while (runAgain == true);
}