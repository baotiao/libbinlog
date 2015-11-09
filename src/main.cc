#include "binlog.h"
#include "iterator.h"
#include "xdebug.h"


int main()
{
  Binlog *binlog = new Binlog("./db/");

  int i = 10;
  while (i--) {
    binlog->Append("hei");
  }

  // binlog->Close();

  Iterator *iter = binlog->NewIterator();
  std::string sgid;
  binlog->gid()->EncodeTo(sgid);
  iter->Seek(sgid);
  

  return 0;
}
