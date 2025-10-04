// COMSC-210 | Lab 18 | Dainiz Almazan
// IDE used: CLion
#include <iostream>
#include <limits>
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

// getUserChoice prompts the user for a choice, validates it, and then returns it.
// arguments: none
// returns: a char value 'Y' or 'N'
char getUserChoice();

int getValidRating();

string getValidComment();

int main() {
	// Initializing variables
	int listMethod;
	double tempRating;
	string tempComment;
	char choice = 'Y';
	Node *head = nullptr;

	cout << "Which linked list method should we use?" << endl;
	cout << "\t [1] New nodes are added to the head of the linked list" << endl;
	cout << "\t [2] New nodes are added to the tail of the linked list" << endl;
	cout << "\tChoice: ";
	cin >> listMethod;

	while (choice != 'N') {
		tempRating = getValidRating();
		tempComment = getValidComment();
		// // TODO: How should this be validated? Can't this be anything?
		// cout << "Enter review comments: ";
		// while (!getline(cin, tempComment)) {
		// 	cout << "Invalid input. Please enter a review comment:";
		// 	cin.clear();
		// 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// }

		if (listMethod == 1)
			addNodeToHead(head, tempRating, tempComment);
		else
			addNodeToTail(head, tempRating, tempComment);

		choice = getUserChoice();
	}

	cout << "Outputting all reviews:" << endl;
	Node *cur = head;
	int count = 0;
	double total = 0;
	while (cur) {
		cout << "\t> Review #" << count + 1 << ": " << cur->rating << ": " << cur->comment << endl;
		count++;
		total += cur->rating;
		cur = cur->next;
	}
	cout << "\t> Average: " << total / count << endl;

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

	// If list is empty, just set the new node as head
	if (!head)
		head = newNode;
	else {
		// Otherwise, traverse linked list until we reach the end (i.e. cur->next is nullptr)
		Node *cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		// Now that cur is the last node in the linked list, the new node is added after it
		cur->next = newNode;
	}
}

char getUserChoice() {
	char temp;
	bool isValid = false;
	cout << "Enter another review? Y/N: ";
	while (!isValid) {
		if (cin >> temp) {
			if (temp == 'N' || temp == 'n' || temp == 'Y' || temp == 'y')
				isValid = true;
			else
				cout << "Invalid input. Please enter Y or N:" << endl;
		} else {
			cout << "Invalid input. Please enter Y or N:" << endl;
			cin.clear();
			// Clearing the number of characters inputted by the user
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	return toupper(temp);
}

int getValidRating() {
	int temp;
	bool isValid = false;
	cout << "Enter review rating 0-5: ";
	while (!isValid) {
		if (cin >> temp) {
			if (temp >= 0 && temp <= 5)
				isValid = true;
			else
				cout << "Invalid input. Please enter a review rating 0-5:";
		} else {
			cout << "Invalid input. Please enter a review rating 0-5:";
			cin.clear();
			// Clearing the number of characters inputted by the user
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return temp;
}

string getValidComment() {
	string temp;
	cout << "Enter review comments: ";
	while (!getline(cin, temp)) {
		cout << "Invalid input. Please enter a review comment:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return temp;
}
