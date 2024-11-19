#ifndef FILE_WRITE_H
#define FILE_WRITE_H   

#include <iostream>
#include <fstream>
#include <string>

    // Function prototypes
    // int read_file(string file_name, fstream::openmode mode = fstream::in);
    int write_file(std::string file_name, std::string file_content, std::fstream::openmode mode = std::fstream::app);

    // Function prototypes

#endif