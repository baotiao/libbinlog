#include "data.h"

#include <string>
Data::Data(std::string path, int filenum) :
  path_(path),
  filenum_(filenum)
{
  f_ = fopen(GetFileName().c_str(), "w");

}

std::string Data::GetFileName()
{
  char buf[128];
  snprintf(buf, sizeof(buf), "%s/binlog.%d", path_.c_str(), filenum_);
  return buf;
}

int Data::Append(const std::string &str)
{
  size_t r = fwrite(str.c_str(), 1, str.size(), f_);
  if (r != str.size()) {
    return -1;
  } else {
    return r;
  }
}
