
schemadir = join_paths(get_option('datadir'), 'glib-2.0/schemas')
install_data([
  'org.github.FreaxMATE.peyote.gschema.xml',
], install_dir: schemadir)

appdatadir = join_paths(get_option('datadir'), 'metainfo')
install_data([
  'org.github.FreaxMATE.peyote.appdata.xml',
], install_dir: appdatadir)

desktopdir = join_paths(get_option('datadir'), 'applications')
install_data([
  'org.github.FreaxMATE.peyote.desktop',
], install_dir: desktopdir)

gladedir = join_paths(get_option('datadir'), 'peyote/')
install_data([
  'org.github.FreaxMATE.peyote.glade',
],  install_dir: gladedir)

subdir('icons')

