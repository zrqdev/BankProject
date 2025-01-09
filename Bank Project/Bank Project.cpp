#include "inpoutsFuntion.h"
#include "fileDataUpdateAndDelete.h"
#include "printDataClientsAndMenuesFunction.h"


// This function is responsible for checking duplicate names.

static bool checkAccountName(vector<Inpouts::stInfo> accountsName, Inpouts::stInfo Info)
{

	for (int i = 0; i < accountsName.size(); i++)
	{
		if (accountsName.at(i).accountName == Info.accountName)
		{
			return true;
		}
	}

	return false;
}


//This function is responsible for taking data frome the user and reteurn strcat

static Inpouts::stInfo clientInfo(vector<Inpouts::stInfo> accountsName, string Line, string S, bool activeName = true)
{
	Inpouts::stInfo Info;
	bool check;
	if (activeName)
	{
		FileDataUpdateAndDelete::fillDataInVector(Line, S);

		do
		{
			Info.accountName = Inpouts::inpouts_string_user("Plese enter account Name.");
			check = checkAccountName(accountsName, Info);

			if (check)
			{
				cout << "client with [" << Info.accountName << "] already eixsts, ";
			}

		} while (check);
	}



	do
	{
		Info.pinCode = Inpouts::inpouts_string_user("Plese enter Pin Code.");


		if (Info.pinCode.length() < 3 || Info.pinCode.length() > 4) {
			cout << "The PIN code is incorrect, ";
		}

	} while (Info.pinCode.length() < 3 || Info.pinCode.length() > 4);



	Info.fullName = Inpouts::inpouts_string_user("Plese enter Full Name.");


	do
	{

		Info.Phone = Inpouts::inpouts_string_user("Plese enter Phone Number.");

		if (Info.Phone.length() < 10 || Info.Phone.length() > 12) {
			cout << "The wrong phone number, ";
		}

		if (Info.Phone.length() == 12) {
			Info.Phone = "+" + Info.Phone;
			break;
		}

	} while (Info.Phone.length() < 10 || Info.Phone.length() > 12);


	Info.accountBalance = Inpouts::inpouts_float_user("Plese enter Account Balance.");

	return Info;
}

//This function is responsible for deleting the clients and returns True or false
static bool checkAndDeleteClients(vector<Inpouts::stInfo>& infoClients, string& accountName, Inpouts::stInfo& Info)
{
	Info;
	for (int i = 0; i < infoClients.size(); i++)
	{

		if (infoClients.at(i).accountName == accountName)
		{

			Info = infoClients.at(i);
			return true;
		}
	}

	return false;
}

