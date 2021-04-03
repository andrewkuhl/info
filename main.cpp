#include "info.h"
#include "util.h"
#include <fstream>

int main(){
    FILE* ifile = nullptr;
    LIST* data = nullptr;
    while(true){
        char c = NEXT_COMMAND();
        switch(c){
            case 's':
                return(0);
            case 'c':
                data = INITIALIZE_LIST();
                break;
            case 'r':
            {
                ifile = fopen("infoList.txt", "r");
                if (!ifile) {
                    std::cout << "Error: cannot open file for reading" << std::endl;
                    break;
                }
                data = INITIALIZE_LIST();
                string line;
                getline(cin, line);
                while (getline(cin, line)) {
                    getline(cin, line);
                    INFO *newInfo = INITIALIZE_INFO();
                    newInfo->website = line.substr(line.find(' '), line.size());
                    getline(cin, line);
                    newInfo->username = line.substr(line.find(' '), line.size());
                    getline(cin, line);
                    newInfo->password = line.substr(line.find(' '), line.size());
                    data = INSERT(data, newInfo);
                    data->size++;
                }
                break;
            }
            case 'p':
                if (data == nullptr) {
                    std::cout << "[ERROR]: NULL LIST" << std::endl;
                    break;
                } else {
                    PRINT_INFO(data);
                    break;
                }
            case 'w':
            {
                if (data == nullptr) {
                    std::cout << "[ERROR]: NULL LIST" << std::endl;
                    break;
                }
                ofstream out("infoList.txt");
                string printed = "Size: " + to_string(data->size) + "\n";
                out << printed;
                for(int i = 0; i < data->size; i++){
                    string line0 = to_string(i);
                    string line1 = "\tWebsite: " + data->list[i]->website + "\n";
                    string line2 = "\tUsername: " + data->list[i]->username + "\n";
                    string line3 = "\tPassword: " + data->list[i]->password + "\n";
                    out << line0;
                    out << line1;
                    out << line2;
                    out << line3;
                    out << "\n";
                }
                out.close();
                break;
            }
            case 'd':
            {
                if (data == nullptr) {
                    std::cout << "[ERROR]: NULL LIST" << std::endl;
                    break;
                }
                cout << "[ENTER WEBSITE]: ";
                string websiteInput;
                cin >> websiteInput;
                DELETE(data, websiteInput);

            }
                break;
            case 'i':
            {
                INFO* insertedObject = INITIALIZE_INFO();
                string insertInput;
                cout << "[ENTER WEBSITE]: ";
                cin >> insertInput;
                insertedObject->website = insertInput;
                cout << "[ENTER USERNAME]: ";
                cin >> insertInput;
                insertedObject->username = insertInput;
                cout << "[ENTER PASSWORD]: ";
                cin >> insertInput;
                insertedObject->password = insertInput;
                INSERT(data, insertedObject);
            }
                break;
            case 'x':
                break;
        }
    }
}



