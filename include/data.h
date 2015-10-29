#ifndef DATA_H_
#define DATA_H_

#include <string>

class Data {
public:
  Data(std::string path, int filenum);
  int Open();
  ~Data();
  int Append(const std::string &str);

private:
  int fd_;
  int filenum_;
  std::string path_;

  FILE *f_;

  std::string GetFileName();

};

#endif

