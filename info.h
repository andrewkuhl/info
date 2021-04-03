#ifndef _INFO
#define _INFO
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

struct INFO{
	string website;
	string username;
	string password;
};

struct LIST{
	INFO** list;
	int size;
};

LIST* INITIALIZE_LIST(int size);
INFO* INITIALIZE_INFO();
void PRINT_LIST(LIST* data);
void DELETE(LIST* data, string selectedWebsite);
LIST* INSERT(LIST* info, INFO* newData);
#endif
