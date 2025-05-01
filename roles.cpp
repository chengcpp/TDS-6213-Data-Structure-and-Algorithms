#include "roles.h"
#include "utilityTools.h"

#include <iostream>
#include <string>
#include <cstdlib>


roleBase::roleBase() //constructor
{

}
roleBase::~roleBase() //destructor
{

}
void roleBase::displayHeader() const
{
	std::cout << "   Parcel Management System   " << "\n";
	std::cout << std::string(30, '-') << "\n";
	std::cout << "Hi, " << std::endl; // SHOW NAMEE
}
void roleBase::displayfooter() const
{
	std::cout << std::string(30, '-') << "\n";
	std::cout << "Option: " << "\033[s";
}
void roleBase::manageAcc()
{

}
int roleBase::logOut()
{
	return 0;
}
void roleBase::exit()
{
	std::exit(0);
}




void guest::displayHeader() const
{
	std::cout << "   Parcel Management System   " << "\n";
	std::cout << std::string(30, '-') << "\n";
}
void guest::displayMenu() const 
{
	displayHeader();
	std::cout << "1) Track parcel" << "\n";
	std::cout << "2) Log in" << "\n";
	std::cout << "3) Exit" << "\n";
	roleBase::displayfooter();
}
void guest::trackParcel()
{

}
void guest::excuteCommand(int option)
{
	switch (option)
	{
	case 1:
		trackParcel();
		break;
	case 2:

		break;
	case 3:
		std::exit(0);
	default:
		printScreen::colorWord("INVALID CHOICE", 1, 0, 1, 1);
		break;
	}
}


void user::displayMenu() const
{
	roleBase::displayHeader();
	std::cout << "1) Track parcel" << "\n";
	std::cout << "2) History" << "\n";
	std::cout << "3) Manage Acc" << "\n"; //change password
	std::cout << "4) Log out" << "\n";
	roleBase::displayfooter();
}
int user::history()
{
	return 0;
}
void user::manageAcc()
{

}
void user::excuteCommand(int option)
{
	switch (option)
	{
	case 1:
		trackParcel();
		break;
	case 2:
		history();
		break;
	case 3:
		manageAcc();
	case 4:
		logOut();
		break;
	default:
		printScreen::colorWord("INVALID CHOICE", 1, 0, 1, 1);
		break;
	}

}


void employee::displayMenu() const
{
	roleBase::displayHeader();
	std::cout << "1) Track parcel" << "\n"; //show more details than user
	std::cout << "2) Create parcel" << "\n";
	std::cout << "3) Manage parcel" << "\n"; //edit or delete
	std::cout << "4) Manage Acc" << "\n"; //change password
	std::cout << "5) Log out" << "\n";
	roleBase::displayfooter();
}
void employee::trackParcel()
{

}
void employee::excuteCommand(int option)
{
	switch (option)
	{
	case 1:
		trackParcel();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		manageAcc();
		break;
	case 5:
		logOut();
		break;
	default:
		printScreen::colorWord("INVALID CHOICE", 1, 0, 1, 1);
		break;
	}

}


void manager::displayMenu() const
{
	roleBase::displayHeader();
	std::cout << "1) Track parcel" << "\n"; //show more details than user
	std::cout << "2) Create parcel" << "\n";
	std::cout << "3) Manage parcel" << "\n"; //edit or delete
	std::cout << "4) Manage Acc" << "\n"; //can be add new employee
	std::cout << "5) Log out" << "\n";
	roleBase::displayfooter();
}
void manager::manageAcc()
{

}
void manager::excuteCommand(int option)
{
	switch (option)
	{
	case 4:
		manageAcc();
		break;
	default:
		employee::excuteCommand(option);
	}

}

