#include <iostream>
#include <vector>
using namespace std;

void findAndReplace (char cold, char cnew, vector<char> &v){
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == cold) v[i] = cnew;
	}
}

void printVector (vector<char> v){
	cout << "(";
	for (int i = 0; i < v.size(); i++){
		if (i != v.size()-1)
			cout << v[i] << ", ";
		else cout << v[i];
	}
	cout << ")" << endl;
}

int main()
{
	char myOld = 'k';
	char myNew = 'j';
	vector<char> v;
	v.push_back('i');
	v.push_back('o');
	v.push_back('a');
	v.push_back('6');
	v.push_back('k');
	v.push_back('j');
	v.push_back('2');
	v.push_back('l');
	v.push_back('k');

	printVector (v);
	findAndReplace (myOld, myNew, v);
	printVector (v);
	return 0;
}