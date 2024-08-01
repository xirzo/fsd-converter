#include "./filenamesReader/filenamesReader.h"
#include "./foldersCreator/foldersCreator.h"

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

  char *filePath = argv[1];

  if (exists(filePath) == false) {
    cout << "ERROR: Can`t access file with that path\n";
    return 1;
  }

  create_fsd_folder_directory(filePath);
  return 0;
}
