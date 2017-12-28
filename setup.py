from distutils.core import setup, Extension

pyjieba_module = Extension('pyjieba',
                sources = ['pyjieba.cpp'],
                include_dirs = [
                    './',
                    './cppjieba/include/cppjieba/',
                    './cppjieba/deps/'
                ]
    )

setup (name = 'pyjieba',
    version = '0.1.0',
    description = '',
    author = 'rryqszq4',
    author_email = 'rryqszq@gmail.com',
    ext_modules = [pyjieba_module],
    packages = ['cppjieba'],
    package_dir = {'cppjieba': 'cppjieba'},
    package_data = {'cppjieba': ['dict/*.utf8']}
    )