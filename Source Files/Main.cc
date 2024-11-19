#include <cca.h>


int main()
{

    std::string base_dir = std::filesystem::path("Playground").string();
    std::cout << std::filesystem::absolute(base_dir) << std::endl;
    std::cout << std::filesystem::current_path() << std::endl;

    if(create_dir({std::filesystem::absolute(base_dir)})) {
        
    }

    return 0;
}