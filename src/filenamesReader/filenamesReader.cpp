#include "filenamesReader.h"

string get_filename(const string &path) {
  string file_name = get_filename_with_extension(path);
  return file_name.substr(0, file_name.find_last_of("."));
}

string get_filename_with_extension(const string &path) {
  return path.substr(path.find_last_of("/\\") + 1);
}

string get_file_extension(const string &path) {
  return path.substr(path.find_last_of(".") + 1);
}

void read_directory_filenames(const string &path, stringvec &filenames) {
  DIR *directory = opendir(path.c_str());
  struct dirent *dirents;

  while ((dirents = readdir(directory)) != NULL) {
    filenames.push_back(dirents->d_name);
  }

  closedir(directory);
}
