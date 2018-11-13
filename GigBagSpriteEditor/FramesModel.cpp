#include "FramesModel.h"
#include "gif.h"

FramesModel::FramesModel()
{
    height = 0;
    width = 0;
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

void FramesModel::addFrame() {
    QImage temp;
    if (frames.length() > 0) {
        temp = frames[frames.length() - 1];
    }
    frames.push_back(temp);
}
void FramesModel::deleteFrame(int index) {
    frames.remove(index);
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
void FramesModel::newProject() {
    frames.clear();
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
void FramesModel::saveAsGIF(std::string filePath)
{
    //create gifwriter
    GifWriter newGifFile;

    //initialize writer
    GifBegin(&newGifFile, filePath.c_str(), width, height, 10);

    //take each current frame and write it
    for (size_t i = 0; i < frames.length(); i++)
    {
      QImage original;
      QImage temp = frames[i];
      QByteArray imageByteArr;
      QBuffer buffer(&imageByteArr);
      buffer.open(QIODevice::WriteOnly);
      original.save(&buffer, "");

      char* imageData = imageByteArr.data();
      uint8_t* imageData8t = (uint8_t*)imageData;

      GifWriteFrame(&newGifFile, imageData8t, width, height, 10, 8, false);
    }

    //complete EOF code
    GifEnd(&newGifFile);

    //safe file to stream
    std::ofstream outfile (filePath + ".gif");
    outfile << newGifFile.f;
    outfile.close();
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

    frames.clear();
    for (int frameNum = 0; frameNum < numberOfFrames; frameNum++) {
        QImage q(width, height, QImage::Format_RGB32);
        frames.push_back(q);
    }

    // Get frame data and put it into frames
    for (int currentFrameNumber = 0; currentFrameNumber < numberOfFrames; currentFrameNumber++) {
        QImage currentFrame;
        QColor currentColor;
        for (int currentRowNumber = 0; currentRowNumber < height; currentRowNumber++) {
            getline(fileToOpen, currentLine);
            for (int pixelInRowIndex = 0; pixelInRowIndex < width; pixelInRowIndex++) {
                // red
                pos = currentLine.find(delimiter);
                token = currentLine.substr(0, pos);
                int red = std::stoi(token);
                currentLine.erase(0, pos + delimiter.length());

                // green
                pos = currentLine.find(delimiter);
                token = currentLine.substr(0, pos);
                int green = std::stoi(token);
                currentLine.erase(0, pos + delimiter.length());

                // blue
                pos = currentLine.find(delimiter);
                token = currentLine.substr(0, pos);
                int blue = std::stoi(token);
                currentLine.erase(0, pos + delimiter.length());

                // alpha
                pos = currentLine.find(delimiter);
                token = currentLine.substr(0, pos);
                int alpha = std::stoi(token);
                currentLine.erase(0, pos + delimiter.length());

                currentColor.setRgb(red, green, blue, alpha);
                frames[currentFrameNumber].setPixelColor(pixelInRowIndex, currentRowNumber, currentColor);
            }
        }
    }
}
