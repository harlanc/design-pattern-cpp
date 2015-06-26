#pragma once
#include "OperationFactory.h"
#include "Operation.h"
#include <iostream>
using namespace std;
namespace DesignPattern {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  rbResult;
	protected: 

	private: System::Windows::Forms::Button^  bt1;
	private: System::Windows::Forms::Button^  bt3;
	protected: 


	private: System::Windows::Forms::Button^  bt2;
	private: System::Windows::Forms::Button^  bt5;
	private: System::Windows::Forms::Button^  bt6;



	private: System::Windows::Forms::Button^  bt4;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  bt0;

	private: System::Windows::Forms::Button^  bt8;
	private: System::Windows::Forms::Button^  bt9;




	private: System::Windows::Forms::Button^  bt7;
	private: System::Windows::Forms::Button^  btdvid;


	private: System::Windows::Forms::Button^  btMul;

	private: System::Windows::Forms::Button^  btDel;

	private: System::Windows::Forms::Button^  btAdd;


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->rbResult = (gcnew System::Windows::Forms::TextBox());
			this->bt1 = (gcnew System::Windows::Forms::Button());
			this->bt3 = (gcnew System::Windows::Forms::Button());
			this->bt2 = (gcnew System::Windows::Forms::Button());
			this->bt5 = (gcnew System::Windows::Forms::Button());
			this->bt6 = (gcnew System::Windows::Forms::Button());
			this->bt4 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->bt0 = (gcnew System::Windows::Forms::Button());
			this->bt8 = (gcnew System::Windows::Forms::Button());
			this->bt9 = (gcnew System::Windows::Forms::Button());
			this->bt7 = (gcnew System::Windows::Forms::Button());
			this->btdvid = (gcnew System::Windows::Forms::Button());
			this->btMul = (gcnew System::Windows::Forms::Button());
			this->btDel = (gcnew System::Windows::Forms::Button());
			this->btAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rbResult
			// 
			this->rbResult->Location = System::Drawing::Point(38, 30);
			this->rbResult->Name = L"rbResult";
			this->rbResult->Size = System::Drawing::Size(318, 20);
			this->rbResult->TabIndex = 0;
			// 
			// bt1
			// 
			this->bt1->Location = System::Drawing::Point(38, 81);
			this->bt1->Name = L"bt1";
			this->bt1->Size = System::Drawing::Size(75, 23);
			this->bt1->TabIndex = 1;
			this->bt1->Text = L"1";
			this->bt1->UseVisualStyleBackColor = true;
			// 
			// bt3
			// 
			this->bt3->Location = System::Drawing::Point(200, 81);
			this->bt3->Name = L"bt3";
			this->bt3->Size = System::Drawing::Size(75, 23);
			this->bt3->TabIndex = 2;
			this->bt3->Text = L"3";
			this->bt3->UseVisualStyleBackColor = true;
			// 
			// bt2
			// 
			this->bt2->Location = System::Drawing::Point(119, 81);
			this->bt2->Name = L"bt2";
			this->bt2->Size = System::Drawing::Size(75, 23);
			this->bt2->TabIndex = 3;
			this->bt2->Text = L"2";
			this->bt2->UseVisualStyleBackColor = true;
			// 
			// bt5
			// 
			this->bt5->Location = System::Drawing::Point(119, 110);
			this->bt5->Name = L"bt5";
			this->bt5->Size = System::Drawing::Size(75, 23);
			this->bt5->TabIndex = 7;
			this->bt5->Text = L"5";
			this->bt5->UseVisualStyleBackColor = true;
			// 
			// bt6
			// 
			this->bt6->Location = System::Drawing::Point(200, 110);
			this->bt6->Name = L"bt6";
			this->bt6->Size = System::Drawing::Size(75, 23);
			this->bt6->TabIndex = 6;
			this->bt6->Text = L"6";
			this->bt6->UseVisualStyleBackColor = true;
			// 
			// bt4
			// 
			this->bt4->Location = System::Drawing::Point(38, 110);
			this->bt4->Name = L"bt4";
			this->bt4->Size = System::Drawing::Size(75, 23);
			this->bt4->TabIndex = 5;
			this->bt4->Text = L"4";
			this->bt4->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(119, 168);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 13;
			this->button4->Text = L".";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(200, 168);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 12;
			this->button5->Text = L"=";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// bt0
			// 
			this->bt0->Location = System::Drawing::Point(38, 168);
			this->bt0->Name = L"bt0";
			this->bt0->Size = System::Drawing::Size(75, 23);
			this->bt0->TabIndex = 11;
			this->bt0->Text = L"0";
			this->bt0->UseVisualStyleBackColor = true;
			// 
			// bt8
			// 
			this->bt8->Location = System::Drawing::Point(119, 139);
			this->bt8->Name = L"bt8";
			this->bt8->Size = System::Drawing::Size(75, 23);
			this->bt8->TabIndex = 10;
			this->bt8->Text = L"8";
			this->bt8->UseVisualStyleBackColor = true;
			this->bt8->Click += gcnew System::EventHandler(this, &Form1::bt8_Click);
			// 
			// bt9
			// 
			this->bt9->Location = System::Drawing::Point(200, 139);
			this->bt9->Name = L"bt9";
			this->bt9->Size = System::Drawing::Size(75, 23);
			this->bt9->TabIndex = 9;
			this->bt9->Text = L"9";
			this->bt9->UseVisualStyleBackColor = true;
			this->bt9->Click += gcnew System::EventHandler(this, &Form1::bt9_Click);
			// 
			// bt7
			// 
			this->bt7->Location = System::Drawing::Point(38, 139);
			this->bt7->Name = L"bt7";
			this->bt7->Size = System::Drawing::Size(75, 23);
			this->bt7->TabIndex = 8;
			this->bt7->Text = L"7";
			this->bt7->UseVisualStyleBackColor = true;
			// 
			// btdvid
			// 
			this->btdvid->Location = System::Drawing::Point(281, 168);
			this->btdvid->Name = L"btdvid";
			this->btdvid->Size = System::Drawing::Size(75, 23);
			this->btdvid->TabIndex = 17;
			this->btdvid->Text = L"/";
			this->btdvid->UseVisualStyleBackColor = true;
			// 
			// btMul
			// 
			this->btMul->Location = System::Drawing::Point(281, 139);
			this->btMul->Name = L"btMul";
			this->btMul->Size = System::Drawing::Size(75, 23);
			this->btMul->TabIndex = 16;
			this->btMul->Text = L"*";
			this->btMul->UseVisualStyleBackColor = true;
			// 
			// btDel
			// 
			this->btDel->Location = System::Drawing::Point(281, 110);
			this->btDel->Name = L"btDel";
			this->btDel->Size = System::Drawing::Size(75, 23);
			this->btDel->TabIndex = 15;
			this->btDel->Text = L"-";
			this->btDel->UseVisualStyleBackColor = true;
			// 
			// btAdd
			// 
			this->btAdd->Location = System::Drawing::Point(281, 81);
			this->btAdd->Name = L"btAdd";
			this->btAdd->Size = System::Drawing::Size(75, 23);
			this->btAdd->TabIndex = 14;
			this->btAdd->Text = L"+";
			this->btAdd->UseVisualStyleBackColor = true;
			this->btAdd->Click += gcnew System::EventHandler(this, &Form1::btAdd_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 226);
			this->Controls->Add(this->btdvid);
			this->Controls->Add(this->btMul);
			this->Controls->Add(this->btDel);
			this->Controls->Add(this->btAdd);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->bt0);
			this->Controls->Add(this->bt8);
			this->Controls->Add(this->bt9);
			this->Controls->Add(this->bt7);
			this->Controls->Add(this->bt5);
			this->Controls->Add(this->bt6);
			this->Controls->Add(this->bt4);
			this->Controls->Add(this->bt2);
			this->Controls->Add(this->bt3);
			this->Controls->Add(this->bt1);
			this->Controls->Add(this->rbResult);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private :
			double _numA,_numB;
			Operation *op;
#pragma endregion
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 op->SetA(_numA);
				  op->SetB(_numB);
				 double aa = op->compute();
				char buf[28];
              sprintf(buf, "%f", aa);
				 rbResult->Text = gcnew String(buf);

			 }
private: System::Void bt8_Click(System::Object^  sender, System::EventArgs^  e) {
			 _numA=8;
			 	char buf[28];
              sprintf(buf, "%f", 8.0);
				 rbResult->Text = gcnew String(buf);
		 }
private: System::Void bt9_Click(System::Object^  sender, System::EventArgs^  e) {
			 _numB=9;
			 	 	char buf[28];
              sprintf(buf, "%f", 9.0);
				 rbResult->Text = gcnew String(buf);
		 }
private: System::Void btAdd_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			   op = OperationFactory::GenerateOperation('+');

		 }
};
}

