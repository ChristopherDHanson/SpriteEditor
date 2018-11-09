#include "FramesModel.h"

FramesModel::FramesModel()
{
  
}
FramesModel::~FramesModel()
{

}
FramesModel::FramesModel(const FramesModel& other)
{

}
FramesModel& FramesModel::operator=(FramesModel framesToCopy)
{
    return *this;
}

void FramesModel::addFrame(QImage newFrame) {
    frames.push_back(newFrame);
}
void FramesModel::saveFrame(int frameIndex, QImage frame) {
    if (frameIndex < frames.size())
        frames[frameIndex] = frame;
}
void FramesModel::swapFrameOrder(int firstIndex, int secondIndex) {
    if (firstIndex < frames.length() && secondIndex < frames.length()) {
        QImage temp = frames[firstIndex];
        frames[firstIndex] = frames[secondIndex];
        frames[secondIndex] = temp;
    }
}


void FramesModel::saveAsSSP(std::string fileName) {
      std::ofstream outfile (fileName + ".ssp");
      int height = 0, width = 0;
      // Output dimensions, number of frames
      outfile << height << " " << width << "\n";
      outfile << frames.length() << "\n";
      // Output data
      for (QImage frame : frames) {
          for ( int row = 1; row < frame.height() + 1; ++row ) {
              for ( int col = 1; col < frame.width() + 1; ++col )
              {
                  QColor clrCurrent( frame.pixel( row, col ) );

                  outfile
                            << clrCurrent.red() << " "
                            << clrCurrent.green() << " "
                            << clrCurrent.blue() << " "
                            << clrCurrent.alpha() << " "
                            << std::endl;
              }
          }
      }
      outfile.close();
}
void FramesModel::saveAsGIF(std::string fileName) {

}

QVector<QImage> FramesModel::openSSP(std::string filepath) {

}
