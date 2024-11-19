#include <Files/filesystem_management.h>

int create_dir(std::vector<std::filesystem::path> paths) {

    for(const std::filesystem::path& path : paths) {

        if(path.string().find(DIR_SEPARATOR) != std::string::npos) {

            if(!std::filesystem::create_directories(path)) {
                return 0;
            }

        } else {
        
            if(!std::filesystem::create_directory(path)) {
                return 0;
            }

        }
    }
    
    return 1;
}

int remove_dir(std::filesystem::path path, std::string mode) {
    try{

        if(!std::filesystem::exists(path)) {

            std::cout << "Path '" << path.string() << "' does not exist" << std::endl;
            return 1;
        }

        if(mode == "r") {
            return std::filesystem::remove_all(path);
        } else {
            return std::filesystem::remove(path);
        }
    
    } catch (const std::filesystem::filesystem_error& e) {
    
        std::cout << e.what() << std::endl;
        return 1;
    
    }
}