#include "Leaderboard.h"
#include "Dependency.h"
bool Cmp(const Score& a,const Score& b)
{
	if (a.score > b.score)return 1;
	else return 0;
}

vector <Score> Scores;
void DisplayLeaderBoard()
{
	system("cls");
	SetConsoleTextAttribute(console, 96);
	cout << "Leaderboard                                         \n";
	cout << "Press Esc to exit                                   \n";
	SetConsoleTextAttribute(console, 79);
	if(Scores.size()!=0)cout << "Highscore : " << Scores[0].score << " "<< Scores[0].Date<<endl;
	SetConsoleTextAttribute(console, 7);
	for(int i = 1; i < Scores.size(); i++) {
		cout<< Scores[i].score << " " << Scores[i].Date << endl;
	}
}
void ReadScores()
{
	Score scr;
	fstream fin("Scores.txt");
	while (fin >> scr.score) {
		getline(fin, scr.Date);
		Scores.push_back(scr);
	}
	sort(Scores.begin(), Scores.end(), Cmp);
}
