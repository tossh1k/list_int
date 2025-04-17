#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct ListNode
{
	int Data;
	ListNode* Next;
	ListNode* Prev;
};

class List
{
	ListNode Head;
	ListNode Tail;
public:
	List();
	List(int Val);
	List(const List& Lst);
	List(List&& Lst);
	~List();
	List& operator = (const List& Lst);
	List& operator = (List&& Lst);
	void Add(int Val);
	void AddAfter(int Val, unsigned int Pos);
	void AddBefore(int Val, unsigned int Pos);
	void Print();
	void PrintReverse();
	void Delete(int Val);
	void DeleteAllWithVal(int Val);
	void Clear();
	bool IsEmpty();
	friend std::fstream& operator << (std::fstream& File, List& Lst);
};

std::fstream& operator >> (std::fstream& File, List& Lst);