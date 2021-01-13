#include "Dependency.h"
#include "Menu.h"
#include "Cursor.h"
static bool IsSelected;
static int DifficultySelected=-1;
chrono::duration<double> Speed = 0.6s;
int Menu()
{
	system("cls");
	IsSelected = true;
	int OptionSelected = 0;
	LogMenu(OptionSelected);
	thread T_FlashyMenu(FlashyMenu,&OptionSelected);
	while (IsSelected)
	{
		if (_kbhit())
			switch (_getch())
			{
			case 'w':
			{
				if (OptionSelected != 0)OptionSelected--;
				break;
			}
			case 's':
			{
				if (OptionSelected != 3)OptionSelected++;
				break;
			}
			case 224:
			{
				switch (_getch())
				{
				case 72://w
				{
					if (OptionSelected != 0)OptionSelected--;
					break;
				}
				case 80://s
				{
					if (OptionSelected != 3)OptionSelected++;
					break;
				}
				}
				break;
			}
			case '\r':
			{
				if (OptionSelected == 1) {
					if(DifficultySelected==2)DifficultySelected=0;
					else 
					DifficultySelected++;
					break;
				}
				IsSelected = false;
				T_FlashyMenu.join();
				system("cls");
				switch (DifficultySelected)
				{
				case -1:
				{
					break;
				}
				case 0:
				{
					Speed = 0.6s;
					break;
				}
				case 1:
				{
					Speed = 0.3s;
					break;
				}
				case 2:
				{
					Speed = 0.1s;
					break;
				}
				default:
					break;
				}
				return OptionSelected;
				break;
			}
			default:
				break;
			}
	}
	return OptionSelected;
}

void FlashyMenu (int* Optionselected)
{
	int NoFlash=-1;
	while (IsSelected) {
		while (*Optionselected == 0 && IsSelected)
		{
			SetCursorPosition(2, 1);
			for (char c : "-> Play") {
				
				SetConsoleTextAttribute(console, 6);
				cout << c;
				std::this_thread::sleep_for(0.08s);
				SetConsoleTextAttribute(console, 15);
				cout << "\b" << c;
				if (*Optionselected != 0 || !IsSelected ) {
					LogMenu(*Optionselected );
					break;
				}
			}
		}
		while (*Optionselected == 1 && IsSelected)
		{
			SetCursorPosition(2, 2);
			string a;
			if (DifficultySelected == 0)a = "-> Difficulty Normal         ";
			else if (DifficultySelected == 1)a = "-> Difficulty Hard          ";
			else if (DifficultySelected == 2)a = "-> Difficulty Extreme         ";
			else a = "-> Difficulty";
			SetConsoleTextAttribute(console, 6);
			cout << a;
			SetConsoleTextAttribute(console, 15);
			if (*Optionselected != 1 || !IsSelected) {
				LogMenu(*Optionselected);
				break;
			}
		}
		while (*Optionselected == 2 && IsSelected)
		{
			SetCursorPosition(2, 3);
			for (char c : "-> Leaderboard") {
				
				SetConsoleTextAttribute(console, 6);
				cout << c;
				std::this_thread::sleep_for(0.08s);
				SetConsoleTextAttribute(console, 15);
				cout << "\b" << c; 
				if (*Optionselected != 2 || !IsSelected ) {
					LogMenu(*Optionselected);
					break;
				}
			}
		}
		while (*Optionselected == 3 && IsSelected)
		{
			SetCursorPosition(2, 4);
			for (char c : "-> Quit") {
				
				SetConsoleTextAttribute(console, 6);
				cout << c;
				std::this_thread::sleep_for(0.08s);
				SetConsoleTextAttribute(console, 15);
				cout << "\b" << c;
				if (*Optionselected != 3 || !IsSelected) {
					LogMenu(*Optionselected);
					break;
				}
			}
		}
	}
	return;
}


void LogMenu(int Optionselected)
{
	switch (Optionselected)
	{
	case 0:
	{
		system("cls");
		SetConsoleTextAttribute(console, 96);
		cout << "Tetris                                                   \n";
		SetConsoleTextAttribute(console, 15);
		cout << "\n";
		SetConsoleTextAttribute(console, 7);
		cout << "  Difficulty\n";
		cout << "  Leaderboard\n";
		cout << "  Quit\n";
		break;
	}
	case 1:
	{
		system("cls");
		SetConsoleTextAttribute(console, 96);
		cout << "Tetris                                                   \n";
		SetConsoleTextAttribute(console, 7);
		cout << "  Play\n";
		SetConsoleTextAttribute(console, 15);
		cout << "\n";
		SetConsoleTextAttribute(console, 7);
		cout << "  Leaderboard\n";
		cout << "  Quit\n";
		break;
	}
	case 2:
	{
		system("cls");
		SetConsoleTextAttribute(console, 96);
		cout << "Tetris                                                   \n";
		SetConsoleTextAttribute(console, 7);
		cout << "  Play\n";
		cout << "  Difficulty\n";
		SetConsoleTextAttribute(console, 15);
		cout << "\n";
		SetConsoleTextAttribute(console, 7);
		cout << "  Quit\n";
		break;
	}
	case 3:
	{
		system("cls");
		SetConsoleTextAttribute(console, 96);
		cout << "Tetris                                                   \n";
		SetConsoleTextAttribute(console, 7);
		cout << "  Play\n";
		cout << "  Difficulty\n";
		cout << "  Leaderboard\n";
		SetConsoleTextAttribute(console, 15);
		cout << "\n";
		SetConsoleTextAttribute(console, 7);
		break;
	}
	}
}