#pragma once

#pragma unmanaged

#include "COMMON/tmath.h"


class Ball
{
  double m_r   ; //”¼Œa
  EVec3f m_pos ; //ˆÊ’u
  EVec3f m_velo; //‘¬“x

public:
  Ball(const EVec3f pos, const EVec3f velo)
  {
    m_pos  = pos;
    m_velo = velo;
  }

  Ball(const Ball& src) {
    this->m_r = src.m_r;
    this->m_pos = src.m_pos;
    this->m_velo = src.m_velo;
 
  }
  
  Ball& operator =(const Ball& src) {
    this->m_r = src.m_r;
    this->m_pos = src.m_pos;
    this->m_velo = src.m_velo;

  }
  
  void Draw();
  void Step(float t);
};



#pragma managed
