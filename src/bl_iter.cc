#include "bl_iter.h"
#include "gid.h"

#include <string>


extern Iterator* NewBLIterator(const Gid *gid)
{
  return new BLIter(gid);
}

~BLIter::BLIter()
{
  sequentialFile_->Close();
}
