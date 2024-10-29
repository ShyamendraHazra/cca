#include <filesystem_management.h>

using namespace std;

int create_directory(filesystem::path path) {

    if(exists(path)) {
    
        std::cout << "Directory already exists\n";
        return 1;
    }


    if (!filesystem::create_directory(path)) {
    
        std::cout << "Failed to create directory\n";
        return 1;

    } 

    std::cout << "Directory created successfully\n";

    return 0;

}


int remove_directory(filesystem::path path) {

    if(!(exists(path) && is_directory(path))) {

        std::cout << "Either " << path << " does not exist or it is not a directory\n";
        return 1;

    }


    if (!filesystem::remove(path)) {

        std::cout << "Failed to remove directory\n";
        return 1;

    }

    std::cout << "Directory removed successfully\n";

    return 0;

}