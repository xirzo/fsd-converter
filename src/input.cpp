#include <dirent.h>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
typedef std::vector<std::string> stringvec;

void read_directory_filenames(const std::string &name, stringvec &filenames) {
  DIR *directory = opendir(name.c_str());
  struct dirent *dirents;

  while ((dirents = readdir(directory)) != NULL) {
    filenames.push_back(dirents->d_name);
  }

  closedir(directory);
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("ERROR: Type in a filename\n");
    return 1;
  }

  char *directoryPath = argv[1];

  if (std::filesystem::exists(directoryPath) == false) {
    std::cout << "ERROR: Can`t access directory with that path\n";
  }

  stringvec filenames;
  read_directory_filenames(directoryPath, filenames);
  std::copy(filenames.begin(), filenames.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"));

  return 0;
}
