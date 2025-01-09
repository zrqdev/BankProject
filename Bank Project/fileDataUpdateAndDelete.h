#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "inpoutsFuntion.h"

//This file is responsible for filling the data in the Clinte file

using namespace std;

string S = "#//#";
string nameFile = "Client.txt";

namespace FileDataUpdateAndDelete
{
	//This function is responsible for converting Strcat to String
	string convertInfoToLine(Inpouts::stInfo Info, string S)
	{
		return Info.accountName + S + Info.pinCode + S + Info.fullName + S + Info.Phone + S + to_string(Info.accountBalance);
	}






	//This function is responsible for deleting and updating the data in the file
	void fillDataInFileAndUbdate(Inpouts::stInfo Info, string Line, string S, vector<Inpouts::stInfo> infoClients, string updateOrDeleteUser, bool ActiveFunction = true, bool deletOrUpdate = true)
	{
		fstream file;

		if (ActiveFunction)
		{
			//This is section for filling The data in Client file 
			file.open(nameFile, ios::out | ios::app);

			if (file.is_open())
			{
				file << Line << "\n";
			}
		}
		else
		{
			// This is section for updating client data
			file.open(nameFile, ios::out);

			if (deletOrUpdate)
			{

				for (int i = 0; i < infoClients.size(); i++)
				{

					if (infoClients.at(i).accountName == updateOrDeleteUser)
					{
						Line = updateOrDeleteUser;
						Line += convertInfoToLine(Info, S);
						file << Line << "\n";
					}
					else
					{
						Line = convertInfoToLine(infoClients.at(i), S);
						file << Line << "\n";
					}
				}
			}
			else
			{
				// This is scetion for deleting client data
				for (int i = 0; i < infoClients.size(); i++)
				{

					if (infoClients.at(i).accountName == updateOrDeleteUser)
					{
						continue;
					}
					else
					{
						Line = convertInfoToLine(infoClients.at(i), S);
						file << Line << "\n";
					}
				}
			}
		}

		file.close();
	}


	// This function is responsible for diposit and withdraw.
	void depositOrWithdraw(Inpouts::stInfo Info, string Line, string S, string accountName, vector<Inpouts::stInfo> infoClients, float depositOrWithdraw, bool Active = true) {


		fstream file;


			file.open(nameFile, ios::out);

			for (int i = 0; i < infoClients.size(); i++)
			{
				if (accountName == infoClients.at(i).accountName)
				{
					if (Active)
						infoClients.at(i).accountBalance += depositOrWithdraw;
					else {
						infoClients.at(i).accountBalance -= depositOrWithdraw;

					}
					Line = convertInfoToLine(infoClients.at(i), S);
					file << Line << "\n";
				}
				else
				{
					Line = convertInfoToLine(infoClients.at(i), S);
					file << Line << "\n";
				}
			}




		}







		//Thes funtion is responsible for filling the array vector. 
		vector<Inpouts::stInfo> fillDataInVector(string Line, string S)
		{
			vector<Inpouts::stInfo> infoClients;
			Inpouts::stInfo Info;
			fstream file(nameFile);

			if (file.is_open())
			{
				while (getline(file >> ws, Line))
				{
					Info = Inpouts::converStringTostInfo(Line, S);
					infoClients.push_back(Info);
				}
			}

			file.close();

			return infoClients;
		}

	}
