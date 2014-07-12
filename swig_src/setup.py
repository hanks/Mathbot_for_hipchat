from distutils.core import setup, Extension

setup(name='four_rubes', ext_modules=[Extension("_four_rubes", ["four_rubes.cpp", "four_rubes_wrap.cxx"], extra_compile_args=['-g'])])
