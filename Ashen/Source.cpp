#include<Ashen/AshenStack.h>
#include<Ashen/AshenLinkedList.h>
#include<iostream>
using namespace std;
int main(){
	char ch = 'w';
	AshenLinkedList<int> stack;
	while (ch!='e')
	{
		cout << "Enter the options for AshenStack \n1.Push Value\n2.pop value\n";
		cin >> ch;
		switch (ch)
		{
		case '1':
			int x;
			cout << "Enter the new vaue to be pushed\n";
			cin >> x;
			stack.push(x);
			break;
		case '2':
			try
			{
				cout << stack.pop() << "\n";
			}
			catch (const std::exception& e)
			{
				cout << e.what() << "\n";
			}
			
			break;
		default:
			break;
		}
	}
}