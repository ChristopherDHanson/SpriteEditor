#ifndef FRAMESMODEL_H
#define FRAMESMODEL_H

#include <QMainWindow>
#include <QBuffer>
#include <fstream>
#include "framesarea.h"

class FramesModel {
private:
  QVector<QImage> frames;
  int height, width;
public:
  FramesModel();
  FramesModel(int dimensions);
  ~FramesModel();
  FramesModel(const FramesModel& other);
  FramesModel& operator=(FramesModel framesToCopy);

  QVector<QImage> getFrames();

  // Should be called whenever user adds new frame to their sprite
  void addDuplicateFrame();
  void addNewFrame();
  void deleteFrame(int index);
  void showPreview();
  void updateCurrentFrame();
  QImage nextFrame(framesarea *fa, QImage image, int &currentFrameIndex);
  QImage previousFrame(framesarea *fa, QImage image, int &currentFrameIndex);
  void updateTimeline(framesarea *fa);

  // Each time the user changes frames or saves (slot from save signal calls this, then saveAsxxx method)
  void saveFrame(int frameIndex, QImage frame);
  void swapFrameOrder(int firstIndex, int secondIndex);
  void newProject();

  void saveAsSSP(std::string filename);
  void saveAsGIF(std::string filename);
  void openSSP(std::string filepath);
};

#endif // FRAMESMODEL_H
