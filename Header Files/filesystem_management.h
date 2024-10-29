#ifndef DIR_MANAGEMENT_H
#define DIR_MANAGEMENT_H

    #include <iostream>
    #include <filesystem>


    int create_directory(std::filesystem::path path);

    int remove_directory(std::filesystem::path path);


#endif