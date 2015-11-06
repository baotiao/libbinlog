#ifndef BINLOG_GID_H_
#define BINLOG_GID_H_

#include <string>

class Gid {
public:
  explicit Gid(int sid);
  Gid(int sid, int op, int ts);

  ~Gid() {};

  int Update();
  int EncodeTo(std::string &str) const;
  int DecodeFrom(char *str);


private:
  int sid_;
  int op_;
  int ts_;
};

#endif
