#include "shapescreator.h"

#include <iostream>
#include <filesystem>
#include <QDebug>

ShapesCreator::ShapesCreator(const std::string& shapesDirPath)
{
    namespace fs = std::filesystem;

    for (const auto & entry : fs::directory_iterator(shapesDirPath))
    {
        std::string path = entry.path();
        //std::cout << "loading " << path << "\n";
        qDebug() << "loading " << path.c_str() << "\n";
        this->dlls[path] = dlopen(path.c_str(), RTLD_NOW | RTLD_LAZY);

        if (!this->dlls[path])
        {
            qDebug() << "Can't open lib " << path.c_str() << "\n";
            this->dlls.erase(path);
            continue;
        }

        ShapeCreator create = (ShapeCreator)dlsym(this->dlls[path], "createShape");

        if (!create)
        {
            this->dlls.erase(path);
            continue;
        }

        Shape *exampleShape = create();

        shapes[exampleShape->getName().toStdString()] = create;
        shapesNames.push_back(exampleShape->getName().toStdString());

        delete exampleShape;
    }
}

ShapesCreator::~ShapesCreator()
{
    for (auto it = this->dlls.begin(); it != this->dlls.end(); it++)
    {
        dlclose(it->second);
    }
    std::cout << "closed all plugin dlls\n";
}

Shape* ShapesCreator::createShape(std::string shapeName)
{
    qDebug() << "Create shape: " << shapeName.c_str() << "\n";
    return shapes[shapeName]();
}
