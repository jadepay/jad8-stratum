from distutils.core import setup, Extension

jad8_hash_module = Extension('jad8_hash',
                               sources = ['jad8module.c',
                                          'jad8.c',
										  'sha3/skein.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/luffa.c',
										  'sha3/bmw.c',
										  'sha3/echo.c',
										  'sha3/shavite.c',
										  'sha3/simd.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'jad8_hashs',
       version = '1.0',
       description = 'Bindings for proof of work used by Jad8',
       ext_modules = [jad8_hash_module])
