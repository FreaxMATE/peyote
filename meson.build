project('peyote', 'c',
  version: '0.0.1rc4',
  meson_version: '>= 0.40.0',
)

i18n = import('i18n')
cc = meson.get_compiler('c')

subdir('src')
subdir('data')

meson.add_install_script('meson-post-install.py')

