#include "bl_iter.h"
#include "gid.h"
#include "data_reader.h"
#include "xdebug.h"

#include <string>
#include <cstring>


extern Iterator* NewBLIterator(const std::string &path)
{
  return new BLIter(path);
}

BLIter::BLIter(const std::string &path) :
  path_(path)
{
  Gid gid;
  dataReader_ = new DataReader(path_, 0, &gid);
}

BLIter::~BLIter()
{
  // sequentialFile_->Close();
}

bool BLIter::Valid() const
{
}

void BLIter::Next()
{
}

void BLIter::Seek(const std::string &target)
{
  char buf[1024];
  Gid tmp;
  uint32_t item_len = 0;
  while (dataReader_->Read(12, buf) == 0) {
    tmp.DecodeFrom(std::string(buf, 12));
    dataReader_->Read(4, buf);
    memcpy(&item_len, buf, sizeof(uint32_t));
    dataReader_->Read(item_len, buf);

    log_info("op %lu sid %lu item_len %lu", tmp.op(), tmp.sid(), item_len);
    sleep(1);
  }
}
