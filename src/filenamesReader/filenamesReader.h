#pragma once
#include <dirent.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

typedef vector<string> stringvec;

string get_filename(const string &path);
string get_filename_with_extension(const string &path);
string get_file_extension(const string &path);
void read_directory_filenames(const string &path, stringvec &filenames);
