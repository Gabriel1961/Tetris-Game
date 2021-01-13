#include "Shapes.h"
#include "Render.h"
Block& Block::operator=(Block& other)
{
	Set = other.Set;
	pos = other.pos;
	memcpy(Coords, other.Coords, sizeof(Position) * 4);
	memcpy(ShapeCoords, other.ShapeCoords, sizeof(Position) * 4);
	color = other.color;
	orientation = other.orientation;
	return *this;
}
void I_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

I_block::I_block(int x, int y)
{
	this->color = (int)E_Color::I_TEAL;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::SR_HORIZONTAL;
	ShapeCoords = new Position[4]{ {-1,0},{0,0},{1,0}, {2,0} };
	UpdatePos();
}

void L_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

L_block::L_block(int x, int y)
{
	this->color = (int)E_Color::L_ORANGE;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::DOWN;
	ShapeCoords = new Position[4]{ {0,0},{-1,0},{1,0}, {1,1} };
	UpdatePos();
}
//ShapeCoords = new Position[4]{ {-1,0},{0,0},{1,0}, {1,1} };
void J_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

J_block::J_block(int x, int y)
{
	this->color = (int)E_Color::J_BLUE;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::DOWN;
	ShapeCoords = new Position[4]{ {-1,0},{0,0},{1,0}, {-1,1} };
	UpdatePos();
}

void Z_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

Z_block::Z_block(int x, int y)
{
	this->color = (int)E_Color::Z_RED;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::SR_HORIZONTAL;
	ShapeCoords = new Position[4]{ {-1,0},{0,0},{0,1}, {1,1} };
	UpdatePos();
}

void S_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

S_block::S_block(int x, int y)
{
	this->color = (int)E_Color::S_GREEN;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::SR_HORIZONTAL;
	ShapeCoords = new Position[4]{ {0,0},{1,0},{0,1}, {-1,1} };
	UpdatePos();
}

void T_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

T_block::T_block(int x, int y)
{
	this->color = (int)E_Color::T_PURPLE;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::DOWN;
	ShapeCoords = new Position[4]{ {-1,0},{0,0},{1,0}, {0,1} };
	UpdatePos();
}

void O_block::UpdatePos()
{
	for (int i = 0; i < 4; i++) {
		Coords[i].x = ShapeCoords[i].x + pos.x;
		Coords[i].y = ShapeCoords[i].y + pos.y;
	}
}

O_block::O_block(int x, int y)
{
	this->color = (int)E_Color::O_YELLOW;
	pos.x = x;
	pos.y = y;
	orientation = E_Orientation::NO_ROTATION;
	ShapeCoords = new Position[4]{ {0,0},{1,0},{0,1}, {1,1} };
	UpdatePos();
}
