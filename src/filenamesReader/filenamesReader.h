#pragma once
#include <dirent.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

typedef vector<string> stringvec;

void read_directory_filenames(const string &name, stringvec &filenames);
