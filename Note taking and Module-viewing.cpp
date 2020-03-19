#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <cstdio>
#include <string>
using namespace std;

void read_module_record(ifstream &inFile);
void input_notes1(ofstream &outFile);
void input_notes2(ofstream &outFile);
void input_notes3(ofstream &outFile);
void input_notes4(ofstream &outFile);
void input_notes5(ofstream &outFile);
void view_notes(ifstream &inFile);
void modules(ofstream& outFile);
void gotoxy(short x, short y);
void notes_holder(ifstream &inFile);
void logo_repeat();
void exitprogram();
void modquiz1(int);
void modquiz2(int);
void modquiz3(int);
void modquiz4(int);
void modquiz5(int);
void setWindow();
void header();
void clear();
void logo();
int gwa(double &average);
int menu(int &choice);
int student_account();

void clear () {
	system("cls");
}

void exitprogram () {
	clear();
	logo_repeat();
	header();
	gotoxy (25, 15); cout << "\n\nThank you for everything you've taught us\n";
	gotoxy (25, 16); cout << " in Computer Programming 2, Ma'am Joie! <3 \n";
	exit(1);
}

void gotoxy (short x, short y) {
	COORD pos = {x,y};
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
}

void header() {
	gotoxy (37, 0); cout << " #####  #         #     #####   ###  ####   ###   # ";
	gotoxy (37, 1); cout << " #      #   # ##  #     #      #   # #   #  #  #  # ";
	gotoxy (37, 2); cout << " #     ###  ##    #     ####   ##### ####   #   # # ";
	gotoxy (37, 3); cout << " #      #   #     #     #      #   # #   #  #    ## ";
	gotoxy (37, 4); cout << " #####  #   #     ####  #####  #   # #    # #     # ";
}

void setWindow (){
HWND console = GetConsoleWindow();
  RECT ConsoleRect;
  GetWindowRect(console, &ConsoleRect); 
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 2700, 1000, TRUE);
}

struct Notes {
	char student[50];
	FILE fp[6];
	string mod1 = "Module 1_";
	string mod2 = "Module 2_";
	string mod3 = "Module 3_";
	string mod4 = "Module 4_";
	string mod5 = "Module 5_";
} access;

class Grades {
	private: 
			 float quizscore[5];
			 float rawscore;
    public: 
    		void setScore(float *score);
    		double computeRawScore();
    		string matchRawScore();
			 
};

struct Account {
    string name, school, email;
    int age;
} records;

int main ()
{	
	system ("title CtrLearn: Control Your Learning");
	
	ifstream inFile;
	ofstream outFile;
	FILE *fp;
	int choice, score, modquiz;
	double average;
	
	logo_repeat();
	student_account();
	
	while(1){
	menu(choice);
	switch (choice) {
		case 1:
			clear();
			header();
			modules(outFile);
			break;
		case 2:
			clear();
			header();
			cout << "\n\n";
			cout << "Hello " << records.name <<"!\n\n";
			cout << "CHOOSE A MODULE QUIZ:\n";
			cout << "[1] Module 1: Cell Theory\n";
			cout << "[2] Module 2: Cell Structure and Function\n";
			cout << "[3] Module 3: Eukaryotic Cells vs Prokaryotic Cells\n";
			cout << "[4] Module 4: Cell Types\n";
			cout << "[5] Module 5: Cell Cycle\n";
			cout << "Enter choice: ";
			cin >> modquiz;
				switch (modquiz) {
					case 1:
						clear();
						modquiz1(score);
						break;
					case 2:
						clear();
						modquiz2(score);
						break;
					case 3:
						clear();
						modquiz3(score);
						break;
					case 4:
						clear();
						modquiz4(score);
						break;
					case 5:
						clear();
						modquiz5(score);
						break;
				}
			break;
		case 3:
			clear();
			header();
			view_notes(inFile);
			gotoxy (5,25); system("pause");
			break;
		case 4:
			clear();
			header();
			gwa(average);
			break;
		case 5:
			exitprogram();
		default:
			cout << "Not a valid choice...\n";
			Sleep (750);
			cout << "Loading menu...\n";
			Sleep(750);
	}
}
	
	return 0;
}

int student_account() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 10);
	
	ifstream inFile;
    ofstream outFile;
    int choice;
    header();
    cout << "\n\n";
    outFile.open("Student Record.txt");
    
    cout << "\t\t\t\t\t\t\t R E C O R D S \n\n\n";
    cout << "Enter your name: " ;
    getline (cin, records.name);
    cout << "\n";
    cout << "Enter the school you're from: ";
    getline (cin, records.school);
    cout << "\n";
    cout << "Enter your email address: " ;
    getline (cin, records.email);
    cout << "\n";
    cout << "Enter your age: " ;
    cin >> records.age;
    cout << "\n";

    outFile << "Name: " << records.name << endl;
    outFile << "School: " << records.school << endl;
    outFile << "Email address: " << records.email << endl;
    outFile << "Age: " << records.age << endl;
    clear();
}

int menu (int &choice) {
	clear();
	header();
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 11);
	cout << "\n\nHello " << records.name << "!" << endl << endl;
	cout << "CHOOSE AN OPTION:\n";
	cout << "[1] Modules\n";
	cout << "[2] Quizzes\n";
	cout << "[3] Notes\n";
	cout << "[4] Compute average\n";
	cout << "Enter choice: ";
	cin >> choice;
}

void modules (ofstream& outFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 12);
	int choice;
	cout << "\n\nCHOOSE A MODULE:\n\n";
	cout << "[1] Module 1: Cell Theory\n";
	cout << "[2] Module 2: Cell Structure and Function\n";
	cout << "[3] Module 3: Eukaryotic Cells vs Prokaryotic Cells\n";
	cout << "[4] Module 4: Cell Types\n";
	cout << "[5] Module 5: Cell Cycle\n";
	cout << "Enter choice: ";
	cin >> choice; 
	switch (choice) {
		case 1:
			clear();
			header();
			input_notes1(outFile);
			break;
		case 2:
			clear();
			header();
			input_notes2(outFile);
			break;
		case 3:
			clear();
			header();
			input_notes3(outFile);
			break;
		case 4:
			clear();
			header();
			input_notes4(outFile);
			break;
		case 5:
			clear();
			header();
			input_notes5(outFile);
			break;
		default:
			clear();
			header();
			cout << "\n\nNo module detected.\n";
			system("pause");
	}
}

