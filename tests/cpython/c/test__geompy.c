#include <Python.h>

#include "../../../src/_geompy/include/Geompy.h"

int test_cpython__geompy() {
    int fail;
	PyObject* pArgs;
	PyObject* pFunc;
    PyObject *pModule;
    PyObject* pName;
	PyObject *pValue;

    fail = 0;
	pName = PyUnicode_FromString("test__geompy");
    pModule = PyImport_Import(pName);
    if (! pModule) {
        fail = 2;
        goto except;
    }
    /* tests.cpython.test__geompy.test_polygon___init___valid */
    pFunc = PyObject_GetAttrString(pModule, "test_polygon___init___valid");
	if (! (pFunc && PyCallable_Check(pFunc))) {
		fail = 3;
		goto except;
	}

	PyObject* point2d = PyTuple_New(3);
	PyObject* point1 = Py_BuildValue("(dd)", 0.0, 0.0);
	PyObject* point2 = Py_BuildValue("(dd)", 2.0, 0.0);
	PyObject* point3 = Py_BuildValue("(dd)", 0.0, 1.0);
	PyTuple_SetItem(point2d, 0, point1);
	PyTuple_SetItem(point2d, 1, point2);
	PyTuple_SetItem(point2d, 2, point3);

	pArgs = PyTuple_New(1);
	PyTuple_SetItem(pArgs, 0, point2d);
	if (! pArgs) {
		fail = 4;
		Py_DECREF(pArgs);
		goto except;
	}

	pValue = PyObject_CallObject(pFunc, pArgs);
	if (! pValue) {
		fail = 5;
		goto except;
	}
	Py_DECREF(pValue);
    /*
     * Test other geompy functions here
     */
	goto finally;
except:
    assert(fail != 0);
finally:
    Py_XDECREF(pModule);
    return fail;
}

void test_cpython_geompy_code(int argc, char *argv[]) {
    int res_geompy;
	PyObject* path_list;
	PyObject* sys_path;
	wchar_t* program;

	// https://stackoverflow.com/questions/78247260/how-to-set-the-python-executable-name-now-that-py-setprogramname-is-deprecate
	program = Py_DecodeLocale(argv[0], NULL);
    if (! program) {
        fprintf(stderr, "error: cannot decode argv[0]\n");
        exit(1);
    }

    Py_SetProgramName(program);  /* optional, recommended */
    Py_Initialize();

	sys_path = PySys_GetObject("path");
	PyList_Insert(sys_path, 0, PyUnicode_FromString("D:\\Projects\\VSCProjects\\geompy\\geompy\\src"));
	PyList_Insert(sys_path, 1, PyUnicode_FromString("D:\\Projects\\VSCProjects\\geompy\\geompy\\tests\\cpython"));
	PyList_Insert(sys_path, 2, PyUnicode_FromString("D:\\Projects\\VSCProjects\\geompy\\geompy\\.venv\\Lib\\site-packages"));
    path_list = PyUnicode_Join(PyUnicode_FromWideChar(L"\n", -1), sys_path);
    printf("\n%ls", PyUnicode_AsWideCharString(path_list, NULL));

    res_geompy = test_cpython__geompy();
    if (! res_geompy && ! PyErr_Occurred()) {
        PyErr_Print();
    }

    /*
     * Test other modules here
     */
	
     if (Py_FinalizeEx() < 0) {
		fprintf(stderr, "error: %s: Py_FinalizeEx error\n", __func__); // __func__ only defined in C99+
		exit(120);
	}

	PyMem_RawFree(program);
}

int main(int argc, char *argv[]) {
	fprintf(stdout, "Testing starting ");
	test_cpython_geompy_code(argc, argv);
	fprintf(stdout, "Testing finishing ");
	
	return 0;
}