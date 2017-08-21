#include <iostream>
#include <fstream>
#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>
 
#include "SpectralViewer.h"
#include "GL/glut.h"


void create_menu(QMainWindow &w);
void usage_and_exit(int xcode);

int main(int argc, char **argv) {
	// OpenGL check
	QApplication::setColorSpec( QApplication::CustomColor );
	QApplication app(argc,argv); 
	glutInit(&argc,argv); 

	if ( !QGLFormat::hasOpenGL() ) {
		QString msg = "System has no OpenGL support!";
		QMessageBox::critical( 0, QString("OpenGL"), msg + QString(argv[1]) );
		return -1;
	}

	int c;
	OpenMesh::IO::Options opt;

	while ( (c=getopt(argc,argv,"hbs"))!=-1 ) {
		switch(c) {
			case 'b': opt += OpenMesh::IO::Options::Binary; break;
			case 'h': usage_and_exit(0);
			case 's': opt += OpenMesh::IO::Options::Swap; break;
			default: usage_and_exit(1);
		}
	}

	// enable most options for now
	opt += OpenMesh::IO::Options::VertexColor;
	opt += OpenMesh::IO::Options::VertexNormal;
	opt += OpenMesh::IO::Options::VertexTexCoord;
	opt += OpenMesh::IO::Options::FaceColor;
	opt += OpenMesh::IO::Options::FaceNormal;
	opt += OpenMesh::IO::Options::FaceTexCoord;

	// create widget
	QMainWindow mainWin;
	SpectralViewer spectralWindow(&mainWin);
	spectralWindow.setOptions(opt);
	mainWin.setCentralWidget(&spectralWindow);

	create_menu(mainWin);

	// static mesh, hence use strips
	spectralWindow.enable_strips();

	mainWin.resize(640, 480);
	mainWin.show();

	// load scene if specified on the command line
	if ( optind < argc ) {
		spectralWindow.open_mesh_gui(argv[optind]);
	}

	if ( ++optind < argc ) {
		spectralWindow.open_texture_gui(argv[optind]);
	}

	return app.exec();
}

void create_menu(QMainWindow &w) {
    using namespace Qt;
    QMenu *fileMenu = w.menuBar()->addMenu(w.tr("&File"));

    QAction* openAct = new QAction(w.tr("&Open mesh..."), &w);
    openAct->setShortcut(w.tr("Ctrl+O"));
    openAct->setStatusTip(w.tr("Open a mesh file"));
    QObject::connect(openAct, SIGNAL(triggered()), w.centralWidget(), SLOT(query_open_mesh_file()));
    fileMenu->addAction(openAct);

    QAction* texAct = new QAction(w.tr("Open &texture..."), &w);
    texAct->setShortcut(w.tr("Ctrl+T"));
    texAct->setStatusTip(w.tr("Open a texture file"));
    QObject::connect(texAct, SIGNAL(triggered()), w.centralWidget(), SLOT(query_open_texture_file()));
    fileMenu->addAction(texAct);
}

void usage_and_exit(int xcode) {
   std::cout << "Usage: meshviewer [-s] [mesh] [texture]\n" << std::endl;
   std::cout << "Options:\n"
	     << "  -b\n"
	     << "    Assume input to be binary.\n\n"
             << "  -s\n"
             << "    Reverse byte order, when reading binary files.\n"
             << std::endl;
   exit(xcode);
}
