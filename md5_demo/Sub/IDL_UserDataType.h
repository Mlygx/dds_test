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
		md5_message = new char[255];
		md5_message[0]= '\0';
	}

  UserDataType(const UserDataType  &IDL_s);

  ~UserDataType(){
		delete message;
		message = NULL;
		delete md5_message;
		md5_message = NULL;
	}

  	int StructSize()
	{
		int strSize = 0;
		strSize += sizeof(UserDataType);
		strSize += strlen(message);
		strSize += strlen(md5_message);
		return strSize;
	}
  UserDataType& operator= (const UserDataType &IDL_s);

  void Marshal(CDR *cdr) const;
  void UnMarshal(CDR *cdr);

  char* message;
char* md5_message;
  
};

typedef sequence<UserDataType> UserDataTypeSeq;

#endif




#endif /*IDL_UserDataType_hh */
