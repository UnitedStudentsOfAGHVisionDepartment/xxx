///////////////////////////////////////////////////////////////////////////////
// File generated by HDevelop for HALCON/C++ Version 13.0
///////////////////////////////////////////////////////////////////////////////



#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#endif



using namespace HalconCpp;

// Procedure declarations 
void oae (HImage *ho_obraz, HTuple hv_licz, HTuple *hv_liczd);
// Procedures 
void oae (HImage *ho_obraz, HTuple hv_licz, HTuple *hv_liczd)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_WindowHandle;
//fdgdfg
  ReadImage(&(*ho_obraz), "C:/Users/LENOVO/Desktop/testy QT/cpp/h1/halcon1/res/nic.bmp");
  (*hv_liczd) = hv_licz;


  return;
}


