#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

void loadConfig(const std::string& filename, std::map<std::string, std::string>& configMap) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (iss >> key >> value) {
                configMap[key] = value;
            }
        }
        file.close();
    } else {
        std::cout << "Failed to open file: " << filename << std::endl;
    }
}

void saveConfig(const std::string& filename, const std::map<std::string, std::string>& configMap) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : configMap) {
            file << pair.first << " " << pair.second << std::endl;
        }
        file.close();
    } else {
        std::cout << "Failed to open file: " << filename << std::endl;
    }
}

int main() {
    std::string filename = "49_config.txt";
    std::map<std::string, std::string> configMap;

    // 读取配置
    loadConfig(filename, configMap);

    // 输出配置
    for (const auto& pair : configMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 修改配置
    configMap["name"] = "Alice";
    configMap["age"] = "30";

    // 保存配置
    saveConfig(filename, configMap);

    return 0;
}
