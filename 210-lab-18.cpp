// COMSC-210 | Lab 18 | Dainiz Almazan
// IDE used: CLion

// write a program to store the reviews by reviewers
// write code to add nodes to tail of linked list
// also add code for adding nodes to head of linked list
// at program startup ask which mode to use (head or tail)
// prompt user to enter data and store in linked list
// after inputting all reviews, traverse linked list to output the data and calculate/output average review

#include <iostream>
using namespace std;

struct Node {
	double rating;
	string comment;
	Node *next;
};

// addNodeToHead() adds a new Node with the rating and comment values provided to the front of a linked list and sets the head to be the new node
// arguments: the head Node of a linked list, a double rating, a string comment
// returns: nothing
void addNodeToHead(Node *&, double, string);

// addNodeToTail() adds a new Node with the rating and comment values provided to the end of a linked list
// arguments: the head Node of a linked list, a double rating, a string comment
// returns: nothing
void addNodeToTail(Node *&, double, string);

int main() {
	// Initializing variables
	int listMethod, count;
	double tempRating, average;
	string tempComment;
	char choice;
	Node *head = nullptr;

	cout << "Which linked list method should we use?" << endl;
	cout << "\t [1] New nodes are added to the head of the linked list" << endl;
	cout << "\t [2] New nodes are added to the tail of the linked list" << endl;
	cout << "\tChoice: ";
	cin >> listMethod;

	do {
		cout << "Enter review rating 0-5: ";
		cin >> tempRating;
		cout << "Enter review comments: ";
		getline(cin, tempComment);
		cin.ignore();

		if (listMethod == 1)
			addNodeToHead(head, tempRating, tempComment);
		else
			addNodeToTail(head, tempRating, tempComment);

		cout << "Enter another review? Y/N: ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	cout << "Outputting all reviews:" << endl;
	Node *cur = head;
	while (cur != nullptr) {

	}
	cout << "\t> Review #" << ":" << endl;
	cout << "\t> Average: ";

	return 0;
}

void addNodeToHead(Node *&head, double rating, string comment) {
	// Creating a new Node with the values provided by the user
	Node *newNode = new Node();
	newNode->comment = comment;
	newNode->rating = rating;
	// Setting newNode->next to head to put newNode in front of head in the linked list
	newNode->next = head;
	// Setting head to newNode so that when we use the head pointer it's pointing to the correct node
	head = newNode;
}

void addNodeToTail(Node *&head, double rating, string comment) {
	// Creating a new Node with the values provided by the user
	Node *newNode = new Node();
	newNode->comment = comment;
	newNode->rating = rating;
	newNode->next = nullptr;
	// Traversing linked list until we reach the end (i.e. cur->next is nullptr)
	Node *cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	// Now that cur is the last node in the linked list, the new node is added after it
	cur->next = newNode;
}
