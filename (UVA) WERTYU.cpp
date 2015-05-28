#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main() {
	map <char,char> chars;
	chars['1'] = '`';
	chars['2'] = '1';
	chars['3'] = '2';   
	chars['4'] = '3';
	chars['5'] = '4';
	chars['6'] = '5';
	chars['7'] = '6';
	chars['8'] = '7';
	chars['9'] = '8';
	chars['0'] = '9';
	chars['B'] = 'V';
	chars['D'] = 'S';
	chars['E'] = 'W';
	chars['F'] = 'D';
	chars['G'] = 'F';
	chars['H'] = 'G';
	chars['I'] = 'U';
	chars['J'] = 'H';
	chars['K'] = 'J';
	chars['L'] = 'K';
	chars['N'] = 'B';
	chars['M'] = 'N';
	chars['O'] = 'I';
	chars['P'] = 'O';
	chars['R'] = 'E';
	chars['S'] = 'A';
	chars['T'] = 'R';
	chars['U'] = 'Y';
	chars['V'] = 'C';
	chars['W'] = 'Q';
	chars['X'] = 'Z';
	chars['Y'] = 'T';
	chars['-'] = '0';
	chars['='] = '-';
	chars['['] = 'P';
	chars[']'] = '[';
	chars[';'] = 'L';
	chars[','] = 'M';
	chars['.'] = ',';
	chars['/'] = '.';
	string line;
	while(getline(cin,line)) {
		for(int i=0;i<line.size();i++) {
			if(line[i] == ' ') printf(" ");
			if(line[i] == 92) printf("]");
			if(line[i] == 39) printf(";");
			printf("%c",chars[line[i]]);
		}
		printf("\n");
	}
	return 0;
}
