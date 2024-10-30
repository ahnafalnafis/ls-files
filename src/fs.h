#ifndef SRC_FS_H_
#define SRC_FS_H_

#include <string>
#include <string_view>
#include <vector>

void listFiles(std::string_view _dir, std::string_view _first_dir,
               const std::vector<std::string> &ignored_directories = {});

#endif  // SRC_FS_H_
