/*
2. Реализовать стек использую односвязный список.
a. stack_push
b. stack_pop
c. stack_top //вернуть указатель (или значение) хранимое на вершине стека
*/
#include <stdio.h>
#include <iostream>
#include <string>

#pragma warning(disable : 4996); //Директива препроцессора, которая отключает вывод предупреждения с кодом ошибки 4996.
//Код ошибки 4996 связан с использованием устаревших функций

using namespace std;

struct Node {
	Node(int data) : data(data), next(nullptr) {
	}

	int data;
	Node* next;
};

class TStack {
private:
	Node* top = NULL;

public:
	//Метод добавляет новый элемент на вершину стека
	void stack_push(int data) {
		Node* newNode = new Node(data);
		newNode->next = top;
		top = newNode;
	}
	//Метод  удаляет верхний элемент стека
	void stack_pop() {
		if (top == nullptr)
		{
			cout << "Стек пуст" << endl;
			exit(EXIT_FAILURE);
		}

		Node* tmp = top;
		top = top->next;
		delete tmp;
	}
	//Метод возвращает значение верхнего элемента стека.
	int stack_top() {
		if (top == nullptr)
		{
			cout << "Стек пуст" << endl;
			exit(EXIT_FAILURE);
		}
		else
			return top->data;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	TStack stack;

	stack.stack_push(1);
	stack.stack_push(2);
	stack.stack_push(3);

	cout << "Верхний элемент: " << stack.stack_top() << endl;
	stack.stack_pop();
	cout << "Верхний элемент: " << stack.stack_top() << endl;
	stack.stack_pop();
	cout << "Верхний элемент: " << stack.stack_top() << endl;
	stack.stack_pop();
	cout << "Верхний элемент: " << stack.stack_top() << endl;
	stack.stack_pop();
	cout << "Верхний элемент: " << stack.stack_top() << endl;

}