#pragma once

#include <QtCore/qglobal.h>

#if defined(POLYGON_LIBRARY)
#  define POLYGON_EXPORT Q_DECL_EXPORT
#else
#  define POLYGON_EXPORT Q_DECL_IMPORT
#endif
