
#ifndef QGSVECTORCOLORRAMPV2_H
#define QGSVECTORCOLORRAMPV2_H

#include <QColor>

#include "qgssymbollayerv2.h" // for QgsStringMap

class QgsVectorColorRampV2
{
public:
  virtual ~QgsVectorColorRampV2() {}
  
  virtual QColor color(double value) const = 0;
  
  virtual QString type() const = 0;
  
  virtual QgsVectorColorRampV2* clone() const = 0;
  
  virtual QgsStringMap properties() const = 0;
  
};

#define DEFAULT_GRADIENT_COLOR1 QColor(0,0,255)
#define DEFAULT_GRADIENT_COLOR2 QColor(0,255,0)

class QgsVectorGradientColorRampV2 : public QgsVectorColorRampV2
{
public:
  QgsVectorGradientColorRampV2(QColor color1 = DEFAULT_GRADIENT_COLOR1,
                               QColor color2 = DEFAULT_GRADIENT_COLOR2);
  
  static QgsVectorColorRampV2* create(const QgsStringMap& properties = QgsStringMap());
    
  virtual QColor color(double value) const;
  
  virtual QString type() const { return "gradient"; }
  
  virtual QgsVectorColorRampV2* clone() const;
  
  virtual QgsStringMap properties() const;
  
  QColor color1() const { return mColor1; }
  QColor color2() const { return mColor2; }
  
  void setColor1(QColor color) { mColor1 = color; }
  void setColor2(QColor color) { mColor2 = color; }
  
protected:
  QColor mColor1, mColor2;
};

#define DEFAULT_RANDOM_COUNT   10
#define DEFAULT_RANDOM_HUE_MIN 0
#define DEFAULT_RANDOM_HUE_MAX 359
#define DEFAULT_RANDOM_VAL_MIN 0
#define DEFAULT_RANDOM_VAL_MAX 255
#define DEFAULT_RANDOM_SAT_MIN 0
#define DEFAULT_RANDOM_SAT_MAX 255

class QgsVectorRandomColorRampV2 : public QgsVectorColorRampV2
{
public:
  QgsVectorRandomColorRampV2(int count = DEFAULT_RANDOM_COUNT,
                             int hueMin = DEFAULT_RANDOM_HUE_MIN, int hueMax = DEFAULT_RANDOM_HUE_MAX,
                             int satMin = DEFAULT_RANDOM_SAT_MIN, int satMax = DEFAULT_RANDOM_SAT_MAX,
                             int valMin = DEFAULT_RANDOM_VAL_MIN, int valMax = DEFAULT_RANDOM_VAL_MAX );

  static QgsVectorColorRampV2* create(const QgsStringMap& properties = QgsStringMap());

  virtual QColor color(double value) const;

  virtual QString type() const { return "random"; }

  virtual QgsVectorColorRampV2* clone() const;

  virtual QgsStringMap properties() const;

  void updateColors();

  int count() const { return mCount; }
  int hueMin() const { return mHueMin; }
  int hueMax() const { return mHueMax; }
  int satMin() const { return mSatMin; }
  int satMax() const { return mSatMax; }
  int valMin() const { return mValMin; }
  int valMax() const { return mValMax; }

  void setCount(int val) { mCount = val; }
  void setHueMin(int val) { mHueMin = val; }
  void setHueMax(int val) { mHueMax = val; }
  void setSatMin(int val) { mSatMin = val; }
  void setSatMax(int val) { mSatMax = val; }
  void setValMin(int val) { mValMin = val; }
  void setValMax(int val) { mValMax = val; }

protected:
  int mCount;
  int mHueMin, mHueMax, mSatMin, mSatMax, mValMin, mValMax;
  QList<QColor> mColors;
};

#endif
