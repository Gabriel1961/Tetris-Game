#pragma once
#include <string>
#include <iostream>
struct Score
{
	int score;
	std::string Date;
};
bool Cmp(const Score& a, const Score& b);
void DisplayLeaderBoard();
void ReadScores();
