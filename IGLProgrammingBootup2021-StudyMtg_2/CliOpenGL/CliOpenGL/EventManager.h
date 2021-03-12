#pragma once

#pragma unmanaged

#include "COMMON/OglForCLI.h"
#include <vector>
#include "Ball.h"

class EventManager
{
private:
  EventManager ();
  bool m_bL, m_bR, m_bM;
  
  std::vector<Ball> m_balls;

public:
  static EventManager* GetInst() {
    static EventManager p;
    return &p;
  }

  void LBtnDown (EVec2i p, OglForCLI* ogl);
  void MBtnDown (EVec2i p, OglForCLI* ogl);
  void RBtnDown (EVec2i p, OglForCLI* ogl);
  void LBtnUp   (EVec2i p, OglForCLI* ogl);
  void MBtnUp   (EVec2i p, OglForCLI* ogl);
  void RBtnUp   (EVec2i p, OglForCLI* ogl);
  void MouseMove(EVec2i p, OglForCLI* ogl);

  void DrawScene(OglForCLI* ogl);

  void Step();
};


#pragma managed

