#if !defined(FILEHANDLE_H)
#define FILEHANDLE_H

#include <vector>
#include <string>
#include <fstream>

class fileHandle
{
private:
	std::string fileName;
	std::vector <std::string> field;
	std::vector <std::string> ColData;
	std::vector<std::vector<std::string>> fetchedFile;
	std::pair<int, int> dataPos;

public:
	fileHandle(std::string fileName);
	std::vector<std::vector<std::string>> fetchFile() const;
	std::vector<std::vector<std::string>> getFetchedFile() const;
	void getCol(unsigned int col = 0);
	//add, edit, remove data is not implement immediately to the file
	//need to call saveFile() to save the changes
	void addData(std::vector<std::string> newData, unsigned int col = 0);
	void editData(unsigned int col, const std::string& target, const std::vector<std::string>& newValue);
	void removeData(unsigned int col, const std::string& target);
	void saveFile() const;
};





#endif //FILEHANDLE_H

