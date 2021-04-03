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

LIST* INITIALIZE_LIST();
INFO* INITIALIZE_INFO();
void PRINT_INFO(LIST* info);
void DELETE(LIST* data, string selectedWebsite);
LIST* INSERT(LIST* info, INFO* newData);
#endif
