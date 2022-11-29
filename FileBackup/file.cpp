#include "pch.h"

#include <filesystem>

#include "file.hpp"

namespace CppCLRWinFormsProject {

	std::filesystem::path const& file::get_file_path() const { return file_path_; }

	std::filesystem::path const& file::get_backup_path() const { return backup_path_; }

	std::string const& file::get_name() const { return file_name_; }
}
