/* *
 * Copyright 2023 Ahnaf Al Nafis <ahnafalnafis@gmail.com>
 * */
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::string strip_dir_slash(std::string dir_name);
std::string strip_dir_name(std::string file_name, std::string dir_name);

/* *
 * _dir is the directory to be listed.
 * _first_dir is directory that should be the _dir that was passed first time.
 * */
void list_files(const std::string &_dir, const std::string &_first_dir,
                const std::vector<std::string> &_ignored = {});

int main(int argc, char *argv[]) {
  std::string directory = ".";

  // Directories to ignore.
  std::vector<std::string> ignored{};

  // To store each argument of argument values.
  std::string argument;

  // Check if there are any argument(s) other than the command name.
  if (argc - 1) {
    for (int i = 1; i < argc; i++) {
      argument = argv[i]; /* Each argument values */

      if (argument == "--directory" || argument == "-d") {
        directory = argv[i + 1];
        if (!fs::is_directory(directory)) {
          std::cout << "No such file or directory: " << directory << std::endl;
        }

      } else if (argument == "--ignore" || argument == "-I") {
        ignored.push_back(argv[i + 1]);
      }
    }
  }

  list_files(directory, directory, ignored);

  return 0;
}

std::string strip_dir_slash(std::string dir_name) {
  if (dir_name.back() == '/') {
    dir_name.pop_back();
  }
  return dir_name;
}

std::string strip_dir_name(std::string file_name, std::string dir_name) {
  dir_name = strip_dir_slash(dir_name) + '/';
  if (file_name.rfind(dir_name, 0) == 0) {
    file_name = file_name.erase(file_name.find(dir_name), dir_name.length());
  }
  return file_name;
}

void list_files(const std::string &_dir, const std::string &_first_dir,
                const std::vector<std::string> &_ignored) {
  bool is_ignored;
  std::string entry_string;

  for (const auto &entry : fs::directory_iterator(_dir)) {
    entry_string = entry.path().string();
    is_ignored =
        (std::find(_ignored.begin(), _ignored.end(),
                   strip_dir_name(entry_string, _dir)) != _ignored.end());

    if (!is_ignored) {
      if (entry.is_directory()) {
        list_files(entry_string, _first_dir, _ignored);
      } else {
        std::cout << strip_dir_name(entry_string, _first_dir) << std::endl;
      }
    }
  }
}
