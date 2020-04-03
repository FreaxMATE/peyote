sources = [
  'main.c',
  'peyote-application.c',
  'peyote-window.c',
  'peyote-render.c',
  'peyote-filechooser.c',
  'peyote-menu.c',
  'peyote-tabs.c',
  'peyote-file-parser.c',
  'peyote-dialog.c',
]

add_project_arguments('-rdynamic', '-Wl,--export-dynamic', language : 'c')

libgtk = dependency('gtk+-3.0')
gmoddep = dependency('gmodule-2.0')

executable('peyote', sources, dependencies : [libgtk, gmoddep], install: true)

