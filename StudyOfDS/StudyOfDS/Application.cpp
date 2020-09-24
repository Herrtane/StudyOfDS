#include "Application.h"

void Application::GetCommand() {
	cout << endl << endl;
	cout << '\t' << "[Menu]" << endl;
	cout << '\t' << "==MasterList==" << endl;
	cout << '\t' << "1. Add item" << endl;
	cout << '\t' << "2. Delete item" << endl;
	cout << '\t' << "3. Search item" << endl;
	cout << '\t' << "4. Display all items" << endl;
	cout << '\t' << "0. Exit program" << endl;
	cout << '\t' << "Enter your command >>";
	cin >> this->m_command;
}

void Application::Run() {
	while (1) {
		this->GetCommand();
		switch (this->m_command) {
		case 1:
			this->AddItem();
			break;
		case 2:
			this->DeleteItem();
			break;
		case 3:
			this->SearchItem();
			break;
		case 4:
			this->DisplayAllItem();
			break;
		case 0:
			exit(100);
			break;
		default:
			cout << '\t' << "[System] Error command" << endl;
		}
	}
}

void Application::AddItem() {
	int temp_item;
	int isadd;
	cout << '\t' << "Enter the item >> ";
	cin >> temp_item;
	isadd = this->m_masterList.InsertItem(temp_item);
	if (isadd)
		cout << '\t' << "[System] Add successfully!" << endl;
	else
		cout << '\t' << "[System] Error: Cannot add the item" << endl;
}

void Application::DeleteItem() {
	int temp_item;
	int isdelete;
	cout << '\t' << "Enter the item that you want to delete >> ";
	cin >> temp_item;
	isdelete = this->m_masterList.DeleteItem(temp_item);
	if (isdelete)
		cout << '\t' << "[System] Delete successfully!" << endl;
	else
		cout << '\t' << "[System] Error: Cannot delete the item" << endl;
}

void Application::SearchItem() {
	int temp_item;
	int isfound;
	cout << '\t' << "Enter the item that you want to search >> ";
	cin >> temp_item;
	isfound = this->m_masterList.RetrieveItem(temp_item);
	if (isfound)
		cout << '\t' << "[System] Search successfully!" << endl;
	else
		cout << '\t' << "[System] Error: Cannot search the item" << endl;
}

void Application::DisplayAllItem() {
	int temp_item;
	this->m_masterList.ResetList();
	while (this->m_masterList.GetNextItem(temp_item)) {
		cout << '\t' << temp_item;
	}
	cout << endl;
}