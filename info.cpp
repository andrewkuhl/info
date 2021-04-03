#include "info.h"

LIST* INITIALIZE_LIST() {
	LIST* data = (LIST*) calloc(1,sizeof(LIST));
    data->size = 0;
	data->list = (INFO**) calloc(1,sizeof(INFO*));
	return data;
}

INFO* INITIALIZE_INFO() {
    INFO* info = (INFO *) calloc(1, sizeof(INFO));
    info->password = "";
    info->username = "";
    info->website = "";
    return info;
}

void PRINT_LIST(LIST* data){
    std::cout <<"Size = " << data->size << std::endl;
    if(data->size != 0) {
        for (int i = 0; i < data->size; i++) {
            std::cout << std::endl;
            std::cout << "Website: " << data->list[i]->website << std::endl;
            std::cout << "Username: " << data->list[i]->username << std::endl;
            std::cout << "Password: " << data->list[i]->password << std::endl;
        }
    }
}

void DELETE(LIST* data, string selectedWebsite){
    for (int i = 0; i < data->size; i++){
        if(selectedWebsite == data->list[i]->website){
            if(i == data->size){
                data->list[i] = nullptr;
                data->size--;
            }
            else{
                data->list[i] = data->list[data->size];
                data->size--;;
            }

        }
        else{
            std::cout << selectedWebsite <<" not found" << std::endl;
        }
    }
}

LIST* INSERT(LIST* data, INFO* newInfo){
    LIST* newData = (LIST*) calloc(data->size+1,sizeof(LIST));
    newData->size = data->size+1;
    for(int i = 0; i < data->size; i++){
        newData->list[i] = data->list[i];
    }
    newData->list[newData->size] = newInfo;
    return newData;
}

void PRINT_INFO(LIST* data){
    cout << "Size: " << data->size << endl;
    cout << endl;
    for(int i = 0; i < data->size; i++){
        cout << "Website: " << data->list[i]->website << endl;
        cout << "Username: " << data->list[i]->username << endl;
        cout << "Password: " << data->list[i]->password << endl;
    }
}