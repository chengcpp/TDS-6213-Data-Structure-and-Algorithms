#include "utilityTools.h"
#include "fileHandle.h" // for testFileHandle, delete later

#include <iostream>
#include <thread>
#include <iomanip>
#include <sstream>

void printScreen::colorWord(std::string word, int color, int width, float time, bool isWarning)
{
	unsigned int MilliSeconds = int(time * 1000);
	if (isWarning == 1)
		std::cout << "\033[u\033[K";
	switch (color)
	{
	case 1://Red
		//ASCII escape code
		std::cout << "\033[31;1m" << std::setw(width) << std::left << word << "\033[0m";
		break;
	case 2://Green
		std::cout << "\033[32;1m" << std::setw(width) << std::left << word << "\033[0m";
		break;
	case 3://Yellow
		std::cout << "\033[33;1m" << std::setw(width) << std::left << word << "\033[0m";
		break;
	case 4://gray
		std::cout << "\033[30;1m" << std::setw(width) << std::left << word << "\033[0m";
	}
	if (isWarning == 1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(MilliSeconds));
		std::cout << "\033[u\033[K";
	}
};

// split data by delimiter, return a vector of string
std::vector<std::string> splitData(const std::string& data, char delimiter)
{
	std::vector<std::string> line;
	std::istringstream lineStream(data);
	std::string temp;
	while(std::getline(lineStream, temp, '|'))
	{
		line.push_back(temp);
	}
	return line;
}

//pass by reference, note that original data will be changed
bool mergeSort(std::vector<std::string>& data, int left, int right)
{
    //check all parameters are valid or not
    if (data.empty()) {
        throw std::invalid_argument("Error: The input vector is empty");
    }
    if (left < 0 || right >= data.size() || left > right) {
        throw std::out_of_range("Error: Invalid indices for mergeSort");
    }

	//condition to stop the recursion
    if (left >= right) return true;

    int mid = left + (right - left) / 2;

    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);

	std::vector<std::string> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            temp.push_back(data[i]);
            i++;
        }
        else {
            temp.push_back(data[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(data[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(data[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        data[left + k] = temp[k];
    }
}

bool mergeSort2D(std::vector<std::vector<std::string>>& data, int left, int right, int col)
{
	//check all parameters are valid or not
    if (data.empty()) {
        throw std::invalid_argument("Error: The input 2D vector is empty");
    }
    if (col < 0 || (data.size() > 0 && col >= data[0].size())) {
        throw std::out_of_range("Error: Column index is out of range");
    }
    if (left < 0 || right >= data.size()) {
        throw std::out_of_range("Error: Row index is out of range");
    }

	//condition to stop the recursion
    if (left >= right) return true;

    int mid = left + (right - left) / 2;

    mergeSort2D(data, left, mid, col);
    mergeSort2D(data, mid + 1, right, col);

    std::vector<std::vector<std::string>> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (data[i][col] <= data[j][col]) {
            temp.push_back(data[i]);
            i++;
        }
        else {
            temp.push_back(data[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(data[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(data[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        data[left + k] = temp[k];
    }
}


// dataPos is optional
// target column must be sorted before using binary search
bool binarySearch(const std::vector<std::string>& data, const std::string& target, int* dataPos)
{
    int left = 0, right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            if (dataPos) {
                *dataPos = mid;
            }
			return true; //find the target
        }
        else if (data[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

	return false; //cannot find the target
}

void test::testMenu()
{
	unsigned int option = 0;
    while (1)
    {
        std::cout << "Test Menu" << std::endl;
        std::cout << "1. Test fileHandle" << std::endl;
        std::cout << "99. Exit" << std::endl;
		std::cout << "Option: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            testFileHandle();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
		case 99:
			exit(0);
        }
    }
}

void test::testFileHandle()
{
    std::ofstream testFile("testFile.txt");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            testFile << i << j;
            if (j < 4)
            {
                testFile << "|";
            }
        }
		testFile << "\n";
    }
	testFile.close();
	system("pause");

	system("cls");
    try
    {
        fileHandle test("testFile.txt");

        std::vector<std::vector<std::string>> data = test.getFetchedFile();
        for (const auto& line : data)
        {
            for (const auto& word : line)
            {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }

        std::vector<std::string> newValue = { "01", "20", "30", "99", "99" };

		//test.addData(newValue, 1);
        //test.editData(1, "11", newValue);
		test.removeData(11, "20");

		system("pause");
        data = test.getFetchedFile();
        for (const auto& line : data)
        {
            for (const auto& word : line)
            {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }

        test.saveFile();
        std::cout << "File saved" << std::endl;
        system("pause");
        system("cls");
    }
    catch (const std::exception& e)
    {
		printScreen::colorWord(e.what(), 1, 0, 0, 0);
		system("pause");
		system("cls");
    }

}
