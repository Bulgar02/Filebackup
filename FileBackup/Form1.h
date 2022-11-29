#pragma once

#include "file_manager.hpp"
#include "file.hpp"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Папка с файлами";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Папка для резервных копий";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(169, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(435, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(169, 38);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(435, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(610, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Выбрать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(610, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Выбрать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(15, 64);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(678, 306);
			this->textBox3->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(313, 376);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(187, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Просмотр изменений";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(506, 376);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(187, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Синхронизировать файлы";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 411);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Создание резервных копий";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FolderBrowserDialog^ selectFolderDialog = gcnew FolderBrowserDialog();

		selectFolderDialog->Description = "Папка с файлами";
		selectFolderDialog->ShowNewFolderButton = true;
		selectFolderDialog->RootFolder = System::Environment::SpecialFolder::MyComputer;

		//Display dialog box
		if (selectFolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			textBox1->Text = selectFolderDialog->SelectedPath;
			textBox3->Clear();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		FolderBrowserDialog^ selectFolderDialog = gcnew FolderBrowserDialog();

		selectFolderDialog->Description = "Папка для резервных копий";
		selectFolderDialog->ShowNewFolderButton = true;
		selectFolderDialog->RootFolder = System::Environment::SpecialFolder::MyComputer;

		//Display dialog box
		if (selectFolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			textBox2->Text = selectFolderDialog->SelectedPath;
			textBox3->Clear();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text->Length == 0 || textBox2->Text->Length == 0) {
			return;
		}
		
		std::string path_from;
		std::string path_to;

		MarshalString(textBox1->Text, path_from);
		MarshalString(textBox2->Text, path_to);

		file_manager fm(path_from, path_to);
		auto lst = fm.get_backup_list();

		textBox3->Clear();

		for (auto const& entry : lst) {
			textBox3->AppendText(gcnew String(entry.get_file_path().string().data()) + Environment::NewLine);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text->Length == 0 || textBox2->Text->Length == 0) {
			return;
		}

		std::string path_from;
		std::string path_to;

		MarshalString(textBox1->Text, path_from);
		MarshalString(textBox2->Text, path_to);

		file_manager fm(path_from, path_to);

		auto lst = fm.get_backup_list();
		textBox3->Clear();

		for (auto const& entry : lst) {
			textBox3->AppendText(gcnew String(entry.get_file_path().string().data()) + Environment::NewLine);
		}

		if (!fm.backup()) {
			MessageBox::Show("Не удалось создать резервную копию!");
			return;
		}

		textBox3->AppendText(Environment::NewLine + gcnew String("Готово!") + Environment::NewLine);
		textBox3->AppendText(gcnew String("Скопировано файлов: ") + static_cast<Int64>(fm.get_total_count()).ToString() + Environment::NewLine);
		textBox3->AppendText(gcnew String("Общий объем: ") + static_cast<Int64>(fm.get_total_size()).ToString() + gcnew String(" байт") + Environment::NewLine);
	}
	};
}
