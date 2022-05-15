#pragma once

#include "shape.h"

#include <dlfcn.h>
#include <string>
#include <map>


typedef Shape *(* ShapeCreator)();

class ShapesCreator
{
public:
    ShapesCreator(const std::string& shapesDirPath);
    ~ShapesCreator();

    Shape *createShape(std::string shapeName);

    std::list<std::string> getAllShapesNames() const { return shapesNames; }

private:
    std::map<std::string, void *> dlls;

    // name of the shape -> its creator
    std::map<std::string, ShapeCreator> shapes;
    std::list<std::string> shapesNames;
};


