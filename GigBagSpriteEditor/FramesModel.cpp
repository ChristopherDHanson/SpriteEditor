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

void FramesModel::saveAsSSP(std::string fileName) {
    std::ofstream outfile (fileName + ".ssp");
    int height = 0, width = 0;

    // Output dimensions, number of frames
    outfile << height << " " << width << "\n";
    outfile << frames.length() << "\n";

    // Output data
    for (QImage frame : frames) {
        outfile << "my text here!" << std::endl;
    }

    outfile.close();
}
void FramesModel::saveAsGIF(std::string fileName) {

}
