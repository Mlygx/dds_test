#ifndef _IDL_TYPESUPPORT_H_INCLUDED_ 
#define _IDL_TYPESUPPORT_H_INCLUDED_

#include <string>
using std::string;
#include "IDL_DataWriter.h"
#include "IDL_DataReader.h"
#include "DDS/TypeSupport.h"

#include "DDS/DomainParticipant.h"
class DomainParticipant;

list<string> ListData;
static void initList()
{	if (ListData.size() <= 0)
	{
		ListData.push_back("struct UserDataType{");
		ListData.push_back("string 255 message;");
		ListData.push_back("short message_size;");
		ListData.push_back("longlong send_count;");
		ListData.push_back("double sub_mbps;");
		ListData.push_back("double pub_mbps;");
		ListData.push_back("longlong sub_mes_size;");
		ListData.push_back("longlong pub_mes_size;");
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

	static void print_data(UserDataType* pUserDataType,int layer = 0)
	{
		char *c = new char[layer];
		int i = 0;
		for (; i < layer; i++)
		{
			c[i] = '\t';
		}
		c[i] = '\0';
		std::cout<<c<<"UserDataType:"<<std::endl;
		std::cout<<c<<"  message = "<< pUserDataType->message <<std::endl;
		std::cout<<c<<"  message_size = "<< pUserDataType->message_size <<std::endl;
		std::cout<<c<<"  send_count = "<< pUserDataType->send_count <<std::endl;
		std::cout<<c<<"  sub_mbps = "<< pUserDataType->sub_mbps <<std::endl;
		std::cout<<c<<"  pub_mbps = "<< pUserDataType->pub_mbps <<std::endl;
		std::cout<<c<<"  sub_mes_size = "<< pUserDataType->sub_mes_size <<std::endl;
		std::cout<<c<<"  pub_mes_size = "<< pUserDataType->pub_mes_size <<std::endl;
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
		return participant->register_type(type_name,ListData);
	}
	static void thread_function(UserDataType* udt) {
		while (udt) {
			double data = sizeof(*udt) * 8;
			udt->pub_mbps = data / 1024 / 1024;
			std::cout << "pub_mbps = " << udt->pub_mbps << " Mbps" << std::endl;
			Sleep(1000);
			if (!udt->message) {
				break;
			}

		}
	}
};

#endif