void input_notes1 (ofstream &outFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	FILE *fp;
	int choice;
	string new_name, line;
	string sentence;
	
	cin.ignore(INT_MAX,'\n');
	cin.clear();
	gotoxy (0, 6); cout << "Enter file name: ";
	getline(cin,new_name);
	
	clear();
	header();
	
	ifstream module1 ("module1.txt");
			if (module1.is_open()){
				while (getline (module1, line)){
					cout << line <<endl;
				}
			module1.close();
			}
			else
				cout << "Unable to open the file.";
			
	access.mod1 = access.mod1 + new_name + ".txt";
	outFile.open("record_module_name.txt");
	outFile<<access.mod1<<endl;
	outFile.close();

	gotoxy (0,43); cout << access.mod1 << endl << endl;
	gotoxy (0, 45); cout << "INSTRUCTION: Enter '|' if you want to end writing notes.";
	gotoxy (2, 46);  cout << "==================================================================================================================";
	gotoxy (2, 47); cout << "|                                                                                                                |";
	gotoxy (2, 48); cout << "==================================================================================================================";
	gotoxy (2, 49); cout << "|                                                                                                                |";
	gotoxy (2, 50); cout << "|                                                                                                                |";
	gotoxy (2, 51); cout << "|                                                                                                                |";
	gotoxy (2, 52); cout << "|                                                                                                                |";
	gotoxy (2, 53); cout << "|                                                                                                                |";
	gotoxy (2, 54); cout << "|                                                                                                                |";
	gotoxy (2, 55); cout << "|                                                                                                                |";
	gotoxy (2, 56); cout << "|                                                                                                                |";
	gotoxy (2, 57); cout << "|                                                                                                                |";
	gotoxy (2, 58); cout << "|                                                                                                                |";
	gotoxy (2, 59); cout << "|                                                                                                                |";
	gotoxy (2, 60); cout << "|                                                                                                                |";
	gotoxy (2, 61); cout << "|                                                                                                                |";
	gotoxy (2, 62); cout << "|                                                                                                                |";
	gotoxy (2, 63); cout << "|                                                                                                                |";
	gotoxy (2, 64); cout << "|                                                                                                                |";
	gotoxy (2, 65); cout << "|                                                                                                                |";
	gotoxy (2, 66); cout << "|                                                                                                                |";
	gotoxy (2, 67); cout << "|                                                                                                                |";
	gotoxy (2, 68); cout << "|                                                                                                                |";
	gotoxy (2, 69); cout << "|                                                                                                                |";
	gotoxy (2, 70); cout << "|                                                                                                                |";
	gotoxy (2, 71); cout << "|                                                                                                                |";
	gotoxy (2, 72); cout << "|                                                                                                                |";
	gotoxy (2, 73); cout << "|________________________________________________________________________________________________________________|";
	gotoxy (50, 47); cout << "TYPE YOUR NOTES\n"; 
	
	string sentence_holder;
	int counter = 0;
	bool enter_sentence = true;
	while(enter_sentence == true){
		gotoxy (5, 49 + counter); getline(cin,sentence);
		if(sentence == "|")
			enter_sentence = false;
		sentence_holder = sentence_holder + sentence + "\n";
		counter++;
	}
	
	outFile << "\n\nModule 1 notes:\n\n" << sentence;
	outFile.open(access.mod1, ios::app);
	outFile<<sentence_holder<<endl;
	outFile.close();
	
	gotoxy (0, 74);
	system("pause");
}

void input_notes2(ofstream &outFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	FILE *fp;
	int choice;
	string new_name, line;
	string sentence;
	
	cin.ignore(INT_MAX,'\n');
	cin.clear();
	gotoxy (0, 6); cout << "Enter file name: ";
	getline(cin,new_name);
	
	clear();
	header();
	
	ifstream module2 ("module2.txt");
			if (module2.is_open()){
				while (getline (module2, line)){
					cout << line << endl;
				}
			module2.close();
			}
			else
				cout << "Unable to open the file.";
			
	access.mod2 = access.mod2 + new_name + ".txt";
	outFile.open("record_module_name.txt");
	outFile<<access.mod2<<endl;
	outFile.close();

	gotoxy (0,49); cout << access.mod2 << endl << endl;
	gotoxy (0, 51); cout << "INSTRUCTION: Enter '|' if you want to end writing notes.";
	gotoxy (2, 52);  cout << "==================================================================================================================";
	gotoxy (2, 53); cout << "|                                                                                                                |";
	gotoxy (2, 54); cout << "==================================================================================================================";
	gotoxy (2, 55); cout << "|                                                                                                                |";
	gotoxy (2, 56); cout << "|                                                                                                                |";
	gotoxy (2, 57); cout << "|                                                                                                                |";
	gotoxy (2, 58); cout << "|                                                                                                                |";
	gotoxy (2, 59); cout << "|                                                                                                                |";
	gotoxy (2, 60); cout << "|                                                                                                                |";
	gotoxy (2, 61); cout << "|                                                                                                                |";
	gotoxy (2, 62); cout << "|                                                                                                                |";
	gotoxy (2, 63); cout << "|                                                                                                                |";
	gotoxy (2, 64); cout << "|                                                                                                                |";
	gotoxy (2, 65); cout << "|                                                                                                                |";
	gotoxy (2, 66); cout << "|                                                                                                                |";
	gotoxy (2, 67); cout << "|                                                                                                                |";
	gotoxy (2, 68); cout << "|                                                                                                                |";
	gotoxy (2, 69); cout << "|                                                                                                                |";
	gotoxy (2, 70); cout << "|                                                                                                                |";
	gotoxy (2, 71); cout << "|                                                                                                                |";
	gotoxy (2, 72); cout << "|                                                                                                                |";
	gotoxy (2, 73); cout << "|                                                                                                                |";
	gotoxy (2, 74); cout << "|                                                                                                                |";
	gotoxy (2, 75); cout << "|                                                                                                                |";
	gotoxy (2, 76); cout << "|                                                                                                                |";
	gotoxy (2, 77); cout << "|                                                                                                                |";
	gotoxy (2, 78); cout << "|                                                                                                                |";
	gotoxy (2, 79); cout << "|________________________________________________________________________________________________________________|";
	gotoxy (50, 53); cout << "TYPE YOUR NOTES\n"; 
	
	string sentence_holder;
	int counter = 0;
	bool enter_sentence = true;
	while(enter_sentence == true){
		gotoxy (5, 55 + counter); getline(cin,sentence);
		if(sentence == "|")
			enter_sentence = false;
		sentence_holder = sentence_holder + sentence + "\n";
		counter++;
	}
	
	outFile << "\n\nModule 2 notes:\n\n" << sentence;
	outFile.open(access.mod2, ios::app);
	outFile<<sentence_holder<<endl;
	outFile.close();
	
	gotoxy (0, 80);
	system("pause");
}

void input_notes3(ofstream &outFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	FILE *fp;
	int choice;
	string new_name, line;
	string sentence;
	
	cin.ignore(INT_MAX,'\n');
	cin.clear();
	gotoxy (0, 6); cout << "Enter file name: ";
	getline(cin,new_name);
	
	clear();
	header();
	
	ifstream module3 ("module3.txt");
			if (module3.is_open()){
				while (getline (module3, line)){
					cout << line <<endl;
				}
			module3.close();
			}
			else
				cout << "Unable to open the file.";
			
	access.mod3 = access.mod3 + new_name + ".txt";
	outFile.open("record_module_name.txt");
	outFile<<access.mod3<<endl;
	outFile.close();

	gotoxy (0, 55); cout << access.mod3 << endl << endl;
	gotoxy (0, 57); cout << "INSTRUCTION: Enter '|' if you want to end writing notes.";
	gotoxy (2, 58);  cout << "==================================================================================================================";
	gotoxy (2, 59); cout << "|                                                                                                                |";
	gotoxy (2, 60); cout << "==================================================================================================================";
	gotoxy (2, 61); cout << "|                                                                                                                |";
	gotoxy (2, 62); cout << "|                                                                                                                |";
	gotoxy (2, 63); cout << "|                                                                                                                |";
	gotoxy (2, 64); cout << "|                                                                                                                |";
	gotoxy (2, 65); cout << "|                                                                                                                |";
	gotoxy (2, 66); cout << "|                                                                                                                |";
	gotoxy (2, 67); cout << "|                                                                                                                |";
	gotoxy (2, 68); cout << "|                                                                                                                |";
	gotoxy (2, 69); cout << "|                                                                                                                |";
	gotoxy (2, 70); cout << "|                                                                                                                |";
	gotoxy (2, 71); cout << "|                                                                                                                |";
	gotoxy (2, 72); cout << "|                                                                                                                |";
	gotoxy (2, 73); cout << "|                                                                                                                |";
	gotoxy (2, 74); cout << "|                                                                                                                |";
	gotoxy (2, 75); cout << "|                                                                                                                |";
	gotoxy (2, 76); cout << "|                                                                                                                |";
	gotoxy (2, 77); cout << "|                                                                                                                |";
	gotoxy (2, 78); cout << "|                                                                                                                |";
	gotoxy (2, 79); cout << "|                                                                                                                |";
	gotoxy (2, 80); cout << "|                                                                                                                |";
	gotoxy (2, 81); cout << "|                                                                                                                |";
	gotoxy (2, 82); cout << "|                                                                                                                |";
	gotoxy (2, 83); cout << "|                                                                                                                |";
	gotoxy (2, 84); cout << "|                                                                                                                |";
	gotoxy (2, 85); cout << "|________________________________________________________________________________________________________________|";
	gotoxy (50, 59); cout << "TYPE YOUR NOTES\n"; 
	
	string sentence_holder;
	int counter = 0;
	bool enter_sentence = true;
	while(enter_sentence == true){
		gotoxy (5, 61 + counter); getline(cin,sentence);
		if(sentence == "|")
			enter_sentence = false;
		sentence_holder = sentence_holder + sentence + "\n";
		counter++;
	}
	
	outFile << "\n\nModule 3 notes:\n\n" << sentence;
	outFile.open(access.mod3, ios::app);
	outFile<<sentence_holder<<endl;
	outFile.close();
	
	gotoxy (0, 86);
	system("pause");
}

