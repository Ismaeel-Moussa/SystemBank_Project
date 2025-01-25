#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short LoginFaildTrials = 3;

		string UserName, Password;

		do
		{
			if (LoginFaild)
			{
				LoginFaildTrials--;
				cout << "\nInvalid UserName/Password!\n";
				cout << "You have " << LoginFaildTrials << " Trial(s) to login.\n";

			}

			if (LoginFaildTrials == 0)
			{
				cout << "\n\nYour are Locked after 3 faild trail(s)\n\n";
				return false;
			}

			cout << "\nEnter UserName? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);


		CurrentUser.RegisterLogIn(); 
		clsMainScreen::ShowMainMenue();
		return true;
	}


public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}


};

