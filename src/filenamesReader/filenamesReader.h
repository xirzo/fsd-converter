#pragma once
#include <dirent.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

typedef vector<string> stringvec;

string get_filename(const string &path);
void read_directory_filenames(const string &path, stringvec &filenames);