void input_notes4(ofstream &outFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	FILE *fp;
	int choice;
	string new_name, line;
	string sentence;
	
	cin.ignore(INT_MAX,'\n');
	cin.clear();
	gotoxy (0, 6); cout << "Enter file name: ";
	getline(cin,new_name);
	
	clear();
	header();
	
	ifstream module4 ("module4.txt");
			if (module4.is_open()){
				while (getline (module4, line)){
					cout << line << endl;
				}
			module4.close();
			}
			else
				cout << "Unable to open the file.";
			
	access.mod4 = access.mod4 + new_name + ".txt";
	outFile.open("record_module_name.txt");
	outFile<<access.mod4<<endl;
	outFile.close();

	gotoxy (0,66); cout << access.mod4 << endl << endl;
	gotoxy (0, 68); cout << "INSTRUCTION: Enter '|' if you want to end writing notes.";
	gotoxy (2, 69);  cout << "==================================================================================================================";
	gotoxy (2, 70); cout << "|                                                                                                                |";
	gotoxy (2, 71); cout << "==================================================================================================================";
	gotoxy (2, 72); cout << "|                                                                                                                |";
	gotoxy (2, 73); cout << "|                                                                                                                |";
	gotoxy (2, 74); cout << "|                                                                                                                |";
	gotoxy (2, 75); cout << "|                                                                                                                |";
	gotoxy (2, 76); cout << "|                                                                                                                |";
	gotoxy (2, 77); cout << "|                                                                                                                |";
	gotoxy (2, 78); cout << "|                                                                                                                |";
	gotoxy (2, 79); cout << "|                                                                                                                |";
	gotoxy (2, 80); cout << "|                                                                                                                |";
	gotoxy (2, 81); cout << "|                                                                                                                |";
	gotoxy (2, 82); cout << "|                                                                                                                |";
	gotoxy (2, 83); cout << "|                                                                                                                |";
	gotoxy (2, 84); cout << "|                                                                                                                |";
	gotoxy (2, 85); cout << "|                                                                                                                |";
	gotoxy (2, 86); cout << "|                                                                                                                |";
	gotoxy (2, 87); cout << "|                                                                                                                |";
	gotoxy (2, 88); cout << "|                                                                                                                |";
	gotoxy (2, 89); cout << "|                                                                                                                |";
	gotoxy (2, 90); cout << "|                                                                                                                |";
	gotoxy (2, 91); cout << "|                                                                                                                |";
	gotoxy (2, 92); cout << "|                                                                                                                |";
	gotoxy (2, 93); cout << "|                                                                                                                |";
	gotoxy (2, 94); cout << "|                                                                                                                |";
	gotoxy (2, 95); cout << "|                                                                                                                |";
	gotoxy (2, 96); cout << "|________________________________________________________________________________________________________________|";
	gotoxy (50, 70); cout << "TYPE YOUR NOTES\n"; 
	
	string sentence_holder;
	int counter = 0;
	bool enter_sentence = true;
	while(enter_sentence == true){
		gotoxy (5, 72 + counter); getline(cin,sentence);
		if(sentence == "|")
			enter_sentence = false;
		sentence_holder = sentence_holder + sentence + "\n";
		counter++;
	}
	
	outFile << "\n\nModule 4 notes:\n\n" << sentence;
	outFile.open(access.mod4, ios::app);
	outFile<<sentence_holder<<endl;
	outFile.close();
	
	gotoxy (0, 97);
	system("pause");
}

void input_notes5(ofstream &outFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	FILE *fp;
	int choice;
	string new_name, line;
	string sentence;
	
	cin.ignore(INT_MAX,'\n');
	cin.clear();
	gotoxy (0, 6); cout << "Enter file name: ";
	getline(cin,new_name);
	
	clear();
	header();
	
	ifstream module5 ("module5.txt");
			if (module5.is_open()){
				while (getline (module5, line)){
					cout << line << endl;
				}
			module5.close();
			}
			else
				cout << "Unable to open the file.";
			
	access.mod5 = access.mod5 + new_name + ".txt";
	outFile.open("record_module_name.txt");
	outFile<<access.mod5<<endl;
	outFile.close();

	gotoxy (0,57); cout << access.mod5 << endl << endl;
	gotoxy (0, 59); cout << "INSTRUCTION: Enter '|' if you want to end writing notes.";
	gotoxy (2, 60);  cout << "==================================================================================================================";
	gotoxy (2, 61); cout << "|                                                                                                                |";
	gotoxy (2, 62); cout << "==================================================================================================================";
	gotoxy (2, 63); cout << "|                                                                                                                |";
	gotoxy (2, 64); cout << "|                                                                                                                |";
	gotoxy (2, 65); cout << "|                                                                                                                |";
	gotoxy (2, 66); cout << "|                                                                                                                |";
	gotoxy (2, 67); cout << "|                                                                                                                |";
	gotoxy (2, 68); cout << "|                                                                                                                |";
	gotoxy (2, 69); cout << "|                                                                                                                |";
	gotoxy (2, 70); cout << "|                                                                                                                |";
	gotoxy (2, 71); cout << "|                                                                                                                |";
	gotoxy (2, 72); cout << "|                                                                                                                |";
	gotoxy (2, 73); cout << "|                                                                                                                |";
	gotoxy (2, 74); cout << "|                                                                                                                |";
	gotoxy (2, 75); cout << "|                                                                                                                |";
	gotoxy (2, 76); cout << "|                                                                                                                |";
	gotoxy (2, 77); cout << "|                                                                                                                |";
	gotoxy (2, 78); cout << "|                                                                                                                |";
	gotoxy (2, 79); cout << "|                                                                                                                |";
	gotoxy (2, 80); cout << "|                                                                                                                |";
	gotoxy (2, 81); cout << "|                                                                                                                |";
	gotoxy (2, 82); cout << "|                                                                                                                |";
	gotoxy (2, 83); cout << "|                                                                                                                |";
	gotoxy (2, 84); cout << "|                                                                                                                |";
	gotoxy (2, 85); cout << "|                                                                                                                |";
	gotoxy (2, 86); cout << "|                                                                                                                |";
	gotoxy (2, 87); cout << "|________________________________________________________________________________________________________________|";
	gotoxy (50, 61); cout << "TYPE YOUR NOTES\n"; 
	
	string sentence_holder;
	int counter = 0;
	bool enter_sentence = true;
	while(enter_sentence == true){
		gotoxy (5, 63 + counter); getline(cin,sentence);
		if(sentence == "|")
			enter_sentence = false;
		sentence_holder = sentence_holder + sentence + "\n";
		counter++;
	}
	
	outFile << "\n\nModule 5 notes:\n\n" << sentence;
	outFile.open(access.mod5, ios::app);
	outFile<<sentence_holder<<endl;
	outFile.close();
	
	gotoxy (0, 88);
	system("pause");
}	

