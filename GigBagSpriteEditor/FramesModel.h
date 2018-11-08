#include <QMainWindow>

class FramesModel {
private:
  QVector<QImage> frames;
public:
  FramesModel();
  FramesModel(int width, int height);
  ~FramesModel();
  FramesModel(const FramesModel& other);
  FramesModel& operator=(FramesModel framesToCopy);

  void saveAsSSP();
  void saveAsGIF();
};
