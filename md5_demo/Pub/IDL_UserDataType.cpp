// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  message = IDL_s.message;
  md5_message = IDL_s.md5_message;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  message = IDL_s.message;
  md5_message = IDL_s.md5_message;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutString(message);
  cdr->PutString(md5_message);
}

void UserDataType::UnMarshal(CDR *cdr){
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(message != NULL )
    {
        delete message;
        message = NULL;
    }
    message = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(md5_message != NULL )
    {
        delete md5_message;
        md5_message = NULL;
    }
    md5_message = IDL_str;
  }
}

