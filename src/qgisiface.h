/***************************************************************************
                          qgisiface.h 
 Interface class for exposing functions in QgisApp for use by plugins
                             -------------------
    begin                : 2004-02-11
    copyright            : (C) 2004 by Gary E.Sherman
    email                : sherman at mrcc.com
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 /* $Id$ */
#ifndef QGISIFACE_H
#define QGISIFACE_H
#include "qgisinterface.h"

class QgsMapLayer;
/** \class QgisIface
* \brief Interface class to provide access to private methods in QgisApp
* for use by plugins.
* 
* Only those functions "exposed" by QgisIface can be called from within a
* plugin.
*/
class QgisIface : public QgisInterface{
	public:
  /**
  * Constructor.
  * @param qgis Pointer to the QgisApp object
  */
	QgisIface(QgisApp *qgis=0, const char *name=0);
	~QgisIface();
  /* Exposed functions */
  //! Zoom map to full extent
	void zoomFull();
  //! Zoom map to previous extent
	void zoomPrevious();
  //! Zoom to active layer
	void zoomActiveLayer();
  //! Add a vector layer
  void addVectorLayer(QString vectorLayerPath, QString baseName, QString providerKey);
  //! Get pointer to the active layer (layer selected in the legend)
  QgsMapLayer *activeLayer();
  //! Get source of the active layer
  QString activeLayerSource();
  //! Add a menu to the main menu bar of the application, positioned to the left of Help
  int addMenu(QString menuText, QPopupMenu *menu);
  //! Get an integer from the QgisApp object. This is a test function with no real utility
	int getInt();
  /** Open a url in the users browser. By default the QGIS doc directory is used
  * as the base for the URL. To open a URL that is not relative to the installed
  * QGIS documentation, set useQgisDocDirectory to false.
  * @param url URL to open
  * @param useQgisDocDirectory If true, the URL will be formed by concatenating 
  * url to the QGIS documentation directory path (<prefix>/share/doc)
  */
  void openURL(QString url, bool useQgisDocDirectory=true);
private:
//! Pointer to the QgisApp object
QgisApp *qgis;
};


#endif //#define QGISIFACE_H
