#include "pch.h"
#include "MainForm.h"
#include <iostream>
#include <vector>


using namespace CliOpenGL;

System::Void MainForm::panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
  auto pen = gcnew System::Drawing::Pen(Drawing::Color::Red);
  e->Graphics->DrawLine(pen, Drawing::Point(10, 10), Drawing::Point(100, 200));

  delete pen; //明示的なdeleteも可（ほっておけばガベコレが入る）
}

System::Void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
  std::cout << "AAAAAAAAAAAAAAAAAA\n";
  
  /*
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  //a = [1,2,3,4]

  for ( int i=0; i < a.size(); ++i ) a[i];
  for ( auto &it : a  ) it = 1;
  */
  
}



System::Void MainForm::panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
  if (e->Button == System::Windows::Forms::MouseButtons::Left  ) std::cout << "left " << e->X << " " << e->Y << "\n";
  if (e->Button == System::Windows::Forms::MouseButtons::Middle) std::cout << "mid"   << e->X << " " << e->Y << "\n";
  if (e->Button == System::Windows::Forms::MouseButtons::Right ) std::cout << "right" << e->X << " " << e->Y << "\n";
}

System::Void MainForm::panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
  std::cout << "move" << e->X << " " << e->Y << "\n";
}
System::Void MainForm::panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){}
System::Void MainForm::MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){}