#ifndef ENV_H_
#define ENV_H_

#include <string>
#include <vector>

int CreateDir(const std::string& path);

int FileExists(const std::string& path);

int GetChildren(const std::string& dir, std::vector<std::string>& result);
#endif
