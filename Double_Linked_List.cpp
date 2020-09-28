//Code for the creation of double linked lists and its basic functions.

//3/30/2020

//Santiago Monsalve-Mejia

//Data struc and algorythm analysis

// This program will create a double link list with n number of nodes based on the user's input

//The program will also allow the user to add and delete nodes from the link list

//Header #include using namespace std;

// Prorotypes

void CreateList(int n, struct Node*& start);

void DisplayList(Node* start);

void InsertNode(Node* start, int n);

void DeleteNode(Node* start, int n);

void eraseAll(Node* start);

int NodeCount(Node* start);

//Node Structure struct Node {

struct Node* left;
int data;
struct Node* right;
};

int main() {

//initialization and definition of starting node
Node* start = NULL;

//initialization and def of select, which is used for the switch statement 
//and the do while loop
int select = 0;

//initialization and def of variable n, which is used to ask for the users input
int n = 0;

//main do-while loop
do {

	//Menu selection output
	cout << "\nPlease select an option: " << endl
		<< "Enter 1 to create n number of nodes" << endl
		<< "Enter 2 to insert a node (in the middle)" << endl
		<< "Enter 3 to delete a node (in the middle)" << endl
		<< "Enter 0 to exit the program" << endl;
	//Menu selection output
	cin >> select;


	//Menu selection switch statement
	switch (select)
	{
	//case 1: CREATE LIST
	case 1:
		cout << "\nHow many nodes would you like to create?: " << endl;
		cin >> n;

		CreateList(n, start);

		cout << "\n\n\t" << n << " Nodes have been created" << endl;

		DisplayList(start);

		break;

	//case 2: INSERT NODE
	case 2:
		if (n == 0) {

			cout << "\nPlease create a new link list" << endl;
			break;

		}
		else
		{
			InsertNode(start, n);
			DisplayList(start);

		}
		break;


	//case 3: DELETE NODE
	case 3:

		DeleteNode(start, n);
		DisplayList(start);

		break;


	//defaule case: RETURN TO HEAD OF THE LOOP OR EXIT THE LOOP IF SELECT = 0;
	default:
		break;


	}

} while (select != 0);

//dealocation of memory
eraseAll(start);
start = NULL;

//end of program
cout << "\nEnd of program" << endl;
return 0;
}

//Function definitions Node* Createnode() { Node* NewNode; NewNode = new Node(); cout << "\nEnter Data" << endl; cin >> NewNode->data; NewNode->left = NULL; NewNode->right = NULL; return NewNode; }

void CreateList(int n, Node*& start) {

Node* NewNode, * Temp;

for (int i = 0; i < n; i++) {

	NewNode = Createnode();

	if (start == NULL) {

		start = NewNode;

	}
	else
	{
		Temp = start;
		while (Temp->right != NULL)
		{
			Temp = Temp->right;
		}
		Temp->right = NewNode;
		NewNode->left = Temp;
	}
}
}

void DisplayList(Node* start) {

Node* temp;
temp = start;
int cntr = 0;

if (start == NULL) {

	cout << "\nList is Empty" << endl;
	return;

}
else {
	cout << "\n\nYour list is: " << endl;
	cout << "\n";
	while (temp != NULL)
	{
		cout << "Node #" << cntr + 1 << "  Data: " << temp->data << endl;
		temp = temp->right;
		cntr++;
	}
	delete temp;
}
}

void InsertNode(Node* start, int n) { Node* NewNode, * temp, * prev; int pos, nodecount = NodeCount(start), count = 1;

cout << "\nAt what position would you like to insert the node?" << endl;
cin >> pos;

NewNode = Createnode();



if (pos > 1 && pos < nodecount) {

	temp = start;
	prev = start;
	while (count < pos) {

		prev = temp;
		temp = temp->right;
		count++;
	}

	NewNode->left = prev;
	NewNode->right = temp;
	prev->right = NewNode;
	temp->left = NewNode;
}
else if (start == NULL) {
	cout << "\nList is empty" << endl;
}
else
	cout << "\nNode position not in between" << endl;
}

void DeleteNode(Node* start, int n) {

Node* temp;
int pos, nodecount = NodeCount(start), count = 1;

cout << "\nAt what position would you like to delete the node?" << endl;
cin >> pos;





if (pos > 1 && pos < nodecount) {

	temp = start;

	while (count < pos) {


		temp = temp->right;
		count++;
	}

	temp->right->left = temp->left;
	temp->left->right = temp->right;
	delete temp;
}
else if (start == NULL) {
	cout << "\nList is empty" << endl;
}
else
	cout << "\nNode position not in between" << endl;
}

void eraseAll(Node* start) {

Node* temp, * prev;
temp = start;
prev = start;

if (start == NULL) {
	return;
}
else {

	while (temp != NULL) {

		prev = temp;
		temp = temp->right;
		delete prev;

	}

}
}

int NodeCount(Node* start){

if (start == NULL)
	return 0;
else
	return (1 + NodeCount(start->right));
}
