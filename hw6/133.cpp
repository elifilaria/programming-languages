#include <iostream>
#include <vector>
using namespace std;

//  struct Node {
//     int Data;
//     Node* Left;
//     Node* Right; 
// };

// Node* Find( Node* node, int value )
// {
//     if( node == NULL )
//         return NULL;
//     if( node->Data == value )
//         return node;
//     if( node->Data > value )
//         return Find( node->Left, value );
//     else
//         return Find( node->Right, value );
// };

// void Insert( Node* node, int value )
// {
//     if( node == NULL ) {
//         node = new Node( value );
//         return;
//     }
//     if( node->Data > value )
//         Insert( node->Left, value );
//     else
//         Insert( node->Right, value );
// };
void printVector (vector<int> v){
	cout << "(";
	for (int i = 0; i < v.size(); i++){
		if (i != v.size()-1){
			cout << v[i];
			if (i % 3 == 0) cout << ": ";
			else if (i % 3 != 2) cout << ", ";
			else cout << " | ";
			// elif (i % 3 == 1) cout << 
		}
		else cout <<v[i];
	}
	cout << ")" << endl;
}

void howManyRed (vector<int> &v){
	printVector (v);
	int num = 0;
	for (int i = 0; i < v.size()/3; i++)
	{
		if (v[i*3] == 0) num++;
	}
	cout << num << " " << num << endl;
	v.pop_back();
	v.pop_back();
	v.pop_back();
	if (v.size() == 0) return;
	howManyRed (v);
}

int main()
{
	vector<int> v;
	v.push_back(0);// red
	v.push_back(3);
	v.push_back(1);
	v.push_back(0);// red
	v.push_back(1);
	v.push_back(9);
	v.push_back(1);// not red
	v.push_back(3);
	v.push_back(6);
	v.push_back(0);// red
	v.push_back(1);
	v.push_back(8);
	v.push_back(1);// not red
	v.push_back(2);
	v.push_back(4);

	printVector (v);
	howManyRed (v);
	return 0;
}