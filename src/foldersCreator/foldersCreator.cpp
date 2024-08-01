#include "foldersCreator.h"

void create_fsd_folder_directory(const string &filename) {
  string lowercase_filename = filename;
  lower_case(lowercase_filename);
  std::filesystem::create_directory(lowercase_filename);
}
