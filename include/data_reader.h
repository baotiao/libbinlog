#ifndef DATA_READER_H_
#define DATA_READER_H_

#include "gid.h"

#include <string>

class SequentialFile;

class DataReader
{
public:
  DataReader(const std::string &path, int filenum, Gid *gid);
  ~DataReader();

  std::string GetFileName() const;

  int Read(size_t n, char *&result);

  bool Valid();

private:
  std::string path_;
  int filenum_;
  Gid *gid_;

  char *buf_;

  SequentialFile *sequentialFile_;

};

#endif
