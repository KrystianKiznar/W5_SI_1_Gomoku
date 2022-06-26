#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;


vector<vector<char>> createVector2D(int m, int n) {

	vector<vector<char>>board;
	for (int j = 0; j < m; j++) {
		vector<char> row;
		for (int i = 0; i < n; i++)
			row.push_back('.');
		board.push_back(row);
	}
	return board;
}

void printVector2D(vector<vector<char>> v, int n, int m) {

	cout << "   ";
	for (int i = 0; i < m; i++) { 
		cout << (char)('A' + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (i < 10)
			cout << i << "  ";
		else
			cout << i << " ";

		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

char changeSign(char sign) {

	if (sign == 'X')
		sign = 'O';
	else
		sign = 'X';
	return sign;
}

int inputCol(int numberOfLetters) {
	char x;
	int col;
	numberOfLetters = 'A' + numberOfLetters;
	while (true) {
		cout << "Enter a column letter ";
		cin >> x;
		x = toupper(x);
		if ((x < 'A') || (x >= numberOfLetters)) {
			cout << "Input a proper letter!"<<endl;
			continue;
		}
		col = x - 'A';
		return col; 
		
	}
}

int inputRow(int rowNumber) {
	int y;
	while (true) {
		cout << "Enter a row number ";
		if (!(cin >> y)) {
			cin.clear();
			cin.ignore();
			continue;
		}
		else if ((y > rowNumber - 1) || (y < 0)) {
			cout << "Input a proper number!" << endl;
			continue;
		}
		return y;
	}
}

int main() {
	int m;
	int n;

	cout << "Enter a number of columns: >>";
	cin >> n;
	cout << "Enter a number of rows: >>";
	cin >> m;
	

	vector<vector<char>>board = createVector2D(m, n);
	printVector2D(board, m, n);
	int x;
	int y;
	char sign = 'X';
	while (true){
		x = inputCol(n);
		y = inputRow(m);
		board[y][x] = sign;
		sign = changeSign(sign);
		system("CLS");
		printVector2D(board, m, n);
	}
}