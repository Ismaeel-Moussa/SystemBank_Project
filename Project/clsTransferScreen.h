#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number To Transfer " << Message << ": ";
        cin >> AccountNumber;

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.";
            AccountNumber = _ReadAccountNumber("Please enter another one: ");
        }
        return AccountNumber;
    }

    static double _ReadAmount(clsBankClient SourceClient)
    {
        double Amount;
        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadNumber<double>();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the availabe Balance, Enter another Amount ?";
            Amount = clsInputValidate::ReadNumber<double>();
        }

        return Amount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\tTransfer Screen");

        string AccoutNumberOfSC = _ReadAccountNumber("From");
        clsBankClient SourceClient = clsBankClient::Find(AccoutNumberOfSC);
        _PrintClient(SourceClient);


        string AccoutNumberOfDC = _ReadAccountNumber("To");

        while (AccoutNumberOfSC == AccoutNumberOfDC)
        {
            cout << "\nThey are same Account, Enter another one :\n";
            AccoutNumberOfDC = _ReadAccountNumber("To");
        }

        clsBankClient DestinationClient = clsBankClient::Find(AccoutNumberOfDC);
        _PrintClient(DestinationClient);

        double Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation ?";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nTransfer done Successfully.\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }

        }
        
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);

    }
};

