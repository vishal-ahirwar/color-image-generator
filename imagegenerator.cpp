#include "imagegenerator.h"

ImageGenerator::ImageGenerator()
{

}

void ImageGenerator::Generate()
{
    unsigned int numberOfImage{};
    unsigned int dimentions[2]{0};
    std::cerr<<"How Many Color Images you want to generate ??";
    std::cin>>numberOfImage;
    std::cerr<<"Dimentions of Image [Width/Height]??";
    std::cin>>dimentions[0]>>dimentions[1];
    QDir directory{QDir::current()};
    bool is_dirExists{directory.cd("../../source")};
    if(is_dirExists)
    {
        std::cerr<<"[message] pics Dir Exists!\n";
        std::cerr<<"[message] Source ing Directory pics!\n";

        bool  is_picsDirectory{directory.exists("pics")};
        if(is_picsDirectory)
        {
            directory.cd("pics");
        }else
        {
            directory.mkdir("pics");
            directory.cd("pics");
        };
        foreach(QString filePath,directory.entryList())
        {
            directory.remove(filePath);
        };
        QRandomGenerator random;
        for(int i=0;i<numberOfImage;++i)
        {
            QImage image(dimentions[0],dimentions[1],QImage::Format_ARGB32);
            QColor color(random.bounded(255),random.bounded(255),random.bounded(255));
            image.fill(color);
            QString filePath{directory.absoluteFilePath(QString::number(i)+".png")};
            std::cerr<<"Save file : "<<filePath.toStdString()<<"\n";
            image.save(filePath);
        }
    }else
    {

        std::cerr<<"[error] Dir Doesn't Exists!\n";
        std::cerr<<"[message] Creating Directory!\n";
        directory.mkdir("../../source");
    };
};
