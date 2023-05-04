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
		circulate_count = 0;
		message = new char[255];
		message[0]= '\0';
		message_size = 0;
		start_time = new char[255];
		start_time[0]= '\0';
		end_time = new char[255];
		end_time[0]= '\0';
	}

  UserDataType(const UserDataType  &IDL_s);

  ~UserDataType(){
		delete message;
		message = NULL;
		delete start_time;
		start_time = NULL;
		delete end_time;
		end_time = NULL;
	}

  	int StructSize()
	{
		int strSize = 0;
		strSize += sizeof(UserDataType);
		strSize += strlen(message);
		strSize += strlen(start_time);
		strSize += strlen(end_time);
		return strSize;
	}
  UserDataType& operator= (const UserDataType &IDL_s);

  void Marshal(CDR *cdr) const;
  void UnMarshal(CDR *cdr);

  short circulate_count;
char* message;
short message_size;
char* start_time;
char* end_time;
  
};

typedef sequence<UserDataType> UserDataTypeSeq;

#endif




#endif /*IDL_UserDataType_hh */
