#include "filenamesReader.h"

void read_directory_filenames(const string &name, stringvec &filenames) {
  DIR *directory = opendir(name.c_str());
  struct dirent *dirents;

  while ((dirents = readdir(directory)) != NULL) {
    filenames.push_back(dirents->d_name);
  }

  closedir(directory);
}
