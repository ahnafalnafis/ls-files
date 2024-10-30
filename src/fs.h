#ifndef SRC_FS_H_
#define SRC_FS_H_

#include <string>
#include <vector>

void listFiles(std::string &directory, std::string &first_directory,
               const std::vector<std::string> &ignored_directories = {});

#endif  // SRC_FS_H_
