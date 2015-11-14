#include "env.h"
#include "binlog.h"
#include "data_builder.h"
#include "bl_iter.h"

#include "xdebug.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

Binlog::Binlog(const std::string& path) :
  path_(path)
{
  if (FileExists(path_) == false) {
    CreateDir(path_);
  }

  GetCurNum();

  gid_ = new Gid(uint32_t(1));
  dataBuilder_ = new DataBuilder(path_, cur_num_, gid_);
}

void Binlog::GetCurNum()
{
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
}

int Binlog::Append(const std::string& item)
{
  int ret = 0;
  dataBuilder_->Append(item);
  gid_->Update();
  return ret;
}

Iterator* Binlog::NewIterator()
{
  return NewBLIterator(path_);
}

void Binlog::Close()
{
  dataBuilder_->Close();
}
