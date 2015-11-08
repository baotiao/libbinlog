#ifndef BINLOG_GID_H_
#define BINLOG_GID_H_

#include <string>

class Gid {
public:
  Gid() {};
  explicit Gid(uint32_t sid);
  Gid(uint32_t sid, uint32_t op, uint32_t ts);

  ~Gid() {};

  uint32_t op() { return op_; };
  uint32_t sid() { return sid_; };
  int Update();
  int EncodeTo(std::string &str) const;
  int DecodeFrom(const std::string &);


  void DumpSelf() const;
  std::string DebugString() const;

private:
  uint32_t sid_;
  uint32_t op_;
  uint32_t ts_;
};

#endif
