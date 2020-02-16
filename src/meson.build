sources = [
  'main.c',
]

libgtk = dependency('gtk+-3.0')
gmoddep = dependency('gmodule-2.0')

executable('peyote', sources, dependencies : [libgtk, gmoddep], install: true)
