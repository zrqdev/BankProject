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
static bool checkAndDeleteClients(vector<Inpouts::stInfo>& infoClients, string& DeleteUser, Inpouts::stInfo& Info)
{
	Info;
	for (int i = 0; i < infoClients.size(); i++)
	{

		if (infoClients.at(i).accountName == DeleteUser)
		{

			Info = infoClients.at(i);
			return true;
		}
	}

	return false;
}

//This function is responsible for starting the app
static void startApp(short actionUser, Inpouts::stInfo Info, string Line, string S, char newAdd, char YorN, vector<Inpouts::stInfo> infoClients, string deleteUser, string updateUser, string findUser)
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

				FileDataUpdateAndDelete::fillDataInFileAndUbdate(Info, Line, S, infoClients, deleteUser);

				newAdd = Inpouts::inpouts_char_user("Do you want to add new Client? Y/N :");

			} while (toupper(newAdd) == 'Y');
		}
		else if (actionUser == 3)
		{
			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Delete Client Screen");

			deleteUser = Inpouts::inpouts_string_user("Please enter Account Name : ");

			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			if (checkAndDeleteClients(infoClients, deleteUser, Info))
			{

				PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client datails.");

				YorN = Inpouts::inpouts_char_user("Are you sure want delete this client : Y/N ");

				if (toupper(YorN) == 'Y')
				{

					FileDataUpdateAndDelete::fillDataInFileAndUbdate(Info, Line, S, infoClients, deleteUser, false, false);
					cout << "\nClient Delete Successfully.\n\n";
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "Client with Account Name " << deleteUser << " is not find\n";
			}

			system("pause");
		}
		else if (actionUser == 4)
		{

			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Update Client Screen");

			updateUser = Inpouts::inpouts_string_user("Please enter Account Name : ");

			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			if (checkAndDeleteClients(infoClients, updateUser, Info))
			{

				PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client update.");

				YorN = Inpouts::inpouts_char_user("Are you sure want update info this client : Y/N ");

				if (toupper(YorN) == 'Y')
				{

					Info = clientInfo(infoClients, Line, S, false);

					FileDataUpdateAndDelete::fillDataInFileAndUbdate(Info, Line, S, infoClients, updateUser, false);

					cout << "\nClient Update Successfully.\n\n";
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "Client with Account Name " << updateUser << " is not find\n";
			}

			system("pause");
		}
		else if (actionUser == 5)
		{

			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Find Client Screen");

			findUser = Inpouts::inpouts_string_user("Please enter Account Name : ");
			infoClients = FileDataUpdateAndDelete::fillDataInVector(Line, S);

			if (checkAndDeleteClients(infoClients, findUser, Info))
			{
				PrintDataClientsAndMenues::printOneDataClint(Info, "The following are the client update.");
			}
			else
			{
				cout << "Client with Account Name " << findUser << " is not find\n";
			}

			system("pause");
		}
		else
		{
			system("cls");
			PrintDataClientsAndMenues::titelsMenue("Program Ends :)");
			break;
		}
	} while (actionUser != 6);
}

int main()
{
	// This is the variable section 
	short actionUser = 1;
	string DeleteUser, updateUser, findUser;
	Inpouts::stInfo Info;
	string Line = "";
	const string S = "#//#";
	char newAdd = 'Y';
	char YorN = 'Y';
	vector<Inpouts::stInfo> infoClients;

	startApp(actionUser, Info, Line, S, newAdd, YorN, infoClients, DeleteUser, updateUser, findUser);

	return 0;
}