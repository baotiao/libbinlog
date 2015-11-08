#include "data_reader.h"
#include "env.h"

DataReader::DataReader(const std::string &path, int filenum, Gid *gid) :
  path_(path),
  filenum_(filenum),
  gid_(gid)
{
  NewSequentialFile(GetFileName(), &sequentialFile_);
  buf_ = (char *)malloc(sizeof(char));
}

std::string DataReader::GetFileName() const
{
  char buf[128];
  snprintf(buf, sizeof(buf), "%s/binlog.%d", path_.c_str(), filenum_);
  return buf;
}

int DataReader::Read(size_t n, std::string &result)
{
  char *p;
  int ret = sequentialFile_->Read(n, p, buf_);

  result = std::string(p, n);
  return ret;
}
