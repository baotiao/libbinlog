#include "env.h"
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#include <vector>

#include "xdebug.h"


int CreateDir(const std::string& path)
{
  int res = 0;

  if (mkdir(path.c_str(), 0755) != 0) {
    log_warn("mkdir error is %s", strerror(errno));
  }
  return res;
}

int FileExists(const std::string& path)
{
  return access(path.c_str(), F_OK) == 0;
}

int GetChildren(const std::string& dir, std::vector<std::string>& result) 
{
  int res = 0;
  result.clear();
  DIR* d = opendir(dir.c_str());
  if (d == NULL) {
    return errno;
  }
  struct dirent* entry;
  while ((entry = readdir(d)) != NULL) {
    result.push_back(entry->d_name);
  }
  closedir(d);
  return res;
}
