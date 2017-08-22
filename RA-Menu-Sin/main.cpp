#include <QApplication>
#include "window.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    int side = 200;

    Window controlMenu( 3, 5 );

    Block *b1   = new Block( "Home.png",   "Inicio",      side );
    Block *b2   = new Block( "Info.png",   "Informacion", side );
    Block *b3   = new Block( "Pencil.png", "Dibujar",     side );
    Block *b4   = new Block( "Phone.png",  "Llamadas",    side );
    Block *b5   = new Block( "Pin.png",    "Lugares",     side );

    Block *b13  = new Block( "Plus.png",   "Mas",     side );
    Block *b14  = new Block( "User.png",   "Perfil",  side );
    Block *b15  = new Block( "Cart.png",   "Compras", side );
    Block *b16  = new Block( "Delete.png", "Borrar",  side );
    Block *b17  = new Block( "Home.png",   "Hogar",   side );

    Block *b25  = new Block( "Info.png",   "Intereses", side );
    Block *b26  = new Block( "Pencil.png", "Lapiz",     side );
    Block *b27  = new Block( "Phone.png",  "Contactos", side );
    Block *b28  = new Block( "Pin.png",    "Pines",     side );
    Block *b29  = new Block( "Plus.png",   "Opciones",  side );

    controlMenu.container->setBlock( 0, 0,  b1 );
    controlMenu.container->setBlock( 0, 1,  b2 );
    controlMenu.container->setBlock( 0, 2,  b3 );
    controlMenu.container->setBlock( 0, 3,  b4 );
    controlMenu.container->setBlock( 0, 4,  b5 );

    controlMenu.container->setBlock( 1, 0,  b13 );
    controlMenu.container->setBlock( 1, 1,  b14 );
    controlMenu.container->setBlock( 1, 2,  b15 );
    controlMenu.container->setBlock( 1, 3,  b16 );
    controlMenu.container->setBlock( 1, 4,  b17 );

    controlMenu.container->setBlock( 2, 0,  b25 );
    controlMenu.container->setBlock( 2, 1,  b26 );
    controlMenu.container->setBlock( 2, 2,  b27 );
    controlMenu.container->setBlock( 2, 3,  b28 );
    controlMenu.container->setBlock( 2, 4,  b29 );

    controlMenu.showMaximized();

    return app.exec();
}
