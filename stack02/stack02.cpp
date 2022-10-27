#include <iostream>
#include <list>
#include <stack>
using namespace std;

template<class T>
void list_stack_print(stack<T, list<T>> stack) {

   	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl << endl;
}

int main() {
	int arr_[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> list_(arr_, arr_ + 10);
	stack<int, list<int>> stack_(list_);
	stack<int, list<int>> stack_2(stack_);
	cout << "old_stack -> ";
	list_stack_print(stack_);
	cout << "new_stack -> ";
	list_stack_print(stack_2);
	while (stack_2.top() != 3) {
		if (stack_2.size() == 1)
			break;
		cout << "new_stack top -> " << stack_2.top() << endl;
		stack_.push(stack_2.top());
		stack_2.pop();
		cout << "\ndeleted & added to old stack.\n\nold_stack -> ";
		list_stack_print(stack_);
		cout << "new_stack -> ";
		list_stack_print(stack_2);
	}
	if (stack_2.top() == 3)
		cout << "3!";
	else
		cout << "there is no 3.";
}