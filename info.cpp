#include "info.h"

LIST* INITIALIZE_LIST(int size) {
	LIST* data = (LIST*) calloc(1,sizeof(LIST));
    data->size = size;
	data->list = (INFO**) calloc(size,sizeof(INFO*));
	return data;
}

INFO* INITIALIZE_INFO() {
    INFO* info = (INFO*) calloc(1, sizeof(INFO));
    info->password = "null";
    info->username = "null";
    info->website = "null";
    return info;
}

void PRINT_LIST(LIST* data){
    std::cout <<"Size = " << data->size << std::endl;
    if(data->size != 0) {
        for (int i = 0; i < data->size; i++) {
            cout << endl;
            cout << "\tWebsite: " << data->list[i]->website << endl;
            cout << "\tUsername: " << data->list[i]->username << endl;
            cout << "\tPassword: " << data->list[i]->password << endl;
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
    LIST* newData = INITIALIZE_LIST(data->size+1);  
    if(data->size == 0){
    cout << data->size+1 << endl;
    cout << newData->size+1 << endl;
    newData->list[0] = newInfo;
    return newData;
    }  
    else{
    for(int i = 0; i < data->size; i++){
        newData->list[i] = data->list[i];
    }
    newData->list[newData->size-1] = newInfo;
    delete data;
    return newData;
    }
}
