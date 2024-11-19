#ifndef FILESYSTEM_MANAGEMENT_H
#define FILESYSTEM_MANAGEMENT_H

    #include <iostream>
    #include <filesystem>
    #include <string>
    #include <vector>

    #define DIR_SEPARATOR "/"

    int create_dir(std::vector<std::filesystem::path> paths);
    int remove_dir(std::filesystem::path path, std::string mode);
    // int rename_dir(filesystem::path path);
    // int move_dir(filesystem::path path);

#endif