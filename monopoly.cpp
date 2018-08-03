#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include "stack.hpp"

Node*       make_move(Node*);
int         dice_roll();
void        setup_board(stack&);



int numDoubles = 0;  //global int to track doubles
bool rolledDoubles = false;  //tracks number of doubles rolled in a row


int main() {
	srand(time(NULL));
	
	stack board;
	setup_board(board);
	
	
	float totalMoves;
	
	std::cout << "enter how many moves you want to make: " << std::endl;
	std::cin >> totalMoves;
	std::cout << std::endl;

	float movesMade = 0;
	Node* currentSpace = board.top();
	
	
	while (movesMade < totalMoves) {
		Node* newSpace = make_move(currentSpace);  //makes one move
		newSpace->data = newSpace->data + 1;            //marks that space was landed on
		movesMade++;
		currentSpace = newSpace;
	}

	currentSpace = board.top();

	std::cout << std::setw(25) << "property name" << std::setw(15) << "times landed" <<
		std::setw(15)  << "        percent landed" << std::endl << std::endl;

	for (int i = 0; i < 40; i++) {
		std::cout << std::setw(25) << currentSpace->name << " " << std::setw(15) << currentSpace->data <<
			" " << std::setw(15) << ((currentSpace->data/totalMoves) * 100) << " percent" << std::endl;

		currentSpace = currentSpace->next;
	}
}

void setup_board(stack& a) {
	std::ifstream in;
	in.open("list_of_spaces.txt");
	std::string name;
	
	for (int i = 0; i < 40; i++) {  //sets all spaces to count 0
		getline(in, name);
		a.push(0, name);
	}
	in.close();
}

Node* make_move(Node* node) {         //moves piece number of spaces based on die roll
	do {
		int numMoves = dice_roll();
		
		if (numMoves == 0) {           //dice roll returns 0 after 3 doubles in a row
			while (node->name != "Jail") {
				node = node->next;
			}
			return node;
		}
		for (int i = 0; i < numMoves; i++)
			node = node->next;
	} while (rolledDoubles == true);



	if (node->name == "Go To Jail")
		while (node->name != "Jail")
			node = node->next;

	return node;
}

int dice_roll() {    //generates sum of 2 dice rolled
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);

	if (a == b) {
		numDoubles++;
		rolledDoubles = true;
		if (numDoubles == 3) {
			numDoubles = 0;
			return 0;
		}
	}
	rolledDoubles = false;
	return (a + b);
}
