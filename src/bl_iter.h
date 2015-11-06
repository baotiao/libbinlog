#ifndef BINLOG_ITER_
#define BINLOG_ITER_

#include "iterator.h"
#include "env.h"

#include "gid.h"


extern Iterator* NewBLIterator(const Gid *gid);


class BLIter: public Iterator {
public:
  explicit BLIter(const Gid *gid);
  ~BLIter();


  virtual bool Valid();

  virtual void Next();
  virtual void Seek();

private:

  SequentialFile *sequentialFile_;

};

#endif
