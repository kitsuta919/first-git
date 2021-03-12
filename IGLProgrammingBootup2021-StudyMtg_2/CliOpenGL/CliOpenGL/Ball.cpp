#include "pch.h"
#include "Ball.h"

#include "COMMON/OglForCLI.h"


static void DrawSphere(const EVec3f& p, double r)
{
  const int N = 10;

  glTranslated(p[0], p[1], p[2]);

  glBegin(GL_TRIANGLES);
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      double t0 = i / (double)N * 2 * M_PI;
      double t1 = (i + 1) / (double)N * 2 * M_PI;
      double p0 = j / (double)N * M_PI - 0.5f * M_PI;
      double p1 = (j + 1) / (double)N * M_PI - 0.5f * M_PI;

      glNormal3d(cos(t0) * cos(p0), sin(t0) * cos(p0), sin(p0));
      glVertex3d(r * cos(t0) * cos(p0), r * sin(t0) * cos(p0), r * sin(p0));
      glVertex3d(r * cos(t1) * cos(p0), r * sin(t1) * cos(p0), r * sin(p0));
      glVertex3d(r * cos(t1) * cos(p1), r * sin(t1) * cos(p1), r * sin(p1));

      glVertex3d(r * cos(t0) * cos(p0), r * sin(t0) * cos(p0), r * sin(p0));
      glVertex3d(r * cos(t1) * cos(p1), r * sin(t1) * cos(p1), r * sin(p1));
      glVertex3d(r * cos(t0) * cos(p1), r * sin(t0) * cos(p1), r * sin(p1));
    }
  }
  glEnd();

  glTranslated(-p[0], -p[1], -p[2]);
}

void Ball::Draw()
{

  float   shin[1] = { 64 };
  EVec4f  spec(1, 1, 1, 0.5), diff(0.1f, 0.7f, 1.0f, 0.7f), ambi(0.1f, 0.2f, 0.1f, 0.5f);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec.data());
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff.data());
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi.data());
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);


  m_r = 1.0f;
  DrawSphere(m_pos, m_r);

}

void Ball::Step(float t) {
    m_velo += t * EVec3f(0, -1,0);
    m_pos +=  m_velo * t;
    if (m_pos[1] < m_r) {
        m_velo[1] = -0.9 * m_velo[1];
    }


}
//
//x += dt * v 
//v += dt * a


//ball 反射、コリジョン、ドラッグ
//BaneBall 伸び縮