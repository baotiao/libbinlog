#include "bl_iter.h"
#include "gid.h"

#include <string>


extern Iterator* NewBLIterator(const Gid* gid)
{
  return new BLIter();
}

BLIter::BLIter()
{

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
  Gid gid;
  gid.DecodeFrom(target);
  gid.DumpSelf();
  char buf[24];
  Gid tmp;
  while (dataReader_->Read(12, buf) == 0) {
    tmp.DecodeFrom(std::string(buf, 12));

    dataReader_
    if (tmp.op() == gid.op()) {
      return ;
    }
  }
}
