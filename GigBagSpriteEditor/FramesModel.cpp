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

QVector<QImage> FramesModel::getFrames() {
    return frames;
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
    std::string currentLine;
    std::ifstream fileToOpen (filepath);

    // Get width and height
    getline(fileToOpen, currentLine);
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    pos = currentLine.find(delimiter);
    token = currentLine.substr(0, pos);
    height = std::stoi(token);
    currentLine.erase(0, pos + delimiter.length());
    width = std::stoi(currentLine);

    // Get number frames
    getline(fileToOpen, currentLine);
    int numberOfFrames = std::stoi(currentLine);

    // Get frame data and put it into frames
    for (int currentFrameNumber = 0; currentFrameNumber < numberOfFrames; currentFrameNumber++) {
        QImage currentFrame;
        // get pixel data for this frame
        // assemble qimage for this frame
        // add qimage to frames
        frames.push_back(currentFrame);
    }
}
