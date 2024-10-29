#include <cca.h>

int main()
{

    if(create_directory("Code_Workspace/")) {

        if(create_directory("Code_Workspace/Logs/")) {

            write_file("Code_Workspace/Logs/logs.txt", log_formatter("Hello World!"));

        }
    }

    return 0;
}