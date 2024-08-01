#include "./filenamesReader/filenamesReader.h"
#include "./foldersCreator/foldersCreator.h"
#include "caser/caser.h"

#include <cstdio>
#include <filesystem>
#include <iostream>
#include <ostream>

using std::cout;
using std::filesystem::create_directory;
using std::filesystem::exists;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: Type in a file path\n");
    return 1;
  }

  char *file_path = argv[1];

  if (exists(file_path) == false) {
    cout << "ERROR: Can`t access file with that path\n";
    return 1;
  }

  string filename = get_filename(file_path);
  string filename_with_extension = get_filename_with_extension(file_path);
  create_directory(filename);
  create_directory((filename + "/ui").c_str());
  rename(filename_with_extension.c_str(),
         (filename + "/ui/" + filename_with_extension).c_str());

  return 0;
}
