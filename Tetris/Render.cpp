#include "Render.h"
#include "Dependency.h"
#include "Cursor.h"
#include "Shapes.h"
vector <Block*> blocks;
bool Moved = false;
Block* LastBlockPos = new I_block(5,0);
void RenderInit()
{
	int c=0;
	for (int i = 0; i < 22; i++)
	{
		for (int j=0; j < 24; j++)
		{
			if (i == 0 || i == 21)
			{
				SetConsoleTextAttribute(console, 130);
				cout <<" ";
			}
			else if (j == 0 || j == 21)
			{
				SetConsoleTextAttribute(console, 130);
				cout << "  ";
			}
			else if(j<22 && j%2==1)
			{
				SetConsoleTextAttribute(console,(c%2==0 ? 250 : 112));
				cout << "  ";
				c++;
			}
		}
		cout << endl;
		c++;
	}
}
void Render()
{	
	blocks[blocks.size() - 1]->UpdatePos();
	LastBlockPos->UpdatePos();
	if (Moved) {
		for (int i = 0; i < 4; i++) {
			SetCursorPosition(2*LastBlockPos->Coords[i].x, LastBlockPos->Coords[i].y+1);
			if ((LastBlockPos->Coords[i].y+1) % 2 == LastBlockPos->Coords[i].x%2) {
				SetConsoleTextAttribute(console, 112);
				cout << "  ";
			}
			else {
				SetConsoleTextAttribute(console, 250);
				cout << "  ";
			}
		}
		Moved = false;
	}
	for (int i = 0; i < 4; i++) {
		SetCursorPosition(2 * blocks[blocks.size()-1]->Coords[i].x , blocks[blocks.size() - 1]->Coords[i].y + 1);
		SetConsoleTextAttribute(console, blocks[blocks.size() - 1]->color);
		cout << "  ";
	}
	*LastBlockPos = *blocks[blocks.size() - 1];
}
void RenderTets()
{

	for(int i=1;i<21;i++)
		for (int j = 1; j < 11; j++) {
			SetCursorPosition(2*j, i);
			if (j % 2 == i % 2) {
				SetConsoleTextAttribute(console, 112);
				cout << "  ";}
			else {
				SetConsoleTextAttribute(console, 250);
				cout << "  ";}
		}

	for(int i=0;i<blocks.size();i++) 
		for (int j = 0; j < 4; j++) {
			if (blocks[i]->Coords[j].y >= 0) {
				SetConsoleTextAttribute(console, blocks[i]->color);
				SetCursorPosition(2 * blocks[i]->Coords[j].x, blocks[i]->Coords[j].y + 1);
				cout << "  ";
			}
		}
}
