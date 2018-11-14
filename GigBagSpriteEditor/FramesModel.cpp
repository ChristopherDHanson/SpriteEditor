#include "FramesModel.h"
#include "gif.h"
#include <qbuffer.h>
#include "previewwindow.h"
#include "iostream"

FramesModel::FramesModel()
{
    height = 0;
    width = 0;
}
FramesModel::FramesModel(int dimensions)
{
    height = dimensions;
    width = dimensions;
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

void FramesModel::addDuplicateFrame() {
    QImage temp;
    if (frames.length() > 0) {
        temp = frames[frames.length() - 1];
    }
    frames.push_back(temp);
}
void FramesModel::addNewFrame() {
    QImage temp;
    if (frames.length() > 0) {
        temp = QImage(frames[frames.length() - 1].size(), QImage::Format_RGB32);
    }
    frames.push_back(temp);
}
void FramesModel::deleteFrame(int index) {
    if (index >= 0 && index < frames.length() - 1) {
        frames.remove(index);
    }
}

<<<<<<< HEAD
=======

>>>>>>> 3ca60282f525130df5c1b214ce0fbcb96338dcd6
void FramesModel::showPreview()
{
    PreviewWindow *w = new PreviewWindow(frames);
    w->show();
}

void FramesModel::saveFrame(int frameIndex, QImage frame) {
    if (frameIndex < frames.size())
        frames[frameIndex] = QImage(frame);
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
          for ( int row = 0; row < frame.height(); ++row ) {
              for ( int col = 0; col < frame.width(); ++col )
              {
                  QColor clrCurrent( frame.pixel( row, col ) );

                  outfile
                            << clrCurrent.red() << " "
                            << clrCurrent.green() << " "
                            << clrCurrent.blue() << " "
                            << clrCurrent.alpha() << " ";
              }
              outfile << std::endl;
          }
      }
      outfile.close();
}
void FramesModel::saveAsGIF(std::string filePath)
{
    //create gifwriter
    GifWriter newGifFile;

    //initialize writer
    GifBegin(&newGifFile, filePath.c_str(), frames[0].width(), frames[0].height(), 10);

    //take each current frame and write it
    for (size_t i = 0; i < frames.length(); i++)
    {
      QImage original = frames[i].convertToFormat(QImage::Format_RGBA8888);
      GifWriteFrame(&newGifFile, original.bits(), frames[i].width(), frames[i].height(), 10, 8, false);
    }

    //complete EOF code
    GifEnd(&newGifFile);
}

void FramesModel::openSSP(std::string filepath) {
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
