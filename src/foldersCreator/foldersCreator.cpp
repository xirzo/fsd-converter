#include "foldersCreator.h"

void createFsdFoldersDirectory(const string &filename) {
  string lowercaseFilename = filename;
  lowerCase(lowercaseFilename);
  std::filesystem::create_directory(filename);
}