void view_notes (ifstream &inFile) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	
	int modchoice, choice, counter=0;
	string open_file;
	read_module_record(inFile);
	
	header();
	cout << "\n\n";
	
	cout << "NOTES:\n\n";
	cout << "[1] Module 1: Cell Theory\n";
	cout << "[2] Module 2: Cell Structure and Function\n";
	cout << "[3] Module 3: Eukaryotic Cells vs Prokaryotic Cells\n";
	cout << "[4] Module 4: Cell Types\n";
	cout << "[5] Module 5: Cell Cycle\n";
	cout << "Enter choice: ";
	cin >> modchoice;
	switch (modchoice) {
		case 1:
			clear();
			header();
			gotoxy (50, 6); cout << "Module 1 notes: \n";
			inFile.open(access.mod1);
			while(!inFile.eof()){
				getline(inFile, open_file,'\n');
				gotoxy (25, 15 + counter); cout << open_file << endl;
				counter++;
			}
			inFile.close();
			break;
		case 2:
			clear();
			header();
			gotoxy (50, 6); cout << "Module 2 notes: \n";
			inFile.open(access.mod2);
			while(!inFile.eof()){
				getline(inFile, open_file,'\n');
				gotoxy (10, 15 + counter); cout << open_file << endl;
				counter++;
			}
			inFile.close();
			break;
		case 3:
			clear();
			header();
			gotoxy (50, 6); cout << "Module 3 notes: \n";
			inFile.open(access.mod3);
			while(!inFile.eof()){
				getline(inFile, open_file,'\n');
				gotoxy (10, 15 + counter); cout << open_file << endl;
				counter++;
			}
			inFile.close();
			break;
		case 4:
			clear();
			header();
			gotoxy (50, 6); cout << "Module 4 notes: \n";
			inFile.open(access.mod4);
			while(!inFile.eof()){
				getline(inFile, open_file,'\n');
				gotoxy (10, 15 + counter); cout << open_file << endl;
				counter++;
			}
			inFile.close();
			break;
		case 5:
			clear();
			header();
			gotoxy (50, 6); cout << "Module 5 notes: \n";
			inFile.open(access.mod5);
			while(!inFile.eof()){
				getline(inFile, open_file,'\n');
				gotoxy (10, 15 + counter); cout << open_file << endl;
				counter++;
			}
			inFile.close();
			break;
		default:
			clear();
			header();
			cout << "No file detected.\n";
			system("pause");
			menu(choice);
		}
	inFile.close();
}

void read_module_record(ifstream &inFile) {
	string access_record;
	int counter = 0;
	
	inFile.open("record_module_name.txt");
	
	while(!inFile.eof()){ //while the recorder for "record_module.... is not at the end of the file then loop continues
		getline(inFile,access_record,'\n'); //this transfers inFile contents to access_record, then limits the read if it detects enter "\n" or newline
		if( counter == 0 && access_record != "\0")//if counter is 0 and != to null then sets the mod1 to access_record
			access.mod1 = access_record;
		else if(counter == 1 && access_record != "\0")
			access.mod2 = access_record;
		else if (counter == 2 && access_record != "\0")
			access.mod3 = access_record;
		counter++;
	}
	
	inFile.close();		
}

