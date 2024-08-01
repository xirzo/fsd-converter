#include "./filenamesReader/filenamesReader.h"
#include "./foldersCreator/foldersCreator.h"

#include <cstdio>
#include <iostream>
#include <iterator>

using std::copy;
using std::cout;
using std::ostream_iterator;
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
  string new_file_path = "../" + filename;
  rename(file_path, new_file_path.c_str());

  create_fsd_folder_directory(filename);
  return 0;
}
