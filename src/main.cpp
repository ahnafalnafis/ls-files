/**
 * Copyright (C) 2023 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "fs.h"

int main(int argc, char *argv[]) {
  std::string argument;
  std::string next_arg;
  const bool has_arguments = (argc - 1 != 0);

  std::string directory = ".";
  std::vector<std::string> ignored_directories{};

  if (has_arguments) {
    for (int i = 1; i < argc; i++) {
      argument = argv[i];
      next_arg = argv[i + 1];

      if (argument == "--directory" || argument == "-d") {
        directory = next_arg;

        if (!std::filesystem::is_directory(directory)) {
          std::cout << "\"" << directory << "\" is not a directory"
                    << std::endl;

          return 0;
        }

      } else if (argument == "--ignore" || argument == "-I") {
        ignored_directories.push_back(next_arg);
      }
    }
  }

  listFiles(directory, directory, ignored_directories);

  return 0;
}