void modquiz1 (int) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 9);
	char q[9];
	int score=0;
	int choice;
	
	header();
	gotoxy(30,15); cout << "Welcome to the Module 1 quiz. \n";
	gotoxy(30,16); cout << "This is a multiple choice 10-question item quiz. \n";
	gotoxy(30,17); cout << "Goodluck! \n";
	
	gotoxy(1,30);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "1) This scientist coined the term 'cell' \n\n";
	gotoxy(30,13); cout << "[a] Robert Hooke \n";
	gotoxy(30,14); cout << "[b] Matthia Schleiden \n";
	gotoxy(30,15); cout << "[c] Antony van Leeuwenhoek \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[0];
		if (q[0]== 'a' || q[0]=='A' )
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "2) This scientist famously said that all cells only arise\n";
	gotoxy(30,12); cout << "   from pre-existing cells \n\n";
	gotoxy(30,14); cout << "[a] Theodor Schwann \n";
	gotoxy(30,15); cout << "[b] Rudolf Virchow \n";
	gotoxy(30,16); cout << "[c] Robert Brown \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[1];
		if (q[1]=='b' || q[1]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "3) Spontaneous generation is otherwise known as: \n\n";
	gotoxy(30,13); cout << "[a] Sapeogenesis \n";
	gotoxy(30,14); cout << "[b] Theogenesis \n";
	gotoxy(30,15); cout << "[c] Abiogenesis \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[2];
		if (q[2]=='c'|| q[2]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "4) Which among the choices are NOT part of the Cell Theory? \n\n";
	gotoxy(30,13); cout << "[a] Living things are composed of one or more cells. \n";
	gotoxy(30,14); cout << "[b] Organisms are either eukaryotic or prokaryotic. \n";
	gotoxy(30,15); cout << "[c] The Cell is the basic unit of life. \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[3];
		if (q[3]=='b' || q[3]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "5) Antony van Leeuwenhoek collectively called the single-celled organisms\n";
	gotoxy(30,12); cout << "   he observed under the microscope: \n\n";
	gotoxy(30,14); cout << "[a] Animalcules \n";
	gotoxy(30,15); cout << "[b] Protistas \n";
	gotoxy(30,16); cout << "[c] Microscoplings \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[4];
		if (q[4]=='a' || q[4]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "6) Cells arise from other cells through: \n\n";
	gotoxy(30,13); cout << "[a] Regeneration \n";
	gotoxy(30,14); cout << "[b] Budding \n";
	gotoxy(30,15); cout << "[c] Cellular division \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[5];
		if (q[5]=='c' || q[5]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "7) Leeuwenhoek, the one behind the earliest microscope was a Dutch: \n\n";
	gotoxy(30,13); cout << "[a] Botanist \n";
	gotoxy(30,14); cout << "[b] Shopkeeper \n";
	gotoxy(30,15); cout << "[c] Craftsman \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[6];
		if (q[6]=='b'|| q[6]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "8) The phrase 'Omnis cellula e cellula' means: \n\n";
	gotoxy(30,13); cout << "[a] All cells only arise from pre-existing cells. \n";
	gotoxy(30,14); cout << "[b] The cell is the basic unit of life. \n";
	gotoxy(30,15); cout << "[c] Living things are composed of one or more cells. \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[7];
		if (q[7]=='a'|| q[7]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "9) What is the name of the publication from 1655 wherein the\n";
	gotoxy(30,12); cout << "   term cell was first coined? \n\n";
	gotoxy(30,14); cout << "[a] Sciencia Potentia Est \n";
	gotoxy(30,15); cout << "[b] Cellula \n";
	gotoxy(30,16); cout << "[c] Microphagia \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[8];
		if (q[8]=='c'|| q[8]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "10) What was the kind of tissue observed by Robert Hooke through lens? \n\n";
	gotoxy(30,13); cout << "[a] Parenchyma Tissue \n";
	gotoxy(30,14); cout << "[b] Cork Tissue \n";
	gotoxy(30,15); cout << "[c] Vascular Tissue \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[9];
		if (q[9]=='b' || q[9]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,13); cout << "Your score is " << score << " out of 10 items";

	char ak_choice;
	
	gotoxy(30,14); cout << "Would you like to see the answer key? Y or N \n";
	gotoxy(30,15); cout << "Enter choice: ";
	cin >> ak_choice;
		if (ak_choice=='Y' || ak_choice=='y')
		{
			gotoxy(1,29);
			system("PAUSE");
			clear();
			header();
			gotoxy (35,9);  cout << "A. Robert Hooke                 1) This scientist coind the term 'cell' \n";
			gotoxy (35,10); cout << "B. Rudolf Virchow               2) This scientist famously said that all\n";
			gotoxy (35,11); cout << "                                   cells only arise from pre-existing cells \n";
			gotoxy (35,12); cout << "C. Abiogenesis                  3) Spontaneous generation is otherwise known as\n";
			gotoxy (35,13); cout << "B. Organisms are either         4) Which among are NOT part of the Cell Theory:  \n";
			gotoxy (35,14); cout << "   eukaryotic or prokaryotic\n";
			gotoxy (35,15); cout << "A. Animalcules                  5) Antony van Leeuwenhoek collectively called the single-\n";
			gotoxy (35,16); cout << "                                   celled organisms he observed under the microscope:\n";
			gotoxy (35,17); cout << "C. Cellular Division            6) Cells arise from other cells through\n";
			gotoxy (35,18); cout << "B. Shopkeeper                   7) Leewenhoek, the one behind the earlies microscope,\n";
			gotoxy (35,19); cout << "                                   was a Dutch: \n";
			gotoxy (35,20); cout << "A. All cells only arise from    8) The phrase 'Omnis cellula e cellula' means:\n";
			gotoxy (35,21); cout << "   pre-existing cells \n";
			gotoxy (35,22); cout << "C. Microphagia                  9) What is the name of the publication from 1655\n";
			gotoxy (35,23); cout << "                                   wherein teh term cell was frist coined?\n";
			gotoxy (35,24); cout << "B. Cork tissue                 10) What was the kind of tissue observed by Robert Hooke\n";
			gotoxy (35,25); cout << "                                   through lens? \n";
			
			gotoxy(1,29);
			system("PAUSE");
			clear();
			menu(choice);
		} else {
			exitprogram();
		}
	return;
}


void modquiz2 (int) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 9);
	char q[9];
	int score=0;
	int choice;
	
	header();
	gotoxy(30,15); cout << "Welcome to the Module 2 quiz. \n";
	gotoxy(30,16); cout << "This is a multiple choice 10-question item quiz. \n";
	gotoxy(30,17); cout << "Goodluck! \n";
	
	gotoxy(1,30);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "1) Every cell i a person's body is enclosed by a ____ \n\n";
	gotoxy(30,13); cout << "[a] Cell membrane \n";
	gotoxy(30,14); cout << "[b] Cellular lining \n";
	gotoxy(30,15); cout << "[c] Cell sheet \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[0];
		if (q[0]== 'a' || q[0]=='A' )
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "2) Cell membrane is also called: \n\n";
	gotoxy(30,13); cout << "[a] Cell wall \n";
	gotoxy(30,14); cout << "[b] Plasma membrane \n";
	gotoxy(30,15); cout << "[c] Cellular layer \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[1];
		if (q[1]=='b' || q[1]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "3) It is a dense region of ribonucleic acid in the nucleus and site\n";
	gotoxy(30,12); cout << "   of ribosome formation.\n\n";
	gotoxy(30,14); cout << "[a] Endoplasmic reticulum \n";
	gotoxy(30,15); cout << "[b] Mitochondria \n";
	gotoxy(30,16); cout << "[c] Nucleolus \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[2];
		if (q[2]=='c'|| q[2]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "4) Within the cytoplasm, materials move by of: \n\n";
	gotoxy(30,13); cout << "[a] Adhesion \n";
	gotoxy(30,14); cout << "[b] Diffusion \n";
	gotoxy(30,15); cout << "[c] Scattering \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[3];
		if (q[3]=='b' || q[3]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "5) This fluid is the medium for chemical reaction. \n\n";
	gotoxy(30,13); cout << "[a] Cytoplasm \n";
	gotoxy(30,14); cout << "[b] Nucleoplasm \n";
	gotoxy(30,15); cout << "[c] Riboplasm \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[4];
		if (q[4]=='a' || q[4]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "6) Which of the following is NOT an organelle? \n\n";
	gotoxy(30,13); cout << "[a] Lysosomes \n";
	gotoxy(30,14); cout << "[b] Golgo apparatus \n";
	gotoxy(30,15); cout << "[c] Villi \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[5];
		if (q[5]=='c' || q[5]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "7) Which of the folliwng is NOT a function of cytoplasm? \n\n";
	gotoxy(30,13); cout << "[a] Cell expansion \n";
	gotoxy(30,14); cout << "[b] Cell conversion \n";
	gotoxy(30,15); cout << "[c] Cell growth \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[6];
		if (q[6]=='b'|| q[6]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "8) The nucleus is the ___ of the cell. \n\n";
	gotoxy(30,13); cout << "[a] Control center \n";
	gotoxy(30,14); cout << "[b] Trash can \n";
	gotoxy(30,15); cout << "[c] Source code \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[7];
		if (q[7]=='a'|| q[7]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "9) The cell membrane is a double layer of ____ molecules. \n";
	gotoxy(30,13); cout << "[a] Carbohydrate Est \n";
	gotoxy(30,14); cout << "[b] Inorganic \n";
	gotoxy(30,15); cout << "[c] Phospholipid \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[8];
		if (q[8]=='c'|| q[8]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "10) Which of the following is NOT a provision of the cell membrane? \n\n";
	gotoxy(30,13); cout << "[a] Structural support \n";
	gotoxy(30,14); cout << "[b] Cell nutrition \n";
	gotoxy(30,15); cout << "[c] Identification markers \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[9];
		if (q[9]=='b' || q[9]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,13); cout << "Your score is " << score << " out of 10 items";
	
	char ak_choice;
	
	gotoxy(30,14); cout << "Would you like to see the answer key? Y or N \n";
	gotoxy(30,15); cout << "Enter choice: ";
	cin >> ak_choice;
		if (ak_choice=='Y' || ak_choice=='y')
		{
			gotoxy(1,29);
			system("PAUSE");
			clear();
			header();
			gotoxy (35,9);  cout << "A. Cell membrane              1) Every cell in a person's body is enclosed by a __  \n";
			gotoxy (35,10); cout << "B. Plasma membrane            2) Cell membrane is also called: \n";
			gotoxy (35,11); cout << "C. Nucleolus                  3) It is a dense region of ribonucleic acid in the\n";
			gotoxy (35,12); cout << "                                 nucleus and site of ribosome formation. \n";
			gotoxy (35,13); cout << "B. Diffusion                  4) Within the cytoplasm, materials move by of: \n";
			gotoxy (35,14); cout << "A. Cytoplasm                  5) This fluid is the medium for chemical reaction.\n";
			gotoxy (35,15); cout << "C. Villi                      6) Which of the following is NOT an organelle? \n";
			gotoxy (35,16); cout << "B. Cell conversion            7) Which of the folliwng is NOT a function of cytoplasm? \n";
			gotoxy (35,17); cout << "A. Control center             8) The nucleus is the _ of the cell.\n";
			gotoxy (35,18); cout << "C. Phospholipid               9) The cell membrane is a double layer of __ molecules. \n";
			gotoxy (35,19); cout << "B.  Cell nutrition           10) Which of the following is NOT a provision of the cell membrane? \n";
			
			gotoxy(1,29);
			system("PAUSE");
			clear();
			menu(choice);
		} else {
			exitprogram();
		}
	return;	
}

void modquiz3 (int) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 9);
	char q[9];
	int score=0;
	int choice;
	
	header();
	gotoxy(30,15); cout << "Welcome to the Module 3 quiz. \n";
	gotoxy(30,16); cout << "This is a multiple choice 10-question item quiz. \n";
	gotoxy(30,17); cout << "Goodluck! \n";
	
	gotoxy(1,30);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "1) Prokaryotic cells range from 0.1 to ___ um in diameter. \n";
	gotoxy(30,13); cout << "[a] 5.0 \n";
	gotoxy(30,14); cout << "[b] 10.0 \n";
	gotoxy(30,15); cout << "[c] 3.0 \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[0];
		if (q[0]== 'a' || q[0]=='A' )
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "2) Unlike eukaryotic cells, prokaryotice cells do not have: \n";
	gotoxy(30,13); cout << "[a] Ribosomes \n";
	gotoxy(30,14); cout << "[b] Golgi apparatus \n";
	gotoxy(30,15); cout << "[c] Cytoplasm \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[1];
		if (q[1]=='b' || q[1]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "3) It is microtubule-organizing center. \n";
	gotoxy(30,13); cout << "[a] Endoplasmic reticulum \n";
	gotoxy(30,14); cout << "[b] Vacuole\n";
	gotoxy(30,15); cout << "[c] Centorsome \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[2];
		if (q[2]=='c'|| q[2]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "4) These organelles carry out photosynthesis in plants. \n";
	gotoxy(30,13); cout << "[a] Chlorosomes \n";
	gotoxy(30,14); cout << "[b] Chloroplasts \n";
	gotoxy(30,15); cout << "[c] Central vacuoles \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[3];
		if (q[3]=='b' || q[3]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "5) Animal cells lack: \n";
	gotoxy(30,13); cout << "[a] Cell walls \n";
	gotoxy(30,14); cout << "[b] Lysosomes \n";
	gotoxy(30,15); cout << "[c] Centrosomes \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[4];
		if (q[4]=='a' || q[4]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "6) Which of the following is NOT a function of the cell wall? \n";
	gotoxy(30,13); cout << "[a] Protects the cell \n";
	gotoxy(30,14); cout << "[b] Provides structural support \n";
	gotoxy(30,15); cout << "[c] Converts carbon dioxide to oxygen \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[5];
		if (q[5]=='c' || q[5]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "7) Prokaryotic DNA is found in a central part of the cell: \n";
	gotoxy(30,13); cout << "[a] Vacuole \n";
	gotoxy(30,14); cout << "[b] Nucleoid \n";
	gotoxy(30,15); cout << "[c] Plastid \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[6];
		if (q[6]=='b'|| q[6]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "8) Which of the following statements is false?  \n";
	gotoxy(30,13); cout << "[a] A prokaryote relies on photosynthesis to thrive. \n";
	gotoxy(30,14); cout << "[b] A prokaryote is a simple, single-celled (unicellular) organism.\n";
	gotoxy(30,15); cout << "[c] A prokaryote lacks membrane-bound organelles. \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[7];
		if (q[7]=='a'|| q[7]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "9) It its where protein synthesis occurs. \n";
	gotoxy(30,13); cout << "[a] Lysosomes Est \n";
	gotoxy(30,14); cout << "[b] Centrioles \n";
	gotoxy(30,15); cout << "[c] Ribosomes \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[8];
		if (q[8]=='c'|| q[8]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "10) Eukaryotic cells' diameter range from 10 to ___ um. \n";
	gotoxy(30,13); cout << "[a] 80 \n";
	gotoxy(30,14); cout << "[b] 100 \n";
	gotoxy(30,15); cout << "[c] 60 \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[9];
		if (q[9]=='b' || q[9]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,13); cout << "Your score is " << score << " out of 10 items";
	
	char ak_choice;
	
	gotoxy(30,14); cout << "Would you like to see the answer key? Y or N \n";
	gotoxy(30,15); cout << "Enter choice: ";
	cin >> ak_choice;
		if (ak_choice=='Y' || ak_choice=='y')
		{
			gotoxy(1,29);
			system("PAUSE");
			clear();
			header();
			gotoxy (35,9);  cout << "A. 5.0                                  1) Prokaryotic cells range from 0.1 to _ um in diameter.  \n";
			gotoxy (35,10); cout << "B. Golgi apparatus                      2) Unlike eukaryotic cells, prokaryotic cells do not have: \n";
			gotoxy (35,11); cout << "C. Centorsome                           3) It is microtubule-organizing center. \n";
			gotoxy (35,12); cout << "B. Chloroplasts                         4) These organelles carry out photosynthesis in plants. \n";
			gotoxy (35,13); cout << "A. Cell walls                           5) Animal cells lack: \n";
			gotoxy (35,14); cout << "C. Converts carbon dioxide to oxygen    6) Which of the following is NOT a function of the cell wall? \n";
			gotoxy (35,15); cout << "B. Nucleoid                             7) Prokaryotic DNA is found in a central part of the cell:  \n";
			gotoxy (35,16); cout << "A. A prokaryote relies on               8) Which of the following statements is false? \n";
			gotoxy (35,17); cout << "   photosynthesis to thrive.\n";
			gotoxy (35,18); cout << "C. Ribosomes                            9) It is where protein synthesis occurs.  \n";
			gotoxy (35,19); cout << "B.  100                                10) Eukaryotic cells' diameter range from 10 to _ um  \n";
			
			gotoxy(1,29);
			system("PAUSE");
			clear();
			menu(choice);
		} else {
			exitprogram();
		}
	return;
}

void modquiz4 (int) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 9);
	char q[9];
	int score=0;
	int choice;
	
	header();
	gotoxy(30,15); cout << "Welcome to the Module 4 quiz. \n";
	gotoxy(30,16); cout << "This is a multiple choice 10-question item quiz. \n";
	gotoxy(30,17); cout << "Goodluck! \n";
	
	gotoxy(1,30);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "1) Which of the following is NOT a type of bone cell? \n";
	gotoxy(30,13); cout << "[a] Osteosome \n";
	gotoxy(30,14); cout << "[b] bOsteoclast \n";
	gotoxy(30,15); cout << "[c] Osteocyte \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[0];
		if (q[0]== 'a' || q[0]=='A' )
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "2) This type of blood cell help blood clot. \n";
	gotoxy(30,13); cout << "[a] Red blood cells \n";
	gotoxy(30,14); cout << "[b] Platelets \n";
	gotoxy(30,15); cout << "[c] White blood cells \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[1];
		if (q[1]=='b' || q[1]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "3) Which of the following is a function of a muscle cell? \n";
	gotoxy(30,13); cout << "[a] Carry oxygen throughout the blood \n";
	gotoxy(30,14); cout << "[b] Forms new bones \n";
	gotoxy(30,15); cout << "[c] Movement \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[2];
		if (q[2]=='c'|| q[2]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "4) This is another name for muscle cells. \n";
	gotoxy(30,12); cout << "[a] Myoblast \n";
	gotoxy(30,13); cout << "[b] Myocyte \n";
	gotoxy(30,14); cout << "[c] Myollum \n";
	gotoxy(30,15); cout << "Enter your answer: ";
	cin >> q[3];
		if (q[3]=='b' || q[3]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "5) Which of these statements are NOT true when it comes to\n";
	gotoxy(30,12); cout << "   sperm cells\n";
	gotoxy(30,14); cout << "[a] Sperm cells are also called adipocytes \n";
	gotoxy(30,15); cout << "[b] Sperm cells are motile \n";
	gotoxy(30,16); cout << "[c] Sperm cells cannot divide \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[4];
		if (q[4]=='a' || q[4]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "6) The tail of a sperm is also called:  \n";
	gotoxy(30,13); cout << "[a] Spermule \n";
	gotoxy(30,14); cout << "[b] Diploid \n";
	gotoxy(30,15); cout << "[c] Flagellum \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[5];
		if (q[5]=='c' || q[5]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "7) Fat cells contain stored fats called:  \n";
	gotoxy(30,13); cout << "[a] Lipids \n";
	gotoxy(30,14); cout << "[b] Triglycerides \n";
	gotoxy(30,15); cout << "[c] Adipocytes \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[6];
		if (q[6]=='b'|| q[6]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "8) Which of the following statements is false? \n";
	gotoxy(30,13); cout << "[a] Nerve cells are also called neutrons. \n";
	gotoxy(30,14); cout << "[b] Nerve cells consist of two major parts - the cell body\n";
	gotoxy(30,15); cout << "    and nerve processes\n";
	gotoxy(30,16); cout << "[c] Nerve cells are made up of triglycerides \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[7];
		if (q[7]=='a'|| q[7]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "9) The nerve processes of a nerve cells consists of the axon \n";
	gotoxy(30,12); cout << "    and the ____\n";
	gotoxy(30,14); cout << "[a] Neurons Est \n";
	gotoxy(30,15); cout << "[b] Axioms \n";
	gotoxy(30,16); cout << "[c] Dendrites \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[8];
		if (q[8]=='c'|| q[8]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "10) The ___ contains the nucleus, and other organelles of\n";
	gotoxy(30,12); cout << "    a nerve cell.\n";
	gotoxy(30,14); cout << "[a] Nerve processes \n";
	gotoxy(30,15); cout << "[b] Central body \n";
	gotoxy(30,16); cout << "[c] Ovary 60 \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[9];
		if (q[9]=='b' || q[9]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,13); cout << "Your score is " << score << " out of 10 items";
	
	char ak_choice;
	
	gotoxy(30,14); cout << "Would you like to see the answer key? Y or N \n";
	gotoxy(30,15); cout << "Enter choice: ";
	cin >> ak_choice;
		if (ak_choice=='Y' || ak_choice=='y')
		{
			gotoxy(1,29);
			system("PAUSE");
			clear();
			header();
			gotoxy (35,9);  cout << "A. Osteosome                   1) Which of the following is NOT a type of bone cell?  \n";
			gotoxy (35,11); cout << "B. Platelets                   2) This type of blood cell help blood clot.  \n";
			gotoxy (35,12); cout << "C. Movement                    3) Which of the following is a function of a muscle cell?  \n";
			gotoxy (35,13); cout << "B. Myocyte                     4) This is another name for muscle cells.  \n";
			gotoxy (35,14); cout << "A. Sperm cells are             5) Which of these statements are NOT true when it comes to sperm cells \n";
			gotoxy (35,15); cout << "   also called adipocytes\n";
			gotoxy (35,16); cout << "C. Spermule                    6) The tail of a sperm is also called:  \n";
			gotoxy (35,17); cout << "B. Triglycerides               7) Fat cells contain stored fats called:  \n";
			gotoxy (35,18); cout << "A. Nerve cells are also        8) Which of the following statements is false? \n";
			gotoxy (35,19); cout << "   called neutrons.\n";
			gotoxy (35,20); cout << "C. Dendrites                   9) The nerve processes of a nerve cells consists of the axon  \n";
			gotoxy (35,21); cout << "B. Central body               10) The _ contains the nucleus, and other organelles of a nerve cell.  \n";
			
			gotoxy(1,29);
			system("PAUSE");
			clear();
			menu(choice);
		} else {
			exitprogram();
		}
	return;
}

void modquiz5 (int) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 9);
	char q[9];
	int score=0;
	int choice;
	
	header();
	gotoxy(30,15); cout << "Welcome to the Module 5 quiz. \n";
	gotoxy(30,16); cout << "This is a multiple choice 10-question item quiz. \n";
	gotoxy(30,17); cout << "Goodluck! \n";
	
	gotoxy(1,30);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "1) It is during this phase that the cell grows. \n";
	gotoxy(30,13); cout << "[a] Interphase \n";
	gotoxy(30,14); cout << "[b] Telophase \n";
	gotoxy(30,15); cout << "[c] Prophase \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[0];
		if (q[0]== 'a' || q[0]=='A' )
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "2) It is the process by which the cytoplasm of a cell is split into two\n";
	gotoxy(30,13); cout << "[a] Cytopathy \n";
	gotoxy(30,14); cout << "[b] Cytokinesis \n";
	gotoxy(30,15); cout << "[c] Cytosis \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[1];
		if (q[1]=='b' || q[1]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "3) Which of the following does NOT occur in interphase? \n";
	gotoxy(30,13); cout << "[a] The cells grow physically larger \n";
	gotoxy(30,14); cout << "[b] The cell duplicates the structure called the centrosome \n";
	gotoxy(30,15); cout << "[c] The cell divides its copied DNA and cytoplasm to make two new cells \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[2];
		if (q[2]=='c'|| q[2]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "4) Cells must grow, copy its DNA, and physically split into two daughter cells.\n";
	gotoxy(30,12); cout << "   This process is called the: \n";
	gotoxy(30,14); cout << "[a] Cell Creation \n";
	gotoxy(30,15); cout << "[b] Cell Cycle \n";
	gotoxy(30,16); cout << "[c] Cell Theory \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[3];
		if (q[3]=='b' || q[3]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "5) Which of the phase of interphase does the synthesis of the \n";
	gotoxy(30,12); cout << "   complete copy of the DNA occur?\n";
	gotoxy(30,14); cout << "[a] S Phase \n";
	gotoxy(30,15); cout << "[b] G1 Phase \n";
	gotoxy(30,16); cout << "[c] G2 Phase \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[4];
		if (q[4]=='a' || q[4]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "6) The cell grows more, makes proteins and organelles and begins to \n";
	gotoxy(30,12); cout << "   reorganize its contents in preparation for mitosis in what phase?\n";
	gotoxy(30,14); cout << "[a] S \n";
	gotoxy(30,15); cout << "[b] G1 \n";
	gotoxy(30,16); cout << "[c] G2 \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[5];
		if (q[5]=='c' || q[5]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "7) During ___ phase, the cell divides its copied DNA and cytoplasm\n";
	gotoxy(30,12); cout << "   to make two new cells.\n"; 
	gotoxy(30,14); cout << "[a] I \n";
	gotoxy(30,15); cout << "[b] M \n";
	gotoxy(30,16); cout << "[c] S \n";
	gotoxy(30,17); cout << "Enter your answer: ";
	cin >> q[6];
		if (q[6]=='b'|| q[6]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "8) Which of the following is NOT part of the Mitotic phase?  \n";
	gotoxy(30,13); cout << "[a] Cytophase \n";
	gotoxy(30,14); cout << "[b] Anaphase \n";
	gotoxy(30,15); cout << "[c] Metaphase \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[7];
		if (q[7]=='a'|| q[7]=='A')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "9) The mitotic spindle is a specialized structure made out of: \n";
	gotoxy(30,13); cout << "[a] Blood vessels Est \n";
	gotoxy(30,14); cout << "[b] Animalcules \n";
	gotoxy(30,15); cout << "[c] Microtubules\n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[8];
		if (q[8]=='c'|| q[8]=='C')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,11); cout << "10) Cytokinesis takes place differently in animal and plant cells. \n";
	gotoxy(30,13); cout << "[a] False \n";
	gotoxy(30,14); cout << "[b] True \n";
	gotoxy(30,15); cout << "[c] Only animals have cytokinesis. \n";
	gotoxy(30,16); cout << "Enter your answer: ";
	cin >> q[9];
		if (q[9]=='b' || q[9]=='B')
		{
			score= score+1;
		}
	
	gotoxy(1,29);
	system("PAUSE");
	clear();
	header();
	
	gotoxy(30,13); cout << "Your score is " << score << " out of 10 items";
	
	char ak_choice;
	
	gotoxy(30,14); cout << "Would you like to see the answer key? Y or N \n";
	gotoxy(30,15); cout << "Enter choice: ";
	cin >> ak_choice;
		if (ak_choice=='Y' || ak_choice=='y')
		{
			gotoxy(1,29);
			system("PAUSE");
			system("CLS");
			gotoxy (35,9);  cout << "A. Interphase                                1)  It is during this phase that the cell grows.  \n";
			gotoxy (35,10); cout << "B. Cytokinesis                               2) It is the process by which the cytoplasm of a cell is split into two.  \n";
			gotoxy (35,11); cout << "C. The cell divides its copied               3) Which of the following does NOT occur in interphase?   \n";
			gotoxy (35,12); cout << "   DNA and cytoplasm to make two new cells\n";
			gotoxy (35,13); cout << "B. Cell Cycle                                4) Cells must grow, copy its DNA, and physically split into two daughter\n";
			gotoxy (35,14); cout << "                                                cells. This process is called the:  \n";
			gotoxy (35,15); cout << "A. S Phase                                   5) Which of the phase of interphase does the synthesis of the complete copy\n";
			gotoxy (35,16); cout << "                                                of the DNA occur?  \n";
			gotoxy (35,17); cout << "C. G2                                        6) The cell grows more, makes proteins and organelles and begins to reorganize\n";
			gotoxy (35,18); cout << "                                                its contents in preparation for mitosis in what phase?  \n";
			gotoxy (35,19); cout << "B. M                                         7) During _ phase, the cell divides its copied DNA and cytoplasm  \n";
			gotoxy (35,20); cout << "A. Cytophase                                 8)Which of the following is NOT part of the Mitotic phase? \n";
			gotoxy (35,21); cout << "C. Microtubules                              9) The mitotic spindle is a specialized structure made out of:  \n";
			gotoxy (35,22); cout << "B. True                                     10) Cytokinesis takes place differently in animal and plant cells.   \n";
			
			gotoxy(1,29);
			system("PAUSE");
			clear();
			menu(choice);
		} else {
			exitprogram();
		}
	return;
}


int gwa(double &average) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h, 15);
	Grades myGrades; 
	float score[5];
	char back_menu;
	int choice;
	
	cout << "\n\nEnter your grade for the Module Quizzes: " << endl << endl; 
	for(int i=0; i<5; i++) {
		bool repeat_Score = true;
		while(repeat_Score == true) {
			cout << "Module " << i + 1 << " Quiz Grade: " << endl;
			cin >> score[i];
			score[i] = (score[i] / 10) * 100;
			if(score[i] == false || (score[i] > 100 || score[i] < 0)) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');	
				repeat_Score = true;
			}
			else repeat_Score = false;
		}
	}
	clear();
	header();
	
	myGrades.setScore(score);
	gotoxy (15, 8); cout << records.name  << " here is the summary of your grades: \n";
	gotoxy (20, 10); cout << "Your average grade for the Module Quizzes is: " << endl;
	gotoxy (20, 11); cout << myGrades.computeRawScore() << endl << endl;
	gotoxy (20, 13); cout << "Your grade for this Module is: " << endl;
	gotoxy (20, 14); cout << myGrades.matchRawScore() << endl;
	
	gotoxy (20, 18);
	system("pause");

	return average;
}

void Grades::setScore(float *score) {
	for(int i = 0; i < sizeof(score)-1; i++)
		quizscore[i] = score[i];	
}

double Grades::computeRawScore() {
    	return ((quizscore[0] + quizscore[1] + quizscore[2] + quizscore[3] + quizscore[4]) / 5);
    	system("pause");
}

string Grades:: matchRawScore() {
    if(computeRawScore() >= 95.8 && computeRawScore() <= 100)
    	return "A+";
    else if(computeRawScore() >= 91.5 && computeRawScore() <= 95.7)
    	return "A-";
    else if(computeRawScore() >= 87.2 && computeRawScore() <= 91.4)
    	return "B+";
    else if(computeRawScore() >= 82.9 && computeRawScore() <= 87.1)
    	return "B";
    else if(computeRawScore() >= 78.6 && computeRawScore() <= 82.8)
    	return "B-";
    else if(computeRawScore() >= 74.3 && computeRawScore() <= 78.5)
    	return "C";
    if(computeRawScore() >= 70.00 && computeRawScore() <= 74.2)
    	return "D";
    if(computeRawScore() < 70.0)
    	return "E";
}

void logo () {
	
	gotoxy (12, 12); cout << "	      *******        **************    ********         *******   __________   _________   __________                    " << endl;
 	gotoxy (12, 13); cout << "         *********       **************   ***********       *******   |           |         |  |         |   ||      |     " << endl;
 	gotoxy (12, 14); cout << "       ****   *****      **************   ************      *******   |           |         |  |          |  | |     |     " << endl;
 	gotoxy (12, 15); cout << "     *****     *****     **************   ****    ****      *******   |           |         |  |           | |  |    |     " << endl;
 	gotoxy (12, 16); cout << "    ****        *****       ********      ****     ****     *******   |_______    |_________|  |          |  |   |   |     " << endl;
 	gotoxy (12, 17); cout << "   ****                     ********      ****    ****      *******   |           |         |  |_________|   |    |  |     " << endl;
 	gotoxy (12, 18); cout << "  ****                      ********      ****    ***       *******   |           |         |  |         |   |     | |     " << endl;
 	gotoxy (12, 19); cout << "  ****                      ********      **********        *******   |           |         |  |          |  |      ||     " << endl;
 	gotoxy (12, 20); cout << "   ****                     ********      ***********       *******   |_________  |         |  |           | |       |     " << endl;
 	gotoxy (12, 21); cout << "    ****         ****       ********      ************      *******                                                        " << endl;
	gotoxy (12, 22); cout << "     *****     *****        ********      *****   *****     *************                                                  " << endl;
 	gotoxy (12, 23); cout << "      *****   *****         ********      *****    *****    *************                                                  " << endl;
 	gotoxy (12, 24); cout << "        *********           ********      *****     *****   *************                                                  " << endl;
 	gotoxy (12, 25); cout << "         *******            ********      *****      *****  *************                                                  " << endl;

}

void logo_repeat () {
	
	char slogan[22] = "Control Your Learning";
 	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	Sleep(1000);
	clear();
		SetConsoleTextAttribute (h, 10);
		logo();
		Sleep(500);
	clear();
		SetConsoleTextAttribute (h, 12);
		logo();
		Sleep(500);
 	clear();
		SetConsoleTextAttribute (h, 7);
		logo();
		Sleep(500);
	clear();
		SetConsoleTextAttribute (h, 6);
		logo();
		Sleep(500);
	clear();
		SetConsoleTextAttribute (h, 4);
		logo();
		Sleep(500);	
	cout << endl << endl;
	cout << "\t";
	for (int i=0; i<22; i++) {
		SetConsoleTextAttribute (h, 8);
		cout << slogan[i] << "     ";
		Beep(500, 250);
	}
	cout << "\n\n\n\n\n";
	
	Sleep(1000);
	clear();
}
