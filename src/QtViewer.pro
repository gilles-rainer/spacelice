################################################################################
#
################################################################################

include( $$TOPDIR/qmake/all.include )

QT += widget

Application()
glew()
glut()
openmesh()

DIRECTORIES = .

# Input
HEADERS += $$getFilesFromDir($$DIRECTORIES,*.hh)
SOURCES += $$getFilesFromDir($$DIRECTORIES,*.cc)
FORMS   += $$getFilesFromDir($$DIRECTORIES,*.ui)

################################################################################
