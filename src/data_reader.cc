#include "data_reader.h"
#include "xdebug.h"
#include "env.h"

#include "assert.h"

DataReader::DataReader(const std::string &path, int filenum, Gid *gid) :
  path_(path),
  filenum_(filenum),
  gid_(gid)
{
  int ret = NewSequentialFile(GetFileName(), &sequentialFile_);
  assert(ret == 0);
  buf_ = (char *)malloc(sizeof(char));
}

DataReader::~DataReader()
{

}

std::string DataReader::GetFileName() const
{
  char buf[128];
  snprintf(buf, sizeof(buf), "%s/binlog.%d", path_.c_str(), filenum_);
  return buf;
}

int DataReader::Read(size_t n, char *&result)
{
  log_info("DataReader read %zu", n);
  int ret = sequentialFile_->Read(n, result, buf_);

  log_info("sequential read ret %d", ret);
  return ret;
}

bool DataReader::Valid()
{
  return true;
}
