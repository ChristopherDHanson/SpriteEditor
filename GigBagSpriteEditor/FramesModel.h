#include <QMainWindow>
#include <fstream>

class FramesModel {
private:
  QVector<QImage> frames;
public:
  FramesModel();
  FramesModel(int width, int height);
  ~FramesModel();
  FramesModel(const FramesModel& other);
  FramesModel& operator=(FramesModel framesToCopy);

  void saveAsSSP(std::string filename);
  void saveAsGIF(std::string filename);
  QVector<QImage> openSSP(std::string filepath);
};
