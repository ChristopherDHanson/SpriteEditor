
class FramesModel {
private:
  int frames[256][256];
public:
  FramesModel();
  FramesModel(int width, int height);
  ~FramesModel();
  FramesModel(const FramesModel& other);
  FramesModel& operator=(FramesModel framesToCopy);
};
