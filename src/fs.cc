#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "util.h"

void listFiles(std::string &directory, std::string &first_directory,
               const std::vector<std::string> &ignored_directories = {}) {
  bool is_ignored;
  std::string entry_path;

  for (const auto &entry : std::filesystem::directory_iterator(directory)) {
    entry_path = entry.path().string();
    is_ignored =
        (std::find(ignored_directories.begin(), ignored_directories.end(),
                   removeCurrentDirectory(entry_path, directory)) !=
         ignored_directories.end());

    if (!is_ignored) {
      if (entry.is_directory()) {
        listFiles(entry_path, first_directory, ignored_directories);
      } else {
        std::cout << removeCurrentDirectory(entry_path, first_directory)
                  << std::endl;
      }
    }
  }
}
