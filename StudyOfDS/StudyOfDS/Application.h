#pragma once
#include <iostream>
#include <string>
#include "ArrayList.h"
using namespace std;

class Application
{
private:
	ArrayList<int> m_masterList;
	int m_command;

public:
	void GetCommand();
	void Run();
	void AddItem();
	void DeleteItem();
	void SearchItem();
	void DisplayAllItem();
};

