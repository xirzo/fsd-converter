#include "./caser/caser.h"
#include "./filenamesReader/filenamesReader.h"

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>

using std::cout;
using std::ofstream;
using std::filesystem::create_directory;
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

  string file_extension = get_file_extension(file_path);

  if (file_extension != "tsx") {
    cout << "ERROR: File should have .tsx extension\n";
    return 1;
  }

  string filename = get_filename(file_path);
  string upper_cased_filename_with_extension = filename + "." + file_extension;
  lower_case(filename);
  string filename_with_extension = filename + "." + file_extension;

  create_directory(filename);
  create_directory((filename + "/ui").c_str());
  rename(upper_cased_filename_with_extension.c_str(),
         (filename + "/ui/" + filename_with_extension).c_str());

  string function_name = filename;
  upper_case(function_name);

  ofstream index_file((filename + "/" + "index.ts").c_str());
  index_file << "export { " << function_name << " } from './ui/" << filename
             << "';";
  index_file.close();

  return 0;
}
