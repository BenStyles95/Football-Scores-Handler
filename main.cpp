// LIBRARIES
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// CONSTANTS USED
const int P = 9;	// Players

// MAIN BODY
void main()
{
	struct Statistics
	{
		string T;	// Teams
		int Pl;		// Plays
		int W;		// Wins
		int D;		// Draws
		int L;		// Losses
		int F;		// Goals For
		int A;		// Goals Against
		int Pts;	// Points
	};

	Statistics Teams[P];

	ifstream File("scores.txt");	// Loading Scores From Text File
	if (!File)
	{
		cout << "'Scores.txt' cannot be found." << endl;	// Error Handling
	}
	for (int i = 0; i < P; i++)	// Loading Loop
	{
		File >> Teams[i].T >> Teams[i].Pl >> Teams[i].W >> Teams[i].D >> Teams[i].L >> Teams[i].F >> Teams[i].A >> Teams[i].Pts;
	}

	int loop = 0;	// Menu Loop
	while (loop != 1)
	{
		cout << "Team\t\tP\tW\tD\tL\tF\tA\tPts\n";	// Leaderboard
		for (int i = 0; i < P; i++)
		{
			cout << "\n" << left << setw(11) << Teams[i].T << "\t" << Teams[i].Pl << "\t" << Teams[i].W << "\t" << Teams[i].D << "\t" << Teams[i].L <<
				"\t" << Teams[i].F << "\t" << Teams[i].A << "\t" << Teams[i].Pts;
		}

		char User_Input1;
		cout << "\n\nWould you like to update the leaderboard? [y/n] ";
		cin >> User_Input1;

		if (User_Input1 == 'y')
		{
		Try_Again1:
			string Team_Selection1;
			cout << "\n\nWhat team would you like to update? ";
			cin >> Team_Selection1;

			int TIV1;// Team Index Value One
			int TIV2;// Team Index Value Two
			for (int i = 0; i < P; i++)
			{
				if (Team_Selection1 == Teams[i].T)
				{
					TIV1 = i;
					goto Next_Step1;
				}
			}
			int Error_Check1 = 1;

		Next_Step1:
			if (Error_Check1 == 1)
			{
				cout << "\n\nThe team you've inputted is incorrect, try again.";
				goto Try_Again1;
			}
			else
			{
			Try_Again2:
				string Team_Selection2;
				cout << "\n\nWhat team did you play against? ";
				cin >> Team_Selection2;

				for (int i = 0; i < P; i++)
				{
					if (Team_Selection2 == Teams[i].T)
					{
						TIV2 = i;
						goto Next_Step2;
					}
				}
				int Error_Check2 = 1;

			Next_Step2:
				if (Error_Check2 == 1)
				{
					cout << "\n\nThe team you've inputted is incorrect, try again.";
					goto Try_Again2;
				}
				Teams[TIV1].Pl = Teams[TIV1].Pl + 1;
				Teams[TIV2].Pl = Teams[TIV2].Pl + 1;

				system("cls");

				cout << "Team\t\tP\tW\tD\tL\tF\tA\tPts\n";	// Leaderboard
				for (int i = 0; i < P; i++)
				{
					cout << "\n" << left << setw(11) << Teams[i].T << "\t" << Teams[i].Pl << "\t" << Teams[i].W << "\t" << Teams[i].D << "\t" << Teams[i].L <<
						"\t" << Teams[i].F << "\t" << Teams[i].A << "\t" << Teams[i].Pts;
				}

				char User_Input2;
				cout << "\n\nDid your team win, draw or lose? [w/d/l] ";
				cin >> User_Input2;

				if (User_Input2 == 'w')
				{
					Teams[TIV1].W = Teams[TIV1].W + 1;
					Teams[TIV2].L = Teams[TIV2].L + 1;
					Teams[TIV1].Pts = Teams[TIV1].Pts + 3;
				}
				else if (User_Input2 == 'd')
				{
					Teams[TIV1].D = Teams[TIV1].D + 1;
					Teams[TIV2].D = Teams[TIV2].D + 1;
					Teams[TIV1].Pts = Teams[TIV1].Pts + 1;
					Teams[TIV2].Pts = Teams[TIV2].Pts + 1;
				}
				else if (User_Input2 = 'l')
				{
					Teams[TIV2].W = Teams[TIV2].W + 1;
					Teams[TIV1].L = Teams[TIV1].L + 1;
					Teams[TIV2].Pts = Teams[TIV2].Pts + 3;
				}

				system("cls");

				cout << "Team\t\tP\tW\tD\tL\tF\tA\tPts\n";	// Leaderboard
				for (int i = 0; i < P; i++)
				{
					cout << "\n" << left << setw(11) << Teams[i].T << "\t" << Teams[i].Pl << "\t" << Teams[i].W << "\t" << Teams[i].D << "\t" << Teams[i].L <<
						"\t" << Teams[i].F << "\t" << Teams[i].A << "\t" << Teams[i].Pts;
				}

				int User_Input3;
				cout << "\n\nHow many goals did your team score? ";
				cin >> User_Input3;
				Teams[TIV1].F = Teams[TIV1].F + User_Input3;
				Teams[TIV2].A = Teams[TIV2].A + User_Input3;

				system("cls");

				cout << "Team\t\tP\tW\tD\tL\tF\tA\tPts\n";	// Leaderboard
				for (int i = 0; i < P; i++)
				{
					cout << "\n" << left << setw(11) << Teams[i].T << "\t" << Teams[i].Pl << "\t" << Teams[i].W << "\t" << Teams[i].D << "\t" << Teams[i].L <<
						"\t" << Teams[i].F << "\t" << Teams[i].A << "\t" << Teams[i].Pts;
				}

				int User_Input4;
				cout << "\n\nHow many goals did your team conceed? ";
				cin >> User_Input4;
				Teams[TIV2].F = Teams[TIV2].F + User_Input4;
				Teams[TIV1].A = Teams[TIV1].A + User_Input4;

				system("cls");

				cout << "Team\t\tP\tW\tD\tL\tF\tA\tPts\n";	// Leaderboard
				for (int i = 0; i < P; i++)
				{
					cout << "\n" << left << setw(11) << Teams[i].T << "\t" << Teams[i].Pl << "\t" << Teams[i].W << "\t" << Teams[i].D << "\t" << Teams[i].L <<
						"\t" << Teams[i].F << "\t" << Teams[i].A << "\t" << Teams[i].Pts;
				}

				cout << "\n\nBoth teams have now been updated!\n\n";
				system("pause");
				system("cls");

				std::ofstream New;
				New.open("C:\\Users\\Ben\\Documents\\Football Scores\\Football_Table\\Football_Table\\Scores.txt", ios::out);
				for (int i = 0; i < P; i++)
				{
					New << Teams[i].T << "\t" << Teams[i].Pl << "\t" << Teams[i].W << "\t" << Teams[i].D << "\t" << Teams[i].L <<
						"\t" << Teams[i].F << "\t" << Teams[i].A << "\t" << Teams[i].Pts << "\n";
				}

			}
		}

		else if (User_Input1 == 'n')
		{
			break;
		}
	}
}