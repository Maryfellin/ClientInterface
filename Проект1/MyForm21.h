#pragma once

namespace Проект1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			button1->Enabled = false;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label1;




	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 126);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(79, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(120, 126);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(79, 20);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(226, 126);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(79, 20);
			this->textBox3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(336, 126);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(79, 20);
			this->textBox4->TabIndex = 3;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(440, 126);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(79, 20);
			this->textBox5->TabIndex = 4;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox5_TextChanged);
			// 
			// label1
			// 
			this->label1->AllowDrop = true;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Введите ключ продукта";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(186, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 37);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Далее";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(541, 252);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm2";
			this->Text = L"Проверка ключа";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//32063-42155-89820-78679-51263 - - - > ключ
	if (textBox1->Text == "32063" && textBox2->Text == "42155" && textBox3->Text == "89820" && textBox4->Text == "78679" && textBox5->Text == "51263"){
		label1->Text = "Верный ключ! Нажмите ДАЛЕЕ";
		button1->Enabled = true;
	}


}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
