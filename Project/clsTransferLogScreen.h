#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << left << setw(8) << left << "";
        cout << "| " << left << setw(25) << left << TransferLogRecord.DateTime;
        cout << "| " << left << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << left << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << left << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << left << setw(10) << left << TransferLogRecord.srcBalanceAfter;
        cout << "| " << left << setw(10) << left << TransferLogRecord.destBalanceAfter;
        cout << "| " << left << setw(10) << left << TransferLogRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "";
        cout << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

