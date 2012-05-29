#ifndef PHASOR_H
#define PHASOR_H

#include <QGraphicsScene>
#include <qmath.h>
#include <QGraphicsView>
#include "streamtablemodel.h"

#define PHASOR_VIEW_MAX_PHASOR_SIZE 100.0
#define PHASOR_VIEW_MAX_SIZE        (PHASOR_VIEW_MAX_PHASOR_SIZE + 20.0)    // defines max distance from centre in any direction
#define PHASOR_VIEW_WIDTH           (2.0 * PHASOR_VIEW_MAX_SIZE)

#define PHASOR_LINE_ALPHA           210

class PhasorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    PhasorScene(StreamTableModel *tableModel, QObject *parent = 0);

public slots:
    void streamSelectionChanged(Stream *stream);
    void streamChanged();
    void streamRemoved();

protected:
    StreamTableModel *tableModel;
    Stream *stream;

    virtual qreal getPhasorMag(int phase);
    virtual qreal getPhasorAngle(int phase);
    QString phaseNumberToText(int phase);

private:
    void draw();
    virtual QString getToolTipText(int phase);

    QPen pen[3];
    QPen plotLinePen;
    QPen plotLineCiclePen;
    QGraphicsLineItem *phaseLine[3];
    QGraphicsTextItem *phaseLabel[3];
    QGraphicsEllipseItem *outerPlotLine;
    QGraphicsEllipseItem *innerPlotLine;
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    QGraphicsTextItem *zeroDegText;
    QGraphicsTextItem *nintyDegText;
    QGraphicsTextItem *oneEightyDegText;
    QGraphicsTextItem *minusNinetyDegText;
};





class CurrentPhasorScene : public PhasorScene
{
    Q_OBJECT
public:
    CurrentPhasorScene(StreamTableModel *tableModel, QObject *parent = 0);

public slots:
    //void streamSelectionChanged(QString svID);

protected:

    qreal getPhasorMag(int phase);
    qreal getPhasorAngle(int phase);

private:

    QString getToolTipText(int phase);
};





class VoltagePhasorScene : public PhasorScene
{
    Q_OBJECT
public:
    VoltagePhasorScene(StreamTableModel *tableModel, QObject *parent = 0);

public slots:
    //void streamSelectionChanged(QString svID);

protected:

    qreal getPhasorMag(int phase);
    qreal getPhasorAngle(int phase);

private:

    QString getToolTipText(int phase);
};

#endif // PHASOR_H
