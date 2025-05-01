#include <iostream>
#include <vector>
#include <string>
#include "fileHandle.h"
#include "utilityTools.h"

int main() {
    try {
        // 创建 fileHandle 对象，绑定到 data.csv 文件
        fileHandle fh("data.csv");

        // 获取整个文件的数据
        std::vector<std::vector<std::string>> data = fh.getFetchedFile();
        std::cout << "Original Data:" << std::endl;
        for (const auto& row : data) {
            for (const auto& col : row) {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }

        // 添加新数据
        std::vector<std::string> newRow = {"4", "Diana", "28", "Australia"};
        fh.addData(newRow, 0); // 在文件中按第 0 列（ID）排序后添加

        // 修改数据
        std::vector<std::string> newValues = {"3", "Charlie", "36", "Canada"};
        fh.editData(0, "3", newValues); // 修改 ID 为 "3" 的行

        // 删除数据
        fh.removeData(0, "2"); // 删除 ID 为 "2" 的行

        // 保存修改后的数据
        fh.saveFile();

        // 打印最终数据
        std::cout << "\nModified Data:" << std::endl;
        data = fh.getFetchedFile();
        for (const auto& row : data) {
            for (const auto& col : row) {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
