#include "./filenamesReader/filenamesReader.h"
#include "./foldersCreator/foldersCreator.h"
#include "caser/caser.h"

#include <cstdio>
#include <iostream>

using std::cout;
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

  string temp_filename = get_filename(file_path);
  string filename = temp_filename;
  lower_case(filename);
  rename(temp_filename.c_str(), filename.c_str());

  string directory_name = filename;
  upper_case(directory_name);
  create_fsd_folder_directory(directory_name);
  rename(filename.c_str(), (directory_name + "/" + filename).c_str());

  return 0;
}
