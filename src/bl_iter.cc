#include "bl_iter.h"
#include "gid.h"

#include <string>


extern Iterator* NewBLIterator(const Gid *gid)
{
  return new BLIter(gid);
}

BLIter::BLIter(const Gid* gid)
{

}

BLIter::~BLIter()
{
  sequentialFile_->Close();
}

bool BLIter::Valid() const
{
}

void BLIter::Next()
{
}

void BLIter::Seek(const std::string& target)
{
}
