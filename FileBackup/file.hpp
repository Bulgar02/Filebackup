#pragma once

#include <filesystem>
#include <utility>

// ���� ��� ��������������
namespace CppCLRWinFormsProject {

	class file
	{
	public:
		file() = delete;
		file(std::filesystem::path f, std::filesystem::path b, std::string s)
			: file_path_(std::move(f)), backup_path_(std::move(b)), file_name_(std::move(s)) {}

		[[nodiscard]] std::filesystem::path const& get_file_path() const;   // ������ ����������
		[[nodiscard]] std::filesystem::path const& get_backup_path() const; // ���� ����������
		[[nodiscard]] std::string const& get_name() const;                  // ��� �����

	private:
		std::filesystem::path file_path_;   // ������ ����������
		std::filesystem::path backup_path_;	// ���� ����������
		std::string file_name_;				// ��� �����
	};
}
