#include "./filenamesReader/filenamesReader.h"
#include "./foldersCreator/foldersCreator.h"

#include <iostream>
#include <iterator>

using std::copy;
using std::cout;
using std::ostream_iterator;
using std::filesystem::exists;

typedef vector<string> stringvec;

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

  stringvec filenames;
  read_directory_filenames(filePath, filenames);
  copy(filenames.begin(), filenames.end(),
       ostream_iterator<string>(cout, "\n"));

  return 0;
}
