
#include <Python.h>
#include "Jieba.hpp"
#include "pyjieba.h"

int
pyjieba_init(pyjieba_t *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {
        (char *)"dict_path", 
        (char *)"hmm_path", 
        (char *)"user_dict_path", 
        (char *)"idf_path",
        (char *)"stop_word_path",
        NULL
    };
    const char *dict_path = "cppjieba/dict/jieba.dict.utf8";
    const char *hmm_path = "cppjieba/dict/hmm_model.utf8";
    const char *user_dict_path = "cppjieba/dict/user.dict.utf8";
    const char *idf_path = "cppjieba/dict/idf.utf8";
    const char *stop_word_path = "cppjieba/dict/stop_words.utf8";
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sssss", kwlist, 
        &dict_path, &hmm_path, &user_dict_path, &idf_path, &stop_word_path)) 
    {
        return -1;
    }

    self->jieba_handler = new cppjieba::Jieba(
            dict_path,
            hmm_path,
            user_dict_path,
            idf_path,
            stop_word_path
        );

    self->extractor = new cppjieba::KeywordExtractor(
            dict_path,
            hmm_path,
            idf_path,
            stop_word_path,
            user_dict_path
        );

    return 0;
}

void
pyjieba_dealloc(pyjieba_t *self)
{
    cppjieba::Jieba* x = (cppjieba::Jieba *) self->jieba_handler;
    delete x;

    cppjieba::KeywordExtractor* y = (cppjieba::KeywordExtractor *) self->extractor;
    delete y;

    return ;
}

static PyObject *
pyjieba_cut(pyjieba_t *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {(char *)"sentence", NULL};
    PyObject *_text;
    PyObject *_list;
    PyObject *_item;
    std::vector<std::string> words;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &_text)) {
        return NULL;
    }

    if (PyBytes_Check(_text)) {
        // pass    
    }else if (PyUnicode_Check(_text)) {
        _text = PyUnicode_AsUTF8String(_text);
    }else {
        PyErr_SetString(PyExc_TypeError, "Expected string or utf-8 encoded bytes.");
        return NULL;
    }

    std::string s (PyBytes_AS_STRING(_text), PyBytes_GET_SIZE(_text));
    self->jieba_handler->Cut(s, words);

    _list = PyList_New(0);

    for (size_t i = 0; i < words.size(); i++) {
        // c++ debug
        // std::cout << words[i].c_str() << std::endl;
        _item = PyString_FromStringAndSize(words[i].c_str(), words[i].size());
        PyList_Append(_list, _item);
        Py_DECREF(_item);
    }

    // c++ debug
    // std::cout << limonp::Join(words.begin(), words.end(), "/") << std::endl;

    return _list;
}

static PyObject *
pyjieba_cut_all(pyjieba_t *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {(char *)"sentence", NULL};
    PyObject *_text;
    PyObject *_list;
    PyObject *_item;
    std::vector<std::string> words;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &_text)) {
        return NULL;
    }

    if (PyBytes_Check(_text)) {
        // pass    
    }else if (PyUnicode_Check(_text)) {
        _text = PyUnicode_AsUTF8String(_text);
    }else {
        PyErr_SetString(PyExc_TypeError, "Expected string or utf-8 encoded bytes.");
        return NULL;
    }

    std::string s (PyBytes_AS_STRING(_text), PyBytes_GET_SIZE(_text));
    self->jieba_handler->CutAll(s, words);

    _list = PyList_New(0);

    for (size_t i = 0; i < words.size(); i++) {
        _item = PyString_FromStringAndSize(words[i].c_str(), words[i].size());
        PyList_Append(_list, _item);
        Py_DECREF(_item);
    }

    // c++ debug
    // std::cout << limonp::Join(words.begin(), words.end(), "/") << std::endl;

    return _list;
}

static PyObject *
pyjieba_cut_for_search(pyjieba_t *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {(char *)"sentence", NULL};
    PyObject *_text;
    PyObject *_list;
    PyObject *_item;
    std::vector<std::string> words;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &_text)) {
        return NULL;
    }

    if (PyBytes_Check(_text)) {
        // pass    
    }else if (PyUnicode_Check(_text)) {
        _text = PyUnicode_AsUTF8String(_text);
    }else {
        PyErr_SetString(PyExc_TypeError, "Expected string or utf-8 encoded bytes.");
        return NULL;
    }

    std::string s (PyBytes_AS_STRING(_text), PyBytes_GET_SIZE(_text));
    self->jieba_handler->CutForSearch(s, words);

    _list = PyList_New(0);

    for (size_t i = 0; i < words.size(); i++) {
        _item = PyString_FromStringAndSize(words[i].c_str(), words[i].size());
        PyList_Append(_list, _item);
        Py_DECREF(_item);
    }

    // c++ debug
    // std::cout << limonp::Join(words.begin(), words.end(), "/") << std::endl;

    return _list;
}

