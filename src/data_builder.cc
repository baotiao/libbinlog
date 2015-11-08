#include "data_builder.h"
#include "xdebug.h"
#include "gid.h"

#include <string>

DataBuilder::DataBuilder(std::string path, int filenum, Gid *gid) :
  path_(path),
  filenum_(filenum),
  gid_(gid)
{
  NewWritableFile(GetFileName(), &writableFile_);
  buf_ = (char *)malloc(sizeof(char) * 10240);

}

DataBuilder::~DataBuilder()
{

}

std::string DataBuilder::GetFileName() const
{
  char buf[128];
  snprintf(buf, sizeof(buf), "%s/binlog.%d", path_.c_str(), filenum_);
  return buf;
}

int DataBuilder::Append(const std::string &str)
{
  std::string tmp;
  gid_->EncodeTo(tmp);
  char buf[10];
  int len = str.length();
  memcpy(buf, &len, sizeof(len));
  tmp.append(buf, sizeof(len));
  tmp.append(str);
  return writableFile_->Append(tmp.c_str());
}

int DataBuilder::PackData(const std::string &str)
{

  return 0;
}
