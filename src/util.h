#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>

std::string removeEndSlash(std::string &dir_path);
std::string removeCurrentDirectory(std::string &file_name,
                                   std::string &dir_name);

#endif  // SRC_UTIL_H_
