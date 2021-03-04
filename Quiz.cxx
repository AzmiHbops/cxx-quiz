#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void gameLoop();
bool generator();
bool question(int Qarray[]);
bool confirm(int ans, int Qarray[]);
void resetHighScore(int score, int *highScore);

int main() {
	gameLoop();
}

void gameLoop()
{
	int range;
	int highScore{0};
	
	cout << "How many rounds of play? ";
	cin >> range;
	for (int i = 0; i < range; i++)
	{
		int score{0};
		bool win{true};
		
		while (win)
		{
			win = generator();
			if (win)
				score++;
		}
		resetHighScore(score, &highScore);
	}
}

bool generator()
{
	srand(time(0));

	int num1 = 7 + (rand() % 10);
	int num2 = rand() % 12;
	int Qarray[] = {num1, num2};

	bool win;
	win = question(Qarray);
	return win;
}

bool question(int Qarray[])
{
	int answer;
	cout << Qarray[0] << " x " << Qarray[1] << " = ";
	cin >> answer;

	bool win;
	win = confirm(answer, Qarray);
	
	return win;
}

bool confirm(int ans, int Qarray[])
{
	bool win{false};
	int correct{Qarray[0] * Qarray[1]};
	if (ans == correct)
	{
		cout << "You got it right!!" << endl;
		win = true;
	}
	else
	{
		cout << "You gave a wrong answer, the correct answer is " << correct << endl;
	}
	return win;
}

void resetHighScore(int score, int *highScore)
{
	if (score > *highScore)
	{
		cout << "New Highscore!! You scored " << score << endl << endl;
		*highScore = score;
	}
	else
	{
		cout << "You scored: " << score << " Highscore: " << *highScore << endl << endl;
	}
}
