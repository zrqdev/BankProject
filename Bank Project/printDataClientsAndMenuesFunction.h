#pragma once

#include <iostream>
#include <iomanip>
#include "inpoutsFuntion.h"

using namespace std;

//This file is responsible for printing messages and some data
namespace PrintDataClientsAndMenues
{
	inline void titelsMenue(string Message)
	{
		system("cls");
		cout << "---------------------------------------------------\n\n";
		cout << "\t\t" << Message;
		cout << "\n\n---------------------------------------------------\n";
	}

	inline void mainInfoNames()
	{
		system("cls");
		cout << "===========================================================================================\n";
		cout << "| ";
		cout << left << setw(15) << "Account Name";
		cout << "| ";
		cout << left << setw(10) << "Pin Code";
		cout << "| ";
		cout << left << setw(20) << "Full Name";
		cout << "| ";
		cout << left << setw(20) << "Phone Number";
		cout << "| ";
		cout << left << setw(15) << "Account Balance";
		cout << "|";
		cout << "\n===========================================================================================\n\n";
	}

	inline void printDataClient(Inpouts::stInfo Info)
	{

		cout << "| ";
		cout << left << setw(15) << Info.accountName;
		cout << "| ";
		cout << left << setw(10) << Info.pinCode;
		cout << "| ";
		cout << left << setw(20) << Info.fullName;
		cout << "| ";
		cout << left << setw(20) << Info.Phone;
		cout << "| ";
		cout << left << setw(15) << Info.accountBalance;
		cout << "|\n";
	}

	inline void printOneDataClint(Inpouts::stInfo Info, string Message)
	{

		cout << Message << "\n";
		cout << "---------------------------------------------------\n";
		cout << "Account Nmae : " << Info.accountName << "\n";
		cout << "Pin Code     : " << Info.pinCode << "\n";
		cout << "Full Name    : " << Info.fullName << "\n";
		cout << "Phone Number : " << Info.Phone << "\n";
		cout << "Account balance : " << Info.accountBalance << "\n";
		cout << "---------------------------------------------------\n";
	}

	inline short actions(string Message, bool Active = true)
	{
		system("cls");
		short Action;
		string Ask = "";

		if (Active) {
			cout << "\t" << Message << "\n";
			cout << "=================================\n\n";
			cout << "\t1 => Show Client List.\n";
			cout << "\t2 => Add New Client\n";
			cout << "\t3 => Delete Client.\n";
			cout << "\t4 => Update Client info.\n";
			cout << "\t5 => Find Client.\n";
			cout << "\t6 => Transactions.\n";
			cout << "\t7 => Exit\n\n";
			cout << "=================================\n";
			Ask = "Choose What do you want to do? [1 to 7]?";
		}
		else {

			cout << "\t" << Message << "\n";
			cout << "=================================\n\n";
			cout << "\t1 => Deposit.\n";
			cout << "\t2 => Withdraw\n";
			cout << "\t3 => Total Balance.\n";
			cout << "\t4 => Main Menue\n\n";
			cout << "=================================\n";

			Ask = "Choose What do you want to do? [1 to 4]?";
		}

		Action = Inpouts::inpouts_short_user(Ask);
		return Action;
	}

}
