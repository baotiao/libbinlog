#ifndef DATA_H_
#define DATA_H_

#include <string>
#include "env.h"

struct Gid;

class Data {
public:
  Data(std::string path, int filenum, Gid *gid);
  ~Data();
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