static PyObject *
pyjieba_tag(pyjieba_t *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {(char *)"sentence", NULL};
    PyObject *_text;
    PyObject *_mapping;
    PyObject *_key;
    PyObject *_value;
    std::vector<std::pair<std::string, std::string> > tag_words;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &_text)) {
        return NULL;
    }

    if (PyBytes_Check(_text)) {
        // pass    
    }else if (PyUnicode_Check(_text)) {
        _text = PyUnicode_AsUTF8String(_text);
    }else {
        PyErr_SetString(PyExc_TypeError, "Expected string or utf-8 encoded bytes.");
        return NULL;
    }

    std::string s (PyBytes_AS_STRING(_text), PyBytes_GET_SIZE(_text));
    self->jieba_handler->Tag(s, tag_words);

    _mapping = PyDict_New();

    size_t i;
    for (i = 0; i < tag_words.size(); i++) {
        // c++ debug
        // std::cout << tag_words[i].first << std::endl;
        // std::cout << tag_words[i].second << std::endl;
        _key = PyString_FromStringAndSize(tag_words[i].first.c_str(), tag_words[i].first.size());
        _value = PyString_FromStringAndSize(tag_words[i].second.c_str(), tag_words[i].second.size());
        PyDict_SetItem(_mapping, _key, _value);
        Py_DECREF(_key);
        Py_DECREF(_value);
    }

    return _mapping;
}

static PyObject *
pyjieba_extractor(pyjieba_t *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {(char *)"sentence", (char *)"topk", NULL};
    PyObject *_text;
    int topk = 20;
    PyObject *_mapping;
    PyObject *_list;
    PyObject *_value;
    std::vector<cppjieba::KeywordExtractor::Word> words;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|i", kwlist, &_text, &topk)) {
        return NULL;
    }

    if (PyBytes_Check(_text)) {
        // pass    
    }else if (PyUnicode_Check(_text)) {
        _text = PyUnicode_AsUTF8String(_text);
    }else {
        PyErr_SetString(PyExc_TypeError, "Expected string or utf-8 encoded bytes.");
        return NULL;
    }

    std::string s (PyBytes_AS_STRING(_text), PyBytes_GET_SIZE(_text));
    self->extractor->Extract(s, words, topk);

    _list = PyList_New(0);

    size_t i;
    for (i = 0; i < words.size(); i++) {
        // c++ debug
        // std::cout << words[i].word << std::endl;
        // std::cout << words[i].weight << std::endl;
        _mapping = PyDict_New();
        
        _value = PyString_FromStringAndSize(words[i].word.c_str(), words[i].word.size());
        PyDict_SetItemString(_mapping, "word", _value);
        Py_DECREF(_value);
        
        _value = PyFloat_FromDouble(words[i].weight);
        PyDict_SetItemString(_mapping, "weight", _value);
        Py_DECREF(_value);

        PyList_Append(_list, _mapping);
        Py_DECREF(_mapping);
    }

    // c++ debug
    // std::cout << words << std::endl;

    return _list;
}

static PyMethodDef pyjiebaMethods[] = {
    {"cut", (PyCFunction)pyjieba_cut, METH_VARARGS | METH_KEYWORDS, "jieba.cut"},
    {"cut_all", (PyCFunction)pyjieba_cut_all, METH_VARARGS | METH_KEYWORDS, "jieba.cut_all"},
    {"cut_for_search", (PyCFunction)pyjieba_cut_for_search, METH_VARARGS | METH_KEYWORDS, "jieba.cut_for_search"},
    {"tag", (PyCFunction)pyjieba_tag, METH_VARARGS | METH_KEYWORDS, "jieba.tag"},
    {"extract", (PyCFunction)pyjieba_extractor, METH_VARARGS | METH_KEYWORDS, "jieba.extract"},
    {NULL, NULL}
};

PyDoc_STRVAR(pyjieba_doc, 
"pyjieba.pyjieba");

static PyTypeObject pyjieba_ObjectType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pyjieba.pyjieba",                              /* tp_name */
    sizeof(pyjieba_t),                              /* tp_basicsize */
    0,                                              /* tp_itemsize */
    (destructor)pyjieba_dealloc,                    /* tp_dealloc */
    0,                                              /* tp_print */
    0,                                              /* tp_getattr */
    0,                                              /* tp_setattr */
    0,                                              /* tp_compare */
    0,                                              /* tp_repr */
    0,                                              /* tp_as_number */
    0,                                              /* tp_as_sequence */
    0,                                              /* tp_as_mapping */
    0,                                              /* tp_hash */
    0,                                              /* tp_call */
    0,                                              /* tp_str */
    0,                                              /* tp_getattro */
    0,                                              /* tp_setattro */
    0,                                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE,         /* tp_flags */
    pyjieba_doc,                                    /* tp_doc */
    0,                                              /* tp_traverse */
    0,                                              /* tp_clear */
    0,                                              /* tp_richcompare */
    0,                                              /* tp_weaklistoffset */
    0,                                              /* tp_iter */
    0,                                              /* tp_iternext */
    pyjiebaMethods,                                 /* tp_methods */
    0,                                              /* tp_members */
    0,                                              /* tp_getset */
    0,                                              /* tp_base */
    0,                                              /* tp_dict */
    0,                                              /* tp_descr_get */
    0,                                              /* tp_descr_set */
    0,                                              /* tp_dictoffset */
    (initproc)pyjieba_init,                         /* tp_init */
    0,                                              /* tp_alloc */
    0,                                              /* tp_new */
    0                                               /* tp_free */
};

PyMODINIT_FUNC initpyjieba(void)
{
    PyObject *module;

    pyjieba_ObjectType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&pyjieba_ObjectType) < 0) {
        return ;
    }

    module = Py_InitModule("pyjieba", pyjiebaMethods);
    if (module == NULL) {
        return ;
    }

    Py_INCREF(&pyjieba_ObjectType);
    PyModule_AddObject(module, "jieba", (PyObject *) &pyjieba_ObjectType);
}