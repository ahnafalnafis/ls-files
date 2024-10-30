#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "util.h"

void listFiles(std::string_view _dir, std::string_view _first_dir,
               const std::vector<std::string> &ignored_directories = {}) {
  bool is_ignored;
  std::string entry_path;

  for (const auto &entry : std::filesystem::directory_iterator(_dir)) {
    entry_path = entry.path().string();
    is_ignored =
        (std::find(ignored_directories.begin(), ignored_directories.end(),
                   removeCurrentDirectory(entry_path, _dir)) !=
         ignored_directories.end());

    if (!is_ignored) {
      if (entry.is_directory()) {
        listFiles(entry_path, _first_dir, ignored_directories);
      } else {
        std::cout << removeCurrentDirectory(entry_path, _first_dir)
                  << std::endl;
      }
    }
  }
}
