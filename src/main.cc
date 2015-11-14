#include "binlog.h"
#include "iterator.h"
#include "xdebug.h"


int main()
{
  Binlog *binlog = new Binlog("./db");

  int i = 1;
  binlog->Append("a");

  Iterator *iter = binlog->NewIterator();

  std::string sgid;
  binlog->gid()->EncodeTo(sgid);

  for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
    log_info("iter->value", iter->value().c_str());
  }
  

  return 0;
}
