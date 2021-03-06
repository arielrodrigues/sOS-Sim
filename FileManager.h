#ifndef SIMPLE_OS_SIMULATOR_FILEMANAGER_H
#define SIMPLE_OS_SIMULATOR_FILEMANAGER_H

#include <sstream>
#include <fstream>
#include <iostream>

namespace FileManager {

	static uint32_t numberofLines = 0;
    /***
     * Put the file in a stringstream
     * @param filepath
     * @return out (file stringstream)
     */
    static std::stringstream readFile(std::string filepath) {
        try {
            numberofLines = 0;
            std::stringstream out;
            std::ifstream infile(filepath);
            for (std::string line; getline(infile, line);
                 boost::replace_all(line, ",", " "), out << line << '\n', numberofLines++);
            return out;
        } catch (...) {
            std::cout << "Erro ao abrir o arquivo de leitura\n";
            exit(EXIT_FAILURE);
        }
    }

    /***
     * Write the stringstream content in a file
     * @param filename
     * @param content
     * @return sucess?
     */
    static bool writeFile(std::string filename, std::string content_) {
        try {
            std::ofstream outfile(filename);
            std::stringstream content(content_);
            outfile << content.str();
            return true;
        } catch (...) {
            std::cout << "Erro ao escrever no arquivo\n";
        }
        return false;
    }

};


#endif //SIMPLE_OS_SIMULATOR_FILEMANAGER_H
