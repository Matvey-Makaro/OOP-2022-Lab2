#pragma once

#include <QtCore/qglobal.h>

#if defined(LINES_LIBRARY)
#  define LINES_EXPORT Q_DECL_EXPORT
#else
#  define LINES_EXPORT Q_DECL_IMPORT
#endif
