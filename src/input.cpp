#include <cstdlib>
#include <dirent.h>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
using std::copy;
using std::cout;
using std::ostream_iterator;
using std::string;
using std::vector;
using std::filesystem::exists;

typedef vector<string> stringvec;

void read_directory_filenames(const string &name, stringvec &filenames) {
  DIR *directory = opendir(name.c_str());
  struct dirent *dirents;

  while ((dirents = readdir(directory)) != NULL) {
    filenames.push_back(dirents->d_name);
  }

  closedir(directory);
}

void createFsdFoldersDirectory(const string &filename) {}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("ERROR: Type in a filename\n");
    return 1;
  }

  char *directoryPath = argv[1];

  if (exists(directoryPath) == false) {
    cout << "ERROR: Can`t access directory with that path\n";
    return 1;
  }

  stringvec filenames;
  read_directory_filenames(directoryPath, filenames);
  copy(filenames.begin(), filenames.end(),
       ostream_iterator<string>(cout, "\n"));

  return 0;
}
