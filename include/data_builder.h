#ifndef DATA_BUILDER_H_
#define DataBuilder_H_

#include <string>
#include "env.h"

struct Gid;

class DataBuilder {
public:
  DataBuilder(std::string path, int filenum, Gid *gid);
  ~DataBuilder();
  int Open();
  int Append(const std::string &str);

private:
  int fd_;
  int filenum_;
  std::string path_;

  WritableFile *writableFile_;

  Gid *gid_;

  char *buf_;

  int PackData(const std::string &str);


  std::string GetFileName() const;

};

#endif

