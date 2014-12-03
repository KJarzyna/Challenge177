#include <iostream>
#include <sstream>
#include <Windows.h>

using namespace std;

class morse
{
public:
	morse();
	
private:
	void AskForInput();
	void WordsToMorse();
	void MorseToSound();
	void WriteToConsole();
	string text_original;
	string text_morse;
};