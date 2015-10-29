#include "binlog.h"


int main()
{
  Binlog *binlog = new Binlog("./db/");

  int i = 1000000000;
  while (i--) {
    binlog->Append("heihei");
  }

  return 0;
}
