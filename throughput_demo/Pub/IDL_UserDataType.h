// Don't modify this file as it will be overwritten.
//
#include "CDR/CDR.h"
#include "ReturnCode.h"
#include "BasicTypes.h"

#ifndef IDL_UserDataType_hh
#define IDL_UserDataType_hh

#ifndef UserDataType_defined
#define UserDataType_defined

struct UserDataType {
  UserDataType()
	{
		message = new char[255];
		message[0]= '\0';
		message_size = 0;
		send_count = 0;
		sub_mbps = 0;
		pub_mbps = 0;
		sub_mes_size = 0;
		pub_mes_size = 0;
	}

  UserDataType(const UserDataType  &IDL_s);

  ~UserDataType(){
		delete message;
		message = NULL;
	}

  	int StructSize()
	{
		int strSize = 0;
		strSize += sizeof(UserDataType);
		strSize += strlen(message);
		return strSize;
	}
  UserDataType& operator= (const UserDataType &IDL_s);

  void Marshal(CDR *cdr) const;
  void UnMarshal(CDR *cdr);

  char* message;
short message_size;
long long send_count;
double sub_mbps;
double pub_mbps;
long long sub_mes_size;
long long pub_mes_size;
  
};

typedef sequence<UserDataType> UserDataTypeSeq;

#endif




#endif /*IDL_UserDataType_hh */
