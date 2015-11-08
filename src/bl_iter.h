#ifndef BINLOG_ITER_
#define BINLOG_ITER_

#include "iterator.h"
#include "env.h"
#include "gid.h"

class DataReader;

extern Iterator* NewBLIterator(const Gid *gid);


class BLIter: public Iterator {
public:
  BLIter();
  ~BLIter();


  virtual bool Valid() const;

  virtual void Next();
  virtual void Seek(const std::string &target);

private:

  DataReader *dataReader_;

};

#endif
