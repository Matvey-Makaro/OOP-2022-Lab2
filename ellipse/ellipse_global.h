#pragma once

#include <QtCore/qglobal.h>

#if defined(ELLIPSE_LIBRARY)
#  define ELLIPSE_EXPORT Q_DECL_EXPORT
#else
#  define ELLIPSE_EXPORT Q_DECL_IMPORT
#endif
