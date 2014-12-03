#include "morse.h"

morse::morse()
{
	AskForInput();
	WordsToMorse();
	WriteToConsole();
	MorseToSound();
}

void morse::AskForInput()
{
	cout << "Enter your text and confirm with ENTER: " << endl;
	getline(cin, text_original);
}

void morse::WordsToMorse()
{
	const char* alphabet = "abcdefghijklmnopqrstuwvxyz";
	const char* alphabet_cap = "ABCDEFGHIJKLMNOPQRSTUWVXYZ";
	const char* alphabet_morse[] = {".-", "-...","-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----."};
	
	for(int i=0;i<text_original.size();i++){
		for(int n=0;n<26;n++){
			if(text_original[i]==alphabet[n] || text_original[i]==alphabet_cap[n]){
				text_morse += alphabet_morse[n];
				text_morse += ' ';}
			else if (text_original[i]==' '){
				text_morse += "/ ";
				break;}}}
}

void morse::WriteToConsole()
{
	cout << text_morse << endl;
}

void morse::MorseToSound()
{
	for(int i=0;i<text_morse.size();i++){
		if(text_morse[i]=='.') Beep(300,500);
		else if(text_morse[i]=='-') Beep(300,1000);
		else if(text_morse[i]==' ') Beep(0,1000);
		else if(text_morse[i]=='/') Beep(0,500);}
}