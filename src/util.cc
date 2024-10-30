#include "util.h"

#include <string>

std::string removeEndSlash(std::string &dir_path) {
  if (dir_path.back() == '/') {
    dir_path.pop_back();
  }
  return dir_path;
}

std::string removeCurrentDirectory(std::string &file_name,
                                   std::string &dir_name) {
  dir_name = removeEndSlash(dir_name) + '/';

  if (file_name.rfind(dir_name, 0) == 0) {
    file_name = file_name.erase(file_name.find(dir_name), dir_name.length());
  }

  return file_name;
}
