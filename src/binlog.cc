#include "env.h"
#include "binlog.h"
#include "data.h"
#include "bl_iter.h"

#include "xdebug.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

Binlog::Binlog(const std::string& path) :
  path_(path)
{
  int ans = FileExists(path_);
  if (ans == false) {
    CreateDir(path_);
  }

  GetCurNum();

  gid_ = new Gid(1);
  data_ = new Data(path_, cur_num_, gid_);
  log_info("%d", ans);
  
}

int Binlog::GetCurNum()
{
  int res = 0;
  std::vector<std::string> childrens;
  GetChildren(path_, childrens);
  int max_cur_num = 0;
  std::string::size_type pos;
  int tmp;
  for (int i = 0; i < childrens.size(); i++) {
    pos = childrens[i].find("binlog.");
    if (pos != std::string::npos) {
      tmp = atoi(childrens[i].substr(pos + sizeof("binlog.") - 1).c_str());
      max_cur_num = max_cur_num > tmp ? max_cur_num : tmp;
    }
  }
  cur_num_ = max_cur_num;
  return res;
}

int Binlog::Append(const std::string& item)
{
  data_->Append(item);
  gid_->Update();
}

Iterator* NewIterator(const Gid *gid)
{
  return NewBLIterator(gid);
}
