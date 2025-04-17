#include "List.h"

List::List() {
	this->Head.Data = 0;
	this->Tail.Data = 0;

	this->Head.Prev = nullptr;
	this->Tail.Next = nullptr;

	this->Head.Next = &(this->Tail);
	this->Tail.Prev = &(this->Head);

	std::cout << "List()" << '\n';
}

List::List(int Val) {
	this->Head.Data = 0;
	this->Tail.Data = 0;

	this->Head.Prev = nullptr;
	this->Tail.Next = nullptr;

	ListNode* elem = new ListNode;
	elem->Data = Val;
	elem->Next = &(this->Tail);
	elem->Prev = &(this->Head);
	this->Head.Next = elem;
	this->Tail.Prev = elem;
	std::cout << "List(int Val)" << '\n';
}

List::List(const List& Lst) {
	this->Head.Data = 0;
	this->Tail.Data = 0;

	this->Head.Prev = nullptr;
	this->Tail.Next = nullptr;

	this->Head.Next = &(this->Tail);
	this->Tail.Prev = &(this->Head);

	ListNode* curr = Lst.Head.Next;

	while (curr != (&Lst.Tail)) {
		this->Add(curr->Data);
		curr = curr->Next;
	}
	std::cout << "List(const List& Lst)" << '\n';
}

List::List(List&& Lst) {
	this->Head.Data = 0;
	this->Tail.Data = 0;

	this->Head.Prev = nullptr;
	this->Tail.Next = nullptr;

	this->Head.Next = Lst.Head.Next;
	this->Tail.Prev = Lst.Tail.Prev;

	Lst.Head.Next->Prev = &(this->Head);
	Lst.Tail.Prev->Next = &(this->Tail);

	Lst.Head.Next = &(Lst.Tail);
	Lst.Tail.Prev = &(Lst.Head);
	std::cout << "List(List&& Lst)" << '\n';
}

List::~List() {
	if (!this->IsEmpty()) this->Clear();
	std::cout << "~List()" << '\n';
}

List& List::operator = (const List& Lst) {
	if (this != &Lst) {
		this->Clear();
		ListNode* curr = Lst.Head.Next;

		while (curr != (&Lst.Tail)) {
			this->Add(curr->Data);
			curr = curr->Next;
		}
		std::cout << "List& operator = (const List& Lst)" << '\n';
	}
	return *this;
}

List& List::operator = (List&& Lst) {
	if (this != &Lst) {
		this->Clear();

		this->Head.Next = Lst.Head.Next;
		this->Tail.Prev = Lst.Tail.Prev;

		Lst.Head.Next->Prev = &(this->Head);
		Lst.Tail.Prev->Next = &(this->Tail);

		Lst.Head.Next = &(Lst.Tail);
		Lst.Tail.Prev = &(Lst.Head);

		std::cout << "List& operator = (List&& Lst)" << '\n';
	}
	return *this;
}

void List::Print() {
	ListNode* curr = this->Head.Next;
	
	while (curr != &(this->Tail)) {
		std::cout << curr->Data << " ";
		curr = curr->Next;
	}
	std::cout << std::endl;
}

void List::PrintReverse() {
	ListNode* curr = this->Tail.Prev;

	while (curr != &(this->Head)) {
		std::cout << curr->Data << " ";
		curr = curr->Prev;
	}
	std::cout << std::endl;
}

void List::Add(int Val) {
	ListNode* elem = new ListNode;
	elem->Data = Val;

	this->Tail.Prev->Next = elem;
	elem->Prev = this->Tail.Prev;
	elem->Next = &(this->Tail);
	this->Tail.Prev = elem;
}

void List::AddAfter(int Val, unsigned int Pos) {
	int count = 0;
	ListNode* elem = new ListNode;
	ListNode* curr = this->Head.Next;
	
	while (count != Pos && curr != &(this->Tail)) {
		curr = curr->Next;
		count++;
	}
	
	if (curr == &(this->Tail)) {
		elem->Data = Val;

		this->Tail.Prev->Next = elem;

		elem->Prev = Tail.Prev;
		elem->Next = &(this->Tail);

		this->Tail.Prev = elem;
		
		return;
	}
	
	elem->Data = Val;
	elem->Prev = curr;
	elem->Next = curr->Next;

	curr->Next->Prev = elem;
	curr->Next = elem;
}

void List::AddBefore(int Val, unsigned int Pos) {
	int count = 0;
	ListNode* elem = new ListNode;
	ListNode* curr = this->Head.Next;

	while (count != Pos && curr != &(this->Tail)) {
		curr = curr->Next;
		count++;
	}

	elem->Data = Val;
	elem->Prev = curr->Prev;
	elem->Next = curr;

	curr->Prev->Next = elem;
	curr->Prev = elem;
}

void List::Delete(int Val) {
	ListNode* curr = this->Head.Next;

	while (curr != &(this->Tail)) {
		if (curr->Data == Val) {
			curr->Next->Prev = curr->Prev;
			curr->Prev->Next = curr->Next;

			curr->Next = nullptr;
			curr->Prev = nullptr;

			delete curr;

			return;
		}
		curr = curr->Next;
	}
}

void List::DeleteAllWithVal(int Val) {
	ListNode* curr = this->Head.Next;

	while (curr != &(this->Tail)) {
		if (curr->Data == Val) {
			ListNode* tmp = curr;
			curr = curr->Next;
			tmp->Next->Prev = tmp->Prev;
			tmp->Prev->Next = tmp->Next;

			tmp->Next = nullptr;
			tmp->Prev = nullptr;

			delete tmp;
		}
		else curr = curr->Next;
	}
}

void List::Clear() {
	ListNode* curr = this->Head.Next;

	while (curr != &(this->Tail)) {

		ListNode* tmp = curr;
		curr = curr->Next;
		tmp->Next->Prev = tmp->Prev;
		tmp->Prev->Next = tmp->Next;

		tmp->Next = nullptr;
		tmp->Prev = nullptr;

		delete tmp;
	}
}

bool List::IsEmpty() {
	return (this->Head.Next == &(this->Tail) && this->Tail.Prev == &(this->Head));
}
std::fstream& operator << (std::fstream& File, List& Lst) {
	ListNode* curr = Lst.Head.Next;
	while (curr != &(Lst.Tail)) {
		File << curr->Data << " ";
		curr = curr->Next;
	}

	return File;
}

std::fstream& operator >> (std::fstream& File, List& Lst) {
	int tmp;
	while (File >> tmp) {
		Lst.Add(tmp);
	}

	return File;
}