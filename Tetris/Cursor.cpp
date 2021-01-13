#include "Dependency.h"
#include "Cursor.h"
void hidecursor()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(console, &info);
}
void SetCursorPosition(int x, int y)
{
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(console, coord);
}