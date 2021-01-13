#pragma once
#include "Dependency.h"
enum class E_Orientation
{
	DOWN = 0,
	LEFT,
	UP,
	RIGHT,
	NO_ROTATION = -1,
	SR_HORIZONTAL = 10,
	SR_VERTICAL = 11
};
struct Position
{
	int x, y;
};
class Block
{
public:
	bool Set = false;
	Position pos{ 0,0 };
	virtual void UpdatePos()=0;
	Position Coords[4]{0};
	Position* ShapeCoords;
	E_Orientation orientation;
	int color;
	Block(void) {};
	Block& operator=(Block& other);
};
class I_block : public Block
{
public:
	void UpdatePos()override;
	I_block(int x, int y);
};
class L_block : public Block
{
public:
	void UpdatePos()override;
	L_block(int x, int y);
};
class J_block : public Block
{
public:
	void UpdatePos()override;
	J_block(int x, int y);
};
class Z_block : public Block
{
public:
	void UpdatePos()override;
	Z_block(int x, int y);
};
class S_block : public Block
{
public:
	void UpdatePos()override;
	S_block(int x, int y);
};
class T_block : public Block
{
public:
	void UpdatePos()override;
	T_block(int x, int y);
};
class O_block : public Block
{
public:
	void UpdatePos() override;
	O_block(int x, int y);
};
