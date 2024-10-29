#include <write_file.h>


using namespace std;


int write_file(string file_name, string file_content, ios::openmode mode) {
    
    if(!(file_name.length() > 0)) {
        cout << "file path is empty!" << endl;
        return 1;

    } else if (!(file_content.length() > 0)) {

        cout << "No content given" << endl;
        return 1;

    }
    
    fstream file;

    file.open(file_name, mode);

    if(!file.is_open()) {

        return 1;

    }

    file << file_content;

    cout << "Wrote " << file_content.length() << " characters to " << file_name << endl; 

    file.close();

    return 0;
    
}
