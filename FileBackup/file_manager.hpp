#pragma once

#include <utility>
#include <vector>
#include <filesystem>

#include "file.hpp"

namespace CppCLRWinFormsProject {

	class file_manager {
		std::filesystem::path source_dir_; // ����� � �������
		std::filesystem::path backup_dir_; // ����� ��� ��������������
		std::vector<file> backup_list_; // ������ ��������������

		size_t total_count_ = 0; // ����� ����������� ������
		size_t total_size_ = 0; // ����� ������������� ������

		bool get_paths(std::filesystem::path const& source_dir, std::filesystem::path const& backup_dir); // ������� ������ ��������������

	public:
		// ������������ �� ���������
		file_manager() = delete;
		file_manager(file_manager const&) = delete;
		file_manager(file_manager&&) = delete;
		file_manager& operator=(file_manager const&) = delete;
		file_manager& operator=(file_manager&&) = delete;
		~file_manager() = default;

		file_manager(std::filesystem::path sd, std::filesystem::path bd) // ����������� � �����������
			: source_dir_(std::move(sd)), backup_dir_(std::move(bd)) {
		}

		bool backup();	// backup files from source directory

		[[nodiscard]] std::vector<file> get_backup_list(); // �������� ������ ��������������
		[[nodiscard]] size_t get_total_count() const; // ����� ����������� ������
		[[nodiscard]] size_t get_total_size() const; // ����� ������������� ������
	};
}
