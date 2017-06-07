#include <stdio.h>
#include <math.h>

// 0 = lower    1 = llc     2 = left
// 3 = ulc      4 = upper   5 = urc
// 6 = right    7 = lrc

float dList [][]= {
  {79.35,0,0},
  {49.35,0,0},
  {34.35,0,0},
  {2.5,2.5,1},
  {0,35,2},
  {2.5,67.5,3},
  {34.35,70,4},
  {49.35,70,4},
  {79.35,70,4},
  {109.35,70,4},
  {124.35,70,4},
  {156.35,67.5,5},
  {158.7,35,6},
  {156.2,2.5,7},
  {124.35,0,0},
  {109.35,0,0}
  };

float getR( float xS, float yS, int detector)
{
  float r = sqrt( ( pow(dList[detector][0]-xS,2) + pow(dList[detector][1]-yS,2) ) );
  return r;
};

float getTheta (float xS ,float yS, int detector)
{
  float theta,vx,vy;
  int id = dList[detector][2];

  //lower
  if(id == 0)
  {
    vx = 1;
    vy = 0;
  }
  else
  {
    if(id == 1)
    {
      vx = 1/(sqrt(2));
      vy = -1/(sqrt(2));
    }
    else
    {//left
      if(id == 2)
      {
        vx = 0;
        vy = -1;
      }
      else
      {
        //upper left corner
        if(id == 3)
        {
          vx = -1/(sqrt(2));
          vy = -1/(sqrt(2));
        }
        else
        {
          //upper
          if(id == 4)
          {
            vx = -1;
            vy = 0;
          }
          else
          { //upper right corner
            if(id == 5)
            {
              vx = -1/(sqrt(2));
              vy = 1/(sqrt(2));
            }
            else
            {
              if(id == 6)
              {
                vx = 1;
                vy = 0;
              }
              else
              {

              }
            }
          }
        }
      }
    }
  }

}
