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
  log_info("sequential file rent %d", ret);
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

int DataReader::Read(size_t n, char *result)
{
  int ret = sequentialFile_->Read(n, result, buf_);
  if (n == 12) {
    // log_info("result %p buf %p", result, buf_);
    // log_info("address result %p buf %p", result, buf_);
    for (int i = 0; i < n; i++) {
      printf("%d ", result[i]);
    }
    printf("\n");

    // for (int i = 0; i < n; i++) {
    //   printf("%d ", buf_[i]);
    // }
    // printf("\n");
  }

  return ret;
}

bool DataReader::Valid()
{
  return true;
}
