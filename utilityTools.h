#if !defined(UTILITYTOOLS_H)
#define UTILITYTOOLS_H

#include <vector>
#include <string>

class printScreen
{
private:

public:
	static void colorWord(std::string Word, int Color, int width, float Time, bool IsWarning);

};

std::vector<std::string> splitData(const std::string& data, char delimiter);

bool mergeSort(std::vector<std::string>& data, int left, int right);
bool mergeSort2D(std::vector<std::vector<std::string>>& data, int left, int right, int col);

bool binarySearch(const std::vector<std::string>& data, const std::string& target, int* dataPos = nullptr);

// for testing purpose
// 
class test
{
	public:
	static void testMenu();
	static void testFileHandle();
};
#endif //UTILITYTOOLS_H
