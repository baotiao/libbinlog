#include "gid.h"

#include <stdio.h>
#include <cstring>
#include <string>


Gid::Gid(int sid) :
  sid_(sid)
{
  op_ = 0;
}

Gid::Gid(int sid, int op, int ts) :
  sid_(sid),
  op_(op),
  ts_(ts)
{}

int Gid::Update()
{
  op_++;
  return 0;
}

int Gid::EncodeTo(std::string &str) const
{
  char buf[24];
  memcpy(buf, &sid_, sizeof(int));
  memcpy(buf, &op_, sizeof(int));
  memcpy(buf, &ts_, sizeof(int));

  str.append(buf, sizeof(Gid));

  return 0;
}

int Gid::DecodeFrom(char *str)
{
}
