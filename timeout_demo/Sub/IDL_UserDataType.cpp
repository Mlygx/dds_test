// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  circulate_count = IDL_s.circulate_count;
  message = IDL_s.message;
  message_size = IDL_s.message_size;
  start_time = IDL_s.start_time;
  end_time = IDL_s.end_time;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  circulate_count = IDL_s.circulate_count;
  message = IDL_s.message;
  message_size = IDL_s.message_size;
  start_time = IDL_s.start_time;
  end_time = IDL_s.end_time;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutShort(circulate_count);
  cdr->PutString(message);
  cdr->PutShort(message_size);
  cdr->PutString(start_time);
  cdr->PutString(end_time);
}

void UserDataType::UnMarshal(CDR *cdr){
  cdr->GetShort(circulate_count);
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
  cdr->GetShort(message_size);
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(start_time != NULL )
    {
        delete start_time;
        start_time = NULL;
    }
    start_time = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(end_time != NULL )
    {
        delete end_time;
        end_time = NULL;
    }
    end_time = IDL_str;
  }
}

