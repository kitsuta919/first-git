#include "pch.h"
#include "MainForm.h"
#include "COMMON/tmath.h"
#include "EventManager.h"
#include <iostream>
#include <vector>

#pragma comment( lib, "opengl32.lib" )
#pragma comment( lib, "glu32.lib" )
#pragma comment( lib, "gdi32.lib" )
#pragma comment( lib, "User32.lib" )


using namespace CliOpenGL;


static void CALLBACK MyTimerProc(
  HWND hWnd,           // handle of CWnd that called SetTimer
  UINT nMsg,           // WM_TIMER
  UINT_PTR nIDEvent,   // timer identification
  DWORD dwTime         // system time
)
{
  EventManager::GetInst()->Step();
  MainForm_RedrawMainPanel();
}


MainForm::MainForm(void)
{
  m_ogl = 0;
  InitializeComponent();
  m_ogl = new OglForCLI(GetDC((HWND)panel1->Handle.ToPointer()));
  SetTimer((HWND)panel1->Handle.ToPointer(), 1, 10, &MyTimerProc);
}



void MainForm::RedrawMainPanel()
{
  float  fovY = 45.0;
  float  nearDist = 0.1f;
  float  farDist = 1000.0f;
  m_ogl->OnDrawBegin(panel1->Width, panel1->Height,fovY, nearDist, farDist);

  
  EventManager::GetInst()->DrawScene(m_ogl);
  m_ogl->OnDrawEnd();
}



System::Void MainForm::panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
  RedrawMainPanel();
  //auto pen = gcnew System::Drawing::Pen(Drawing::Color::Red);
  //e->Graphics->DrawLine(pen, Drawing::Point(10, 10), Drawing::Point(100, 200));
  //delete pen; //明示的なdeleteも可（ほっておけばガベコレが入る）
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
  if (e->Button == System::Windows::Forms::MouseButtons::Left  ) EventManager::GetInst()->LBtnDown( EVec2i(e->X,e->Y), m_ogl);
  if (e->Button == System::Windows::Forms::MouseButtons::Middle) EventManager::GetInst()->MBtnDown( EVec2i(e->X, e->Y), m_ogl);
  if (e->Button == System::Windows::Forms::MouseButtons::Right ) EventManager::GetInst()->RBtnDown( EVec2i(e->X, e->Y), m_ogl);
}

System::Void MainForm::panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
  EventManager::GetInst()->MouseMove(EVec2i(e->X, e->Y), m_ogl);
}

System::Void MainForm::panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
  if (e->Button == System::Windows::Forms::MouseButtons::Left  ) EventManager::GetInst()->LBtnUp( EVec2i(e->X, e->Y), m_ogl);
  if (e->Button == System::Windows::Forms::MouseButtons::Middle) EventManager::GetInst()->MBtnUp( EVec2i(e->X, e->Y), m_ogl);
  if (e->Button == System::Windows::Forms::MouseButtons::Right ) EventManager::GetInst()->RBtnUp( EVec2i(e->X, e->Y), m_ogl);
}

System::Void MainForm::MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
  
}