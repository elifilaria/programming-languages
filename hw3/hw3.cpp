#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node{
	string info;
	node *link;
};

void printList(node *head)
{
	node *current = head;

	if (head == NULL)
	{
		cout << "Empty list\n";
	}
	else{

		while (current != NULL)
		{
			cout << current->info << "  ";
			current = current->link;
		}
		cout << endl;
	}
}

void remove(node* head)
{
	node *current = head;
	while (current != NULL && current->link != NULL)
		{
			cout << current->info << "  ";
			node * next = current->link->link;
			current->link = current->link->link;
			current = next;
		}
		cout << endl;
}

void inputList(node* &head)
{
	node *temp;
	node *current;
	ifstream inFile;
	inFile.open("input.txt");
	if (!inFile) {
    cout << "Unable to open file input.txt";
    exit(1);   // call system to stop
	} else{
		current = new node();
		getline(inFile, current->info);
		temp = current;
		head = current;

		while (inFile){
			current = new node();
			getline(inFile, current->info);
			temp->link = current;
			temp = temp->link;
		}

		// head = 
		printList(head);
		remove(head);

	}

}


int main()
{

	node *head = NULL;

	inputList(head);

	printList(head);
}