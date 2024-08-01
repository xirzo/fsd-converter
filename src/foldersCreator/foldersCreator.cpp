#include "foldersCreator.h"

void create_fsd_folder_directory(const string &filename) {
  string lowercaseFilename = filename;
  lower_case(lowercaseFilename);
  std::filesystem::create_directory(filename);
}
