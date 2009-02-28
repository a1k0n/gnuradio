#ifndef CONSTELLATION_DISPLAY_PLOT_HPP
#define CONSTELLATION_DISPLAY_PLOT_HPP

#include <qwt_plot.h>
#include <qwt_painter.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_scale_engine.h>
#include <qwt_scale_widget.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_marker.h>
#include <highResTimeFunctions.h>
#include <qwt_symbol.h>

class ConstellationDisplayPlot:public QwtPlot{
  Q_OBJECT

public:
  ConstellationDisplayPlot(QWidget*);
  virtual ~ConstellationDisplayPlot();

  void PlotNewData(const double* realDataPoints, const double* imagDataPoints, 
		   const int64_t numDataPoints);
    
  virtual void replot();

protected slots:
  void LegendEntryChecked(QwtPlotItem *plotItem, bool on);

protected:

private:
  QwtPlotCurve* _plot_curve;

  QwtPlotPanner* _panner;
  QwtPlotZoomer* _zoomer;
  
  double* _realDataPoints;
  double* _imagDataPoints;

  timespec _lastReplot;

  int64_t _numPoints;

  double _displayIntervalTime;
};

#endif /* CONSTELLATION_DISPLAY_PLOT_HPP */