//This function is responsible for starting the app
static void startApp(short actionUser, Inpouts::stInfo Info, string Line, string S, char newAdd, char YorN, vector<Inpouts::stInfo> infoClients, string accountName, float depositOrWithdraw)
{
	do
	{
		actionUser = PrintDataClientsAndMenues::actions("Main Menue Screen");

		if (actionUser == 1)
		{
			system("cls");

			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			PrintDataClientsAndMenues::mainInfoNames();

			for (int i = 0; i < infoClients.size(); i++)
			{
				PrintDataClientsAndMenues::printDataClient(infoClients.at(i));
			}
			cout << "\n===========================================================================================\n\n";

			system("pause");
		}
		else if (actionUser == 2)
		{
			do
			{
				system("cls");
				Info = clientInfo(infoClients, Line, S);

				Line = FileDataUpdateAndDelete::convertInfoToLine(Info, S);

				FileDataUpdateAndDelete::fillDataInFileAndUbdate(Info, Line, S, infoClients, accountName);

				newAdd = Inpouts::inpouts_char_user("Do you want to add new Client? Y/N :");

			} while (toupper(newAdd) == 'Y');
		}
		else if (actionUser == 3)
		{
			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Delete Client Screen");

			accountName = Inpouts::inpouts_string_user("Please enter Account Name : ");

			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			if (checkAndDeleteClients(infoClients, accountName, Info))
			{

				PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client datails.");

				YorN = Inpouts::inpouts_char_user("Are you sure want delete this client : Y/N ");

				if (toupper(YorN) == 'Y')
				{

					FileDataUpdateAndDelete::fillDataInFileAndUbdate(Info, Line, S, infoClients, accountName, false, false);
					cout << "\nClient Delete Successfully.\n\n";
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "Client with Account Name " << accountName << " is not find\n";
			}

			system("pause");
		}
		else if (actionUser == 4)
		{

			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Update Client Screen");

			accountName = Inpouts::inpouts_string_user("Please enter Account Name : ");

			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			if (checkAndDeleteClients(infoClients, accountName, Info))
			{

				PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client update.");

				YorN = Inpouts::inpouts_char_user("Are you sure want update info this client : Y/N ");

				if (toupper(YorN) == 'Y')
				{

					Info = clientInfo(infoClients, Line, S, false);

					FileDataUpdateAndDelete::fillDataInFileAndUbdate(Info, Line, S, infoClients, accountName, false);

					cout << "\nClient Update Successfully.\n\n";
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "Client with Account Name " << accountName << " is not find\n";
			}

			system("pause");
		}
		else if (actionUser == 5)
		{

			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Find Client Screen");

			accountName = Inpouts::inpouts_string_user("Please enter Account Name : ");
			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			if (checkAndDeleteClients(infoClients, accountName, Info))
			{
				PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client update.");
			}
			else
			{
				cout << "Client with Account Name " << accountName << " is not find\n";
			}

			system("pause");
		}
		else if (actionUser == 6) {
			do {

				actionUser = PrintDataClientsAndMenues::actions("Transcations Main Menue", false);

				if (1 == actionUser) {

					PrintDataClientsAndMenues::titelsMenue("Deposit Screen");

					accountName = Inpouts::inpouts_string_user("Please enter Account Name : ");

					infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

					if (checkAndDeleteClients(infoClients, accountName, Info)) {

						PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client update.");

						depositOrWithdraw = Inpouts::inpouts_int_user("Please enter deposit amount ?");

						YorN = Inpouts::inpouts_char_user("Are you sure you want perfrom this tracsaction? y/n ?");

						if ('Y' == toupper(YorN)) {
							FileDataUpdateAndDelete::depositOrWithdraw(Info, Line, S, accountName, infoClients, depositOrWithdraw);
						}
						else {
							continue;
						}
					}
					else {
						cout << "Client with Account Name " << accountName << " is not find\n";
					}
					system("pause");
				}
				else if (2 == actionUser) {

					PrintDataClientsAndMenues::titelsMenue("Withdraw Screen");

					accountName = Inpouts::inpouts_string_user("Please enter Account Name : ");


					infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

					if (checkAndDeleteClients(infoClients, accountName, Info)) {

						PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client update.");

						do {

							depositOrWithdraw = Inpouts::inpouts_int_user("Please enter withdraw amount ?");

							YorN = Inpouts::inpouts_char_user("Are you sure you want perfrom this tracsaction? y/n ?");

							if ((Info.accountBalance - depositOrWithdraw) < 0) {

								cout << "Amount Exaceeds tha balance, ";
							}

						} while ((Info.accountBalance - depositOrWithdraw) < 0);

						if ('Y' == toupper(YorN)) {
							FileDataUpdateAndDelete::depositOrWithdraw(Info, Line, S, accountName, infoClients, depositOrWithdraw, false);
						}
						else {
							continue;
						}
					}
					else {
						cout << "Client with Account Name " << accountName << " is not find\n";
					}
	system("pause");

				}
				else if (3 == actionUser) {

					float totalBalances = 0;

					infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

					PrintDataClientsAndMenues::mainInfoNames();

					for (int i = 0; i < infoClients.size(); i++)
					{

						totalBalances += infoClients.at(i).accountBalance;

						PrintDataClientsAndMenues::printDataClient(infoClients.at(i));
					}
					cout << "\n===========================================================================================\n\n";

					cout << "\t\t\tTotal Balances = " << totalBalances << "\n\n";

					system("pause");
				}


			} while (actionUser < 4);
		}

		else
		{
			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Program Ends :)");
			break;
		}
	} while (actionUser != 7);
}

int main()
{
	// This is the variable section 
	short actionUser = 1;
	string accountName;
	Inpouts::stInfo Info;
	string Line = "";
	const string S = "#//#";
	char newAdd = 'Y';
	char YorN = 'Y';
	vector<Inpouts::stInfo> infoClients;
	float depositOrWithdraw = 0;

	startApp(actionUser, Info, Line, S, newAdd, YorN, infoClients, accountName, depositOrWithdraw);

	return 0;
}