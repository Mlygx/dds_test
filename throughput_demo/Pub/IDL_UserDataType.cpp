// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  message = IDL_s.message;
  message_size = IDL_s.message_size;
  send_count = IDL_s.send_count;
  sub_mbps = IDL_s.sub_mbps;
  pub_mbps = IDL_s.pub_mbps;
  sub_mes_size = IDL_s.sub_mes_size;
  pub_mes_size = IDL_s.pub_mes_size;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  message = IDL_s.message;
  message_size = IDL_s.message_size;
  send_count = IDL_s.send_count;
  sub_mbps = IDL_s.sub_mbps;
  pub_mbps = IDL_s.pub_mbps;
  sub_mes_size = IDL_s.sub_mes_size;
  pub_mes_size = IDL_s.pub_mes_size;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutString(message);
  cdr->PutShort(message_size);
  cdr->PutLongLong(send_count);
  cdr->PutDouble(sub_mbps);
  cdr->PutDouble(pub_mbps);
  cdr->PutLongLong(sub_mes_size);
  cdr->PutLongLong(pub_mes_size);
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
  cdr->GetShort(message_size);
  cdr->GetLongLong(send_count);
  cdr->GetDouble(sub_mbps);
  cdr->GetDouble(pub_mbps);
  cdr->GetLongLong(sub_mes_size);
  cdr->GetLongLong(pub_mes_size);
}

