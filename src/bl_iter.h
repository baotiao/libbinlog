#ifndef BINLOG_ITER_
#define BINLOG_ITER_

#include "iterator.h"
#include "env.h"
#include "gid.h"


#include <string>

class DataReader;

extern Iterator* NewBLIterator(const std::string &path);


class BLIter: public Iterator {
public:
  BLIter(const std::string &path);
  ~BLIter();


  virtual bool Valid() const;

  virtual void Next();
  virtual void Seek(const std::string &target);

private:

  std::string path_;

  DataReader *dataReader_;

};

#endif
