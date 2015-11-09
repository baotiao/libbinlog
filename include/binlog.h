#ifndef BINLOG_H_
#define BINLOG_H_

#include "env.h"
#include "gid.h"


#include <iostream>
#include <stdio.h>
#include <string>


class Index;
class DataBuilder;
class Iterator;
struct Gid;

class Binlog
{
public:
  explicit Binlog(const std::string &path);
  ~Binlog();
  int Append(const std::string &item);
  int LastBinlog(Gid &gid, std::string &item);

  void Close();

  Iterator* NewIterator();
  Gid* gid() {
    return gid_;
  }

private:
  // when we restart the binlog, we need to build the index if it dosen't exist
  // when will this situation happen? such as crash, and we havn't flush the index 
  // to the file
  // so the relation between the index and data is that when we complete write
  // the data then we will flush the index to file, before that time we store
  // the index in memory.
  //
  int Recovery();

  std::string path_;
  int cur_num_;
  Gid *gid_;
  DataBuilder *dataBuilder_;
  Index *index_;

  int GetCurNum();

  // copy and copy assign should be private
  Binlog(const Binlog&);
  void operator =(const Binlog&);

};

#endif
