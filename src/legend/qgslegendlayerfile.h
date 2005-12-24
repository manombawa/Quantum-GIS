/***************************************************************************
 *   Copyright (C) 2005 by Tim Sutton   *
 *   aps02ts@macbuntu   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef QGSLEGENDLAYERFILE_H
#define QGSLEGENDLAYERFILE_H

#include <qgslegenditem.h>
#include <QPixmap>

class QgsMapLayer;

/**
@author Tim Sutton
*/
class QgsLegendLayerFile : public QgsLegendItem
{
public:
    QgsLegendLayerFile(QTreeWidgetItem * theLegendItem, QString theString, QgsMapLayer* theLayer);
    QgsLegendLayerFile(QString theString, QgsMapLayer* theLayer);
    ~QgsLegendLayerFile();
    bool isLeafNode() {return true;}
    DRAG_ACTION accept(LEGEND_ITEM_TYPE type);
    QgsLegendItem::DRAG_ACTION accept(const QgsLegendItem* li) const;
    QgsMapLayer* layer() const {return mLayer;}
    /**Returns the pixmap containing the file symbol.
     This method is used by QgsMapLayer to paint additional
    information (overview, editable, pyramides) to the pixmap*/
    QPixmap getOriginalPixmap() const;
    void setLegendPixmap(const QPixmap& pix);
    /**Sets mVisibilityCheckBox to on/off*/
    void toggleCheckBox(bool state);
    /**Returns a label for a layer. Is static such that
     the name can be passed to the constructor of QgsLegendLayerFile*/
    static QString nameFromLayer(QgsMapLayer* layer);
 protected:
    QgsMapLayer* mLayer;
};

#endif
