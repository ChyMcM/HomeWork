#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include "Inheritance2.h"
#include <fstream>

int main()
{
    int choice = 0;
    float checkacc = float(rand());
    CheckingAccount* check = new CheckingAccount();
    check->setbalance(checkacc);
    float savinacc = float(rand());
    SavingsAccount* save = new SavingsAccount();
    save->setbalance(savinacc);
    float credacc = float(rand());
    CreditAccount* cred = new CreditAccount();
    cred->setbalance(credacc);
    while (choice != 5)
    {
        std::cout << "1. Checking\n2. Savings\n3. Credit\n4. Send to file\n5. Exit\nWhat would you like to do today?\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            std::cout << "Your checking account balance is " << check->getbalance() << ". Would you like to 1. deposit or 2. withdraw today?";
            int cho;
            std::cin >> cho;
            if (cho == 1)
            {
                std::cout << "How much are you depositing today?";
                float amo;
                std::cin >> amo;
                check->deposit(amo);
                std::cout << "Your new balance is " << check->getbalance() << ". Have a nice day!";
                break;
            }
            else if (cho == 2)
            {
                std::cout << "How much are you withdrawing today?";
                float amou;
                std::cin >> amou;
                check->withdraw(amou);
                std::cout << "Your new balance is " << check->getbalance() << ". Have a nice day!";
                break;
            }
            else
            {
                break;
            }
        case 2:
            system("cls");
            std::cout << "Your savings account balance is " << save->getbalance() << ". Would you like to 1. deposit or 2. withdraw today?\n";
            int choy;
            std::cin >> choy;
            if (choy == 1)
            {
                std::cout << "How much are you depositing today?\n";
                float amoy;
                std::cin >> amoy;
                save->deposit(amoy);
                std::cout << "Your new balance is " << save->getbalance() << ". Have a nice day!\n";
                break;
            }
            else if (choy == 2)
            {
                std::cout << "How much are you withdrawing today?\n";
                float amouy;
                std::cin >> amouy;
                save->withdraw(amouy);
                std::cout << "Your new balance is " << save->getbalance() << ". Have a nice day!\n";
                break;
            }
            else
            {
                break;
            }
        case 3:
            system("cls");
            std::cout << "Your credit account has " << cred->getbalance() << " availible. Would you like to 1. make payment or 2. withdraw today?\n";
            int chom;
            std::cin >> chom;
            if (chom == 1)
            {
                std::cout << "How much are you payinhg today?\n";
                float amot;
                std::cin >> amot;
                cred->deposit(amot);
                std::cout << "Your new availible balance is " << cred->getbalance() << ". Have a nice day!\n";
                break;
            }
            else if (chom == 2)
            {
                std::cout << "How much are you withdrawing today? Don't forget if you spend more then 40 dollars, your account charges a fee of 5000!\n";
                float amout;
                std::cin >> amout;
                cred->withdraw(amout);
                std::cout << "Your new availible balance is " << cred->getbalance() << ". Have a nice day!\n";
                break;
            }
            else
            {
                break;
            }
        case 4:
            std::ofstream outfile;
            outfile.open("totals.txt");
            outfile << "Checkings Balance: " << check->getbalance() << "\nSavings Balance: " << save->getbalance() << "\nAvailible Credit: " << cred->getbalance();
            outfile.close();
        }
    }
    if (choice == 5)
    {
        exit(0);
    }
}
