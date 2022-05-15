#include "shapescreator.h"

#include <iostream>
#include <filesystem>

ShapesCreator::ShapesCreator(std::string shapesDirPath)
{
    namespace fs = std::filesystem;

    for (const auto & entry : fs::directory_iterator(shapesDirPath))
    {
        std::string path = entry.path();
        std::cout << "loading " << path << "\n";
        this->dlls[path] = dlopen(path.c_str(), RTLD_NOW | RTLD_LAZY);

        if (!this->dlls[path])
        {
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
    return shapes[shapeName]();
}
