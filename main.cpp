/*
#include "permission.h"
#include "parcelManager.h"
*/
#include "roles.h"
#include "fileHandle.h"
#include "utilityTools.h"


#include <iostream>
#include <string>
#include <memory>
using namespace std;


int main()
{
	int level = 99; //default level is guest: 0
	unsigned int option = 0;
	unique_ptr<roleBase> role; //pointer to the roleBase class

	while (1)
	{

		switch (level)
		{
		case 0:
			role = make_unique<guest>();
			break;
		case 1:
			role = make_unique<user>();
			break;
		case 2:
			role = make_unique<employee>();
			break;
		case 3:
			role = make_unique<manager>();
			break;
		// Set manually 99 level: for testing purpose
		// In utilityTools.cpp, test::testMenu() function
		case 99:
			test::testMenu();
		}
		system("cls");
		role->displayMenu();
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			printScreen::colorWord("ONLY NUMBER", 3, 0, 1, 1);
			continue;
		}
		role->excuteCommand(option);

	}




	system("pause");
	return 0;
}/*
#include "permission.h"
#include "parcelManager.h"
*/
#include "roles.h"
#include "fileHandle.h"
#include "utilityTools.h"


#include <iostream>
#include <string>
#include <memory>
using namespace std;


int main()
{
	int level = 99; //default level is guest: 0
	unsigned int option = 0;
	unique_ptr<roleBase> role; //pointer to the roleBase class

	while (1)
	{

		switch (level)
		{
		case 0:
			role = make_unique<guest>();
			break;
		case 1:
			role = make_unique<user>();
			break;
		case 2:
			role = make_unique<employee>();
			break;
		case 3:
			role = make_unique<manager>();
			break;
		// Set manually 99 level: for testing purpose
		// In utilityTools.cpp, test::testMenu() function
		case 99:
			test::testMenu();
		}
		system("cls");
		role->displayMenu();
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			printScreen::colorWord("ONLY NUMBER", 3, 0, 1, 1);
			continue;
		}
		role->excuteCommand(option);

	}




	system("pause");
	return 0;
}
