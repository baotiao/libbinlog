#ifndef BINLOG_H_
#define BINLOG_H_

#include <iostream>
#include <stdio.h>
#include <string>

class Index;
class Data;
class Iterator;

class Binlog
{
public:
  Binlog(const std::string& path);
  ~Binlog();
  int Append(const std::string& item);

  int Next();

  Iterator* NewIterator();

private:
  std::string path_;
  int cur_num_;
  Index *index_;
  Data *data_;

  int GetCurNum();

  Binlog(const Binlog&);
  void operator =(const Binlog&);

};

#endif
