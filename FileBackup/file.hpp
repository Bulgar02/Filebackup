#pragma once

#include <filesystem>
#include <utility>

// Файл для резервирования
namespace CppCLRWinFormsProject {

	class file
	{
	public:
		file() = delete;
		file(std::filesystem::path f, std::filesystem::path b, std::string s)
			: file_path_(std::move(f)), backup_path_(std::move(b)), file_name_(std::move(s)) {}

		[[nodiscard]] std::filesystem::path const& get_file_path() const;   // откуда копируется
		[[nodiscard]] std::filesystem::path const& get_backup_path() const; // куда копируется
		[[nodiscard]] std::string const& get_name() const;                  // имя файла

	private:
		std::filesystem::path file_path_;   // откуда копируется
		std::filesystem::path backup_path_;	// куда копируется
		std::string file_name_;				// имя файла
	};
}
