#include <Python.h>

#include "jad8.h"

static PyObject *jad8_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    jad8_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    jad8_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Jad8Methods[] = {
    { "getPoWHash", jad8_getpowhash, METH_VARARGS, "Returns the proof of work hash using jad8 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Jad8Module = {
    PyModuleDef_HEAD_INIT,
    "jad8_hash",
    "...",
    -1,
    Jad8Methods
};

PyMODINIT_FUNC PyInit_jad8_hash(void) {
    return PyModule_Create(&Jad8Module);
}

#else

PyMODINIT_FUNC initjad8_hash(void) {
    (void) Py_InitModule("jad8_hash", Jad8Methods);
}
#endif
