#ifndef _IDL_TYPESUPPORT_H_INCLUDED_ 
#define _IDL_TYPESUPPORT_H_INCLUDED_
#include <cstring>
#include <string>
using std::string;
#include "IDL_DataWriter.h"
#include "IDL_DataReader.h"
#include "DDS/TypeSupport.h"
#include "md5.h"
#include "DDS/DomainParticipant.h"
class DomainParticipant;

list<string> ListData;
static void initList()
{
	if (ListData.size() <= 0)
	{
		ListData.push_back("struct UserDataType{");
		ListData.push_back("string 255 message;");
		ListData.push_back("string 255 md5_message;");
		ListData.push_back("};");
	}
}

class UserDataTypeTypeSupport : public TypeSupport {
public:
	static UserDataType* create_data()
	{
		return new UserDataType;
	}

	static ReturnCode_t delete_data(UserDataType* pUserDataType)
	{
		delete pUserDataType;
		pUserDataType = NULL;
		return ReturnCode_t();
	}

	static void print_data(UserDataType* pUserDataType, int layer = 0)
	{
		char *c = new char[layer];
		int i = 0;
		for (; i < layer; i++)
		{
			c[i] = '\t';
		}
		c[i] = '\0';
		std::cout << c << "  UserDataType:" << std::endl;
		std::cout << c << "  message = " << pUserDataType->message << std::endl;
		std::cout << c << "  md5_message = " << pUserDataType->md5_message << std::endl;;
		if (MD5(pUserDataType->message).toStr() != pUserDataType->md5_message) {
			std::cout << "  md5 different" << std::endl;
		}
		else
			std::cout << "  md5 same" << std::endl;
	}

	static const char* get_type_name()
	{
		return "UserDataType";
	}

	static int register_type(DomainParticipant* participant, string type_name)
	{
		if (type_name.empty())
			type_name = get_type_name();

		initList();
		return participant->register_type(type_name, ListData);
	}
	static void printMD5(const string& message) {
		//    MD5(message).toStr();
		std::cout << "  md5_message = " << MD5(message).toStr() << std::endl;
	}

};

#endif
