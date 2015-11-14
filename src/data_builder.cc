#include "data_builder.h"
#include "xdebug.h"
#include "gid.h"
#include "env.h"

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

int DataBuilder::Append(const std::string &item)
{
  std::string tmp;
  gid_->EncodeTo(tmp);
  char buf[12];
  uint32_t len = item.size();
  memcpy(buf, &len, sizeof(uint32_t));
  tmp.append(buf, sizeof(uint32_t));
  tmp += item;

  log_info("tmp %s item %s", tmp.c_str(), item.c_str());

  return writableFile_->Append(tmp.c_str(), tmp.size());
}

void DataBuilder::Close()
{
  writableFile_->Close();
}

int DataBuilder::PackData(const std::string &str)
{

  return 0;
}
