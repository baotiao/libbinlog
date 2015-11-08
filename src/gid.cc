#include "gid.h"
#include "xdebug.h"

#include <stdio.h>
#include <cstring>
#include <string>


Gid::Gid(uint32_t sid) :
  sid_(sid)
{
  op_ = 0;
  ts_ = 0;
}

Gid::Gid(uint32_t sid, uint32_t op, uint32_t ts) :
  sid_(sid),
  op_(op),
  ts_(ts)
{}

int Gid::Update()
{
  op_++;
  return 0;
}

int Gid::EncodeTo(std::string &sgid) const
{
  char buf[24];
  memcpy(buf, &sid_, sizeof(uint32_t));
  memcpy(buf + sizeof(uint32_t), &op_, sizeof(uint32_t));
  memcpy(buf + sizeof(uint32_t) + sizeof(uint32_t), &ts_, sizeof(uint32_t));

  sgid.append(buf, sizeof(Gid));

  return 0;
}

int Gid::DecodeFrom(const std::string &gid)
{
  memcpy(&sid_, gid.c_str(), sizeof(uint32_t));
  memcpy(&op_, gid.c_str() + 4, sizeof(uint32_t));
  memcpy(&ts_, gid.c_str() + 8, sizeof(uint32_t));

  return 0;

}

void Gid::DumpSelf() const
{
  log_info("sid %d op %d ts %d", sid_, op_, ts_);
}

std::string Gid::DebugString() const
{
  char buf[24];
  snprintf(buf, sizeof(buf), "sid %d op %d ts %d", sid_, op_, ts_);

  return std::string(buf, sizeof(buf));
}
