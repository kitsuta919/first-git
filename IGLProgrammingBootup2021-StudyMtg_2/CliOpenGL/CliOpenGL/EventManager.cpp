#include "pch.h"
#include "EventManager.h"
#include "MainForm.h"
#include <iostream>

using namespace CliOpenGL;


EventManager::EventManager() {
  m_bL = m_bR = m_bM = false;
  m_balls.push_back(Ball(EVec3f(0, 3, 0), EVec3f(5, 0, 0)));
  m_balls.push_back(Ball(EVec3f(0, 10, 0), EVec3f(3, 0, 3)));
  m_balls.push_back(Ball(EVec3f(0, 2, 1), EVec3f(1, 0, 0)));
  m_balls.push_back(Ball(EVec3f(0, 3, 0), EVec3f(1, 0, 0)));

}


void EventManager::Step()
{
    for (int i = 0; i < (int) m_balls.size(); ++i) {
        m_balls[i].Step(0.01);
    }
  std::cout << "a";
  //todo

}



void EventManager::LBtnDown(EVec2i p, OglForCLI* ogl)
{
  ogl->BtnDown_Rot(p);
  m_bL = true;
}

void EventManager::MBtnDown(EVec2i p, OglForCLI* ogl)
{
  m_bM = true;
  ogl->BtnDown_Zoom(p);
}

void EventManager::RBtnDown(EVec2i p, OglForCLI* ogl)
{
  m_bR = true;
  ogl->BtnDown_Trans(p);
}

void EventManager::LBtnUp(EVec2i p, OglForCLI* ogl) { ogl->BtnUp(); m_bL = false;}
void EventManager::MBtnUp(EVec2i p, OglForCLI* ogl) { ogl->BtnUp(); m_bM = false;}
void EventManager::RBtnUp(EVec2i p, OglForCLI* ogl) { ogl->BtnUp(); m_bR = false;}

void EventManager::MouseMove(EVec2i p, OglForCLI* ogl) 
{
  if( !m_bR && !m_bM  && !m_bL ) return;
  ogl->MouseMove(p);
  //MainForm_RedrawMainPanel(); 
}




void EventManager::DrawScene(OglForCLI* ogl) 
{
  //電気を消す．glColorが有効になる
  glDisable(GL_LIGHTING);

  glBegin(GL_LINES);
    glColor3d(1, 0, 0); glVertex3d(0, 0, 0); glVertex3d(10, 0, 0);
    glColor3d(0, 1, 0); glVertex3d(0, 0, 0); glVertex3d(0, 10, 0);
    glColor3d(0, 0, 1); glVertex3d(0, 0, 0); glVertex3d(0, 0, 10);
  glEnd();

  //電気付ける．Materialが有効になる
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);

  glEnable(GL_LIGHTING);
  float lPos0[4] = { 1000, 1000,-1000,1 };
  float lPos1[4] = { -1000, 1000,-1000,1 };
  float lPos2[4] = { 1000,-1000,-1000,1 };
  glLightfv(GL_LIGHT0, GL_POSITION, lPos0);
  glLightfv(GL_LIGHT1, GL_POSITION, lPos1);
  glLightfv(GL_LIGHT2, GL_POSITION, lPos2);

  glEnable(GL_DEPTH_TEST);


  for (int i = 0; i < (int)m_balls.size(); ++i)
  {
    m_balls[i].Draw();
  }

}