#include "pch.h"

#include <iostream>
#include <iomanip>

#include "file.hpp"
#include "file_manager.hpp"

namespace CppCLRWinFormsProject {

	// создать список резервирования
	bool file_manager::get_paths(std::filesystem::path const& source_dir, std::filesystem::path const& backup_dir) {
		if (!exists(backup_dir))
			create_directory(backup_dir);

		for (auto& entry : std::filesystem::directory_iterator(source_dir)) {
			if (entry.is_directory()) { // для директорий рекурсивно создать список резервирования
				if (!get_paths(entry.path(), backup_dir.string().append("\\").append(entry.path().filename().string()))) {
					return false;
				}
			}

			if (!entry.is_regular_file()) { // пропускаем не файлы
				continue;
			}

			auto target_path = backup_dir.string().append("\\").append(entry.path().filename().string());

			// запоминаем измененный или отсутствующий файл
			if (!std::filesystem::exists(target_path) ||
				entry.file_size() != std::filesystem::file_size(target_path) ||
				entry.last_write_time() != std::filesystem::last_write_time(target_path)) {
				backup_list_.emplace_back(entry, backup_dir, entry.path().filename().string());
			}
		}

		return true;
	}

	// выполнить резервирование
	bool file_manager::backup() {
		backup_list_.clear();
		total_count_ = 0;
		total_size_ = 0;

		// получаем список файлов
		try {
			if (!get_paths(source_dir_, backup_dir_)) {
				backup_list_.clear();
				return false;
			}
		}
		// если исключение - выходим
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			backup_list_.clear();
			return false;
		}

		// проходим по списку и копируем файлы
		for (auto& p : backup_list_) {
			try {
				if (std::filesystem::exists(p.get_backup_path().string().append("\\").append(p.get_name()))) {
					std::filesystem::remove(p.get_backup_path().string().append("\\").append(p.get_name()));
				}

				copy(p.get_file_path(), p.get_backup_path());
				total_size_ += file_size(p.get_file_path());
				++total_count_;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}

		return true;
	}

	// выдать список резервирования
	std::vector<file> file_manager::get_backup_list() {
		backup_list_.clear();

		try {
			if (!get_paths(source_dir_, backup_dir_)) {
				backup_list_.clear();
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			backup_list_.clear();
		}

		return backup_list_;
	}

	// сколько файлов
	size_t file_manager::get_total_count() const {
		return total_count_;
	}

	// объем файлов
	size_t file_manager::get_total_size() const {
		return total_size_;
	}
}
