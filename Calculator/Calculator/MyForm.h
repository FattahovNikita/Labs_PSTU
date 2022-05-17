#define _USE_MATH_DEFINES
#include<cmath>
#pragma once


namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;











	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(5, 73);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"��������", L"���������", L"���������", L"�������",
					L"���������� � �������", L"���������� �����", L"���������� ���������", L"���������� �������", L"���������� ����������"
			});
			this->comboBox1->Location = System::Drawing::Point(161, 10);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(172, 24);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(5, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 41);
			this->button1->TabIndex = 2;
			this->button1->Text = L"���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(217, 136);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 41);
			this->button2->TabIndex = 3;
			this->button2->Text = L"��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"������ �����";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(135, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"������ �����";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(134, 73);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(270, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"���������";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(261, 73);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"�������� ��������";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(19, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(375, 212);
			this->tabControl1->TabIndex = 7;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(367, 183);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"��������";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->comboBox3);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->textBox5);
			this->tabPage2->Controls->Add(this->textBox4);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->comboBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(367, 183);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"���������������� �������";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(112, 95);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"����� ��";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(6, 136);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(144, 41);
			this->button4->TabIndex = 8;
			this->button4->Text = L"���������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(222, 136);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 41);
			this->button3->TabIndex = 8;
			this->button3->Text = L"��������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�������", L"�������" });
			this->comboBox3->Location = System::Drawing::Point(233, 43);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(92, 24);
			this->comboBox3->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 46);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(221, 17);
			this->label8->TabIndex = 9;
			this->label8->Text = L"�������� ������� ��� �������";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(249, 76);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(76, 17);
			this->label7->TabIndex = 8;
			this->label7->Text = L"���������";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(6, 96);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(209, 96);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(152, 22);
			this->textBox4->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 76);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 17);
			this->label6->TabIndex = 2;
			this->label6->Text = L"��������";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(137, 17);
			this->label5->TabIndex = 1;
			this->label5->Text = L"�������� �������";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"�����", L"�������", L"�������", L"���������",
					L"��������", L"����������", L"����������", L"������������"
			});
			this->comboBox2->Location = System::Drawing::Point(149, 10);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 0;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(410, 27);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(224, 183);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(461, 7);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(128, 17);
			this->label9->TabIndex = 9;
			this->label9->Text = L"���� ��� �������";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 98);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(90, 34);
			this->label10->TabIndex = 7;
			this->label10->Text = L"(���������\r\n ���������)";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(144, 98);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(84, 34);
			this->label11->TabIndex = 8;
			this->label11->Text = L"(��������.\r\n    �����)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 226);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = ""; textBox2->Text = ""; textBox3->Text = "";
	}
		   bool check_input_textbox_1() {
			   if (textBox1->Text->Length == 0) return false;
			   for (int i = 0; i < textBox1->Text->Length; ++i) {
				   if ((textBox1->Text[i] >= '0' && textBox1->Text[i] <= '9') || textBox1->Text[i] == ',' || textBox1->Text[i] == '-') {}
				   else return false;
				   return true;
			   }

	}
		   bool check_input_textbox_2() {
			   if (textBox2->Text->Length == 0) return false;
			   for (int i = 0; i < textBox2->Text->Length; ++i) {
				   if ((textBox2->Text[i] >= '0' && textBox2->Text[i] <= '9') || textBox2->Text[i] == ',' || textBox2->Text[i] == '-') {}
				   else return false;
				   return true;
			   }
		   }
		   bool check_input_textbox_5() {
			   if (textBox5->Text->Length == 0) return false;
			   for (int i = 0; i < textBox5->Text->Length; ++i) {
				   if ((textBox5->Text[i] >= '0' && textBox5->Text[i] <= '9') || textBox5->Text[i] == ',' || textBox5->Text[i] == '-') {}
				   else return false;
				   return true;
			   }
		   }

private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (check_input_textbox_1() && check_input_textbox_2()) {
		double number_1, number_2, result = 0;
		number_1 = System::Convert::ToDouble(textBox1->Text);
		number_2 = System::Convert::ToDouble(textBox2->Text);
		

		if (comboBox1->SelectedItem == "��������") {
			result = number_1 + number_2;
		}
		else if (comboBox1->SelectedItem == "���������") {
			result = number_1 - number_2;
		}
		else if (comboBox1->SelectedItem == "���������") {
			result = number_1 * number_2;
		}
		else if (comboBox1->SelectedItem == "�������") {
			if (number_2 != 0) result = number_1 / number_2;
			else MessageBox::Show("������ ������ �� 0");
		}
		else if (comboBox1->SelectedItem == "���������� �������") {
			if (number_2 != 0) result = (int)number_1 % (int)number_2;
			else MessageBox::Show("������ ������ �� 0");
		}
		else if (comboBox1->SelectedItem == "���������� � �������") {
			result = pow(number_1,number_2);
			
		}
		else if (comboBox1->SelectedItem == "���������� �����") {

			if (number_2 > 0 && number_1 >= 0)  result = pow(number_1, 1/number_2);
			if (number_2 <= 0) MessageBox::Show("������� ����� ������ ���� ������ ����");
			if (number_1 < 0) MessageBox::Show("����� ��� ������ ������ ���� �� ������ ����");
		}
		else if (comboBox1->SelectedItem == "���������� ���������") {

			if (number_1 > 0 && number_2 > 0 && number_1!=1)  result = log(number_2)/log(number_1);
			if (number_1 <= 0) MessageBox::Show("��������������� ��������� ������ ���� ������ 0");
			if (number_2 <= 0) MessageBox::Show("��������������� ����� ������ ���� ������ 0 ");
			if (number_1 == 1) MessageBox::Show("��������������� ��������� �� ������ ���� ����� 1");
		}
		else if (comboBox1->SelectedItem == "���������� ����������") {
			textBox2->Text = System::Convert::ToString(0);
			long long int F = 1;
			for (int i = 1; i <= number_1; ++i)
			{
				F *= i; 
			}
			result = F;
		}
		else return;
		textBox3->Text = System::Convert::ToString(result);
	}
	else MessageBox::Show("������ ������� �����������");
}

