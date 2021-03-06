// LICENSE:
//
// This code is released under the GPL (GNU Public License) version 2.0.
// For full details, see the file GPL.txt included with this source code.
//
// What this means:
//
// This means, in simple terms, that you are free to use this code for any open-source or
// public domain project. You may NOT use this source code as part of a commercial application.
// It may be included, in binary form and bearing a GPL notice, along with commercial
// applications, but the code shall not be compiled directly into a closed-source,
// commercial application.
//
// This code is based on two other products:
// DXFLIB (http://www.ribbonsoft.com/dxflib.html)
//    This is a library for reading DXF files, also GPL.
// MAPWINGIS (http://www.mapwindow.org)
//    This is a library for many general-purpose GIS and mapping applications. It's
//    used for the Shapefile functionality. This software is also open source, this one MPL.
//
// Questions/Comments/Thoughts?
//    http://www.happysquirrel.com/index.php?feature=hs_questions
//
// Thank you!
// Christopher Michaelis

// getInsertions.cpp: The class which retrieves the block insertions from the DXF file


#include "getInsertions.h"

InsertRetrClass::InsertRetrClass()
{
  Names = new string[MaxInserts];
  XVals = new double[MaxInserts];
  YVals = new double[MaxInserts];

  countInserts = 0;
}

InsertRetrClass::~InsertRetrClass()
{
  if ( Names != NULL )
  {
    delete [] Names;
    Names = NULL;
  }
  if ( XVals != NULL )
  {
    delete [] XVals;
    XVals = NULL;
  }
  if ( YVals != NULL )
  {
    delete [] YVals;
    YVals = NULL;
  }
}

void InsertRetrClass::addInsert( const DL_InsertData &data )
{
  if ( countInserts < MaxInserts )
  {
    Names[countInserts] = data.name;
    XVals[countInserts] = data.ipx;
    YVals[countInserts] = data.ipy;
  }
  countInserts++;
}
