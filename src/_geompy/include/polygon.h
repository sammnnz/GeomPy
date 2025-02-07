/* Polygon description */

#ifndef Py_POLYGON_H
#define Py_POLYGON_H
#ifdef __cplusplus
extern C{
#endif

/* Polygon object type */

PyAPI_DATA(PyTypeObject) PyPolygon_Type;

#if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 9
#  define PyPolygon_CheckExact(op) Py_IS_TYPE(op, &PyPolygon_Type)
#else
#  define PyPolygon_CheckExact(op) (Py_TYPE(op) == &PyPolygon_Type)
#endif

PyAPI_FUNC(int)       PyPolygon_Init(PyObject* self, PyObject* args);
PyAPI_FUNC(PyObject*) PyPolygon_New(void);
PyAPI_FUNC(PyObject*) PyPolygon_IsInnerPoint(PyObject* self, PyObject* point);

#ifndef Py_LIMITED_API
#  define Py_CPYTHON_POLYGON_H
#  include  "cpython/polygon.h"
#  undef Py_CPYTHON_POLYGON_H
#endif

#ifdef __cplusplus
}
#endif
#endif // !Py_POLYGON_H