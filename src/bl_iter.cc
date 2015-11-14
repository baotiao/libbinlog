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
  return valid_;
}

void BLIter::Next()
{
  char *buf;
  Gid tmp;
  uint32_t item_len = 0;
  if (dataReader_->Read(12, buf) > 0) {
    valid_ = true;
  } else {
    valid_ = false;
  }
  dataReader_->Read(4, buf);
  memcpy(&item_len, buf, sizeof(uint32_t));
  dataReader_->Read(item_len, buf);
  value_ = std::string(buf, item_len);
}

std::string BLIter::value()
{
  return value_;
}

void BLIter::Seek(const std::string &target)
{
  char *buf;
  Gid tmp;
  uint32_t item_len = 0;
  Gid targetGid;
  targetGid.DecodeFrom(target);
  while (dataReader_->Read(12, buf) > 0) {
    tmp.DecodeFrom(std::string(buf, 12));
    dataReader_->Read(4, buf);

    memcpy(&item_len, buf, sizeof(uint32_t));
    dataReader_->Read(item_len, buf);
    
    log_info("target op %d tmp op %d", targetGid.op(), tmp.op());
    if (targetGid.op() == tmp.op()) {
      
      value_ = std::string(buf, item_len);
      break;
    }
  }
}

void BLIter::SeekToFirst()
{
  dataReader_ = 

}
