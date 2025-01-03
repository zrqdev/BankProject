#pragma once

#include <iostream>
#include <string>

using namespace std;

//This file is responsible for taking the data from the user.

namespace Inpouts
{
	inline char inpouts_char_user(string Message)
	{

		char Char = 0;

		cout << Message << "\n";
		cin >> Char;

		return Char;
	}

	inline int inpouts_int_user(string Message)
	{

		int Number = 0;

		cout << Message << "\n";
		cin >> Number;

		return Number;
	}

	inline short inpouts_short_user(string Message)
	{

		short Number = 0;

		cout << Message << "\n";
		cin >> Number;

		return Number;
	}

	inline float inpouts_float_user(string Message)
	{

		float Number = 0;

		cout << Message << "\n";
		cin >> Number;

		return Number;
	}

	inline string inpouts_string_user(string Message)
	{
		string Word = "";

		cout << Message << "\n";
		getline(cin >> ws, Word);

		return Word;
	}

	struct stInfo
	{
		string accountName;
		string pinCode;
		string fullName;
		string Phone;
		float accountBalance = 0;
	};


	//This function is responsible for converting string to strcat.

	inline stInfo converStringTostInfo(string Line, string S, bool Active = true)
	{

		stInfo Info;
		int Pos = static_cast<int>(Line.find(S));

		Info.accountName = Line.substr(0, Pos);
		Line.erase(0, Pos + S.length());
		Pos = static_cast<int>(Line.find(S));

		if (Active)
		{
			Info.pinCode = Line.substr(0, Pos);
			Line.erase(0, Pos + S.length());
			Pos = static_cast<int>(Line.find(S));

			Info.fullName = Line.substr(0, Pos);
			Line.erase(0, Pos + S.length());
			Pos = static_cast<int>(Line.find(S));

			Info.Phone = Line.substr(0, Pos);
			Line.erase(0, Pos + S.length());
			Pos = static_cast<int>(Line.find(S));

			Info.accountBalance = stof(Line.substr(0, Pos));
			Line.erase(0, Pos + S.length());
			Pos = static_cast<int>(Line.find(S));
		}

		return Info;
	}

}