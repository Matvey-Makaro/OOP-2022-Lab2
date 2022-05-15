#pragma once

#include <QtCore/qglobal.h>

#if defined(RECTANGLE_LIBRARY)
#  define RECTANGLE_EXPORT Q_DECL_EXPORT
#else
#  define RECTANGLE_EXPORT Q_DECL_IMPORT
#endif
