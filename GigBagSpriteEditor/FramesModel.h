#include <QMainWindow>
#include <QBuffer>
#include <fstream>

class FramesModel {
private:
  QVector<QImage> frames;
  int height, width;
public:
  FramesModel();
  FramesModel(int width, int height);
  ~FramesModel();
  FramesModel(const FramesModel& other);
  FramesModel& operator=(FramesModel framesToCopy);

  QVector<QImage> getFrames();

  // Should be called whenever user adds new frame to their sprite
  void addDuplicateFrame();
  void addNewFrame();
  void deleteFrame(int index);
  // Each time the user changes frames or saves (slot from save signal calls this, then saveAsxxx method)
  void saveFrame(int frameIndex, QImage frame);
  void swapFrameOrder(int firstIndex, int secondIndex);
  void newProject();

  void saveAsSSP(std::string filename);
  void saveAsGIF(std::string filename);
  QVector<QImage> openSSP(std::string filepath);
};
