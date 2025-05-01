#include "fileHandle.h"
#include "utilityTools.h"


fileHandle::fileHandle(std::string fileName) : fileName(fileName)
{
	std::ifstream file(fileName);
/*
	try{
		fileHandle file("xxx.csv");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		....
	}
*/
	if (!file.is_open())
		throw std::ios_base::failure("Error fileHandle constructor: Unable to open file \"" + fileName + "\"");

	fetchedFile = fetchFile();
}

std::vector<std::vector<std::string>> fileHandle::fetchFile() const
{
	std::ifstream fetchedFile(fileName);
	std::vector<std::vector<std::string>> fileData;
	std::string line;
	while (std::getline(fetchedFile, line))
	{
		fileData.push_back(splitData(line, '|'));
	}

	fetchedFile.close();
	return fileData;
}


std::vector<std::vector<std::string>> fileHandle::getFetchedFile() const
{
	return fetchedFile;
}

void fileHandle::getCol(unsigned int col)
{
	ColData.clear();
	if (col >= fetchedFile[0].size())
	{
		throw std::out_of_range("Error getCol() of 'col': Column index '" + std::to_string(col) +
			"' is out of range. Valid range: [0, " + std::to_string(fetchedFile[0].size() - 1) + "].");
	}
	for (const auto& line : fetchedFile)
	{
		ColData.push_back(line[col]);
	}
}


//add data to the file, data will be sorted automatically
//make sure all data format is correct before adding data
//default column is 0 (optional)
void fileHandle::addData(std::vector<std::string> newData, unsigned int col)
{
	fetchedFile.push_back(newData);
	if (col >= fetchedFile[0].size())
	{
		throw std::out_of_range("Error addData() of 'col': Column index '" + std::to_string(col) +
			"' is out of range. Valid range: [0, " + std::to_string(fetchedFile[0].size() - 1) + "].");
	}
	// sort the first column as default
	mergeSort2D(fetchedFile, 0, fetchedFile.size() - 1, col);
}

//using binary search, make sure the target column is sorted before using this function
void fileHandle::editData(unsigned int col, const std::string& target, const std::vector<std::string>& newValue)
{
	// validate the column index
	if (col >= fetchedFile[0].size()) {
		throw std::out_of_range("Error editData() of 'col': Column index '" + std::to_string(col) +
			"' is out of range. Valid range: [0, " + std::to_string(fetchedFile[0].size() - 1) + "].");
	}

	int dataPos;
	getCol(); //get the first column of the fetched file

	if (binarySearch(ColData, target, &dataPos))
	{
		if (newValue.size() != fetchedFile[dataPos].size()) {
			throw std::invalid_argument("Error editData() of 'newValue': New values size does not match the number of columns in the target row.");
		}

		// change the line with the new values
		fetchedFile[dataPos] = newValue;
	}
	else
	{
		throw std::logic_error("Error editData() -> binarySearch(): Target '" + target + "' not found in column " + std::to_string(col));
	}
}

// using binary search, make sure the target column is sorted before using this function
void fileHandle::removeData(unsigned int col, const std::string& target)
{
	// validate the column index
	if (col >= fetchedFile[0].size()) {
		throw std::out_of_range("Error removeData() of 'col': Column index '" + std::to_string(col) +
			"' is out of range. Valid range: [0, " + std::to_string(fetchedFile[0].size() - 1) + "].");
	}

	int dataPos;
	getCol();

	if (binarySearch(ColData, target, &dataPos)) {
		// remove the line if the data is found
		fetchedFile.erase(fetchedFile.begin() + dataPos);
	}
	else {
		throw std::logic_error("Error removeData() -> binarySearch(): Target '" + target + "' not found in column " + std::to_string(col));
	}
}

void fileHandle::saveFile() const
{
	std::ofstream wfile(fileName);

	for (const auto& line : fetchedFile)
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			wfile << line[i];
			if (i < line.size() - 1)
			{
				wfile << "|";
			}
		}
		wfile << "\n";
	}
	wfile.close();
}


