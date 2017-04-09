#pragma comment( lib, "ws2_32.lib" )
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>
#include <winsock2.h>

using namespace std;

SOCKET Connection;

enum Packet
{
	P_ChatMessage,
	P_Test
};
namespace Проект1 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	WSADATA WSAData;
	SOCKADDR_IN addr;
	SOCKET my_sock;

	char ServerIP[] = "127.0.0.1";
	char port[] = "1509";
	int Port = atoi(port);

	bool ProcessPacket(Packet packettype)
	{
		switch (packettype)
		{
		case P_ChatMessage:
		{
			int bufferlength; //длина сообщения
			recv(Connection, (char*)&bufferlength, sizeof(int), NULL); //Буфер приема
			char * buffer = new char[bufferlength + 1]; //Выделяем буфер
			buffer[bufferlength] = '\0';
			recv(Connection, buffer, bufferlength, NULL);

			printf (buffer); //печатаем
			delete[] buffer; //удаляем буфер
			break;
		}
		case P_Test:
			printf ("Вы получили тестовый пакет!\n");
			break;
		default:
			printf ("Неизвестный пакет: ", packettype);
			break;
		}
		return true;
	}

	void ClientThread()
	{
		Packet packettype;
		while (true)
		{
			//Сначала получаем тип пакета
			recv(Connection, (char*)&packettype, sizeof(Packet), NULL); //Получение типа пакета с сервера

			if (!ProcessPacket(packettype)) //Если пакет неправильно обработан
				break; //выход из цикла
		}
	}

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
		{
			InitializeComponent();
			button1->Enabled = false;
			richTextBox1->Enabled = false;
			richTextBox2->Enabled = false;
			label5->Text = "Введите данные";

			/*подгрузить настройки сервера*/

			//
			//TODO: добавьте код конструктора
			//
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label6;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(357, 157);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 56);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отправить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 157);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(339, 56);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(130, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(116, 43);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(129, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"IP-адрес сервера";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Номер порта";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(264, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 50);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Соединиться";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(12, 236);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(459, 176);
			this->richTextBox2->TabIndex = 7;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Чат";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Сообщение";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(261, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(10, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L" ";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(116, 78);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(129, 20);
			this->textBox3->TabIndex = 11;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(83, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Ник";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(484, 424);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		/*функция приема сообщений 1
		void recvMessage(){
			char buffer2[1024];
			recv(Connection, buffer2, 1024, 0);
			String^ bufname = "";           //имя строки буфера

			for (int i = 0; i < 1024; i++){
				bufname += buffer2[i];
			}
			richTextBox2->AppendText(bufname);

		};*/
	String^ nickname = ""; //ник пользователя


#pragma endregion


	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		setlocale(LC_ALL, "russian");
		nickname += textBox3->Text;
		textBox3->Text = "";
		button1->Enabled = true;
		richTextBox1->Enabled = true;
		//Подключаемся к серверу и отправляем сообщение на сервер
		WSAStartup(MAKEWORD(2, 0), &WSAData);
		//server = socket(AF_INET, SOCK_STREAM, 0);

		SOCKADDR_IN addr;
		int sizeofaddr = sizeof(addr);
		addr.sin_addr.s_addr = inet_addr(ServerIP);
		addr.sin_family = AF_INET;
		addr.sin_port = htons(Port);
		//connect(server, (SOCKADDR *)&addr, sizeof(addr));
		Connection = socket(AF_INET, SOCK_STREAM, NULL); //Установить гнездо подключения
		if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) //Если мы не можем подключиться...
		{
			label4->Text = "Нет подключения!";

		}

		label5->Text = "Подключён!";
		/*Создание клиентского потока, который получает все данные, отправляемые сервером*/
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); 


	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		String^ user = nickname + ":" + " "; //строка
		user += richTextBox1->Text;
		user += "\n";
		char buffer[1024];
		int bufferlength = user->Length;

		for (int i = 0; i < 1024; i++){
			buffer[i] = 0;
		}
		for (int i = 0; i < bufferlength; i++){
			buffer[i] = user[i];
		}


		Packet chatmessagepacket = P_ChatMessage;
		send(Connection, (char*)&chatmessagepacket, sizeof(Packet), NULL); //Отправить тип пакета: ChatMessage
		send(Connection, (char*)&bufferlength, sizeof(int), NULL); //Отправить длину буфера
		send(Connection, buffer, bufferlength, NULL); //Отправить буфер

		richTextBox2->AppendText(user);
		richTextBox1->Clear();
		Sleep(10);
		
	}
private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