private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Text = ""; textBox5->Text = "";
		   
	   }
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e){
	if (check_input_textbox_5()) {
			   double number_5,tresult = 0;
			   number_5 = System::Convert::ToDouble(textBox5->Text);


			   if (comboBox2->SelectedItem == "�����" && comboBox3->SelectedItem == "�������") {
				   if ((int)number_5 % 180 == 0) tresult = 0;
				   else tresult = sin(number_5 * M_PI/180.0);
			   }
			   else if (comboBox2->SelectedItem == "�����" && comboBox3->SelectedItem == "�������") {
				   if (number_5  == M_PI) tresult = 0;
				   else tresult = sin(number_5);
			   }
			   else if (comboBox2->SelectedItem == "�������" && comboBox3->SelectedItem == "�������") {
				   if ((int)number_5 % 90 == 0 && (int)number_5 % 180 != 0) tresult = 0;
				   else tresult = cos(number_5 * M_PI / 180.0);
			   }
			   else if (comboBox2->SelectedItem == "�������" && comboBox3->SelectedItem == "�������") {
				   tresult = cos(number_5);
			   }
			   else if (comboBox2->SelectedItem == "�������" && comboBox3->SelectedItem == "�������") {
				   if ((int)number_5 % 90 == 0 && (int)number_5 % 180 != 0) MessageBox::Show("������� �� ���������, ������� �� ���� ����������");
				   else if ((int)number_5 % 180 == 0) tresult = 0;
				   else tresult = tan(number_5 * M_PI / 180.0);
			   }
			   else if (comboBox2->SelectedItem == "�������" && comboBox3->SelectedItem == "�������")
			   {
				   tresult = tan(number_5);
			   }
			   else if (comboBox2->SelectedItem == "���������" && comboBox3->SelectedItem == "�������") {
				   if ((int)number_5 % 180 == 0) MessageBox::Show("��������� �� ���������, ������� �� ���� ����������");
				   else if ((int)number_5 % 90 == 0) tresult = 0;
				   else tresult = 1.0/tan(number_5 * M_PI / 180.0);
			   }
			   else if (comboBox2->SelectedItem == "���������" && comboBox3->SelectedItem == "�������")
			   {
				   if (number_5 == 3, 14159265358979) MessageBox::Show("��������� �� ���������, ������� �� ���� ����������");
				   else tresult = 1.0/tan(number_5);
			   }
			   else if (comboBox2->SelectedItem == "��������" && comboBox3->SelectedItem == "�������") {
				   if (number_5<-1 || number_5>1) MessageBox::Show("�������� ������ ���� � �������� �� -1 �� 1");
				   else tresult = asin(number_5) * 180.0 / M_PI;
			   }
			   else if (comboBox2->SelectedItem == "��������" && comboBox3->SelectedItem == "�������") {
				   if (number_5 < -1 || number_5>1) MessageBox::Show("�������� ������ ���� � �������� �� -1 �� 1");
				   else tresult = asin(number_5);
			   }
			   else if (comboBox2->SelectedItem == "����������" && comboBox3->SelectedItem == "�������") {
				   if (number_5 < -1 || number_5>1) MessageBox::Show("�������� ������ ���� � �������� �� -1 �� 1");
				   else tresult = acos(number_5) * 180.0 / M_PI;
			   }
			   else if (comboBox2->SelectedItem == "����������" && comboBox3->SelectedItem == "�������") {
				   if (number_5 < -1 || number_5>1) MessageBox::Show("�������� ������ ���� � �������� �� -1 �� 1");
				   else tresult = acos(number_5);
			   }
			   else if (comboBox2->SelectedItem == "����������" && comboBox3->SelectedItem == "�������") {
				   
				   tresult = atan(number_5) * 180.0 / M_PI;
			   }
			   else if (comboBox2->SelectedItem == "����������" && comboBox3->SelectedItem == "�������") {
				   
				   tresult = atan(number_5);
			   }
			   else if (comboBox2->SelectedItem == "������������" && comboBox3->SelectedItem == "�������") {
				   
				    tresult = (M_PI/2.0 - atan(number_5)) * 180.0 / M_PI;
			   }
			   else if (comboBox2->SelectedItem == "������������" && comboBox3->SelectedItem == "�������") {
				  
				    tresult = (M_PI / 2.0 - atan(number_5));
			   }

			   else return;
			   textBox4->Text = System::Convert::ToString(tresult);
		   }
		   else MessageBox::Show("������ ������� �����������");
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e){
	textBox5->Text = System::Convert::ToString(M_PI);
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
