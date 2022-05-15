#pragma once

#include <QtCore/qglobal.h>

#if defined(LINE_LIBRARY)
#  define LINE_EXPORT Q_DECL_EXPORT
#else
#  define LINE_EXPORT Q_DECL_IMPORT
#endif
