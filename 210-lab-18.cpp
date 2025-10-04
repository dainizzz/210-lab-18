// COMSC-210 | Lab 18 | Dainiz Almazan
// IDE used: CLion

// movie reviewer: watches a film, rates it, provides comments
// write a program to store the reviews by reviewers
// this will be a linked list w/ nodes having a rating and a comment
// write code to add nodes to tail of linked list
// also add code for adding nodes to head of linked list
// at program startup ask which mode to use (head or tail)
// prompt user to enter data and store in linked list
// after inputting all reviews, traverse linked list to output the data and calculate/output average review

#include <iostream>
using namespace std;

int main() {
	int listMethod;
	double tempRating;
	string tempComment;
	char choice;

	cout << "Which linked list method should we use?" << endl;
	cout << "\t [1] New nodes are added to the head of the linked list" << endl;
	cout << "\t [2] New nodes are added to the tail of the linked list" << endl;
	cout << "\tChoice: ";
	cin >> listMethod;

	cout << "Enter review rating 0-5: ";
	cin >> tempRating;
	cout << "Enter review comments: ";
	getline(cin, tempComment);
	cin.ignore();
	cout << "Enter another review? Y/N: ";
	cin >> choice;

	cout << "Outputting all reviews:" << endl;
	cout << "\t> Review #" << ":" << endl;
	cout << "\t> Average: ";

	return 0;
}
