#include "pch.h"
#include "MainForm.h"


using namespace System;
using namespace CliOpenGL;


[STAThreadAttribute]
int main()
{
  MainForm::GetInst()->ShowDialog();
  return 0;
}
