#include "Menu.h"
#include "Cursor.h"
#include "Dependency.h"
#include "Render.h"
#include "Shapes.h"
#include "LeaderBoard.h"
extern vector <Score> Scores;
extern vector <Block*> blocks;
extern vector <int> SCORES;
static int TET[20][10]{0};
bool GameOver = true;
int SCORE=0;
bool Set = true;
extern Block* LastBlockPos;
Block* CurrentBlock;
extern bool Moved;
static bool RotateRight=false;
static bool MoveDown = false;
static bool MoveRight = false;
static bool MoveLeft = false;
static bool Space = false;
extern chrono::duration<double> Speed;
//Vaiables
bool CheckSet();
bool CheckPositions()
{
	CurrentBlock->UpdatePos();
	for (int i = 0; i < 4; i++) {
		if(CurrentBlock->Coords[i].x<1 || CurrentBlock->Coords[i].x > 10  || CurrentBlock->Coords[i].y <0 || CheckSet())
			return 0;
	}
	return 1;
}
void CheckTET()
{
	vector<int> a;
	for (int i = 0; i < blocks.size(); i++) {
		for (int j = 0; j < 4; j++) {
			TET[blocks[i]->Coords[j].y][blocks[i]->Coords[j].x-1]++;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		int k = 0;
		for (int j = 0; j < 10; j++) {
			if (TET[i][j] == 0)
				goto finish;
		}
		a.push_back(i);
		finish:{}
	}

	for (int x : a) {
		for (int i = 0; i < blocks.size(); i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[i]->Coords[j].y == x)
					blocks[i]->Coords[j].y = -blocks[i]->Coords[j].y;
				else if (blocks[i]->Coords[j].y < x)
						blocks[i]->Coords[j].y++;
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {
		SetCursorPosition(2, a[i] + 1);
		SetConsoleTextAttribute(console, 5);
		for (int j = 0; j < 20; j++) {
			cout << " ";
			this_thread::sleep_for(0.003s);
		}
	}
	SCORE += 100.0f*pow(a.size(),1.5);
	if(a.size()!=0)
		RenderTets();
	for(int i=0;i<20;i++)
		for (int j = 0; j < 10; j++) {
			TET[i][j] = 0;}

}
bool CheckSet()
{
	CurrentBlock->UpdatePos();
	for (int i = 0; i < 4; i++) {
		if (CurrentBlock->Coords[i].y == 20)return 1;
		for (int j = 0; j < blocks.size() - 1; j++) {
			for (int k = 0; k < 4; k++) {
				if (blocks[j]->Coords[k].x == CurrentBlock->Coords[i].x && blocks[j]->Coords[k].y == CurrentBlock->Coords[i].y) {
					return 1;
				}
			}
		}
	}
	return 0;
}
void SpaceMove()
{
	while (!CheckSet())	{
		CurrentBlock->pos.y++;
		CurrentBlock->UpdatePos();
	}
	CurrentBlock->pos.y--;
	CurrentBlock->UpdatePos();
	return;
}
void Input()
{
	while (GameOver)
	{
		if (_kbhit())
		{
			switch (_getch())
			{	
			case ' ':
			{
				Space = true;
				break;
			}
			case 'a':
			{
				MoveLeft = true;
				break;
			}
			case 'w':
			{
				RotateRight = true;
				break;
			}
			case 's' :
			{
				MoveDown = true;
				break;
			}
			case 'd':
			{
				MoveRight = true;
				break;
			}
			case 224:
				switch (_getch())
				{
				case 75://a
				{
					MoveLeft = true;
					break;
				}
				case 72://w
				{
					RotateRight = true;
					break;
				}
				case 80://s
				{
					MoveDown = true;
					break;
				}
				case 77://d
				{
					MoveRight = true;
					break;
				}
				default:
					break;
				}
			default:
				break;
			}
		}
	}
}
void Logic()
{
	CurrentBlock = blocks[blocks.size() - 1];

	if ( RotateRight && CurrentBlock->orientation != E_Orientation::NO_ROTATION ) {
		if (CurrentBlock->orientation == E_Orientation::SR_HORIZONTAL)
		{
			for (int i = 0; i < 4; i++) {
				swap(CurrentBlock->ShapeCoords[i].x, CurrentBlock->ShapeCoords[i].y);
				CurrentBlock ->ShapeCoords[i].x = -CurrentBlock->ShapeCoords[i].x;
			}
		}
		else if (CurrentBlock->orientation == E_Orientation::SR_VERTICAL) {
			for (int i = 0; i < 4; i++) {
				swap(CurrentBlock->ShapeCoords[i].x, CurrentBlock->ShapeCoords[i].y);
				CurrentBlock->ShapeCoords[i].y = -CurrentBlock->ShapeCoords[i].y;
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				swap(CurrentBlock->ShapeCoords[i].x, CurrentBlock->ShapeCoords[i].y);
				CurrentBlock->ShapeCoords[i].x = -CurrentBlock->ShapeCoords[i].x;
			}
		}
		if (CurrentBlock->orientation == E_Orientation::SR_HORIZONTAL) {
			CurrentBlock->orientation = E_Orientation::SR_VERTICAL;
		}
		else if (CurrentBlock->orientation == E_Orientation::SR_VERTICAL) {
			CurrentBlock->orientation = E_Orientation::SR_HORIZONTAL;
		}
		else if (CurrentBlock->orientation == E_Orientation::RIGHT) { CurrentBlock->orientation = E_Orientation::DOWN; }
		else {
			CurrentBlock->orientation = E_Orientation((int)(CurrentBlock->orientation) + 1);
		}
		Moved = true;
		RotateRight = false;
	}
	else {
		RotateRight = false;
	}
	if (MoveRight)
	{
		CurrentBlock->pos.x++;
		Moved = true;
		MoveRight = false;
	}
	if (MoveLeft)
	{
		CurrentBlock->pos.x--;
		Moved = true;
		MoveLeft = false;
	}
	if (!CheckPositions()) {
		*CurrentBlock = *LastBlockPos;
	}
	if (Space)
	{
		SpaceMove();
		Moved = true;
		Space = false;
		Set = true;
	}
	if (MoveDown) {
		CurrentBlock->pos.y++;
		Moved = true;
		MoveDown = false;
	}
	if (CheckSet()) {
		Set = true;
		CurrentBlock->Set = true;
		*CurrentBlock = *LastBlockPos;
	}
	CurrentBlock->UpdatePos();
}

void FMoveDown()
{
	while(GameOver)
	while (!Set && GameOver) {
		if (!MoveDown && !Moved) {
			MoveDown = true;
		}
		std::this_thread::sleep_for(Speed);
	}
}
void DisplayScore()
{
	SetConsoleTextAttribute(console, 240);
	SetCursorPosition(26, 0);
	cout << " SCORE : " << SCORE<< " ";
}
void CheckGameOver()
{
	for (int i = 0; i < blocks.size() - 1;i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[i]->Coords[j].y <= 2 && blocks[i]->Coords[j].y>=0) {
				GameOver = false;
			}
		}
	}
}
void GameLoop()
{
	thread T_Input(Input);
	thread T_FMoveDown(FMoveDown);
	RenderInit();
	while (GameOver)
	{
		if (Set) {
			CheckTET();
			Moved;
			RotateRight = false;
			MoveDown = false;
			MoveRight = false;
			MoveLeft = false;
			Space = false;
			
 			switch (rand() % 7)//rand() % 7)
			{
			case 0: {
				blocks.push_back((Block*) new I_block(5, 0));
				Set = false;
				break;						  
			}								  
			case 1: {						  
				blocks.push_back((Block*) new O_block(5, 0));
				Set = false;
				break;						  
			}								  
			case 2: {						  
				blocks.push_back((Block*) new S_block(5, 0));
				Set = false;
				break;						  
			}								  
			case 3: {						  
				blocks.push_back((Block*) new Z_block(5, 0));
				Set = false;
				break;						  
			}								  
			case 4: {
				blocks.push_back((Block*) new L_block(5, 0));
				Set = false;
				break;						  
			}								  
			case 5: {						  
				blocks.push_back((Block*) new J_block(5, 0));
				Set = false;
				break;						  
			}								  
			case 6: {						  
				blocks.push_back((Block*) new T_block(5, 0));
				Set = false;
				break;
			}
			}
			delete LastBlockPos;
			LastBlockPos = new O_block(5, 0);
			Moved = false;
		}
		Logic();
		Render();
		DisplayScore();
		CheckGameOver();
	}

	T_FMoveDown.join();
	T_Input.join();
}
int main()
{
	ReadScores();
	while (1) {
		srand(time(NULL));
		hidecursor();
		switch (Menu())
		{
		case 3:
		{
			return 0;
		}
		case 0:
		{
			Set = true;
			for (int i = 0; i < blocks.size(); i++) {
				delete blocks[i];
			}
			blocks.clear();
			Moved=false;
			RotateRight = false;
			MoveDown = false;
			MoveRight = false;
			MoveLeft = false;
			Space = false;
			GameOver = true;
			SCORE = 0;
			GameLoop();
			SetCursorPosition(0, 10);
			SetConsoleTextAttribute(console, 9);
         	cout << "       GAME OVER                 ";
			fstream fout("Scores.txt", ios::app);
			time_t now = time(0);
			fout << SCORE << " " << ctime(&now);
			Score scr = { SCORE,ctime(&now) };
			Scores.push_back(scr);
			this_thread::sleep_for(2s);
			break;
		}
		case 2:
		{
			sort(Scores.begin(), Scores.end(), Cmp);
			DisplayLeaderBoard();
			while (_getch() != 27)
				break;
		}
		default:
			break;
		}
	}
}
